// WandererView.h : interface of the CWandererView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WANDERERVIEW_H__93B4793E_C11F_49AC_A11C_FADE83025903__INCLUDED_)
#define AFX_WANDERERVIEW_H__93B4793E_C11F_49AC_A11C_FADE83025903__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWandererView : public CView
{
protected: // create from serialization only
	CWandererView();
	DECLARE_DYNCREATE(CWandererView)

// Attributes
public:
	CWandererDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWandererView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWandererView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWandererView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in WandererView.cpp
inline CWandererDoc* CWandererView::GetDocument()
   { return (CWandererDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WANDERERVIEW_H__93B4793E_C11F_49AC_A11C_FADE83025903__INCLUDED_)
