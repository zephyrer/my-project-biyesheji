// WandererDoc.h : interface of the CWandererDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WANDERERDOC_H__D39A1DE3_ABAB_4F44_AEBF_ACD265CF94A0__INCLUDED_)
#define AFX_WANDERERDOC_H__D39A1DE3_ABAB_4F44_AEBF_ACD265CF94A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWandererDoc : public CDocument
{
protected: // create from serialization only
	CWandererDoc();
	DECLARE_DYNCREATE(CWandererDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWandererDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWandererDoc();
	BOOL RouteCmdToAllViews(CView* pView,UINT nID,int nCode,void* pExtra,AFX_CMDHANDLERINFO* pHandlerinfo);
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWandererDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WANDERERDOC_H__D39A1DE3_ABAB_4F44_AEBF_ACD265CF94A0__INCLUDED_)
