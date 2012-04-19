// MyTree.cpp : implementation file
//

#include "stdafx.h"
#include "Wanderer.h"
#include "MyTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyTree

IMPLEMENT_DYNCREATE(CMyTree, CTreeView)

CMyTree::CMyTree()
{
}

CMyTree::~CMyTree()
{
}


BEGIN_MESSAGE_MAP(CMyTree, CTreeView)
	//{{AFX_MSG_MAP(CMyTree)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyTree drawing

void CMyTree::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CMyTree diagnostics

#ifdef _DEBUG
void CMyTree::AssertValid() const
{
	CTreeView::AssertValid();
}

void CMyTree::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyTree message handlers
