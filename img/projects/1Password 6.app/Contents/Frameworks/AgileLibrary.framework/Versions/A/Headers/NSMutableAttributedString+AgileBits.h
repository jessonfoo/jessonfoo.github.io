//
//  NSMutableAttributedString+AgileBits.h
//  ApplicationFrameworks
//
//  Created by Kevin Hayes on 2016-03-01.
//
//

#import <Cocoa/Cocoa.h>

@interface NSMutableAttributedString (AgileBits)

- (void)ag_addHyperlinkAttributesToRange:(NSRange)range withURL:(NSURL*)aURL withColor:(NSColor *)color;
- (void)ag_replaceLinkTagsWithLinks:(NSArray<NSURL *> *)links withColor:(NSColor *)color;
- (NSArray <NSValue *> *)ag_linkRanges;
- (void)ag_removeLinkTagsFromRanges:(NSArray<NSValue *> *)ranges;

@end
