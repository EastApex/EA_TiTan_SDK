//
//  UIImage+SCAdd.h
//  Apps
//
//  Created by 李永彬 on 2018/4/5.
//  Copyright © 2018年 appscomm. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, WatchFaceImageFormat)
{
    WatchFaceImageFormatBMPRGB565,
    WatchFaceImageFormatPNGRGB565,
    WatchFaceImageFormatRGB888,
    WatchFaceImageFormatBMPRGB565Dither,
    WatchFaceImageFormatPNGRGB565Dither,
    WatchFaceImageFormatRGB565GrayDither
};

Byte closest_rb(Byte c);
Byte closest_g(Byte c);

uint16_t RGB16BIT(Byte r, Byte g, Byte b);

uint16_t dither_xy(
                   int x,
                   int y,
                   Byte r,
                   Byte g,
                   Byte b
                   );

@interface UIImage (SCAdd)

- (UIImage *)imageByResizeToSize:(CGSize)size;

- (UIImage *) imageWithTintColor:(UIColor *)tintColor;
- (UIImage *) imageWithGradientTintColor:(UIColor *)tintColor;
- (UIImage *) imageWithTintColor:(UIColor *)tintColor blendMode:(CGBlendMode)blendMode;

/** 生成一张指定颜色的图片 */
+ (UIImage *)imageWithColor:(UIColor *)color;

/**
 返回一个圆形图
 @param opaque 设置为YES，将矩形图片改成圆形后，圆形以外的部分是黑色; NO为透明
 */
- (instancetype)createRoundImageWithOpaque:(BOOL)opaque scale:(CGFloat)scale;

- (UIImage *)clipimageSize:(CGSize)imageSize;
- (UIImage*)transformtoSize:(CGSize)newsize;

+ (UIImage *) imageFromImageView:(UIImageView *)imageView;

- (UIImage *) imageByRotate:(CGFloat)angle;
    
- (NSData *) dataWithFormat:(WatchFaceImageFormat)format;

+ (UIImage *)imageFromSnapShotView:(UIView *)view;

//图片裁剪为圆形
+ (UIImage *)imageWithClipImageToArcImage:(UIImage *)image;

+ (UIImage *)compositeImageWithBgImage:(UIImage *)bgImage subImage:(UIImage *)subImage size:(CGSize)size;

- (NSData *)bitmapData;
- (NSData *)bitmapFileHeaderData;
- (NSData *)bitmapDataWithFileHeader;

@end
