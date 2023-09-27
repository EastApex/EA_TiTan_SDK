//
//  SCBluetoothDevice.h
//  SCBluetooth
//
//  Created by 李永彬 on 2020/12/8.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "SCBluetoothCallback.h"
#import "Scpro.pbobjc.h"

// ================== main ======================
extern NSString *SCBDMainServiceUUID;
extern NSString *SCBD1001CharacteristicMainWriteUUID;
extern NSString *SCBD1002CharacteristicNotificationUUID;

// ================== NFC =====================
extern NSString *SCBDNFCServiceUUID;
extern NSString *SCBDNFCCharacteristicWriteUUID;
extern NSString *SCBDNFCCharacteristicNotifyUUID;

// ================== meida ====================
extern NSString *SCBDMediaServiceUUID;
extern NSString *SCBD1003CharacteristicMainWriteUUID;
extern NSString *SCBD1004CharacteristicNotificationUUID;
extern NSString *SCBDVoiceCharacteristicUUID;

// ================== heart ====================
//extern NSString *SCBD_StandardHeartRateServiceUUID;
//extern NSString *SCBD_StandardHeartRateCharacteristicUUID;

// ================== pay ====================
extern NSString *SCBD_PayServiceUUID;
extern NSString *SCBD_PayCharacteristicWriteUUID;
extern NSString *SCBD_PayCharacteristicNotificationUUID;

// ================== OTA ====================
extern NSString *SCBD_OTAServiceUUID;
extern NSString *SCBD_CharacteristicNotificationUUID;
extern NSString *SCBD_OTACharacteristicWriteUUID;
extern NSString *SCBD_OTADUFVersion;

extern NSString *SCBD_L42_OTAServiceUUID;
extern NSString *SCBD_L42_OTACharacteristicNotificationUUID;
extern NSString *SCBD_L42_OTACharacteristicWriteUUID;

extern NSString *SCBD_FindPhoneNotification;
extern NSString *SCBD_CheckWeatherNotification;
extern NSString *SCBD_CheckAgpsNotification;
extern NSString *SCBD_QueryAdcNotification;
extern NSString *SCBD_CameraNotification;
extern NSString *SCBD_CameraControlNotification;

// userInfo : {data:NSData}
extern NSString *SCBD_1001DidUpdateValueNotification;
extern NSString *SCBD_1002DidUpdateValueNotification;
extern NSString *SCBD_1003DidUpdateValueNotification;
extern NSString *SCBD_1004DidUpdateValueNotification;
extern NSString *SCBD_1531DidUpdateValueNotification;
extern NSString *SCBD_8006DidUpdateValueNotification;
extern NSString *SCBD_DidUpdateValueNotification;
extern NSString *SCBD_ReadFlashAddressNotification;

// 心率值来的通知
// userInfo : bpm:NSNumber
extern NSString *SCBD_HeartRateDidUpdateValueNotification;
extern NSString *SCBD_NstUpdateValueNotification;

typedef NS_ENUM(NSInteger, SCBDChannel)
{
    SCBDChannel1001,
    SCBDChannel1002,
    SCBDChannel1003,
    SCBDChannel1004
};


extern const NSString *SCBluetoothDeviceRSSIUpdateNotification;
//extern NSString *SCBluetoothDevice


@class SCBluetoothConfig;
@class SCBluetoothData;
@class SCBluetoothDevice;

@protocol SCBluetoothDeviceDelegate<NSObject>
@optional
- (void) bluetoothDeviceWriteBackData:(NSData *)data fromCharacteristicUUID:(NSString *)uuid;
- (void) bluetoothDevice:(SCBluetoothDevice *)bluetoothDevice didUpdateValueForCharacteristic:(CBCharacteristic *)characteristic;
- (void) bluetoothDeviceBackOTADataResultType:(SCPT_Response_Result)resultType;

@end

@interface SCBluetoothDevice : NSObject

@property(nonatomic, weak) id<SCBluetoothDeviceDelegate> delegate;
@property(nonatomic, assign, readonly) BOOL connected;

@property(nonatomic, strong, readonly) NSNumber *rssi;
@property(nonatomic, strong, readonly) CBPeripheral *peripheral;
@property(nonatomic, copy, readonly) NSString *name;
@property(nonatomic, copy) NSString *macMap;
@property(nonatomic, strong) SCBluetoothConfig *config;

// 如果peripheral的名字为null。返回也为nil
+ (SCBluetoothDevice *) deviceWithPeripheral:(CBPeripheral *)peripheral
                                        rssi:(NSNumber *)rssi
                           advertisementData:(NSDictionary<NSString *, id> *)advertisementData;


/**
 如果peripheral的名字为null。返回也为nil
 
 @param peripheral p
 @param rssi r
 @return device
 */
- (SCBluetoothDevice *) initWithPeripheral:(CBPeripheral *)peripheral
                                      rssi:(NSNumber *)rssi
                         advertisementData:(NSDictionary<NSString *, id> *)advertisementData;


#pragma mark - public methods
- (void) getReadyWithCallback:(SCBDReadyBlock)callback;

- (void) writeDataModel:(SCBluetoothData *)data toChannel:(SCBDChannel)channel;

- (void) writeData:(NSData *)data toChannel:(SCBDChannel)channel;

- (void) dataModel:(SCBluetoothData *)data failedWithError:(NSError *)error;

- (BOOL) hasService:(NSString *)serviceUUID;
- (BOOL) hasCharacteristic:(NSString *)characteristicUUID;
- (BOOL) writeData:(NSData *)data toCharacteristic:(NSString *)characteristicUUID;
- (BOOL) readDataForCharacteristic:(NSString *)characteristicUUID;

#pragma mark - ota
- (void) getOTAReadyWithCallback:(SCBDReadyBlock)callback;
- (void) writeDataToOTANotificationCharacteristic:(NSData *)data;
- (void) writeDataToOTAWriteCharacteristic:(NSData *)data;

#pragma mark - nfc
@property(nonatomic, assign, readonly, getter=isNfcReady) BOOL nfcReady;
- (void) getNFCReadyWithCallback:(SCBDReadyBlock)callback;
- (void) writeDataToNFCNotifyCharacteristic:(NSData *)data;
- (void) writeDataToNFCWriteCharacteristic:(NSData *)data;

#pragma mark - utils
- (NSUInteger) MTU;

@end
