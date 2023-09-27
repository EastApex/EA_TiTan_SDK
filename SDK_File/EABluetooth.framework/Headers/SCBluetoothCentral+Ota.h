//
//  SCBluetoothCentral+OTA.h
//  SmartcommWatch
//
//  Created by 李永彬 on 2021/3/3.
//

#import "SCBluetoothCentral.h"
#import "Scpro.pbobjc.h"
#import "NSData+lz4.h"
NS_ASSUME_NONNULL_BEGIN
//typedef NS_ENUM(NSInteger, SCBluetoothOTAState)
//{
//    SCBluetoothOTAStatePlain,
//    SCBluetoothOTAStateSending,
//    SCBluetoothOTAStateSent,
//    SCBluetoothOTAStateSendFailed,
//    SCBluetoothOTAStateReciving,
//    SCBluetoothOTAStateRecived,
//    SCBluetoothOTAStateReciveFailed,
//    SCBluetoothOTAStateTimeout
//};

typedef NS_ENUM(NSInteger, SCOtaType) {
    SCOtaTypeApollo3P = 1,
    SCOtaTypeTP,
    SCOtaTypeHeart,
    SCOtaTypePicture,
    SCOtaTypeAgps,
    SCOtaTypeWatchface,
    SCOtaTypeFreeScale,
    SCOtaTypeGps,// SCOtaTypeGpsf1 SCOtaTypeGpsf2 SCOtaTypeGpsf3 SCOtaTypeGpsf4的zip包
    SCOtaTypeGpsf1,
    SCOtaTypeGpsf2,
    SCOtaTypeGpsf3,
    SCOtaTypeGpsf4
};

static const NSInteger kSizeOfPieceData = 2048;
// 设备端每2K数据做一个存储、这边必须等设备存储完成之后才能继续发送数据，所以做数据分区
// 而且每次发送，发送20个字节，分区内，还要分包
@interface SCOtaDataSection : NSObject

// 包大小
@property(nonatomic, assign) NSInteger packageSize;
@property(nonatomic, strong) NSMutableArray *packageList;
// 当前发送到的索引
@property(nonatomic, assign) NSInteger currentPackageIndex;
@property(nonatomic, assign) NSInteger totalPackageCount;

@property(nonatomic, assign) NSInteger sectionSize;
@property(nonatomic, copy) NSData *sectionData;

@property(nonatomic, strong) NSTimer *otaTimer;

+ (SCOtaDataSection *) sectionWithData:(NSData *)data;

@end

@interface SCOTADataModel : NSObject

@property(nonatomic, assign) SCPT_OtaInfo_Type otaType;
@property(nonatomic, copy) NSData *otaData;
//@property(nonatomic, copy) NSData *otaAddressData;
@property(nonatomic, assign) uint32_t otaAddressValue;
//@property(nonatomic, copy) NSData *otaCrcData;
@property(nonatomic, assign) uint32_t otaLength;
@property(nonatomic, assign) uint32_t rxSize;
@property(nonatomic, assign) uint32_t fileCrc;
/** 解压后的大小。0代表无需解压 */
@property(nonatomic, readwrite) uint32_t decmpSize;
@property(nonatomic, copy) NSString *version;
/** 固件id */
@property(nonatomic, readwrite) uint32_t id_p;

@property(nonatomic, assign) NSUInteger otaFailedCount;

// 分片区
@property(nonatomic, strong) NSMutableArray *sectionList;

/// OTA固件（带包头）
/// @param data <#data description#>
+ (SCOTADataModel *)dataModelWithFileData:(NSData *)data;

/// OTA agps文件
/// @param data 文件不带包头
+ (SCOTADataModel *)dataModelWithFileAgpsData:(NSData *)data;

/// ota 带包头的表盘文件(只把id替换掉)
/// @param data <#data description#>
/// @param watchfaceId <#watchfaceId description#>
+ (SCOTADataModel *)dataModelWithOnlineWatchfacesData:(NSData *)data setWatchfaceId:(uint32_t)watchfaceId;

+ (SCOTADataModel *)lz4DataModelWithOnlineWatchfacesData:(NSData *)originData setWatchfaceId:(uint32_t)watchfaceId;

