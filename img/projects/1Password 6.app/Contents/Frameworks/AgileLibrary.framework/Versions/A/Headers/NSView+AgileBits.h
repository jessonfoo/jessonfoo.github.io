//
//  NSView+AgileBits.h
//  OnePasswordOSX
//
//  Created by Roustem Karimov on 2013-05-05.
//  Copyright (c) 2013 AgileBits Inc. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSView (AgileBits)

- (void)ag_fillDirtyRects;

- (NSRect)ag_topLeftCornerForRadius:(CGFloat)radius;
- (NSRect)ag_topRightCornerForRadius:(CGFloat)radius;
- (NSRect)ag_bottomLeftCornerForRadius:(CGFloat)radius;
- (NSRect)ag_bottomRightCornerForRadius:(CGFloat)radius;

- (BOOL)ag_isAncestorOfWindowFirstResponder;

// Debug
- (NSString *)ag_debugDescription;
- (NSString *)ag_recursiveDescription;

@end
