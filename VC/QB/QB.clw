; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDialog_Tab_Calibration
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "QB.h"

ClassCount=6
Class1=CQBApp
Class2=CQBDlg

ResourceCount=6
Resource2=IDD_TAB_TEST
Resource1=IDR_MAINFRAME
Class3=CDialog_Tab_Help
Resource3=IDD_TAB_HELP
Class4=CDialog_Tab_Calibration
Resource4=IDD_QB_DIALOG
Class5=CDialog_Tab_Pcb_Setting
Resource5=IDD_TAB_PCB_SETTING
Class6=CDialog_Tab_TEST
Resource6=IDD_TAB_CALIBRATION

[CLS:CQBApp]
Type=0
HeaderFile=QB.h
ImplementationFile=QB.cpp
Filter=N

[CLS:CQBDlg]
Type=0
HeaderFile=QBDlg.h
ImplementationFile=QBDlg.cpp
Filter=D
LastObject=IDC_SCREEN_TYPE
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_QB_DIALOG]
Type=1
Class=CQBDlg
ControlCount=7
Control1=IDC_TAB_MAIN,SysTabControl32,1342177280
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_SCREEN_TYPE,combobox,1478558019
Control6=IDC_EXIT,button,1342242816
Control7=IDC_STATIC,static,1342308352

[DLG:IDD_TAB_HELP]
Type=1
Class=CDialog_Tab_Help
ControlCount=19
Control1=IDC_STATIC,static,1342308352
Control2=IDC_PASSWORD_1,button,1342242816
Control3=IDC_PASSWORD_2,button,1342242816
Control4=IDC_PASSWORD_3,button,1342242816
Control5=IDC_PASSWORD_4,button,1342242816
Control6=IDC_PASSWORD_5,button,1342242816
Control7=IDC_PASSWORD_6,button,1342242816
Control8=IDC_PASSWORD_7,button,1342242816
Control9=IDC_PASSWORD_8,button,1342242816
Control10=IDC_PASSWORD_9,button,1342242816
Control11=IDC_BUTTON10,button,1342242816
Control12=IDC_PASSWORD_0,button,1342242816
Control13=IDC_BUTTON12,button,1342242816
Control14=IDC_LOGIN,button,1342242816
Control15=IDC_STATIC,button,1342177287
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_USER_NAME,edit,1350631552
Control19=IDC_USER_PASSWORD,edit,1350631584

[CLS:CDialog_Tab_Help]
Type=0
HeaderFile=Dialog_Tab_Help.h
ImplementationFile=Dialog_Tab_Help.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_USER_NAME
VirtualFilter=dWC

