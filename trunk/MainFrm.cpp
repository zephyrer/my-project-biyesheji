// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Wanderer.h"
#include "MainFrm.h"
#include "WandererDoc.h"
#include "WandererView.h"
#include "ButtonView.h"
#include "MyEditView.h"
#include "ThumbnailView.h"
#include "MyTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
//	cs.style&=~WS_MAXIMIZEBOX;
	cs.style=WS_OVERLAPPED|WS_SYSMENU|WS_MINIMIZE;
	cs.cx=700;
	cs.cy=600;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	if (!m_wndSplitter.CreateStatic(this,2,1)
		||!m_wndSplitter1.CreateStatic(&m_wndSplitter,1,2,WS_CHILD|WS_VISIBLE,m_wndSplitter.IdFromRowCol(0,0))
		||!m_wndSplitter1.CreateView(0,0,RUNTIME_CLASS(CMyEditView),CSize(0,0),pContext)
		||!m_wndSplitter1.CreateView(0,1,RUNTIME_CLASS(CButtonView),CSize(0,0),pContext)
		||!m_wndSplitter.CreateView(1,0,RUNTIME_CLASS(CThumbnailView),CSize(0,0),pContext)
		
		)
	{
		return FALSE;
		
	}

// 	if (!m_wndSplitter.CreateStatic(this,2,1)
// 		||!m_wndSplitter1.CreateStatic(&m_wndSplitter,1,2,WS_CHILD|WS_VISIBLE,m_wndSplitter.IdFromRowCol(0,0))
// 		||!m_wndSplitter1.CreateView(0,0,RUNTIME_CLASS(CMyEditView),CSize(0,0),pContext)
// 		||!m_wndSplitter1.CreateView(0,1,RUNTIME_CLASS(CButtonView),CSize(0,0),pContext)
// 		||!m_wndSplitter2.CreateStatic(&m_wndSplitter,1,2,WS_CHILD|WS_VISIBLE,m_wndSplitter.IdFromRowCol(1,0))
// 		||!m_wndSplitter2.CreateView(0,0,RUNTIME_CLASS(CMyTree),CSize(150,100),pContext)
//  		||!m_wndSplitter2.CreateView(0,1,RUNTIME_CLASS(CThumbnailView),CSize(0,0),pContext)
// 		
// 		)
// 	{
// 		return FALSE;
// 
// 	}
	m_wndSplitter.SetRowInfo(0,20,0);
	m_wndSplitter1.SetColumnInfo(0,600,0);
	return TRUE;
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	if (CFrameWnd::OnCmdMsg(nID,nCode,pExtra,pHandlerInfo))
	{
		return TRUE;
	}
	CWandererDoc* pDoc =(CWandererDoc*)GetActiveDocument();
	if (pDoc!=NULL)
	{
		return pDoc->RouteCmdToAllViews(GetActiveView(),nID,nCode,pExtra,pHandlerInfo);
	}
	return FALSE;
}
