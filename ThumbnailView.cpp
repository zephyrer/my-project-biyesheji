// ThumbnailView.cpp : implementation file
//

#include "stdafx.h"
#include "Wanderer.h"
#include "ThumbnailView.h"
#include "MainFrm.h"
#include "ButtonView.h"
#include "MyDialog.h"


#include <io.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define ThumbnailWidth 100

/////////////////////////////////////////////////////////////////////////////
// CThumbnailView

IMPLEMENT_DYNCREATE(CThumbnailView, CScrollView)

CThumbnailView::CThumbnailView()
{
// 	m_pDCMem = NULL;
// 	m_pBmpCanvas = NULL;
// 	m_pBmpOldCanvas = NULL;
// 	m_nWidth = 0;
// 	m_nHeight = 0;
// 	for (int i=0;i<100;i++)
// 	{
// 		pDCMem[i]=NULL;
// 		pBmpCanvas[i]=NULL;
// 		pBmpOldCanvas[i]=NULL;
// 	}
	nCount=0;

}

CThumbnailView::~CThumbnailView()
{
	for (int m=0;m<nCount;m++)
	{
		if (g_pMemDC[m]!=NULL)
		{
			g_pMemDC[m]->SelectObject(g_pBmpOldCanvas[m]);
			g_pMemDC[m]->DeleteDC();
			g_pBmpCanvas[m]->DeleteObject();
			delete g_pMemDC[m];
			delete g_pBmpCanvas[m];

		}
		
	}
	delete[] g_pMemDC;
	delete[] g_pBmpCanvas;
	delete[] g_pBmpOldCanvas;

}


BEGIN_MESSAGE_MAP(CThumbnailView, CScrollView)
	//{{AFX_MSG_MAP(CThumbnailView)
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThumbnailView drawing

void CThumbnailView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	
	// TODO: calculate the total size of this view
	CRect rect;
	this->GetClientRect(&rect);
	CSize sizeTotal;
	sizeTotal.cx = rect.right;
		sizeTotal.cy = rect.bottom;
	SetScrollSizes(MM_TEXT, sizeTotal);
	nCount=rect.bottom;

// 	m_nWidth = rect.right;
// 	m_nHeight = 20000;
// 	
// 	if(m_pDCMem != NULL) {
// 		m_pDCMem->SelectObject(m_pBmpOldCanvas);
// 		m_pDCMem->DeleteDC();
// 		m_pBmpCanvas->DeleteObject();
// 		
// 		delete m_pDCMem;
// 		m_pDCMem = NULL;
// 		delete m_pBmpCanvas;
// 		m_pBmpCanvas = NULL;
// 		m_pBmpOldCanvas = NULL;
// 	}
// 	
// 	m_pDCMem = new CDC();
// 	m_pDCMem->CreateCompatibleDC(GetDC());
// 	
// 	m_pBmpCanvas = new CBitmap();
// 	m_pBmpCanvas->CreateCompatibleBitmap(GetDC(), m_nWidth, m_nHeight);
// 	
// 	m_pBmpOldCanvas = (CBitmap*)m_pDCMem->SelectObject(m_pBmpCanvas);
}

void CThumbnailView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here

//	AfxBeginThread(OnDrawThumbnail,pDC);
//	OnDrawThumbnail(pDC);
	
//	OnDrawThumbnail(this);
// 	CRect rect;
// 	this->GetClientRect(&rect);
// 	if (y+300>m_nHeight)
// 	{
// 		m_nHeight=y+300;
// 	}
	
