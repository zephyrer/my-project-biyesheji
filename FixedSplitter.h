// FixedSplitter.h: interface for the CFixedSplitter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIXEDSPLITTER_H__D94CCA70_BBDD_46CE_B368_B0CA5867E9F8__INCLUDED_)
#define AFX_FIXEDSPLITTER_H__D94CCA70_BBDD_46CE_B368_B0CA5867E9F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFixedSplitter : public CSplitterWnd  
{
public:
	CFixedSplitter();
	virtual ~CFixedSplitter();
	afx_msg void OnLButtonDown(UINT   nFlags,CPoint   point);
	afx_msg void OnMouseMove(UINT   nFlags,CPoint   point);
	afx_msg bool OnSetCursor(CWnd*   pWnd,UINT   nHitTest,UINT   message);
	DECLARE_MESSAGE_MAP()

};

#endif // !defined(AFX_FIXEDSPLITTER_H__D94CCA70_BBDD_46CE_B368_B0CA5867E9F8__INCLUDED_)
