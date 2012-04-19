#if !defined(AFX_MYEDITVIEW_H__0C44242B_B8C8_4951_8A37_B06ACB294054__INCLUDED_)
#define AFX_MYEDITVIEW_H__0C44242B_B8C8_4951_8A37_B06ACB294054__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyEditView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyEditView view

class CMyEditView : public CView
{
protected:
	CMyEditView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMyEditView)

// Attributes
public:
	CEdit myEdit;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyEditView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMyEditView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyEditView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYEDITVIEW_H__0C44242B_B8C8_4951_8A37_B06ACB294054__INCLUDED_)
