//
//  AgileLibrary.h
//  AgileLibrary
//
//  Created by Roustem Karimov on 2014-06-14.
//  Copyright (c) 2014 AgileBits. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for AgileLibrary.
FOUNDATION_EXPORT double AgileLibraryVersionNumber;

//! Project version string for AgileLibrary.
FOUNDATION_EXPORT const unsigned char AgileLibraryVersionString[];


#import <AgileLibrary/AGCrypto.h>
#import <AgileLibrary/AGJSONKit.h>
#import <AgileLibrary/AGLogger.h>
#import <AgileLibrary/AGPasswordUtils.h>
#import <AgileLibrary/AGUserKeychain.h>
#import <AgileLibrary/NSArray+Agile.h>
#import <AgileLibrary/NSData+Agile.h>
#import <AgileLibrary/NSData+ZLib.h>
#import <AgileLibrary/NSDate+Agile.h>
#import <AgileLibrary/NSMutableDictionary+Agile.h>
#import <AgileLibrary/NSDictionary+Agile.h>
#import <AgileLibrary/NSObject+Agile.h>
#import <AgileLibrary/NSString+Agile.h>
#import <AgileLibrary/NSString+AgilePasswords.h>
#import <AgileLibrary/AGReachability.h>
#import <AgileLibrary/AgileLibraryLoggerSettings.h>
#import <AgileLibrary/AgileLibraryMacros.h>
#import <AgileLibrary/NSFileManager+FileInformation.h>
#import <AgileLibrary/NSString+Validation.h>
#import <AgileLibrary/NSString+SecureString.h>
#import <AgileLibrary/NSData+SecureData.h>

#if TARGET_OS_IPHONE

#import <AgileLibrary/UIImage+Agile.h>
#import <AgileLibrary/OPUIApplication.h>

#else

#import <AgileLibrary/NSFileManager+Agile.h>
#import <AgileLibrary/NSMenu+AgileBits.h>
#import <AgileLibrary/NSBezierPath+AgileBits.h>
#import <AgileLibrary/NSImage+Agile.h>
#import <AgileLibrary/AGScriptUtils.h>
#import <AgileLibrary/NSColor+AgileBits.h>
#import <AgileLibrary/NSControl+AgileBits.h>
#import <AgileLibrary/NSString+JSWrapper.h>
#import <AgileLibrary/NSView+AgileBits.h>
#import <AgileLibrary/NSIndexPath+AgileBits.h>
#import <AgileLibrary/NSMutableAttributedString+AgileBits.h>

#endif



