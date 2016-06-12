-- B5 Client Schema

--
-- A billing account provides a master record for everything else. Every User, Team, and Vault belong to a specific billing account
--
CREATE TABLE IF NOT EXISTS accounts (	
	id INTEGER PRIMARY KEY AUTOINCREMENT,

	created_at INTEGER NOT NULL,
	updated_at INTEGER NOT NULL,
	last_auth_at INTEGER,

	account_uuid TEXT NOT NULL, -- account uuid from the server
	user_uuid TEXT, -- user uuid from the server
	user_version INTEGER NOT NULL, -- user attr version (uint32)
	account_version INTEGER NOT NULL, -- account attr version (uint32)
	account_template_version INTEGER NOT NULL, -- (uint32)
	user_keyset_version INTEGER NOT NULL, -- user keyset version (uint32)

	account_type TEXT NOT NULL, -- Personal, Family, or Business account
	account_state TEXT NOT NULL, -- has been verified
	team_name TEXT NOT NULL, -- Only set for Family and Business accounts
	team_avatar TEXT NOT NULL, --

	base_attachment_url TEXT NOT NULL, --
	base_avatar_url TEXT NOT NULL, --

	user_first_name TEXT NOT NULL,
	user_last_name TEXT NOT NULL,
	user_email TEXT NOT NULL,
	user_avatar TEXT NOT NULL,

	server TEXT NOT NULL,
	enc_login TEXT NOT NULL, -- Verify with JG

	UNIQUE (account_uuid)
);

--
-- Each account has a single associated set of billing properties
--
CREATE TABLE IF NOT EXISTS account_billing (
	id INTEGER PRIMARY KEY AUTOINCREMENT,

	account_id INTEGER NOT NULL,

	status TEXT NOT NULL,
	account_will_freeze_at INTEGER,
	storage_capacity INTEGER NOT NULL,
	storage_used INTEGER NOT NULL,

	FOREIGN KEY (account_id) REFERENCES accounts(id) ON DELETE CASCADE
);
CREATE INDEX IF NOT EXISTS idx_account_billing_account_id ON account_billing (account_id);

--
-- Each account has a single associated user overview
--
CREATE TABLE IF NOT EXISTS user_overview (
	id INTEGER PRIMARY KEY AUTOINCREMENT,

	account_id INTEGER NOT NULL,
	account_permissions BIGINT DEFAULT 0 NOT NULL,

	FOREIGN KEY (account_id) REFERENCES accounts(id) ON DELETE CASCADE
);
CREATE INDEX IF NOT EXISTS idx_user_overview_account_id ON user_overview (account_id);

--
-- Current and archived user key sets
--
CREATE TABLE IF NOT EXISTS keysets (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	uuid TEXT NOT NULL,

	account_id INTEGER NOT NULL,

	created_at INTEGER NOT NULL,
	updated_at INTEGER NOT NULL,

	sn INTEGER NOT NULL, -- Serial number is used to determine the current KeySet (uint32)
	encrypted_by TEXT NOT NULL, --

	enc_sym_key TEXT NOT NULL, -- The current symmetric key is always encrypted with the keys derived from the master password. When the new KeySet is added, its sn is incremented and the the new key is used to re-encrypt the previous version.	
	enc_pri_key TEXT NOT NULL, -- The private key is encrypted with the symmetric key, JSON format		
	pub_key TEXT NOT NULL, -- Public key, JSON format
		
	FOREIGN KEY (account_id) REFERENCES accounts(id) ON DELETE CASCADE
);
CREATE INDEX IF NOT EXISTS idx_keysets_account_id ON keysets (account_id);


--
-- The set of vaults the user has access to
--
CREATE TABLE IF NOT EXISTS vaults (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	uuid TEXT NOT NULL,

	account_id INTEGER NOT NULL,
	
	created_at INTEGER NOT NULL,
	updated_at INTEGER NOT NULL,

	metadata_version INTEGER NOT NULL, -- Current version of the meta data for this table (uint32)
	key_sn INTEGER NOT NULL, -- Serial number is used to determine whether we need to sync the arhive keys (uint32)
	content_version INTEGER NOT NULL, -- Current version of the vault's content (used for syncing) (uint32)

	type TEXT NOT NULL, -- [P]ersonal, [E]veryone, [U]ser-created, [T]emplate
	enc_attrs TEXT NOT NULL,

	UNIQUE (account_id, uuid),
	FOREIGN KEY (account_id) REFERENCES accounts(id) ON DELETE CASCADE	
);
CREATE INDEX IF NOT EXISTS idx_vaults_account_id ON vaults (account_id);

--
-- User Personal Keys
--
	CREATE TABLE IF NOT EXISTS user_personal_keys (
	id INTEGER PRIMARY KEY AUTOINCREMENT,

	account_id INTEGER NOT NULL,

	key BLOB NOT NULL,

	created_at INTEGER NOT NULL,
	updated_at INTEGER NOT NULL,

	FOREIGN KEY (account_id) REFERENCES accounts(id) ON DELETE CASCADE
);
CREATE INDEX IF NOT EXISTS idx_user_personal_keys_account_id ON user_personal_keys (account_id);


