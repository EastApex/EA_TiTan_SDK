//
//  DialCustomModel.h
//  SmartcommWatch
//
//  Created by smartcomm on 2021/5/28.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, CustomShowType) {
    CustomTypeShowAdd = 0,       //"+"号
    CustomTypeShowPicture,   //本地相册选择的图片
    CustomTypeShowComponent  //固定的几种表针
};

@interface DialCustomModel : NSObject

//默认的背景图片
@property (nonatomic, copy) NSString *defalutBgName;
//从本地选择的图片
@property (nonatomic, strong) UIImage *photo;
//组件的图片名称（包含背景图）
@property (nonatomic, copy) NSString *componetImgName;;
//预览图片的名字(不包含背景图)
@property (nonatomic, copy) NSString *previewImgName;
//对应的bin文件名
@property (nonatomic, copy) NSString *binFileName;
@property (nonatomic, assign) CustomShowType customShowType;

@property (nonatomic, assign) BOOL selected;

+ (NSArray *)getCustomWatchfaces;

@end

NS_ASSUME_NONNULL_END
