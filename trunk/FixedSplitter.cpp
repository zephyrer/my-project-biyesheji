// FixedSplitter.cpp: implementation of the CFixedSplitter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Wanderer.h"
#include "FixedSplitter.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(CFixedSplitter, CSplitterWnd)
//{{AFX_MSG_MAP(CFixedSplitter)
// NOTE - the ClassWizard will add and remove mapping macros here.
//}}AFX_MSG_MAP
ON_WM_LBUTTONDOWN()
ON_WM_MOUSEMOVE()
ON_WM_SETCURSOR()
END_MESSAGE_MAP()

CFixedSplitter::CFixedSplitter()
{

}

CFixedSplitter::~CFixedSplitter()
{

}
void   CFixedSplitter::OnLButtonDown(UINT   nFlags,CPoint   point) 
{
	CWnd::OnLButtonDown(nFlags,point);
} 

void   CFixedSplitter::OnMouseMove(UINT   nFlags,CPoint   point) 
{ 
	CWnd::OnMouseMove(nFlags,point);
} 
bool   CFixedSplitter::OnSetCursor(CWnd*   pWnd,UINT   nHitTest,UINT   message) 
{
	CWnd::OnSetCursor(pWnd,nHitTest,message);
	return FALSE;
}