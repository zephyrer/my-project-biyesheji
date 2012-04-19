// WandererView.cpp : implementation of the CWandererView class
//

#include "stdafx.h"
#include "Wanderer.h"

#include "WandererDoc.h"
#include "WandererView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWandererView

IMPLEMENT_DYNCREATE(CWandererView, CView)

BEGIN_MESSAGE_MAP(CWandererView, CView)
	//{{AFX_MSG_MAP(CWandererView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWandererView construction/destruction

CWandererView::CWandererView()
{
	// TODO: add construction code here

}

CWandererView::~CWandererView()
{
}

BOOL CWandererView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWandererView drawing

void CWandererView::OnDraw(CDC* pDC)
{
	CWandererDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CWandererView diagnostics

#ifdef _DEBUG
void CWandererView::AssertValid() const
{
	CView::AssertValid();
}

void CWandererView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWandererDoc* CWandererView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWandererDoc)));
	return (CWandererDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWandererView message handlers
