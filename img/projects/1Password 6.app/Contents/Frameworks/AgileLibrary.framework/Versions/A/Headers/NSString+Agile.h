//
//  NSString+Agile.h
//  1Password
//
//  Created by Roustem Karimov on 08/07/08.
//  Copyright 2008 AgileBits Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Agile)

+ (NSString *)ag_stringWithCharacter:(unsigned int)aCharacter;
+ (NSString *)ag_horizontalEllipsisString;

/*!
 @method
 @abstract Tries to create a UTF8 string and falls back to plain C string if conversion to UTF8 fails.
 */
+ (NSString*)ag_utf8stringWithBytes:(const void*)bytes length:(int)length;

+ (NSString*)ag_utf8stringWithData:(NSData*)data;

+ (NSString *)ag_uuid;
+ (NSString *)ag_shortUUID;
- (NSString *)ag_shortUUIDFromLong;
- (NSString *)ag_longUUIDFromShort;

/*!
 @method
 @abstract Tries to create a UTF8 string and falls back to plain C string if conversion to UTF8 fails.
 */
+ (NSString*)ag_utf8stringWithCString:(const char*)source;

+ (BOOL)ag_isEmpty:(NSString *)string;


+ (NSString *)ag_stringWithData:(NSData *)data;
- (NSData *)ag_asData;

- (NSString *)ag_stringByTrimmingTrailingCharactersInSet:(NSCharacterSet *)characterSet;

- (NSString *)ag_stringByAbbreviatingWithTildeInPath;

/*!
	@method
	@abstract Calculate number of lines in the receiver
 */
- (NSUInteger)ag_numberOfLines;

/*!
	@method
	@abstract Calculate number of lines in the receiver, stop and return maxNumber if maxNumber is reached.
	@discussion Improves performances on large strings.
 */
- (NSUInteger)ag_numberOfLinesLimitedTo:(NSUInteger)maxNumber;

- (BOOL)ag_isIPAddress;
- (BOOL)ag_isLocalIPAddress;
- (NSString *)ag_stringByExtractingURI;
- (NSString *)ag_stringByExtractingFullDomain;
- (NSString *)ag_stringByExtracting2ndTLD;
- (NSString *)ag_stringWithURLProtocol;


- (NSString *)ag_firstLetter;

/*!
 @method
 @abstract Will return the contents of the string where each character is replaced by a bullet sign
 */
- (NSString*)ag_asBullets;
- (NSString *)ag_stringAsMaskedPasswordWithPrefixLength:(NSUInteger)prefixLength; // the prefix will be the unmasked portion

- (NSString *)awsStringByReplacingCharactersInRange:(NSRange)r withString:(NSString*)s;
- (NSString *)ag_stringAsLegalFilePath;


- (NSString *)ag_asPrintableHTML;
- (NSString *)ag_html;
- (NSString*)ag_javascript;

- (BOOL)ag_matchesRegex:(NSString *)regex;

- (NSString *)ag_stringByDecodingHTMLEntities;

- (NSString *)ag_trim;

- (BOOL)ag_containsCharacterInSet:(NSCharacterSet *)searchSet;
- (BOOL)ag_containsString:(NSString *)searchString options:(unsigned int)mask;
- (BOOL)ag_containsString:(NSString *)searchString;
- (NSString *)ag_htmlString;
- (NSString *)ag_stringByExtractingScheme;
- (NSString *)ag_stringByExtractingSchemeAndDomain;
- (NSString *)ag_validURLString;
- (NSString *)ag_validSecureURLString;
- (NSString *)ag_stringByExtractingURIPathAndQuery;
- (NSString *)ag_validPredicateFormatString;
- (NSString *)ag_validTagString;

+ (NSString *)ag_humanReadableSizeStringForBytes:(unsigned long long)bytes;

/*!
 @method
 @abstract Removes accent marks that require multi-step input on Mac, for example, Option-i+U. 
	Note that is different from stringByFoldingWithOptions:locale method,
	it does not convert characters that can be entered by single combination of characters like Ø, etc.
 */
- (NSString *)ag_stringByStrippingAccentMarks;

- (NSString *)ag_asFormattedCreditCardNumber;

@end

#ifdef __cplusplus
extern "C" {
#endif
	NSString *concealedString(NSString *s);
#ifdef __cplusplus
}
#endif
