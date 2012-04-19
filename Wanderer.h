// Wanderer.h : main header file for the WANDERER application
//

#if !defined(AFX_WANDERER_H__97632F26_5D11_42DE_B73C_DF0CB2FEE3C5__INCLUDED_)
#define AFX_WANDERER_H__97632F26_5D11_42DE_B73C_DF0CB2FEE3C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "StdAfx.h"
#include <afxmt.h>
/////////////////////////////////////////////////////////////////////////////
// CWandererApp:
// See Wanderer.cpp for the implementation of this class
//

class CWandererApp : public CWinApp
{
public:
	CWandererApp();


public:
	ULONG_PTR m_gdiplusToken;
//	static CString strExePath;

public:
//	static void log_debug(const char *format, ...);
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWandererApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CWandererApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CString strExePath;
extern CString transpath;
extern int nWidth;
extern int nHeight;
extern CDC ** g_pMemDC;
extern CBitmap ** g_pBmpCanvas;
extern CBitmap ** g_pBmpOldCanvas;
BOOL ParseURL(LPCTSTR lpszURL,CString& strServer,CString& strObject,USHORT& nPort, CString &csProtocolType);
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WANDERER_H__97632F26_5D11_42DE_B73C_DF0CB2FEE3C5__INCLUDED_)
