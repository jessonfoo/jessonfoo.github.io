//
//  NSDate+Agile.h
//  AgileLibrary
//
//  Created by Roustem Karimov on 09/07/08.
//  Copyright 2008 AgileBits Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDate (Agile)

+ (NSInteger)ag_currentYear;
+ (NSInteger)ag_currentMonth;

- (NSString *)ag_localFullDateString;
- (NSString *)ag_localDateString;
- (NSString *)ag_localLongDateString;
- (NSString *)ag_localDateTimeString;
- (NSString *)ag_localExpirationDateString;

@end