// 	if(m_pDCMem != NULL) {
// 		pDC->BitBlt(0, 0, m_nWidth, m_nHeight, m_pDCMem, 0, 0, SRCCOPY);
// 	}
	if (nCount!=0)
	{
		CRect rect;
		this->GetClientRect(&rect);
		int lie=rect.right/300;
		int hang;
		if (nCount%lie==0)
		{
			hang=nCount/lie;
		}
		else
		{
			hang=nCount/lie+1;
		}
		
		CSize sizeTotal;
		sizeTotal.cx = rect.right;
		sizeTotal.cy = hang*300;
		SetScrollSizes(MM_TEXT, sizeTotal);
		for (int i=0;i<nCount;i++)
		{
			CRect rect;
			GetClientRect(&rect);
			int n=rect.right/300;
			int m=(i+1)%n;
			int x,y;
			if(m==0)
			{
				x=100+300*(n-1);
				y=100+300*((i+1)/n-1);
			}else
			{
				x=100+300*(m-1);
				y=100+300*((i+1)/n);
			}
			
			if (g_pMemDC[i]!=NULL)
			{
				pDC->BitBlt(x,y,200,200,g_pMemDC[i],0,0,SRCCOPY);
// 				g_pMemDC[i]->SelectObject(g_pBmpOldCanvas[i]);
// 				g_pBmpCanvas[i]->DeleteObject();
				TRACE("nnnnnnnnn");
			}
			
		}
	}
	
}

/////////////////////////////////////////////////////////////////////////////
// CThumbnailView diagnostics

#ifdef _DEBUG
void CThumbnailView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CThumbnailView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CThumbnailView message handlers


// UINT CThumbnailView::OnDrawThumbnail(LPVOID pParam)
// {
// 	CThumbnailView* p=(CThumbnailView*)pParam;
// //	p->cs.Lock();
// 	
// 	CClientDC dc(p);
// 	Graphics graphics(dc.m_hDC);
// 	int x=80;
// 	int y=80;
// 	CRect rect;
// 	p->GetClientRect(&rect);
// // 	if((x+ThumbnailWidth)>(rect.right-rect.left))
// // 	{
// // 		x=80;
// // 		y+=ThumbnailWidth;
// // 		
// // 	}
// 	wchar_t * filename;
// 	CString temp;
// 	POSITION pos;
// 	CStringList localpathlist;
// 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_01.jpg"));
// 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_02.jpg"));
// 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_03.jpg"));
// 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_04.jpg"));
// 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_05.jpg"));
// 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_06.jpg"));
// 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_07.jpg"));
// 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_08.jpg"));
// 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_09.jpg"));
// 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_10.jpg"));
// 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_11.jpg"));
// 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_12.jpg"));
// /*	CString strFilename=p->localPathList.GetTail();*/
// //	filename=strFilename.AllocSysString();
// 	pos=localpathlist.GetHeadPosition();
// 	temp=localpathlist.GetNext(pos);
// 	filename=temp.AllocSysString();
// 	while (pos!=0)
// 	{
// 		Image image(filename);
// 		int width=image.GetWidth();
// 		int height=image.GetHeight();
// // 		CSize sizeTotal;
// // 		sizeTotal.cx = width*12;
// // 		sizeTotal.cy = height;
// // 		SetScrollSizes(MM_TEXT, sizeTotal);
// 		graphics.DrawImage(&image,x,y);
// 
// 		x+=width;
// 		temp=localpathlist.GetNext(pos);
// 		filename=temp.AllocSysString();
// 
// 		
// 	}
// 	
// //	p->cs.Unlock();
// 	return 0;
// }


// UINT OnDrawThumbnail(LPVOID pParam)
// {
// //	CDC* pDC=(CDC*)pParam;
// 	
// 	path* pPath=(path*)pParam;
// 	//	p->cs.Lock();
// 	CMainFrame   *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
// 		CThumbnailView   *pView=(CThumbnailView*)pMain->m_wndSplitter2.GetPane(0,1);
// 	CDC* pDC=pView->GetDC();
// 
// // 	CPaintDC   dc(this),   
// // 		CThumbnailView::OnPrepareDC(&dc)
//  	Graphics graphics(pDC->m_hDC);
// 	int x=100;
// 	int y=100;
// 
// 	
//  	wchar_t * filename;
// // 	CString temp;
// // 	POSITION pos;
// // 	CStringList localpathlist;
// // 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_01.jpg"));
// // 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_02.jpg"));
// // 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_03.jpg"));
// // 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_04.jpg"));
// // 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_05.jpg"));
// // 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_06.jpg"));
// // 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_07.jpg"));
// // 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_08.jpg"));
// // 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_09.jpg"));
// // 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_10.jpg"));
// // 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_11.jpg"));
// // 	localpathlist.AddTail(_T("C:\\gyxc_1440x900\\1440x900_12.jpg"));
// // 	
// // 	pos=localpathlist.GetHeadPosition();
// // 	
// // 	while (pos!=0)
// // 	{
// // 		temp=localpathlist.GetNext(pos);
//  		filename=pPath->localpath.AllocSysString();
//  		Image image(filename);
//  		int width=image.GetWidth();
//  		int height=image.GetHeight();
//   		graphics.DrawImage(&image,x,y,200,height/(width/200));
// // 		
// // 
// // 		
//  		CRect rect;
//  		pView->GetClientRect(&rect);
//  		x+=300;
// 		if(x+200>rect.right)
// 		{
// 			x=100;
// 			y+=300;
// 		}
// 		
// // 		
// // 		
// // 	}
// 	//	p->cs.Unlock();
// 	return 0;
// }

