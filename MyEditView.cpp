// MyEditView.cpp : implementation file
//

#include "stdafx.h"
#include "Wanderer.h"
#include "MyEditView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyEditView

IMPLEMENT_DYNCREATE(CMyEditView, CView)

CMyEditView::CMyEditView()
{
}

CMyEditView::~CMyEditView()
{
}


BEGIN_MESSAGE_MAP(CMyEditView, CView)
	//{{AFX_MSG_MAP(CMyEditView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyEditView drawing

void CMyEditView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
//	CMainFrame   *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd; 
//	CMyEditView   *pView=(CMyEditView *)pMain->GetActiveView();
//	CMyEditView   *pView=(CMyEditView *)pMain->GetActiveWindow();
	CMyEditView   *pView=this;
	CRect rect;
	pView->GetClientRect(&rect);
	myEdit.MoveWindow(rect);


	CRect editrect;
	myEdit.GetRect(&editrect);
	int temp1=rect.bottom-rect.top;
	int temp2=editrect.bottom-editrect.top;
	editrect.top=(temp1-temp2)/2;
	editrect.bottom=editrect.top+temp2;
	myEdit.SetRect(&editrect);
	

	CFont * f; 
	f = new CFont; 
	f->CreateFont(21, // nHeight 
		0, // nWidth 
		0, // nEscapement 
		0, // nOrientation 
		500, // nWeight 
		TRUE, // bItalic 
		FALSE, // bUnderline 
		0, // cStrikeOut 
		ANSI_CHARSET, // nCharSet 
		OUT_DEFAULT_PRECIS, // nOutPrecision 
		CLIP_DEFAULT_PRECIS, // nClipPrecision 
		DEFAULT_QUALITY, // nQuality 
		DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily 
		_T("Arial")); // lpszFac 

	myEdit.SetFont(f,TRUE);
	delete f;

}

/////////////////////////////////////////////////////////////////////////////
// CMyEditView diagnostics

#ifdef _DEBUG
void CMyEditView::AssertValid() const
{
	CView::AssertValid();
}

void CMyEditView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyEditView message handlers

int CMyEditView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
/*
	CMainFrame   *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	CMyEditView   *pView=(CMyEditView*)pMain->m_wndSplitter1.GetPane(0,1);
	CRect rect;
	pView->GetClientRect(&rect);
	myEdit.Create(WS_CHILD|WS_VISIBLE|ES_LEFT/ *|WS_BORDER* /|ES_AUTOHSCROLL,rect,this,1);
*/
	myEdit.Create(WS_CHILD|WS_VISIBLE|ES_LEFT/*|WS_BORDER*/|ES_AUTOHSCROLL,CRect(10,10,500,40),this,1);
	
	return 0;
}

void CMyEditView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	
}
