#if !defined(AFX_THUMBNAILVIEW_H__6EFFCF95_57DA_483E_BEA1_5D47FB905A38__INCLUDED_)
#define AFX_THUMBNAILVIEW_H__6EFFCF95_57DA_483E_BEA1_5D47FB905A38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ThumbnailView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CThumbnailView view

class CThumbnailView : public CScrollView
{
protected:
	CThumbnailView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CThumbnailView)

// Attributes
public:
// 	CDC *m_pDCMem;
// 	CBitmap *m_pBmpCanvas;
// 	CBitmap *m_pBmpOldCanvas;
// 	UINT m_nWidth;
// 	UINT m_nHeight;
// 	CDC *pDCMem[100];
// 	CBitmap *pBmpCanvas[100];
// 	CBitmap *pBmpOldCanvas[100];
	int nCount;


// Operations
public:
//	UINT OnDrawThumbnail(LPVOID pParam);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThumbnailView)
	public:
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CThumbnailView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CThumbnailView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//UINT OnDrawThumbnail(LPVOID pParam);
extern CThumbnailView* Thumbnail;
//UINT display(LPVOID pParam);
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THUMBNAILVIEW_H__6EFFCF95_57DA_483E_BEA1_5D47FB905A38__INCLUDED_)
