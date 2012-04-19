// MyDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Wanderer.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDialog dialog


CMyDialog::CMyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	//{{AFX_MSG_MAP(CMyDialog)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDialog message handlers

void CMyDialog::OnPaint() 
{
	CPaintDC dc(this);
	CString path=transpath;
	wchar_t* filename;
	filename=path.AllocSysString();
	Image image(filename);

	Graphics graphics(dc.m_hDC);

	if (path.Find(".gif")!=-1)
	{
		UINT count=0;
		count=image.GetFrameDimensionsCount();
		GUID *pDimensionIDs=(GUID*)new GUID[count];
		image.GetFrameDimensionsList(pDimensionIDs,count);
		wchar_t strGuid[39];
		StringFromGUID2(pDimensionIDs[0],strGuid,39);
		UINT frameCount=image.GetFrameCount(&pDimensionIDs[0]);
		delete []pDimensionIDs;
		if (frameCount==1)
		{
			Status s=	graphics.DrawImage(&image,0,0,image.GetWidth(),image.GetHeight());
		}
		else
		{
			UINT sizeone;
			UINT totalsize;
			image.GetPropertySize(&totalsize,&sizeone);
			UINT itemsize=image.GetPropertyItemSize(PropertyTagFrameDelay);
			PropertyItem* pItem=NULL;
			pItem=(PropertyItem*)malloc(itemsize);
			memset(pItem,0,itemsize);
			image.GetPropertyItem(PropertyTagFrameDelay,itemsize,pItem);
			int fcount=0;
			GUID Guid=FrameDimensionTime;
			while(TRUE)
			{
				Status s=	graphics.DrawImage(&image,0,0,image.GetWidth(),image.GetHeight());
				image.SelectActiveFrame(&Guid,fcount++);
				if (fcount==frameCount)
				{
					fcount=0;
				}
				long lpause =((long*)pItem->value)[fcount]*10;
				Sleep(lpause);
			}
			
		}
		
	}
	else
	{
		Status s=	graphics.DrawImage(&image,0,0,image.GetWidth(),image.GetHeight());		
	}
	

	
	// Do not call CDialog::OnPaint() for painting messages
}

BOOL CMyDialog::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	return CDialog::PreCreateWindow(cs);
}

BOOL CMyDialog::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::Create(IDD, pParentWnd);
}

void CMyDialog::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CDialog::PreSubclassWindow();
}

BOOL CMyDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetWindowPos(NULL,0,0,nWidth,nHeight,SWP_NOZORDER|SWP_NOMOVE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CMyDialog::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}
