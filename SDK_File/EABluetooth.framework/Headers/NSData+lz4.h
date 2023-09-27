//
//  NSData+lz4.h
//  LYBluetoothSDK
//
//  Created by SuJiang on 2019/6/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (lz4)

- (NSData *) lz4Compress;

@end

NS_ASSUME_NONNULL_END
