//
//  NSImage+Agile.h
//  1PasswordAgent
//
//  Created by Roustem Karimov on 27/06/08.
//  Copyright 2008 AgileBits Inc. All rights reserved.
//

#import <Cocoa/Cocoa.h>

typedef enum {
	OPImagePositionTop,
	OPImagePositionMiddle,
	OPImagePositionBottom,
} OPImagePositionY;

typedef enum {
	OPImagePositionLeft,
	OPImagePositionCenter,
	OPImagePositionRight,
} OPImagePositionX;


@interface NSImage (Agile)

+ (NSImage *)ag_imageNamed:(NSString *)imageName inBundle:(NSBundle *)bundle;

+ (NSImage *)ag_imageWithCGImage:(CGImageRef)imageRef;
+ (NSImage *)ag_imageFromCIImage:(CIImage *)ciImage;
- (CIImage *)ag_toCIImage;
- (NSData *)ag_dataRepresentationOfType:(NSBitmapImageFileType)type;
- (NSData *)ag_dataWithPNGQuantParams:(NSDictionary *)params;

- (void)ag_drawTiledInRect:(NSRect)destRect leftCapWidth:(CGFloat)leftCapWidth rightCapWidth:(CGFloat)rightCapWidth operation:(NSCompositingOperation)op fraction:(CGFloat)delta;
- (void)ag_drawTiledInRect:(NSRect)destRect leftCapWidth:(CGFloat)leftCapWidth rightCapWidth:(CGFloat)rightCapWidth topCapHeight:(CGFloat)topCapHeight bottomCapHeight:(CGFloat)bottomCapHeight operation:(NSCompositingOperation)op fraction:(CGFloat)delta flipped:(BOOL)flipped;
- (void)ag_drawStretchedInRect:(NSRect)destRect topCapWidth:(CGFloat)topCapWidth bottomCapWidth:(CGFloat)bottomCapWidth operation:(NSCompositingOperation)op fraction:(CGFloat)delta flipped:(BOOL)flipped;
- (void)ag_drawStretchedInRect:(NSRect)destRect leftCapWidth:(CGFloat)leftCapWidth rightCapWidth:(CGFloat)rightCapWidth operation:(NSCompositingOperation)op fraction:(CGFloat)delta;
- (void)ag_drawStretchedInRect:(NSRect)destRect leftCapWidth:(CGFloat)leftCapWidth rightCapWidth:(CGFloat)rightCapWidth topCapHeight:(CGFloat)topCapHeight bottomCapHeight:(CGFloat)bottomCapHeight operation:(NSCompositingOperation)op fraction:(CGFloat)delta flipped:(BOOL)flipped;
- (void)ag_drawProportionallyInRect:(NSRect)destRect operation:(NSCompositingOperation)op fraction:(CGFloat)delta;
- (NSImage *)ag_imageByScalingProportionallyToSize:(NSSize)targetSize;
- (NSImage *)ag_imageByScalingProportionallyToSize:(NSSize)targetSize scale:(CGFloat)scaleFactor;
- (NSImage *)ag_imageCroppedWithRect:(NSRect)rect;

- (void)drawInRect:(NSRect)rect positionX:(OPImagePositionX)positionX positionY:(OPImagePositionY)positionY;

- (NSImage *)ag_darkerImage:(CGFloat)amount;


- (void)ag_drawTiledInRect:(NSRect)rect origin:(NSPoint)inOrigin operation:(NSCompositingOperation)inOperation;
- (NSImage *)ag_imageByApplyingBadge:(NSImage *)badge;

@end

NSImage *coreTypesImage(NSString *imageFileName);
NSRect AGCenterRectInRect(NSSize inner, NSRect outer);

NSData *OPImagePNGRepresentation(NSImage *image);
NSData *OPImageJPGRepresentation(NSImage *image, CGFloat quality);
