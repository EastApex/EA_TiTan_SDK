//
//  SCBluetoothCallback.h
//  SCBluetooth
//
//  Created by 李永彬 on 2020/12/8.

#import <UIKit/UIKit.h>

@class SCBluetoothData;
/**
 扫描设备，发现设备的回调，
 如果NSError不为空，说明扫描设备出现错误
 
 @param devices 设备列表
 @param error 错误信息
 */
typedef void (^SCBCSearchDevicesBlock)(NSArray *devices, NSError *error);
typedef void (^SCBCStopSearchingDevicesBlock)(void);

typedef void (^SCBCConnectDeviceBlock)(NSError *error);

typedef void (^SCBCRequestCallback)(SCBluetoothData *dataModel, NSError *error);

typedef void (^SCBCBoolCallback)(BOOL b, NSError *error);
typedef void (^SCBCAddressBookCallback)(BOOL b, NSError *error, NSInteger index);
typedef void (^SCBCIntegerCallback)(NSInteger n, NSError *error);
typedef void (^SCBCFloatCallback)(CGFloat f, NSError *error);
typedef void (^SCBCStringCallback)(NSString *str, NSError *error);
typedef void (^SCBCDictionaryCallback)(NSDictionary *dic, NSError *error);
typedef void (^SCBCArrayCallback)(NSArray *array, NSError *error);
typedef void (^SCBCStringArrayCallback)(NSArray<NSString *> *strArray, NSError *error);
typedef void (^SCBCDictionaryArrayCallback)(NSArray<NSDictionary *> *dicArray, NSError *error);
typedef void (^SCBCDateCallback)(NSDate *date, NSError *error);
typedef void (^SCBCDataCallback)(NSDate *data, NSError *error);
typedef void (^SCBCOtaStatusCallback)(NSUInteger allSize, NSData *crcData, NSUInteger recvSize, NSError *error);
typedef void (^SCBCCompressStatusCallback)(NSUInteger method, int param, NSError *error);

/**
 完成初始化
 扫描完成服务和特征之后
 可以发送数据了
 
 @param error 如果错误了，那就不行
 */
typedef void (^SCBDReadyBlock)(NSError *error);


@interface SCBluetoothCallback : NSObject

@property(nonatomic, copy) SCBCSearchDevicesBlock searchDevicesBlock;
@property(nonatomic, copy) SCBCStopSearchingDevicesBlock stopSearchingDevicesBlock;
@property(nonatomic, copy) SCBCConnectDeviceBlock connectDeviceBlock;
@property(nonatomic, strong) NSMutableArray *connectDeviceBlocks;
@property(nonatomic, copy) SCBCConnectDeviceBlock otaConnectDeviceBlock;
@property(nonatomic, copy) SCBCConnectDeviceBlock disconnectDeviceBlock;

@property(nonatomic, copy) SCBDReadyBlock bdReadyBlock;

- (void) clearAllCallbacks;

@end