/// ota 不带包头的表盘文件
/// @param data 不带包头的表盘bin文件数据
+ (SCOTADataModel *)dataModelWithCustomWatchfacesData:(NSData *)data;

/// Ota dial file with no packet header (recommended setWatchfaceId > 1000)
/// @param data 不带包头的表盘bin文件数据
/// @param watchfaceId 表盘的id，如果传0，默认表盘bin文件的crc值作为id (建议 watchfaceId > 1000)
+ (SCOTADataModel *)dataModelWithCustomWatchfacesData:(NSData *)data setWatchfaceId:(uint32_t)watchfaceId;

+ (SCOTADataModel *)lz4DataModelWithCustomWatchfacesData:(NSData *)originData;

+ (SCOTADataModel *)lz4DataModelWithCustomWatchfacesData:(NSData *)originData setWatchfaceId:(uint32_t)watchfaceId;

- (void) cutDataToSections;
//+ (NSData *)crcDataForData:(NSData *)sendData;

//获取crc值
+ (uint32_t)getFileCrcWithData:(NSData *)data;

@end

@interface SCBluetoothCentral (Ota)<SCBluetoothDeviceDelegate>

@property(nonatomic, copy) SCBCFloatCallback progressCallback;
@property(nonatomic, copy) SCBCBoolCallback finishCallback;
@property(nonatomic, copy) SCBCBoolCallback readyCallback;
// 总的数据长度
@property(nonatomic, strong) NSNumber *otaDataLength;
// 已发送的数据长度
@property(nonatomic, strong) NSNumber *otaSentLength;
// 当前packgeList分组已经发送数据长度
@property(nonatomic, strong) NSNumber *otaPackageListLength;

@property(nonatomic, copy) NSMutableArray *dataModels;
@property(nonatomic, copy) SCOTADataModel *sendingDataModel;
@property(nonatomic, copy) SCOTADataModel *resumeDataModel;

/*!
 普通外设名称，这个接口会发指令给设备，让设备进入OTA模式
 在进入OTA模式之间，会检查电量等条件
 ota interface
 
 @param dataModels ota数据  ota file models
 @param otaDeviceName ota设备名称 ota device's name
 @param needResumeOta 是否需要断点续传 needResumeOta
 @param readyCallback 准好之后的回调 ota get ready callback
 @param progressCallback 进度回调 ota is processing
 @param finishCallback 完成的回调 ota finish(may fail)
 */
- (void) otaWithDataModels:(NSArray<SCOTADataModel *> *)dataModels
             otaDeviceName:(NSString *)otaDeviceName
           otaDeviceMacMap:(NSString *)otaDeviceMacMap
             needResumeOta:(BOOL)needResumeOta
             readyCallback:(SCBCBoolCallback)readyCallback
          progressCallback:(SCBCFloatCallback)progressCallback
            finishCallback:(SCBCBoolCallback)finishCallback;

/*!
 普通外设名称，这个接口会发指令给设备，让设备进入OTA模式
 在进入OTA模式之间
 
 @param dataModels ota数据
 @param otaDeviceName ota设备名称
 @param needJudgeBattery 是否需要判断电量大于30%
 @param readyCallback 准好之后的回调
 @param progressCallback 进度回调
 @param finishCallback 完成的回调
 */
- (void) otaWithDataModels:(NSArray<SCOTADataModel *> *)dataModels
             otaDeviceName:(NSString *)otaDeviceName
           otaDeviceMacMap:(NSString *)otaDeviceMacMap
             needResumeOta:(BOOL)needResumeOta
          needJudgeBattery:(BOOL)needJudgeBattery
             readyCallback:(SCBCBoolCallback)readyCallback
          progressCallback:(SCBCFloatCallback)progressCallback
            finishCallback:(SCBCBoolCallback)finishCallback;

/*!
 普通外设名称，这个接口会发指令给设备，让设备进入OTA模式
 在进入OTA模式之间，会检查电量等条件
 
 @param dataModels ota数据
 @param otaDeviceName ota设备名称
 @param needJudgeBattery 是否需要判断电量大于30%
 @param connectTimeout 是否需要判断电量大于30%
 @param readyCallback 准好之后的回调
 @param progressCallback 进度回调
 @param finishCallback 完成的回调
 */
