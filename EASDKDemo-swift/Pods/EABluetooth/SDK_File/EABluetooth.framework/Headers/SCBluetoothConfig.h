//
//  SCBluetoothConfig.h
//  SCBluetooth
//
//  Created by 李永彬 on 2020/12/8.

#import <Foundation/Foundation.h>

@interface SCBluetoothConfig : NSObject

#pragma mark - 属性
/**
 * 扫描参数,centralManager:scanForPeripheralsWithServices:self.scanForPeripheralsWithServices options:self.scanForPeripheralsWithOptions
 * param An optional dictionary specifying options for the scan.
 *  @see                centralManager:scanForPeripheralsWithServices
 *  @seealso            CBCentralManagerScanOptionAllowDuplicatesKey :忽略同一个Peripheral端的多个发现事件被聚合成一个发现事件
 *    @seealso            CBCentralManagerScanOptionSolicitedServiceUUIDsKey
 */
@property (nonatomic, copy) NSDictionary *scanForPeripheralsWithOptions;

/**
 *  连接设备的参数
 *  method connectPeripheral:options:
 *  param              An optional dictionary specifying connection behavior options.
 *  @see                centralManager:didConnectPeripheral:
 *  @see                centralManager:didFailToConnectPeripheral:error:
 *  @seealso            CBConnectPeripheralOptionNotifyOnConnectionKey
 *  @seealso            CBConnectPeripheralOptionNotifyOnDisconnectionKey
 *  @seealso            CBConnectPeripheralOptionNotifyOnNotificationKey
 */
@property (nonatomic, copy) NSDictionary *connectPeripheralWithOptions;

/**
 * 扫描参数,centralManager:scanForPeripheralsWithServices:self.scanForPeripheralsWithServices options:self.scanForPeripheralsWithOptions
 * param serviceUUIDs A list of <code>CBUUID</code> objects representing the service(s) to scan for.
 *@see                centralManager:scanForPeripheralsWithServices
 */
@property (nonatomic, copy) NSArray *scanForPeripheralsWithServices;

// [peripheral discoverServices:self.discoverWithServices];
@property (nonatomic, copy) NSArray *discoverWithServices;

// [peripheral discoverCharacteristics:self.discoverWithCharacteristics forService:service];
@property (nonatomic, copy) NSArray *discoverWithCharacteristics;

@property(nonatomic, assign) BOOL autoConnect;

// 是否需要发送03结束命令（新的APP，可能不需要）
@property(nonatomic, assign) BOOL needToSend03EndCMD;

// 手动指定MTU
@property(nonatomic, assign) NSUInteger MTU;

+ (SCBluetoothConfig *) defaultConfig;

@end
