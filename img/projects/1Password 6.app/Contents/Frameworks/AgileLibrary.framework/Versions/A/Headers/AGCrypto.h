//
//  AGCrypto.h
//  AgileLibrary
//
//  Created by Roustem Karimov on 16/06/08.
//  Copyright 2008 AgileBits Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (AGCrypto)

+ (NSMutableData *)ag_randomData:(int)length;
+ (NSData *)ag_dataFromHex:(NSString *)hex;

- (NSString *)ag_base64encode;
- (NSString *)ag_base64URLencode;

- (NSString *)ag_hex;
- (NSString *)ag_HEX;
- (NSString *)ag_HeX;

- (NSData *)ag_MD5;
- (NSString *)ag_MD5hex;

- (NSData *)ag_SHA256;
- (NSString *)ag_SHA256hex;

- (NSData *)ag_SHA512;
- (NSString *)ag_SHA512hex;
	
- (NSData *)ag_SHA1;

// RC4
- (NSData *)ag_RC4Encrypt:(NSString *)password;
- (NSData *)ag_RC4Decrypt:(NSString *)password;

// Low-level AES encryption. Key length must be 128 or 256 bit
- (NSMutableData *)ag_AESEncryptWithKey:(NSData *)key ivec:(NSData *)ivec salt:(NSData *)salt;
- (NSMutableData *)ag_AESDecryptWithKey:(NSData *)key ivec:(NSData *)ivec;

// Binary password will be used to compute Key and ivec based on MD5 and salt
// keySize = (kCCKeySizeAES256, kCCKeySizeAES128)
- (NSMutableData *)ag_AESEncryptWithBinaryPassword:(NSData *)password keySize:(int)keySize useSalt:(BOOL)useSalt;
- (NSMutableData *)ag_AESDecryptWithBinaryPassword:(NSData *)password keySize:(int)keySize;


// String password will be used to generate key and ivec using PBKDF2 function
// keySize = (kCCKeySizeAES256, kCCKeySizeAES128)
- (NSMutableData *)ag_AESEncryptWithPassword:(NSString *)password keySize:(int)keySize PBKDF2Iterations:(NSUInteger)iterations salt:(NSData *)salt;
- (NSMutableData *)ag_AESEncryptWithPassword:(NSString *)password keySize:(int)keySize PBKDF2Iterations:(NSUInteger)iterations;
- (NSMutableData *)ag_AESDecryptWithPassword:(NSString *)password keySize:(int)keySize PBKDF2Iterations:(NSUInteger)iterations;


#if TARGET_OS_IPHONE

// Non-salted variety
- (NSMutableData *)ag_aes128encryptWithKey:(NSData *)key ivec:(NSData *)ivec;
- (NSMutableData *)ag_aes128decryptWithKey:(NSData *)key ivec:(NSData *)ivec;

- (NSMutableData *)ag_aes128encryptWithPassword:(NSString *)pwd useSalt:(BOOL)useSalt;
- (NSMutableData *)ag_aes128decryptWithPassword:(NSString *)pwd;


- (NSMutableData *)ag_aes128encryptWithPassword:(NSString *)password PBKDF2Iterations:(NSUInteger)iterations salt:(NSData *)salt;
- (NSMutableData *)ag_aes128encryptWithPassword:(NSString *)password PBKDF2Iterations:(NSUInteger)iterations;
- (NSMutableData *)ag_aes128decryptWithPassword:(NSString *)password PBKDF2Iterations:(NSUInteger)iterations;

- (NSMutableData *)ag_aes128encryptWithKey:(NSData *)pwd useSalt:(BOOL)useSalt;
- (NSMutableData *)ag_aes128decryptWithKey:(NSData *)pwd;
#endif

@end

@interface NSString (AGCrypto)

// + (NSString *)ag_uniqueSystemID;

- (NSString *)ag_base64ToBase64URL; // Safe to call this on already-base64url encoded strings.
- (NSData *)ag_base64decode;
- (NSData *)ag_base64URLdecode;
- (NSData *)ag_hexData;

- (NSData *)ag_base32decode;

- (NSData *)ag_MD5;
- (NSString *)ag_MD5hex;

- (NSData *)ag_SHA256;
- (NSString*)ag_SHA256hex;

- (NSData *)ag_SHA512;
- (NSString *)ag_SHA512hex;

- (NSData *)ag_SHA1;

@end


@interface NSURL (AGCrypto)

- (NSData *)ag_SHA256;
- (NSString *)ag_SHA256hex;

@end

//
//
//
#ifdef __cplusplus
extern "C" {
#endif
	long ag_random(void);
    unsigned long ag_random_range(unsigned long bottom, unsigned long top);
	
	NSString *persistentObfuscatedString(NSString *s);
	NSString *persistentDeobfuscatedString(NSString *s);
    
    NSData *HKDF_SHA256(NSData *seed, NSData *info, NSData *salt, int outputSize);
	
#ifdef __cplusplus
}
#endif
