//
//  AGUserKeychain.h
//  OnePasswordiOS
//
//  Created by Roustem Karimov on 12-04-02.
//  Copyright (c) 2012 AgileBits. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const AGKeychainAccountNameKey;
extern NSString *const AGKeychainValueDataKey;
extern NSString *const AGKeychainServerKey;
extern NSString *const AGKeychainDescriptionKey;

@interface AGUserKeychain : NSObject

/**
 * Make as restrictive as possible. Preferred value: kSecAttrAccessibleWhenUnlockedThisDeviceOnly.
 */
@property (nonatomic, assign) CFTypeRef accessible;
@property (nonatomic, copy) NSString *serviceName;

#if TARGET_OS_IPHONE
@property (nonatomic, copy) NSString *keychainGroupIdentifier;
#endif //TARGET_OS_IPHONE

+ (AGUserKeychain *)keychainForService:(NSString *)serviceName;

/**
 * CFTypeRef kSecAttrAccessibleWhenPasscodeSetThisDeviceOnly
 * CFTypeRef kSecAttrAccessibleWhenUnlockedThisDeviceOnly
 * CFTypeRef kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly
 * CFTypeRef kSecAttrAccessibleAlwaysThisDeviceOnly
 */
+ (AGUserKeychain *)keychainForService:(NSString *)serviceName accessible:(CFTypeRef)accessible;

+ (BOOL)deleteAllAccountsForServiceName:(NSString *)serviceName error:(NSError **)error;

+ (BOOL)isKeychainAvailable;

- (NSArray *)allAccountsWithError:(NSError **)error;

- (NSData *)dataForAccount:(NSString *)accountName error:(NSError **)error;
- (NSDate *)modificationDateForAccount:(NSString *)accountName error:(NSError **)error;
- (BOOL)boolForAccount:(NSString *)accountName error:(NSError **)error;
- (NSString *)stringForAccount:(NSString *)accountName error:(NSError **)error;

- (BOOL)setData:(NSData *)data forAccount:(NSString *)accountName onServer:(NSString *)serverAddress withDescription:(NSString *)description error:(NSError **)error;
- (BOOL)setString:(NSString *)value forAccount:(NSString *)accountName onServer:(NSString *)serverAddress withDescription:(NSString *)description error:(NSError **)error;

- (BOOL)setData:(NSData *)data forAccount:(NSString *)accountName error:(NSError **)error;
- (BOOL)setString:(NSString *)value forAccount:(NSString *)accountName error:(NSError **)error;
- (BOOL)setBool:(BOOL)value forAccount:(NSString *)accountName error:(NSError **)error;

@end