void CThumbnailView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
//	pDC->SetMapMode(MM_TEXT);
	CPoint	pt=GetScrollPosition(); 
	pDC->SetViewportOrg(pt);
	CScrollView::OnPrepareDC(pDC, pInfo);
}





















void CThumbnailView::OnSize(UINT nType, int cx, int cy) 
{
	CScrollView::OnSize(nType, cx, cy);
	if (nType==SIZE_MAXIMIZED)
	{
	}
	if (nType==SIZE_MINIMIZED)
	{
	}
	if (nType==SIZE_RESTORED)
	{
	}
	if (nType==SIZE_MAXHIDE)
	{
	}
	if (nType==SIZE_MAXSHOW)
	{

	}
 //	CSize sizeTotal;
// 	sizeTotal.cx = cx;
// 	sizeTotal.cy = 20000;
// 		SetScrollSizes(MM_TEXT, sizeTotal);
//	CalcWindowRect(&sizeTotal);
	// TODO: Add your message handler code here

// 		m_nWidth = cx;
// 		m_nHeight = 20000;
// 
// 	if(m_pDCMem != NULL) {
// 		m_pDCMem->SelectObject(m_pBmpOldCanvas);
// 		m_pDCMem->DeleteDC();
// 		m_pBmpCanvas->DeleteObject();
// 
// 		delete m_pDCMem;
// 		m_pDCMem = NULL;
// 		delete m_pBmpCanvas;
// 		m_pBmpCanvas = NULL;
// 		m_pBmpOldCanvas = NULL;
// 	}
// 	
// 
// 	m_pDCMem = new CDC();
// 	m_pDCMem->CreateCompatibleDC(GetDC());
// 	
// 
// 
// 	m_pBmpCanvas = new CBitmap();
// 	m_pBmpCanvas->CreateCompatibleBitmap(GetDC(), m_nWidth, m_nHeight);
// 
// 	m_pBmpOldCanvas = (CBitmap*)m_pDCMem->SelectObject(m_pBmpCanvas);
// 	m_pDCMem->FillSolidRect(0,0,cx,20000,RGB(255,255,255));
	

// 	m_nWidth=200;
// 	m_nHeight=200;
// 	srand(GetTickCount());
// 	
// 	for (int i=0;i<100;i++)
// 	{
// 		if (pDCMem[i]!=NULL)
// 		{
// 			pDCMem[i]->SelectObject(pBmpOldCanvas[i]);
// 			pDCMem[i]->DeleteDC();
// 			pBmpCanvas[i]->DeleteObject();
// 
// 			delete pDCMem[i];
// 			pDCMem[i]=NULL;
// 			delete pBmpCanvas[i];
// 			pBmpCanvas[i]=NULL;
// 			pBmpOldCanvas[i]=NULL;
// 
// 		}
// 
// 		pDCMem[i]=new CDC();
// 		pDCMem[i]->CreateCompatibleDC(GetDC());
// 
// 		pBmpCanvas[i]=new CBitmap();
// 		pBmpCanvas[i]->CreateCompatibleBitmap(GetDC(),m_nWidth,m_nWidth);
// 
// 		pBmpOldCanvas[i]=(CBitmap*)pDCMem[i]->SelectObject(pBmpCanvas[i]);
// 		pDCMem[i]->FillSolidRect(0,0,m_nWidth,m_nHeight,RGB(rand()%255,rand()%255,rand()%255));
// 		
// 	}
	
}