[DLG:IDD_TAB_CALIBRATION]
Type=1
Class=CDialog_Tab_Calibration
ControlCount=78
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_SLIDER_DOUBLE_CLICK_AREA,msctls_trackbar32,1342242840
Control4=IDC_EDIT_DOUBLE_CLICK_AREA,edit,1350639744
Control5=IDC_CHECK_ENABLE_RIGHT_CLICK,button,1342242819
Control6=IDC_STATIC,static,1342308352
Control7=IDC_SLIDER_RIGHT_CLICK_DELAY,msctls_trackbar32,1342242840
Control8=IDC_EDIT_RIGHT_CLICK_DELAY,edit,1350639744
Control9=IDC_STATIC,static,1342308352
Control10=IDC_SLIDER_RIGHT_CLICK_AREA,msctls_trackbar32,1342242840
Control11=IDC_EDIT_RIGHT_CLICK_AREA,edit,1350639744
Control12=IDC_CHECK_X_INV,button,1342242819
Control13=IDC_CHECK_Y_INV,button,1342242819
Control14=IDC_CHECK_XY_INV,button,1342242819
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC_HW_SN,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC_HW_VERSION,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC_SN_VERSION,static,1342308352
Control21=IDC_PROGRESS_ACCESS,msctls_progress32,1350565888
Control22=IDC_BUTTON_SCREEN_CALIBRATION,button,1342242816
Control23=IDC_BUTTON_READ_CONFIGURATION,button,1342242816
Control24=IDC_BUTTON_WRITE_CONFIGURATION,button,1342242816
Control25=IDC_STATIC,button,1342177287
Control26=IDC_CHECK_SET_BY_CALIBRATION,button,1342242819
Control27=IDC_BUTTON_UP,button,1342242816
Control28=IDC_BUTTON_LEFT,button,1342242816
Control29=IDC_BUTTON_RIGHT,button,1342242816
Control30=IDC_BUTTON_DOWN,button,1342242816
Control31=IDC_STATIC,static,1342308352
Control32=IDC_STATIC,static,1342308352
Control33=IDC_EDIT_OFFSET_X,edit,1350639744
Control34=IDC_EDIT_OFFSET_Y,edit,1350639744
Control35=IDC_STATIC,static,1342308352
Control36=IDC_EDIT_ZOOM_X,edit,1350639744
Control37=IDC_STATIC,static,1342308352
Control38=IDC_EDIT_ZOOM_Y,edit,1350639744
Control39=IDC_SLIDER1,msctls_trackbar32,1342242840
Control40=IDC_SLIDER2,msctls_trackbar32,1342242840
Control41=IDC_RADIO_ENABLE_FIRST_POINT,button,1342316553
Control42=IDC_RADIO_ENABLE_MIDDLE_POINT,button,1342316553
Control43=IDC_CHECK_ALWAYS_SIMPLE_POINT,button,1342242819
Control44=IDC_CHECK_SIMULATE_MOUSE,button,1342242819
Control45=IDC_CHECK_2POINT_SIMULATE_WHEEL,button,1342242819
Control46=IDC_STATIC,button,1342177287
Control47=IDC_STATIC,static,1342308352
Control48=IDC_STATIC,static,1342308352
Control49=IDC_STATIC,static,1342308352
Control50=IDC_STATIC,static,1342308352
Control51=IDC_STATIC,static,1342308352
Control52=IDC_STATIC,static,1342308352
Control53=IDC_STATIC,static,1342308352
Control54=IDC_STATIC,static,1342308352
Control55=IDC_STATIC,static,1342308352
Control56=IDC_STATIC,static,1342308352
Control57=IDC_STATIC,static,1342308352
Control58=IDC_STATIC,static,1342308352
Control59=IDC_STATIC,static,1342308352
Control60=IDC_STATIC,static,1342308352
Control61=IDC_STATIC,static,1342308352
Control62=IDC_STATIC,static,1342308352
Control63=IDC_EDIT_X1,edit,1350639744
Control64=IDC_EDIT_X2,edit,1350639744
Control65=IDC_EDIT_X3,edit,1350639744
Control66=IDC_EDIT_X4,edit,1350639744
Control67=IDC_EDIT_X5,edit,1350639744
Control68=IDC_EDIT_X6,edit,1350639744
Control69=IDC_EDIT_X7,edit,1350639744
Control70=IDC_EDIT_X8,edit,1350639744
Control71=IDC_EDIT_X9,edit,1350639744
Control72=IDC_EDIT_XA,edit,1350639744
Control73=IDC_EDIT_XB,edit,1350639744
Control74=IDC_EDIT_XC,edit,1350639744
Control75=IDC_EDIT_XD,edit,1350639744
Control76=IDC_EDIT_XE,edit,1350639744
Control77=IDC_EDIT_XF,edit,1350639744
Control78=IDC_EDIT_X0,edit,1350639744

[CLS:CDialog_Tab_Calibration]
Type=0
HeaderFile=Dialog_Tab_Calibration.h
ImplementationFile=Dialog_Tab_Calibration.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_STATIC_SN_VERSION
VirtualFilter=dWC

[DLG:IDD_TAB_PCB_SETTING]
Type=1
Class=CDialog_Tab_Pcb_Setting
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352

[CLS:CDialog_Tab_Pcb_Setting]
Type=0
HeaderFile=Dialog_Tab_Pcb_Setting.h
ImplementationFile=Dialog_Tab_Pcb_Setting.cpp
BaseClass=CDialog
Filter=D
LastObject=CDialog_Tab_Pcb_Setting

[DLG:IDD_TAB_TEST]
Type=1
Class=CDialog_Tab_TEST
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352

[CLS:CDialog_Tab_TEST]
Type=0
HeaderFile=Dialog_Tab_TEST.h
ImplementationFile=Dialog_Tab_TEST.cpp
BaseClass=CDialog
Filter=D
LastObject=CDialog_Tab_TEST
