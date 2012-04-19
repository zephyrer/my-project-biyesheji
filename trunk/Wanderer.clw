; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CThumbnailView
LastTemplate=CTreeView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Wanderer.h"
LastPage=0

ClassCount=14
Class1=CWandererApp
Class2=CWandererDoc
Class3=CWandererView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Class6=Ceditsingleline
Class7=CFileView
Class8=CButtonView
Class9=CMyEditView
Class10=CThumbnailView
Resource2=IDD_ABOUTBOX
Class11=CMyDialog
Class12=CMyWnd
Class13=CMyList
Class14=CMyTree
Resource3=IDD_DIALOG1

[CLS:CWandererApp]
Type=0
HeaderFile=Wanderer.h
ImplementationFile=Wanderer.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CWandererApp

[CLS:CWandererDoc]
Type=0
HeaderFile=WandererDoc.h
ImplementationFile=WandererDoc.cpp
Filter=N

[CLS:CWandererView]
Type=0
HeaderFile=WandererView.h
ImplementationFile=WandererView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=Wanderer.cpp
ImplementationFile=Wanderer.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_APP_EXIT
Command2=ID_APP_ABOUT
CommandCount=2

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[CLS:Ceditsingleline]
Type=0
HeaderFile=editsingleline.h
ImplementationFile=editsingleline.cpp
BaseClass=CEditView
Filter=C
LastObject=Ceditsingleline

[CLS:CFileView]
Type=0
HeaderFile=FileView.h
ImplementationFile=FileView.cpp
BaseClass=CListView
Filter=C
LastObject=CFileView

[CLS:CButtonView]
Type=0
HeaderFile=ButtonView.h
ImplementationFile=ButtonView.cpp
BaseClass=CView
Filter=W
LastObject=CButtonView
VirtualFilter=VWC

[CLS:CMyEditView]
Type=0
HeaderFile=MyEditView.h
ImplementationFile=MyEditView.cpp
BaseClass=CView
Filter=C
LastObject=CMyEditView
VirtualFilter=VWC

[CLS:CThumbnailView]
Type=0
HeaderFile=ThumbnailView.h
ImplementationFile=ThumbnailView.cpp
BaseClass=CScrollView
Filter=C
LastObject=CThumbnailView
VirtualFilter=VWC

[DLG:IDD_DIALOG1]
Type=1
Class=CMyDialog
ControlCount=0

[CLS:CMyDialog]
Type=0
HeaderFile=MyDialog.h
ImplementationFile=MyDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CMyDialog

[CLS:CMyWnd]
Type=0
HeaderFile=MyWnd.h
ImplementationFile=MyWnd.cpp
BaseClass=CFrameWnd
Filter=T
LastObject=CMyWnd

[CLS:CMyList]
Type=0
HeaderFile=MyList.h
ImplementationFile=MyList.cpp
BaseClass=CListView
Filter=C

[CLS:CMyTree]
Type=0
HeaderFile=MyTree.h
ImplementationFile=MyTree.cpp
BaseClass=CTreeView
Filter=C

