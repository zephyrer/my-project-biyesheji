// MyList.cpp : implementation file
//

#include "stdafx.h"
#include "Wanderer.h"
#include "MyList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyList

IMPLEMENT_DYNCREATE(CMyList, CListView)

CMyList::CMyList()
{
}

CMyList::~CMyList()
{
}


BEGIN_MESSAGE_MAP(CMyList, CListView)
	//{{AFX_MSG_MAP(CMyList)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyList drawing

void CMyList::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CMyList diagnostics

#ifdef _DEBUG
void CMyList::AssertValid() const
{
	CListView::AssertValid();
}

void CMyList::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyList message handlers
