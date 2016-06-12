//
//  NSFileManager+FileInformation.h
//  ApplicationFrameworks
//
//  Created by Nathan Van Fleet on 2015-07-24.
//
//

#import <Foundation/Foundation.h>

@interface NSFileManager (FileInformation)
- (NSString *)ag_SHA256OfFileAtURL:(NSURL *)fileURL;
- (BOOL)ag_compareSHA256OfFileAtURL:(NSURL *)fileURL toKnownSHA256:(NSString *)knownHash;
- (unsigned long long)ag_fileSizeAtURL:(NSURL *)fileURL;
- (BOOL)ag_diskSpaceAvailable:(uint64_t)diskSpaceRequired fileURL:(NSURL*)fileURL;
+ (NSString *)ag_UTIOfFileAtFileURL:(NSURL *)fileURL;
@end
