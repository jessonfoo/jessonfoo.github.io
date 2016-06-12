//
//  AGJSONKit
//  OnePasswordOSX
//
//  Created by David Teare on 2013-08-08.
//  Copyright (c) 2013 AgileBits Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AGJSONKit : NSObject

@end

@interface NSString (AGJSONKit)
- (id)ag_objectFromJSONStringWithError:(NSError **)error;
- (id)ag_mutableObjectFromJSONStringWithError:(NSError **)error;
@end

@interface NSData (AGJSONKit)
- (id)ag_objectFromJSONDataWithError:(NSError **)error;
- (id)ag_mutableObjectFromJSONDataWithError:(NSError **)error;
@end

@interface NSArray (AGJSONKit)
- (NSData *)ag_JSONDataWithError:(NSError **)error;
- (NSString *)ag_JSONStringWithError:(NSError **)error;
@end

@interface NSDictionary (AGJSONKit)
- (NSData *)ag_JSONDataWithError:(NSError **)error;
- (NSString *)ag_JSONStringWithError:(NSError **)error;
@end
