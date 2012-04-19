#if !defined(AFX_MYTREE_H__D3BEBA98_FF20_4CF6_89B0_E2553CF40ED4__INCLUDED_)
#define AFX_MYTREE_H__D3BEBA98_FF20_4CF6_89B0_E2553CF40ED4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyTree.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyTree view

class CMyTree : public CTreeView
{
protected:
	CMyTree();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMyTree)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyTree)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMyTree();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyTree)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTREE_H__D3BEBA98_FF20_4CF6_89B0_E2553CF40ED4__INCLUDED_)
