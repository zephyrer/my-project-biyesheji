// Wanderer.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Wanderer.h"

#include "MainFrm.h"
#include "WandererDoc.h"
#include "WandererView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWandererApp

BEGIN_MESSAGE_MAP(CWandererApp, CWinApp)
	//{{AFX_MSG_MAP(CWandererApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWandererApp construction

CWandererApp::CWandererApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CWandererApp object

CWandererApp theApp;
CString strExePath;
CString transpath;
int nWidth;
int nHeight;
CDC ** g_pMemDC;
CBitmap ** g_pBmpCanvas;
CBitmap ** g_pBmpOldCanvas;
/////////////////////////////////////////////////////////////////////////////
// CWandererApp initialization

BOOL CWandererApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CWandererDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CWandererView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;


	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&m_gdiplusToken,&gdiplusStartupInput,NULL);
	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	char chpath[500];
	GetModuleFileName(NULL,chpath,500);	
	strExePath.Format("%s",chpath);
	int nPos=strExePath.ReverseFind('\\');
	strExePath=strExePath.Left(nPos+1);
	strExePath=strExePath+"cache";
	CreateDirectory(strExePath,NULL);

	///初始化Socket函数库
	int err;
	WORD wVersion;
	WSADATA WSAData;
	wVersion=MAKEWORD(2,0);
	err=WSAStartup(wVersion,&WSAData);
	if(err!=0)
	{
		AfxMessageBox("无法装载Socket库.");
	}
	if(LOBYTE( WSAData.wVersion ) != 2)
	{
		AfxMessageBox("无法找到合适的Socket库.");
		WSACleanup();
	}

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CWandererApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CWandererApp message handlers


int CWandererApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	GdiplusShutdown(m_gdiplusToken);
	//清除Socket库
	WSACleanup();
	return CWinApp::ExitInstance();
}


// void CWandererApp::log_debug(const char *format, ...)
// {
// 	HANDLE hFile;
// 	char *text = (char*)malloc(sizeof(char)*1024*64);
// 	DWORD dwLen = 0;
// 	va_list ap;
// 	SYSTEMTIME st;
// 	int len=0;
// 	TCHAR log_path[1024*64];
// 	
// 	_stprintf(log_path, _T("%s%s"), "c:", TEXT("\\wanderer_log.txt"));
// 	
// 	GetLocalTime(&st);
// 	sprintf(text, "[%2d:%2d:%2d] ", st.wHour, st.wMinute, st.wSecond);
// 	len = strlen(text);
// 	hFile = CreateFile(log_path, GENERIC_WRITE, FILE_SHARE_WRITE,
// 		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
// 	if(hFile == INVALID_HANDLE_VALUE) {
// 		hFile = CreateFile(log_path, GENERIC_WRITE, FILE_SHARE_WRITE,
// 			NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
// 	}
// 	if(hFile == INVALID_HANDLE_VALUE){
// 		free(text);
// 		return;
// 	}
// 	va_start(ap,format);
// 	vsprintf(text+len, format, ap);
// 	va_end(ap);
// 	SetFilePointer(hFile, 0, 0, FILE_END);
// 	WriteFile(hFile, text, strlen(text), &dwLen, NULL);
// 	CloseHandle(hFile);
// 	free(text);
// }


BOOL ParseURL(LPCTSTR lpszURL, CString &strServer, CString &strObject,USHORT& nPort, CString &csProtocolType)
{
	if ( !lpszURL || strlen(lpszURL) < 1 ) return FALSE;
	CString csURL_Lower(lpszURL);
	csURL_Lower.TrimLeft();
	csURL_Lower.TrimRight();
	csURL_Lower.Replace ( "\\", "/" );
	CString csURL = csURL_Lower;
	csURL_Lower.MakeLower ();
	
	// 清除数据
	strServer = _T("");
	strObject = _T("");
	nPort	  = 0;
	
	int nPos = csURL_Lower.Find("://");
	if( nPos == -1 )
	{
		csURL_Lower.Insert ( 0, "http://" );
		csURL.Insert ( 0, "http://" );
		nPos = 4;
	}
	csProtocolType = csURL_Lower.Left ( nPos );
	
	csURL_Lower = csURL_Lower.Mid( csProtocolType.GetLength()+3 );
	csURL = csURL.Mid( csProtocolType.GetLength()+3 );
	nPos = csURL_Lower.Find('/');
	if ( nPos == -1 )
		return FALSE;
	
	strObject = csURL.Mid(nPos);
	CString csServerAndPort = csURL_Lower.Left(nPos);
	
	// 查找是否有端口号，站点服务器域名一般用小写
	nPos = csServerAndPort.Find(":");
	if( nPos == -1 )
	{
		strServer	= csServerAndPort;
		nPort		= 80;
		if ( csProtocolType == "ftp" )
			nPort	= 21;
	}
	else
	{
		strServer = csServerAndPort.Left( nPos );
		csServerAndPort	  = csServerAndPort.Mid( nPos+1 );
		nPort	  = (USHORT)_ttoi((LPCTSTR)csServerAndPort);
	}
	return TRUE;
}