- (void) otaWithDataModels:(NSArray<SCOTADataModel *> *)dataModels
             otaDeviceName:(NSString *)otaDeviceName
           otaDeviceMacMap:(NSString *)otaDeviceMacMap
             needResumeOta:(BOOL)needResumeOta
          needJudgeBattery:(BOOL)needJudgeBattery
            connectTimeout:(NSTimeInterval)connectTimeout
             readyCallback:(SCBCBoolCallback)readyCallback
          progressCallback:(SCBCFloatCallback)progressCallback
            finishCallback:(SCBCBoolCallback)finishCallback;

/*!
 不检查任何条件，直接发指令进入ota模式
 
 @param dataModels ota数据
 @param otaDeviceName ota设备名称
 @param readyCallback 准好之后的回调
 @param progressCallback 进度回调
 @param finishCallback 完成的回调
 */
- (void) startOtaWithOtaDeviceName:(NSString *)otaDeviceName
                   otaDeviceMacMap:(NSString *)otaDeviceMacMap
                     needResumeOta:(BOOL)needResumeOta
                         otaModels:(NSArray<SCOTADataModel *> *)dataModels
                     readyCallback:(SCBCBoolCallback)readyCallback
                  progressCallback:(SCBCFloatCallback)progressCallback
                    finishCallback:(SCBCBoolCallback)finishCallback;


/*!
 不检查任何条件，直接发指令进入ota模式
 
 @param dataModels ota数据
 @param otaDeviceName ota设备名称
 @param readyCallback 准好之后的回调
 @param progressCallback 进度回调
 @param finishCallback 完成的回调
 */
- (void) startOtaWithOtaDeviceName:(NSString *)otaDeviceName
                   otaDeviceMacMap:(NSString *)otaDeviceMacMap
                     needResumeOta:(BOOL)needResumeOta
                         otaModels:(NSArray<SCOTADataModel *> *)dataModels
                    connectTimeout:(NSTimeInterval)connectTimeout
                     readyCallback:(SCBCBoolCallback)readyCallback
                  progressCallback:(SCBCFloatCallback)progressCallback
                    finishCallback:(SCBCBoolCallback)finishCallback;



/*!
 连接OTA外设名称直接OTA
 
 @param peripheralName OTA名称
 @param dataModels ota数据
 @param readyCallback 准备好之后回调
 @param progressCallback ota进度回调
 @param finishCallback 完成之后回调
 */
- (void) startOtaWithPeripheralName:(NSString *)peripheralName
                    otaDeviceMacMap:(NSString *)otaDeviceMacMap
                      needResumeOta:(BOOL)needResumeOta
                          otaModels:(NSArray<SCOTADataModel *> *)dataModels
                      readyCallback:(SCBCBoolCallback)readyCallback
                   progressCallback:(SCBCFloatCallback)progressCallback
                     finishCallback:(SCBCBoolCallback)finishCallback;

/*!
 连接OTA外设名称直接OTA
 
 @param peripheralName OTA名称
 @param dataModels ota数据
 @param readyCallback 准备好之后回调
 @param progressCallback ota进度回调
 @param finishCallback 完成之后回调
 */
- (void) startOtaWithPeripheralName:(NSString *)peripheralName
                    otaDeviceMacMap:(NSString *)otaDeviceMacMap
                      needResumeOta:(BOOL)needResumeOta
                          otaModels:(NSArray<SCOTADataModel *> *)dataModels
                     connectTimeout:(NSTimeInterval)connectTimeout
                      readyCallback:(SCBCBoolCallback)readyCallback
                   progressCallback:(SCBCFloatCallback)progressCallback
                     finishCallback:(SCBCBoolCallback)finishCallback;


/*!
 停止当前OTA
 
 @param callback 停止当前OTA操作
 */
- (void) stopOtaWithCallback:(SCBCBoolCallback)callback;

+ (NSData *)crcDataFromData:(NSData *)sendData total:(NSInteger)total;

@end

NS_ASSUME_NONNULL_END
