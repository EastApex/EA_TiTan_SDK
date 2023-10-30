//
//  ListViewController.swift
//  EASDKDemo
//
//  Created by Aye on 2023/2/14.
//

import UIKit
import SnapKit
import EABluetooth
class ListViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    public var type:NSInteger! = 0
    var tableView : UITableView!
    static let cellId = "cellIdl"
    var dataSource : NSMutableArray!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        view.backgroundColor = UIColor.white
        
        tableView = UITableView.init(frame: view.bounds, style: .grouped)
        tableView.contentInsetAdjustmentBehavior = .never
        tableView.delegate = self
        tableView.dataSource = self
        view.addSubview(tableView)
        
        tableView.snp.makeConstraints { make in
            
            make.top.equalTo(view.safeAreaLayoutGuide.snp.top)
            make.left.equalTo(view)
            make.right.equalTo(view)
            make.bottom.equalTo(view.safeAreaLayoutGuide.snp.bottom)
        }
        
        dataSource = NSMutableArray.init();
        
        if (type == 0) {
            let setList:NSArray = [
                "id: 3 \n【EA】Watch information【手表信息】",
                "id: 4 \n【EA】User information【用户信息】",
                "id: 5 \n【EA】Sync watch time【同步时间】",
                "id: 7 \n【EA】Screen brightness【屏幕亮度】",
                "id: 8 \n【EA & SC】Screen rest time【息屏时间】",
                "id: 9 \n【EA & SC】Watch power information【手表电量】",
                "id:10 \n【EA & SC】Language【语言】",
                "id:11 \n【EA】Unit【单位】",
                "id:12 \n【EA】Operating watch【操作手表】",
                "id:13 \n【EA】DND【免打扰】",
                "id:15 \n【EA & SC】Daily target【日常目标】",
                "id:16 \n【EA】Sleep monitoring on-off【睡眠监测开关】",
                "id:17 \n【EA】Heart rate monitoring on-off【心率监测开关】",
                "id:18 \n【EA】Sedentary monitoring【久坐监测】",
                "id:20 \n【EA】Weather【天气】",
                "id:21 \n【EA】Social alert on-off(SMS、PhoneCall、Email Etc.)【社交提醒开关】",
                "id:22 \n【EA & SC】Alerts【提醒】",
                "id:26 \n【EA】Heart rate alarm threshold【手表心率报警门限】",
                "id:27 \n【EA】Calorie on-off【卡路里开关】",
                "id:28 \n【EA】Raise the screen switch【抬手亮屏开关】",
                "id:30 \n【EA】Basic Device Information【设备基本信息】",
                "id:31 \n【EA】Level 1 menu setting【一级菜单设置】",
                "id:32 \n【EA】Menstrual【经期】",
                "id:33 \n【EA】watch face 【表盘】",
                "id:34 \n【EA】Message push switch【消息推送开关】",
                "id:38 \n【EA】Habit tracker【习惯追踪】",
                "id:40 \n【EA】Motion value displayed【当前手表运动界面显示值】",
                "id:41 \n【EA】Bluetooth pairing status【蓝牙配对状态】",
                "id:42 \n【EA】Telephone book【通讯录】",
                "id:43 \n【EA】Read telephone book【读取通讯录】",
                "id:44 \n【EA】Functions supported【支持的功能】",
                "id:45 \n【EA】Monitor reminder event【提醒事件监测】",
                "id:46 \n【EA】App map motion【App地图运动】",
                "id:47 \n【EA】App sends map motion data【App发送地图运动数据】",
                "id:48 \n【EA】App operation watch measurement【App操作手表测量】",
                "id:50 \n【EA】Sleep oxygen monitoring【睡眠血氧监测（夜间血氧监测）】",
                "id:51 \n【EA】Pressure monitoring【压力监测】",
                "id:52 \n【EA】Real-time data switch【实时数据开关】",
                "id:53 \n【EA】Vibrate mode【震动模式】",
                
                
                
                "id:10000 \n 【SC】Mac Address",
                "id:10001 \n 【SC】Serial Number",
                "id:10002 \n 【SC】FW Version",
                "id:10003 \n 【SC】UnitFormat",
                "id:10005 \n 【SC】Temperature Monitor",
                "id:10006 \n 【SC】Agps Info",
                "id:10007 \n 【SC】UserId",
                "id:10008 \n 【SC】Switches",
                "id:10009 \n 【SC】HeartRate Monitor",
                "id:10010 \n 【SC】Sedentary Monitor",
                "id:10012 \n 【SC】Notification Switch",
                "id:10013 \n 【SC】Face List",
                "id:10014 \n 【SC】Watch Face",
                
                
            ]
            let setInfo = NSMutableDictionary.init()
            setInfo.setValue("Command【指令】", forKey: "title")
            setInfo.setObject(setList, forKey: "list" as NSCopying)
            dataSource.add(setInfo)
        }
        else
        {
            let setList:NSArray = [
                "id: 3 \n【EA】Watch information【手表信息】",
                "id: 4 \n【EA & SC】User information【用户信息】",
                "id: 5 \n【EA & SC】Sync watch time【同步时间】",
                "id: 7 \n【EA】Screen brightness【屏幕亮度】",
                "id: 8 \n【EA & SC】Screen rest time【息屏时间】",
                "id: 9 \n【EA & SC】Watch power information【手表电量】",
                "id:10 \n【EA & SC】Language【语言】",
                "id:11 \n【EA & SC】Unit【单位】",
                "id:12 \n【EA & SC】Operating watch【操作手表】",
                "id:13 \n【EA】DND【免打扰】",
                "id:15 \n【EA & SC】Daily target【日常目标】",
                "id:16 \n【EA】Sleep monitoring on-off【睡眠监测开关】",
                "id:17 \n【EA】Heart rate monitoring on-off【心率监测开关】",
                "id:18 \n【EA】Sedentary monitoring【久坐监测】",
                "id:20 \n【EA & SC】Weather【天气】",
                "id:21 \n【EA】Social alert on-off(SMS、PhoneCall、Email Etc.)【社交提醒开关】",
                "id:22 \n【EA & SC】Alerts【提醒】",
                "id:26 \n【EA】Heart rate alarm threshold【手表心率报警门限】",
                "id:27 \n【EA】Calorie on-off【卡路里开关】",
                "id:28 \n【EA】Raise the screen switch【抬手亮屏开关】",
                "id:30 \n【EA】Basic Device Information【设备基本信息】",
                "id:31 \n【EA】Level 1 menu setting【一级菜单设置】",
                "id:32 \n【EA & SC】Menstrual【经期】",
                "id:33 \n【EA】watch face 【表盘】",
                "id:34 \n【EA】Message push switch【消息推送开关】",
                "id:38 \n【EA】Habit tracker【习惯追踪】",
                "id:40 \n【EA】Motion value displayed【当前手表运动界面显示值】",
                "id:41 \n【EA】Bluetooth pairing status【蓝牙配对状态】",
                "id:42 \n【EA】Telephone book【通讯录】",
                "id:43 \n【EA】Read telephone book【读取通讯录】",
                "id:44 \n【EA】Functions supported【支持的功能】",
                "id:45 \n【EA & SC】Monitor reminder event【提醒事件监测】",
                "id:46 \n【EA】App map motion【App地图运动】",
                "id:47 \n【EA】App sends map motion data【App发送地图运动数据】",
                "id:48 \n【EA】App operation watch measurement【App操作手表测量】",
                "id:50 \n【EA】Sleep oxygen monitoring【睡眠血氧监测（夜间血氧监测）】",
                "id:51 \n【EA】Pressure monitoring【压力监测】",
                "id:52 \n【EA】Real-time data switch【实时数据开关】",
                "id:53 \n【EA】Vibrate mode【震动模式】",
                
                
                
                "id:10000 \n【SC】Mac Address",
                "id:10001 \n【SC】Serial Number",
                "id:10002 \n【SC】FW Version",
                "id:10003 \n【SC】UnitFormat",
                "id:10005 \n【SC】Temperature Monitor",
                "id:10006 \n【SC】Agps Info",
                "id:10007 \n【SC】UserId",
                "id:10008 \n【SC】Switches",
                "id:10009 \n【SC】HeartRate Monitor",
                "id:10010 \n【SC】Sedentary Monitor",
                "id:10012 \n【SC】Notification Switch",
                "id:10013 \n【SC】Face List",
                "id:10014 \n【SC】Watch Face",
            ]
            
            let setInfo = NSMutableDictionary.init()
            setInfo.setValue("Command【指令】", forKey: "title")
            setInfo.setObject(setList, forKey: "list" as NSCopying)
            dataSource.add(setInfo)
        }
        
        
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        var cell = tableView.dequeueReusableCell(withIdentifier: ListViewController.cellId)
        if cell == nil {
            cell = UITableViewCell.init(style: .default, reuseIdentifier: ListViewController.cellId)
        }
        let info = dataSource.object(at: indexPath.section) as! NSMutableDictionary
        let list = info.object(forKey: "list") as! NSArray
        cell?.textLabel?.text = list.object(at: indexPath.row) as? String
        cell?.textLabel?.numberOfLines = 0
        return cell!
    }
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        let info = dataSource.object(at: section) as! NSMutableDictionary
        let list = info.object(forKey: "list") as! NSArray
        return list.count
    }
    func numberOfSections(in tableView: UITableView) -> Int {
        return dataSource.count
    }
    func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
        
        let info = dataSource.object(at: section) as! NSMutableDictionary
        
        let headerView = UIView.init(frame: CGRect.init(x: 0, y: 0, width: UIScreen.main.bounds.size.width, height: 40))
        let lable = UILabel.init()
        lable.text = info.object(forKey: "title") as? String
        lable.font = UIFont.boldSystemFont(ofSize: 16)
        headerView.addSubview(lable)
        lable.snp.makeConstraints { make in
            make.left.equalTo(headerView).offset(15)
            make.top.equalTo(headerView)
        }
        return headerView
    }
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        let info = dataSource.object(at: indexPath.section) as! NSMutableDictionary
        let list = info.object(forKey: "list") as! NSArray
        
        if indexPath.section == 0 {
            
            let text = list.object(at: indexPath.row) as? String
            
            let dataInfoTypeString = String((text?.dropFirst(3).prefix(2) ?? "3")) as String
            let dateType = NSNumber.init(string: dataInfoTypeString)
            let dataInfoType = (dateType?.uintValue)!
            
            if type==0 {
                
                getCommand(dataInfoType: EADataInfoType(rawValue: dataInfoType) ?? .watch)
                
            }else {
                
                setCommand(dataInfoType: EADataInfoType(rawValue: dataInfoType) ?? .watch)
            }
        }
    }
    
    func getCommand(dataInfoType:EADataInfoType) {
        
        //        Command.getData(dataInfoType: dataInfoType);
        
        switch dataInfoType {
        case .watch: // id: 3
            Cmd_WatchInfo.getData();break
        case .user: // id: 4
            Cmd_UserInfo.getData();break
        case .syncTime:// id: 5
            Cmd_SyncTime.getData();break
        case .blacklight:// id: 7
            Cmd_Blacklight.getData();break
        case .blacklightTimeout:// id: 8
            Cmd_BlacklightTimeout.getData();break
        case .battery:// id: 9
            Cmd_Battery.getData();break
        case .language:// id: 10
            Cmd_Language.getData();break
        case .unifiedUnit:// id: 11
            Cmd_Unit.getData();break
        case .deviceOps:// id: 12
            Cmd_DeviceOps.getData();break
        case .notDisturb:// id: 13
            Cmd_DND.getData();break
        case .dailyGoal:// id: 15
            Cmd_DailyGoal.getData();break
        case .autoCheckSleep:// id: 16
            Cmd_CheckSleep.getData();break
        case .autoCheckHeartRate:// id: 17
            Cmd_CheckHeartRate.getData();break
        case .autoCheckSedentariness:// id: 19
            Cmd_CheckSedentariness.getData();break
        case .weather:// id: 20
            Cmd_Weather.getData();break
        case .socialSwitch:// id: 21
            Cmd_SocialSwitch.getData();break
        case .reminder:// id: 22
            do {
                let rCtl = RemiderViewController()
                self.navigationController?.pushViewController(rCtl, animated: true)
            };break
        case .heartRateWaringSetting:// id: 26
            Cmd_HeartRateWaringSetting.getData();break
        case .caloriesSetting:// id: 27
            Cmd_CaloriesSetting.getData();break
        case .gesturesSetting:// id: 28
            Cmd_GesturesSetting.getData();break
        case .combination:// id: 30
            Cmd_Combination.getData();break
        case .homePage:// id: 31
            Cmd_HomePage.getData();break
        case .menstrual:// id: 32
            Cmd_Menstrual.getData();break
        case .dialPlate:// id: 33
            Cmd_WatchFace.getData();break
        case .appMessage:// id: 34
            Cmd_AppMessage.getData();break
        case .habitTracker:// id: 38
            Cmd_HabitTracker.getData();break
        case .sportShowData:// id: 40
            Cmd_SportShowData.getData();break
        case .blePairState:// id: 41
            Cmd_BlePairState.getData();break
        case .telephoneBook:// id: 42
            Command.notSupportGetData();break
        case .readTelephoneBook:// id: 43
            Cmd_TelephoneBook.getData();break
        case .watchSupport:// id: 44
            Cmd_WatchSupport.getData();break
        case .monitorReminder:// id: 45
            do{
                let rCtl = MonitorReminderViewController()
                self.navigationController?.pushViewController(rCtl, animated: true)
            };break
            //        case .appLaunchMapSport:// id: 46
            //            Command.notSupportSetData();break
        case .stressMonitor:// id: 51
            Cmd_StressMonitor.getData();break
        case .sendRealTimeDataOnOff:// id: 52
            Cmd_SendRealTimeDataOnOff.getData();break
        case .vibrateIntensity:// id: 53
            Cmd_VibrateIntensity.getData();break
            
            /**
             "id:10000 \n Mac Address",
             "id:10001 \n SerialNumber",
             "id:10002 \n FW Version",
             "id:10003 \n UnitFormat",
             "id:10005 \n Temperature Monitor",
             "id:10006 \n Agps Info",
             "id:10007 \n UserId",
             "id:10008 \n Switches",
             "id:10009 \n HeartRate Monitor",
             "id:10010 \n Sedentary Monitor",
             "id:10012 \n Notification Switch",
             "id:10013 \n Face List",
             "id:10014 \n Watch Face",
             */
        case .scMacAddress:
            Cmd_MacAddress.getData();break
        case .scSerialNumber:
            Cmd_SerialNumber.getData();break
        case .scfwVersion:
            Cmd_FWVersion.getData();break
        case .scUnitFormat:
            Cmd_UnitFormat.getData();break
        case .scTemperatureMonitor:
            Cmd_TemperatureMonitor.getData();break
        case .scAgpsInfo:
            Cmd_AgpsInfo.getData();break
        case .scUserId:
            Cmd_UserId.getData();break
        case .scSwitches:
            Cmd_Switches.getData();break
        case .scHeartRateMonitor:
            Cmd_HeartRateMonitor.getData();break
        case .scSedentaryMonitor:
            Cmd_SedentaryMonitor.getData();break
        case .scNotificationSwitch:
            Cmd_NotificationSwitch.getData();break
        case .scWatchFaceList:
            Cmd_WatchFaceList.getData();break
        case .scWatchFace:
            Cmd_WatchFace.getData();break
        default:break
            
        }
    }
    
    
    
    func setCommand(dataInfoType:EADataInfoType) {
        
        switch dataInfoType {
        case .watch: // id: 3
            Command.notSupportSetData();break
        case .user: // id: 4
            Cmd_UserInfo.setData();break
        case .syncTime:// id: 5
            Cmd_SyncTime.setData();break
        case .blacklight:// id: 7
            Cmd_Blacklight.setData();break
        case .blacklightTimeout:// id: 8
            Cmd_BlacklightTimeout.setData();break
        case .battery:// id: 9
            Command.notSupportSetData();break
        case .language:// id: 10
            Cmd_Language.setData();break
        case .unifiedUnit:// id: 11
            Cmd_Unit.setData();break
        case .deviceOps:// id: 12
            Cmd_DeviceOps.setData();break
        case .notDisturb:// id: 13
            Cmd_DND.setData();break
        case .dailyGoal:// id: 15
            Cmd_DailyGoal.setData();break
        case .autoCheckSleep:// id: 16
            Cmd_CheckSleep.setData();break
        case .autoCheckHeartRate:// id: 17
            Cmd_CheckHeartRate.setData();break
        case .autoCheckSedentariness:// id: 19
            Cmd_CheckSedentariness.setData();break
        case .weather:// id: 20
            Cmd_Weather.setData();break
        case .socialSwitch:// id: 21
            Cmd_SocialSwitch.setData();break
        case .reminder:// id: 22
            do {
                let rCtl = RemiderViewController()
                self.navigationController?.pushViewController(rCtl, animated: true)
            };break
        case .heartRateWaringSetting:// id: 26
            Cmd_HeartRateWaringSetting.setData();break
        case .caloriesSetting:// id: 27
            Cmd_CaloriesSetting.setData();break
        case .gesturesSetting:// id: 28
            Cmd_GesturesSetting.setData();break
        case .combination:// id: 30
            Command.notSupportSetData();break
        case .homePage:// id: 31
            Cmd_HomePage.setData();break
        case .menstrual:// id: 32
            Cmd_Menstrual.setData();break
        case .dialPlate:// id: 33
            Cmd_WatchFace.setData();break
        case .appMessage:// id: 34
            Cmd_AppMessage.setData();break
        case .habitTracker:// id: 38
            Cmd_HabitTracker.setData();break
        case .sportShowData:// id: 40
            Command.notSupportSetData();break
        case .blePairState:// id: 41
            Command.notSupportSetData();break
        case .telephoneBook:// id: 42
            Cmd_TelephoneBook.setData();break
        case .readTelephoneBook:// id: 43
            Command.notSupportSetData();break
        case .watchSupport:// id: 44
            Command.notSupportSetData();break
        case .monitorReminder:// id: 45
            do{
                let rCtl = MonitorReminderViewController()
                self.navigationController?.pushViewController(rCtl, animated: true)
            };break
            //        case .appLaunchMapSport:// id: 46
            //            Command.notSupportSetData();break
        case .stressMonitor:// id: 51
            Cmd_StressMonitor.setData();break
        case .sendRealTimeDataOnOff:// id: 52
            Cmd_SendRealTimeDataOnOff.setData();break
        case .vibrateIntensity:// id: 53
            Cmd_VibrateIntensity.setData();break
            
        case .scMacAddress:
            Command.notSupportSetData();break
        case .scSerialNumber:
            Command.notSupportSetData();break
        case .scfwVersion:
            Command.notSupportSetData();break
        case .scUnitFormat:
            Cmd_UnitFormat.setData();break
        case .scTemperatureMonitor:
            Cmd_TemperatureMonitor.setData();break
        case .scAgpsInfo:
            Command.notSupportSetData();break
        case .scUserId:
            Command.notSupportSetData();break
        case .scSwitches:
            Cmd_Switches.setData();break
        case .scHeartRateMonitor:
            Cmd_HeartRateMonitor.setData();break
        case .scSedentaryMonitor:
            Cmd_SedentaryMonitor.setData();break
        case .scNotificationSwitch:
            Cmd_NotificationSwitch.setData();break
        case .scWatchFaceList:
            Command.notSupportSetData();break
        case .scWatchFace:
            Cmd_WatchFace.getData();break
        default:break
            
        }
        
    }
    
    
}