--
-- Vault Access
--
CREATE TABLE IF NOT EXISTS vault_access (
	id INTEGER PRIMARY KEY AUTOINCREMENT,

	account_id INTEGER NOT NULL,
	vault_id INTEGER NOT NULL,
	
	created_at INTEGER NOT NULL,
	updated_at INTEGER NOT NULL,

	version INTEGER NOT NULL, -- Current version of the vault access record (uint32)

	lease_timeout INTEGER NOT NULL, -- How long this vault can be accessed on the client without checking the permissions with the server. (uint32)
	
	acl INTEGER NOT NULL, -- (uint64)
	enc_vault_key TEXT NOT NULL,
	
	FOREIGN KEY (account_id) REFERENCES accounts(id) ON DELETE CASCADE,
	FOREIGN KEY (vault_id) REFERENCES vaults(id) ON DELETE CASCADE
);
CREATE INDEX IF NOT EXISTS idx_vault_access_account_id ON vault_access (account_id);
CREATE INDEX IF NOT EXISTS idx_vault_access_vault_id ON vault_access (vault_id);

CREATE TABLE IF NOT EXISTS categories (
	id INTEGER PRIMARY KEY AUTOINCREMENT, -- keeping as category UUID is not considered unique
	uuid TEXT NOT NULL,

	account_id INTEGER NOT NULL,

	created_at INTEGER NOT NULL,
	updated_at INTEGER NOT NULL,

	singular_name TEXT NOT NULL,
	plural_name TEXT NOT NULL,
 	json BLOB,

	UNIQUE (account_id, uuid),
	FOREIGN KEY (account_id) REFERENCES accounts(id) ON DELETE CASCADE
);
CREATE INDEX IF NOT EXISTS idx_categories_account_id ON categories (account_id);



CREATE TABLE IF NOT EXISTS items (
	id INTEGER PRIMARY KEY AUTOINCREMENT, -- keeping as item UUID is not considered unique
	uuid TEXT NOT NULL,

	vault_id INTEGER NOT NULL,
	category_id INTEGER NOT NULL,
	category_uuid TEXT NOT NULL,

	created_at INTEGER NOT NULL,
	updated_at INTEGER NOT NULL,

	version INTEGER NOT NULL, -- Current edit version of the vault (uint32)
	local_edit_count INTEGER NOT NULL, -- Count of edits made locally on this item

	trashed INTEGER NOT NULL,
	fave_index INTEGER NOT NULL, -- (uint32)
	scope TEXT,

	rejected_build_version INTEGER,
	rejection_reason TEXT,
	changer_uuid TEXT,

	overview BLOB,
	details BLOB,

	FOREIGN KEY (vault_id) REFERENCES vaults (id) ON DELETE CASCADE,
	FOREIGN KEY (category_id) REFERENCES categories(id) ON DELETE CASCADE
);
CREATE INDEX IF NOT EXISTS idx_items_vault_id ON items (vault_id);
CREATE INDEX IF NOT EXISTS idx_items_trashed ON items (trashed);
CREATE INDEX IF NOT EXISTS idx_items_category_id ON items (category_id);
CREATE UNIQUE INDEX IF NOT EXISTS idx_items_vault_id_uuid ON items (vault_id, uuid);


CREATE TABLE IF NOT EXISTS config (
	name TEXT NOT NULL PRIMARY KEY,
	value TEXT
);

--
-- Set Initial Schema Version to Database
-- Nathan Van Fleet 08-10-2015
-- When we update the B5DatabaseSchema.sql file we create a migrator in tandem to it to update existing installations.
-- We need to increment the version here to match what the migrators will migrate the database to or migrations will run on newly installed DBs.
--
-- NOTE: YOU ALSO NEED TO UPDATE THE VALUE IN THE APPLICATION CODE. It is used by the application to determine that the installed DB is newer than expected
-- if a user loads an older version of the software.
--

INSERT INTO config (name, value) VALUES ("schema_version", "9");

CREATE TABLE IF NOT EXISTS item_usage (
	item_id INTEGER NOT NULL PRIMARY KEY,
	usage_counter INTEGER NOT NULL,
	last_used_at INTEGER NOT NULL,

	FOREIGN KEY (item_id) REFERENCES items(id) ON DELETE CASCADE
);
CREATE INDEX IF NOT EXISTS idx_item_usage_item_id ON item_usage (item_id);



CREATE TABLE IF NOT EXISTS tags (
	id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
	vault_id INTEGER NOT NULL,
	enc_attrs BLOB,

	FOREIGN KEY (vault_id) REFERENCES vaults(id) ON DELETE CASCADE
);
CREATE INDEX IF NOT EXISTS idx_tags_vault_id ON tags (vault_id);


CREATE TABLE IF NOT EXISTS item_tags (
	tag_id INTEGER NOT NULL,
	item_id INTEGER NOT NULL,

	PRIMARY KEY (tag_id, item_id), 
	FOREIGN KEY (tag_id) REFERENCES tags(id) ON DELETE CASCADE, 
	FOREIGN KEY (item_id) REFERENCES items(id) ON DELETE CASCADE
);
CREATE INDEX IF NOT EXISTS idx_item_tags_tag_id ON item_tags (tag_id);
CREATE INDEX IF NOT EXISTS idx_item_tags_item_id ON item_tags (item_id);


CREATE TABLE IF NOT EXISTS item_urls (
	id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,

	item_id INTEGER NOT NULL,

	display_order INTEGER NOT NULL,
	autosave_token TEXT,

	naked_hash TEXT,
	derived_hash TEXT,
	hash_version INTEGER,
	enc_attrs BLOB,

	FOREIGN KEY (item_id) REFERENCES items(id) ON DELETE CASCADE
);
CREATE INDEX IF NOT EXISTS idx_item_urls_item_id ON item_urls (item_id);