int CThumbnailView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}

BOOL CThumbnailView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
// 	CRect rect;
// 	GetClientRect(&rect);
// 
// 	m_nWidth = rect.right;
// 	m_nHeight = 20000;
// 	
// 	if(m_pDCMem != NULL) {
// 		m_pDCMem->SelectObject(m_pBmpOldCanvas);
// 		m_pDCMem->DeleteDC();
// 		m_pBmpCanvas->DeleteObject();
// 		
// 		delete m_pDCMem;
// 		m_pDCMem = NULL;
// 		delete m_pBmpCanvas;
// 		m_pBmpCanvas = NULL;
// 		m_pBmpOldCanvas = NULL;
// 	}
// 	
// 	
// 	m_pDCMem = new CDC();
// 	m_pDCMem->CreateCompatibleDC(GetDC());
// 	
// 	
// 	
// 	m_pBmpCanvas = new CBitmap();
// 	m_pBmpCanvas->CreateCompatibleBitmap(GetDC(), m_nWidth, m_nHeight);
// 	
// 	m_pBmpOldCanvas = (CBitmap*)m_pDCMem->SelectObject(m_pBmpCanvas);
// 	m_pDCMem->FillSolidRect(0,0,rect.right,20000,RGB(255,255,255));
//	return false;
	return CScrollView::OnEraseBkgnd(pDC);
}

void CThumbnailView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	
}

void CThumbnailView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
//	CDC * pDC =GetDC();
// 	point =pDC->GetDeviceScollPosition();
// 	pDC->SetViewportOrg(point);
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.DPtoLP(&point);

	CRect rect;
	GetClientRect(&rect);
	int lie=rect.right/300;
	int m=point.x/300;
	int n=point.x%300;
	int p=point.y/300;
	int q=(point.y)%300;
	int npos;
	if (m==lie)
	{
		return;
	}
	if (n>100&&q>100)
	{
		npos=p*lie+m;
	}
	else
	{
		return;
	}
	CString name;
	name.Format("%d",npos);
	transpath=strExePath+"\\"+name;
	
	if ((_access( transpath+".jpg", 0 )) != -1)
	{
		transpath=transpath+".jpg";
		Image image(transpath.AllocSysString());
		nWidth=image.GetWidth()+6;
		nHeight=image.GetHeight()+32;
		CMyDialog dlg;
		dlg.DoModal();
		

	}else
	if ((_access( transpath+".bmp", 0 )) != -1)
	{
		transpath=transpath+".bmp";
		Image image(transpath.AllocSysString());
		nWidth=image.GetWidth()+6;
		nHeight=image.GetHeight()+32;

		CMyDialog dlg;
		dlg.DoModal();

	}else
	if ((_access( transpath+".ico", 0 )) != -1)
	{
		transpath=transpath+".ico";
		Image image(transpath.AllocSysString());
		nWidth=image.GetWidth()+6;
		nHeight=image.GetHeight()+32;
		CMyDialog dlg;
		dlg.DoModal();
	}
	else
	if ((_access( transpath+".gif", 0 )) != -1)
	{
		transpath=transpath+".gif";
		Image image(transpath.AllocSysString());
		nWidth=image.GetWidth()+6;
		nHeight=image.GetHeight()+32;

		CMyDialog dlg;
		dlg.DoModal();
//		AfxBeginThread(display,NULL);
	}
	else
	if ((_access( transpath+".png", 0 )) != -1)
	{
		transpath=transpath+".png";
		Image image(transpath.AllocSysString());
		nWidth=image.GetWidth()+6;
		nHeight=image.GetHeight()+32;
		
		CMyDialog dlg;
		dlg.DoModal();
	}else
	{
		AfxMessageBox("文件不存在");
	}

	CScrollView::OnLButtonUp(nFlags, point);
}

BOOL CThumbnailView::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CScrollView::PreCreateWindow(cs);
}

// UINT display(LPVOID pParam)
// {
// 	CMyDialog dlg;
// 		dlg.DoModal();
// 		return 0;
// }