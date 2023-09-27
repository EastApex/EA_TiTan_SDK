//
//  DFUAirUpgradeMessageInfo.h
//  APPSBlueToothManger
//
//  Created by Apple on 16/3/23.
//  Copyright © 2016年 iOSLearing. All rights reserved.
//



#ifdef DEBUG

#define DFULog(...) NSLog(__VA_ARGS__)

#else

#define DFULog(...)

#endif

typedef NS_ENUM(int,DFUMessageTips){
    
    DFUMessageTipsProgress                 = 0, /**< 是进度条君 */
    
    DFUMessageTipsHaveFreescaleSuccess     = 1, /**< 是不是有Freescale的升级 Freescale的升级是从手机传到设备缓存 再从缓存写入到Freescale 所以 传输完成后需要验证设备从缓存传输到Freescale是否丢包 */
    
    DFUMessageTipsDontHaveFreescaleSuccess = 2, /**< 没有Freescale升级 成功回调后表示成功 */
    
    DFUMessageTipsConnectSuccess           = 3, /**< 连接升级设备成功 */
    
    DFUMessageTipsConnectFailed            = 4, /**< 设备断连 */
    DFUMessageTipsTimeOut                  = 5, /**< 断连 */
    DFUMessageTipsResponeError             = 6,  /**< 设备响应数据错误 */
    DFUMessageTipsDontFoundUpgradeEquipment= 7   /**< 没有发现升级设备 */
    
};

static NSString * const DFUMessageTipsTimeOutStr                  = @"升级超时";
static NSString * const DFUMessageTipsConnectFailedStr            = @"设备断连";
static NSString * const DFUMessageTipsConnectSuccessStr           = @"连接升级设备成功";
static NSString * const DFUMessageTipsDontHaveFreescaleSuccessStr = @"升级成功";
static NSString * const DFUMessageTipsResponeErrorStr             = @"设备响应数据错误";
static NSString * const DFUMessageTipsHaveFreescaleSuccessStr     = @"需要验证Freescale";
static NSString * const DFUMessageTipsDontFoundUpgradeEquipmentStr     = @"没有发现升级设备";
