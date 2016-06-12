//
//  PasswordUtils.h
//  1Password
//
//  Created by Roustem Karimov on 15/08/07.
//  Copyright 2007 AgileBits Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSInteger PASSWORD_MIXEDCASE;
extern NSInteger PASSWORD_LOWERCASE;
extern NSInteger PASSWORD_UPPERCASE;

extern NSInteger AG_PASSWORD_TERRIBLE;
extern NSInteger AG_PASSWORD_WEAK;
extern NSInteger AG_PASSWORD_GOOD;
extern NSInteger AG_PASSWORD_EXCELLENT;
extern NSInteger AG_PASSWORD_FANTASTIC;

extern NSString *OPPrefPasswordPronounceable;
extern NSString *OPPrefPasswordLength;
extern NSString *OPPrefPasswordDigits;
extern NSString *OPPrefPasswordSymbols;
extern NSString *OPPrefPasswordAvoidAmbiguous;
extern NSString *OPPrefPasswordAllowRepeats;
extern NSString *OPPrefPasswordCopyToClipboard;
extern NSString *OPPrefPasswordSaveWhenCopiedToClipboard;
extern NSString *OPPrefPasswordUseMixedCase;
extern NSString *OPPrefPasswordUseHyphen;
extern NSString *OPPrefPasswordUseDigits;
extern NSString *OPPrefPasswordUseSymbols;
extern NSString *OPPrefPasswordDicewareWordCount;
extern NSString *OPPrefPasswordDicewareWordSeparator;

@class OPUserSettings;

// These methods are to support the predicate editor row for passwordStrength
@interface NSObject (AgileIntegerNumbers)
- (int) ag_number10;
- (int) ag_number20;
- (int) ag_number40;
- (int) ag_number60;
- (int) ag_number90;
- (int) ag_number100;
@end


@interface AGPasswordUtils : NSObject {
}

+ (short)calcStrength:(NSString *)password;
+ (NSString *)strengthDescription:(float)strength;

+ (NSString *)generatePasswordUsingOptionsFromDefaults:(OPUserSettings *)defaults;
+ (NSString *)randomPassword:(NSInteger)length numbers:(NSInteger)numbers symbols:(NSInteger)symbols avoidAmbiguous:(BOOL)avoidAmbiguous allowRepeats:(BOOL)allowRepeats;
+ (NSString *)randomPassword:(NSInteger)length numbers:(NSInteger)numbers symbols:(NSInteger)symbols avoidAmbiguous:(BOOL)avoidAmbiguous allowRepeats:(BOOL)allowRepeats forbiddenCharacters:(NSString *)forbiddenCharacters;
+ (NSString *)pronounceablePassword:(NSInteger)length useMixedCase:(BOOL)useMixedCase separatorSets:(NSArray *)separatorSets;

+ (NSAttributedString *)attributedPasswordString:(NSString *)passwordString selected:(BOOL)selected;
+ (void)attributePasswordString:(NSMutableAttributedString *)value selected:(BOOL)selected;

/**
	Generates pronounceable password with sets of short words delimited by hyphen. The length of the password is going to be maxLength or (maxLength-1) characters delimited by a hyphen. Unlike pronounceablePassword:separator: This method makes sure that the password does not end with the hyphen.
 */
+ (NSString *)pronounceablePasswordWithMaxLength:(NSInteger)maxLength;
+ (NSString *)dicewarePasswordWithNumberOfWords:(NSInteger)numberOfWords useSeparator:(NSString *)separator useSentenceCase:(BOOL)useSentenceCase;

+ (void)runTests;
+ (void)assertEqual:(NSString*)expected actual:(NSString*)actual;

@end

