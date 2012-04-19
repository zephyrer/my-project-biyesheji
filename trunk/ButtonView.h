#if !defined(AFX_BUTTONVIEW_H__EDF69EAD_85F9_413F_9030_7DA62640B372__INCLUDED_)
#define AFX_BUTTONVIEW_H__EDF69EAD_85F9_413F_9030_7DA62640B372__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ButtonView.h : header file
//

#include "ThumbnailView.h"


struct path
{
	CString webpath;
	CString localpath;
	int nNumber;
	CThumbnailView * pView;
	int x;
	int y;
	CEvent *ce;
};

struct downloadparam
{
	CString webpath;
	long from;
	long to;
	int n;
	int len;
	char * temp;
	CEvent *e;
};
UINT MTDownLoad(LPVOID pParam);
/////////////////////////////////////////////////////////////////////////////
// CButtonView view
class CButtonView : public CView
{
protected:
	CButtonView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CButtonView)

// Attributes
public:
	CButton myButton;
// 	CString strRequest;
// 	CString strwebpath;

//	struct path temppath[100];
//	struct path *temppath;

// Operations
public:
	CView* GetView(CRuntimeClass* pClass);


	void DeleteDir(/*wchar_t* lpszDir*/ CString szDir);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CButtonView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CButtonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CButtonView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnButtonClicked();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
void parseChunk();

UINT DownlaodFile(LPVOID pParam);
UINT DownlaodFileWithSocket(LPVOID pParam);
UINT OnDrawThumbnailOne(LPVOID pParam);
UINT ParseImageUrl(LPVOID pParam);
// extern CString g_strExePath;
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUTTONVIEW_H__EDF69EAD_85F9_413F_9030_7DA62640B372__INCLUDED_)
