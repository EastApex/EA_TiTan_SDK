### Native iOS SDK access document 【原生 iOS SDK 接入文档】
<p>https://www.showdoc.com.cn/2042713679210858/0
<p>Password:123456

### github:
https://github.com/EastApex/EASDKTool_iOS.git
### pod： 
in your Podfile 
add this 

pod 'EABluetooth', :git =>  'https://github.com/EastApex/EASDKTool_iOS.git'
or  use tag specified version
pod 'EABluetooth', :git =>  'https://github.com/EastApex/EASDKTool_iOS.git',:tag => '1.0.68.3'



### Release Notes:

    <p>Date：2023-04-15
    
        SDK
        Version：1.0.71.1
        1. Modify the SDK log style
        2. Rectify the fault that commands cannot be sent because the 5526 service is changed.
        3. Fixed an issue where paired watches could not be found.
        4. Fix the 5526 watch face
 

   <p>Date：2023-04-18
 
        Demo
        1.Add the pairing sample code. [ After paired，can use the ANCS service、App push 、Muisc control].When the watch is successfully connected, a pairing request can be initiated.
        
   <p> Date：2023-04-15
   
        SDK
        Version：1.0.68.4
        1. Modify the SDK log style
        2. Rectify the fault that commands cannot be sent because the 5526 service is changed.
        3. Fixed an issue where paired watches could not be found.
        4. Fix the 5526 watch face
        
   <p>Date：2023-04-04
 
        SDK
        Version：1.0.68.3
        1. Modify the 5526 custom watch face
        2. Add a description. The Class EAReminderModel weekCycleBit
        
        Demo
        1. Add sample code。Class EAReminderModel；

  <p> Date：2023-03-29
  
        SDK
        Version：1.0.68.2
        1.Class EAFileModel add binData function.
        
  <p> Date：2023-03-28
  
        SDK
        Version：1.0.68.1
        1.class EARespondModel: New App launch motion response status (id=47) :APP motion has ended.
        2.class EAWatchModel: New type: LCD Pixel type: 0: RGB565 1: GXGPU_RGB888
        3.ADAPTS 5526 chip watch face
        
 <p> Date：2023-03-17
 
         SDK
         Version：1.0.66.1
          1. Add command timeout response.
          2. Modify mtu greater than 509 communication problem.
          3. When modifying the search device, disconnect the connected device.
          4. Modify the universal style custom dial
          5. ENUM EALanguageType new language enumeration type (Vietnamese, Belarusian, Hungarian)
        
         Swift Demo
         1.Change OTA Custom Watch Face
         
 <p> Date：2023-03-08
 
         SDK
         Version：1.0.65.6
         1.Fixed EASyncTime.getCurrent()==>timeZoneMinute error.
         2.Add default custom digital watch face method. See class EAMakeWatchFaceManager.
         3.Added custom pointer watch face method. See class EAMakeWatchFaceManager.
         4.Fix missing motion data.
         5.When OTA, the lower version of bin is ignored.
         6.Add comments to motion type enumeration values. See EAEnum.h ==> EASportType
         
         Swift Demo
         1.Add watch operation mobile phone example.
         2.Fixed incorrect lifting screen example.
        
<p> Date：2023-02-28

        Version：1.0.65.5
        1.Fix the problem that the thumbnail of the custom watch face is blurred.
        2.Modify the dependent library without specifying the version.

<p>Date：2023-02-27

        Version：1.0.65.4
        1.Fixed sleep data without sleep status issues.
        2.Fixed daily data missing some calories.
        3.Added ‘Class EAMakeWatchFaceManager’, a unified management class for custom watch faces. ‘Class EACreatThumbnail’ and ‘Function EABleManager.default().customWatchFaceBackgroundImage:’、‘Function EABleManager.default().customNumberWatchFaceBackgroundImage:’will not be maintained later.
        4.Added custom pointer dial and scale selection.For details, see Class EAMakeWatchFaceManager
 
<p>2023-02-24

       Version：1.0.65.3
       1.Fixed the watch is disconnected from the outside and cannot communicate with each other after reconnecting.【修复手表以外断连，重新连接后不能相互通讯问题。】
       
<p>2023-02-22

      Version：1.0.65.1
      1.Add a pointer dial.
      2.Fixed some bug.
      
<p>2023.02.14

     1.Add part of the sample
     
<p>2023.02.08

     1.Fixed the watch face bule bug;
     2.Class EAMenstruals add new method and abandon method; Detail to see class 'EAMenstruals';
     3.Modify setting the callback of EAReminderModel and EAHabitTrackerModel to EARespondModel. Deprecated EAReminderRespondModel and EAHabitTrackerRespondModel;
     
<p>2023-02-03:

    1. New enumeration values:
    id = 10: Language (Turkish, Czech, Indonesian, Bahasa Malaysia, German, Farsi)
    id = 19: Social network Dingding, Alipay
    id = 22: Reminder Replaces all and all by type
    id = 34: Message push switch Dingding, Alipay
    
    2. Add attributes
    id = 22: EAReminderOps alert type (eType);
    id = 30: EACombinationModel Sleep Oxygen monitor switch (sleepBloodOxygenSw), stressSw,
    id = 44: EAWatchSupportModel supports the pressure monitoring switch protocol (id = 51), real-time data switch protocol (id = 52), all write operations of alert protocols, all replace operations of alert protocols by type (id = 22), and shock mode setting protocol (id = 53) Support App startup motion protocol (screen motion) (id = 54)
    
    3. New protocol:
    Sleep a blood oxygen monitor blood oxygen monitoring (night) EASleepBloodOxygenMonitor id = 50
    Pressure Monitor EAStressMonitor id = 51
    Real-time data switch EASendRealTimeDataOnOff id = 52
    EAVibrateIntensity Mode id = 53
    APP start watch motion (screen motion) EAAppLaunchScreenSport id = 54
    
    4. Change the class name
    APP map sport "EAAppLaunchSport" = "EAAppLaunchMapSport" id = 46
    APP map sports data EAAppSendSportDetails = and EAAppSendMapSportDetails id = 47
    Dial thumbnail EAMakeWatchFaceManager = EACreatThumbnail
    
    5. Change the attribute name
    Watch Function EAWatchSupportModel supportAppSport = supportAppMapSport
    
    6. Add a custom digital dial (Font, color, origin position)
    Time digital model "EACustomNumberWatchFaceModel custom font, color, the origin position
    Method to generate a thumbnail view EACreatThumbnail + (nsstrings *) creatNumberThumbnailWithBackgroundImage:...
    Method to check the oat dial EABleSendManager - (NSInteger) creatPictureNumberThumbnailWithBackgroundImage:...
    
<p>2023-01-30:

    fixed ios connect camera bug
    
<p>2022-12-29:

    1.BT one-click connection.
    2. Add App sports.
    3. Add real-time data
    4. Newly added App Open heart rate, pressure and blood oxygen detection
    5. Modify the custom dial
    
<p>2022-12-08:

     1. Change the yymodel to yykit.
     2. Add ANCS status change notification.
     
<p>2022-10-19:

     1. Added a new periodic reminder protocol, and added a new acquisition of periodic reminders.【class EAMonitorReminder】
     2. Add object query data.
     3. Added quick query of paired watch SN number.【class EAFastGetSnNumberManager】
     4. Fix some bugs.
     
<p>2022-10-13: 

    Modify the bug that the custom watch face file cannot be listed on the App Store.
    
<p>2022-09-22: 

    Adapt to new models of watches, and add methods related to custom dials.
    
<p>2022-09-08: 

    Fix some bugs.
    
<p>2022-09-02: 

    First release.


