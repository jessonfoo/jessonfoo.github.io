//
//  NSArray+AWS.h
//  1Password
//
//  Created by Roustem Karimov on 8/30/07.
//  Copyright 2007 AgileBits Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (Agile)

- (id)ag_firstObject;
- (id)ag_objectAtIndex:(NSUInteger)objectIndex;
- (NSArray*)ag_arrayByRemovingFirstObject;

- (BOOL)ag_containsCaseInsensitiveString:(NSString*)s;

- (NSComparisonResult)ag_compareStringContents:(NSArray *)b;
- (NSArray *)ag_deepTraversalPerformingBlock:(BOOL (^)(id value, NSInteger index, id key, id result))block;

@end

@interface NSMutableArray (Agile)

- (NSMutableArray *)ag_removeNSNullValues;

@end
