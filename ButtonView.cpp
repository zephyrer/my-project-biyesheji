// ButtonView.cpp : implementation file
//


#include "stdafx.h"
#include <math.h>
#include "Wanderer.h"
#include "ButtonView.h"
#include "MainFrm.h"
#include "WandererDoc.h"
#include "MyEditView.h"
#include "SocketForHttp.h"

#include "ThumbnailView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CCriticalSection cs;
CString strRequest;
CString strwebpath;
//struct path temp;
/*list<path> pathlist;*/
// CString g_strExePath;

//int x=100;
//int y=100;
/////////////////////////////////////////////////////////////////////////////
// CButtonView

IMPLEMENT_DYNCREATE(CButtonView, CView)

CButtonView::CButtonView()
{
	
}

CButtonView::~CButtonView()
{
}


BEGIN_MESSAGE_MAP(CButtonView, CView)
	//{{AFX_MSG_MAP(CButtonView)
	ON_WM_CREATE()
	ON_BN_CLICKED(1,OnButtonClicked)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CButtonView drawing

void CButtonView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
//	CMainFrame   *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd; 
//	CButtonView   *pView=(CButtonView *)pMain->GetActiveView();
//	CButtonView   *pView=(CButtonView *)pMain->GetActiveWindow();
// 	CButtonView* pView=this;
// 	CRect rect;
// 	pView->GetClientRect(&rect);
// 	myButton.MoveWindow(rect);

}

/////////////////////////////////////////////////////////////////////////////
// CButtonView diagnostics

#ifdef _DEBUG
void CButtonView::AssertValid() const
{
	CView::AssertValid();
}

void CButtonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CButtonView message handlers

int CButtonView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here

	CRect rect(0,0,100,40);
	myButton.Create(_T("go"),WS_CHILD|WS_VISIBLE|BS_CENTER,rect,this,1);
	return 0;
}



//获取其他视图的指针
CView* CButtonView::GetView(CRuntimeClass* pClass)
{
	CWandererDoc* pDoc=(CWandererDoc*)GetDocument();
	CView* pView;
	POSITION pos=pDoc->GetFirstViewPosition();
	while(pos!=NULL)
	{
		pView=pDoc->GetNextView(pos);
		if (pView->IsKindOf(pClass))
		{
			break;
		}else
		{
			AfxMessageBox("can not iocate the view");
			return NULL;
		}
	}
	return pView;
}


void CButtonView::OnButtonClicked()
{
	DeleteDir(strExePath);
	CMainFrame   *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	CMyEditView   *pView=(CMyEditView*)pMain->m_wndSplitter1.GetPane(0,0);
//	CThumbnailView   *pThunmbnailView=(CThumbnailView*)pMain->m_wndSplitter2.GetPane(0,1);
	CThumbnailView   *pThunmbnailView=(CThumbnailView*)pMain->m_wndSplitter.GetPane(1,0);
	pView->myEdit.SetReadOnly(TRUE);
	int len=pView->myEdit.LineLength();
	pView->myEdit.GetLine(0,strRequest.GetBuffer(len),len);
	strRequest.ReleaseBuffer(len);
	pView->myEdit.SetReadOnly(FALSE);



	if (strRequest.IsEmpty())
	{
		AfxMessageBox(_T("请输入网址！"));
		return;
	}

	int pos = strRequest.ReverseFind('/');
	strwebpath=strRequest.Left(pos);



// 	char chpath[500];
// 	GetModuleFileName(NULL,chpath,500);	
// 	g_strExePath.Format("%s",chpath);
// 	int nPos=g_strExePath.ReverseFind('\\');
// 	g_strExePath=g_strExePath.Left(nPos+1);

//	CreateThread(NULL, 0, DownlaodFileWithSocket, (PVOID)pThunmbnailView, 0, NULL);

//	DownlaodFileWithSocket(this);
	AfxBeginThread(DownlaodFileWithSocket,pThunmbnailView);


// 	POSITION posweb,poslocal;
// 	CStringList webpathlist;
// 	webpathlist.AddTail("http://t03.pic.sogou.com/c9d9f723efd19282.jpg");
// 	webpathlist.AddTail("http://t04.pic.sogou.com/42b5630a6d59b1c7.jpg");
// 	webpathlist.AddTail("http://t01.pic.sogou.com/c5adfc20e08a84fc.jpg");
// 	webpathlist.AddTail("http://t03.pic.sogou.com/87f898f51343f3e6.jpg");
// 	webpathlist.AddTail("http://t03.pic.sogou.com/db4367ad1a3baab6.jpg");
// 	webpathlist.AddTail("http://t01.pic.sogou.com/116f58b75aaa6ee8.jpg");
// 	webpathlist.AddTail("http://t01.pic.sogou.com/bc324d02e9f4584c.jpg");
// 	webpathlist.AddTail("http://t04.pic.sogou.com/04416e9c22011aef.jpg");
// 	webpathlist.AddTail("http://t01.pic.sogou.com/0b207c8110e26c20.jpg");
// 	webpathlist.AddTail("http://t01.pic.sogou.com/e25a6eb0bf87d9c0.jpg");
// 	webpathlist.AddTail("http://t03.pic.sogou.com/e5f3d8ff4aa4818a.jpg");
// 	webpathlist.AddTail("http://t04.pic.sogou.com/0827f88b9b3ce54f.jpg");
// 	CStringList localpathlist;
// 	localpathlist.AddTail(g_strExePath+"1.jpg");
// 	localpathlist.AddTail(g_strExePath+"2.jpg");
// 	localpathlist.AddTail(g_strExePath+"3.jpg");
// 	localpathlist.AddTail(g_strExePath+"4.jpg");
// 	localpathlist.AddTail(g_strExePath+"5.jpg");
// 	localpathlist.AddTail(g_strExePath+"6.jpg");
// 	localpathlist.AddTail(g_strExePath+"7.jpg");
// 	localpathlist.AddTail(g_strExePath+"8.jpg");
// 	localpathlist.AddTail(g_strExePath+"9.jpg");
// 	localpathlist.AddTail(g_strExePath+"10.jpg");
// 	localpathlist.AddTail(g_strExePath+"11.jpg");
// 	localpathlist.AddTail(g_strExePath+"12.jpg");
// 	posweb=webpathlist.GetHeadPosition();
// 	poslocal=localpathlist.GetHeadPosition();
// 	int i=0;
// 	while (posweb!=0)
// 	{
// 		temppath[i].webpath=webpathlist.GetNext(posweb);
// 		temppath[i].localpath=localpathlist.GetNext(poslocal);
// 		AfxBeginThread(DownlaodFile,&temppath[i]);
// 		++i;
// 	}

}

UINT DownlaodFileWithSocket(LPVOID pParam)
{
	CThumbnailView* pThumbnailview=(CThumbnailView*)pParam;
	CSocketForHttp socketForHttp;
	CString strServer,strObject;
	unsigned short nPort;
	DWORD dwServiceType;
	long nLength;
	const char *pRequestHeader=NULL;

	TRACE("url %s",strRequest);
	bool bVaild=AfxParseURL(strRequest,dwServiceType,strServer,strObject,nPort);
	if (!bVaild)
	{
		AfxMessageBox("网址不正确");
		return 0;
	}
	pRequestHeader=socketForHttp.FormatRequestHeader((LPTSTR)(LPCTSTR)strServer,(LPTSTR)(LPCTSTR)strObject,nLength);
	socketForHttp.Socket();
	if (!socketForHttp.Connect((LPTSTR)(LPCTSTR)strServer))
	{
		return 0;
	}
	
	socketForHttp.SendRequest();
	socketForHttp.SetTimeout(10000,0);

//  	int n;
// 	char * request;
// 	request=(char*)malloc(2048);
// 	memset(request,0,2048);
// 	socketForHttp.GetRequestHeader(request,2048);
// 	TRACE("request %s",request);
// 	const char * response=socketForHttp.GetResponseHeader(n);
// 	TRACE("response %s",response);

	char szType[30];
	socketForHttp.GetField("Content-Type",szType,30);
	CString strType=szType;


	int nSvrState=socketForHttp.GetServerState();
	TRACE("state %d",nSvrState);
	if (nSvrState==404)
	{
		socketForHttp.CloseSocket();
		AfxMessageBox("图片不存在");
		return 0;
	}
	if (nSvrState==302)
	{
		char szLocation[512];
		socketForHttp.GetField("Location",szLocation,512);
		CString location =szLocation;
		if (location.Find("http",0)!=-1)
		{	
			strRequest=location;
		}
		else
		{
			int pos = strRequest.ReverseFind('/');
			strRequest=strRequest.Left(pos+1);
			strRequest=strRequest+location;
		}
		
		socketForHttp.CloseSocket();
		UINT nReturn=DownlaodFileWithSocket(pThumbnailview);
		TRACE("nReturn %d",nReturn);
		return nReturn;
// 		AfxBeginThread(DownlaodFileWithSocket,NULL);
// 		return 0;
		
	}
	if (nSvrState==204)
	{
		socketForHttp.CloseSocket();
		AfxMessageBox("图片不存在");
		return 0;
	}

	char szLength[30];
	int nback=socketForHttp.GetField("Content-Length",szLength,30);


	
	char pData[1024*9+1];
	pData[1024*9]=0;

	if (nback==-1)
	{
		CFile fDownload;
		
		fDownload.Open(_T(strExePath+"\\"+"chunk.html"),CFile::modeCreate|CFile::modeReadWrite);
		int nReceSize=1;
		while (nReceSize!=0&&nReceSize!=-1)
		{
			memset(pData,0,1024*9);
			nReceSize=socketForHttp.Receive(pData,1024*9);
			if (nReceSize==0)
			{
				TRACE("complete");
				break;
			}
			if (nReceSize==-1)
			{
				AfxMessageBox("接受数据超时");
				break;
			}
			try
			{
				TRACE("aaaaaaa %d",nReceSize);
				fDownload.Write(pData,nReceSize);
				fDownload.Flush();			
			}
			catch (CMemoryException* e)
			{
				char error[1024];
				e->GetErrorMessage(error,1024);
			}
			catch (CFileException* e)
			{
				char error[1024];
				e->GetErrorMessage(error,1024);
			}
			catch (CException* e)
			{/////////
				char error[1024];
				e->GetErrorMessage(error,1024);
			}

			
			CString temp=pData;
			if (temp.Find("\r\n0\r\n\r\n",0)!=-1)
			{
				break;
			}
			
// 			if (strstr(pData,"\r\n0\r\n\r\n")!=NULL)
// 			{
// 				break;
// 			}
		}
		fDownload.Close();
		parseChunk();
	}
	else
	{
		CFile fDownload;
		
		fDownload.Open(_T(strExePath+"\\"+"first.html"),CFile::modeCreate|CFile::modeReadWrite);

		int nCompletedSize=0;
		int nReceSize=0;
		int nFileSize=atoi(szLength);
		while (nCompletedSize<nFileSize)
		{
			memset(pData,0,1024*9);
			nReceSize=socketForHttp.Receive(pData,1024*9);
			if (nReceSize==0)
			{
				AfxMessageBox("服务器已经关闭连接");
				break;
			}
			if (nReceSize==-1)
			{
				AfxMessageBox("接受数据出错");
				break;
			}
			try
			{
				TRACE("data %d",nReceSize);
				DWORD pos=fDownload.GetPosition();
				TRACE("position %d",pos);
				fDownload.Write(pData,nReceSize);
				fDownload.Flush();
			}
			catch (CMemoryException* e)
			{
			}
			catch (CFileException* e)
			{
			}
			catch (CException* e)
			{
			}
			
			nCompletedSize+=nReceSize;
 		}	
		fDownload.Close();
	}
	
	
	ParseImageUrl(pThumbnailview);
	return 0;

}

void parseChunk()
{
	CFile f;
	f.Open("D:\\mfc\\Wanderer\\Debug\\cache\\chunk.html",CFile::modeReadWrite);
	char * pbuf;
	DWORD dwFileLen;
	dwFileLen=f.GetLength();
	pbuf=new char[dwFileLen+1];
	pbuf[dwFileLen]=0;
	f.Read(pbuf,dwFileLen);
	
	CFile fParse;
	fParse.Open("D:\\mfc\\Wanderer\\Debug\\cache\\first.html",CFile::modeCreate|CFile::modeWrite);
	
	char * pStart=pbuf;
	char * pTemp;
//	char* hex;
	
chunk:
	pTemp=strstr(pStart,"\r\n");
	int nBytes=0;
	int len=pTemp-pStart;
	char* hex=new char[len+1];
	hex[len]=0;
	strncpy(hex,pStart,len);
	pStart=pTemp+2;
	
	int hexSize=strlen(hex);
	
	for (int i=0;i<len;i++)
	{
		if (hex[i]>='0'&&hex[i]<='9')
		{
			nBytes+=(hex[i]-'0')*pow(16,((hexSize--)-1));
		}
		if (hex[i]>='a'&&hex[i]<='z')
		{
			nBytes+=(hex[i]-'a'+10)*pow(16,((hexSize--)-1));
		}
		if (hex[i]>='A'&&hex[i]<='Z')
		{
			nBytes+=(hex[i]-'A'+10)*pow(16,((hexSize--)-1));
		}
	}
	delete[] hex;
	TRACE("size %d",nBytes);
	if (nBytes==0)
	{
		delete[] pbuf;
		fParse.Close();
	}else
	{
		fParse.Write(pStart,nBytes);
		pStart=pStart+nBytes+2;
		fParse.Flush();
		goto chunk;
	}
}
UINT ParseImageUrl(LPVOID pParam)
{
	CThumbnailView* pThumbnailview=(CThumbnailView*)pParam;
	//	WaitForSingleObject(p->eventParseImageUrl.m_hObject,INFINITE);
	CFile fHtml;
	fHtml.Open(_T(strExePath+"\\"+"first.html"),CFile::modeRead,NULL);
	char * pbuf;
	DWORD dwFileLen;
	dwFileLen=fHtml.GetLength();
	pbuf=new char[dwFileLen+1];
	pbuf[dwFileLen]=0;
	fHtml.Read(pbuf,dwFileLen);
	CString sFileData=pbuf;
	delete[] pbuf;

	CStringList webpathlist;
	int nCount=0;
	int bpos,epos;
	int elementpos=sFileData.Find("<img",0);
	int elementepos;
	while(elementpos!=-1)
	{
		elementepos=sFileData.Find(">",elementpos);
		bpos=sFileData.Find("src=\"",elementpos);
		if (bpos!=-1&&bpos<elementepos)
		{
			epos=sFileData.Find("\"",bpos+5);
		}else
		{
			bpos=sFileData.Find("src='",elementpos);
			if (bpos!=-1&&bpos<elementepos)
			{
				epos=sFileData.Find("'",bpos+5);
			}
			else
			{
				elementpos=sFileData.Find("<img",elementepos+1);
				continue;
			}
			
		}
		
		CString strPath=sFileData.Mid(bpos+5,epos-bpos-5);
		if (strPath.Left(4)!="http")
		{		
			if (strPath.Left(1)=="/")
			{
				strPath=strwebpath+strPath;
			}
			else
			{
				strPath=strwebpath+"/"+strPath;
			}
		}
		webpathlist.AddTail(strPath);
		TRACE("----- %s",strPath);
		++nCount;
		elementpos=sFileData.Find("<img",elementepos+1);
	}

	pThumbnailview->nCount=nCount;


	g_pMemDC=new CDC*[nCount];
	g_pBmpCanvas=new CBitmap*[nCount];
	g_pBmpOldCanvas=new CBitmap*[nCount];
	for (int j=0;j<nCount;j++)
	{
		g_pMemDC[j]=NULL;
		g_pBmpCanvas[j]=NULL;
		g_pBmpOldCanvas[j]=NULL;
	}
	for (int i=0;i<nCount;i++)
	{
// 		if (g_pMemDC[i]!=NULL)
// 		{
// 			g_pMemDC[i]->SelectObject(g_pBmpOldCanvas[i]);
// 			g_pMemDC[i]->DeleteDC();
// 			g_pBmpCanvas[i]->DeleteObject();
// 			
// 			delete g_pMemDC[i];
// 			g_pMemDC[i]=NULL;
// 			delete g_pBmpCanvas[i];
// 			g_pBmpCanvas[i]=NULL;
// 			g_pBmpOldCanvas[i]=NULL;
// 			
// 		}

		g_pMemDC[i]=new CDC();
		g_pMemDC[i]->CreateCompatibleDC(pThumbnailview->GetDC());
		
		g_pBmpCanvas[i]=new CBitmap();
		g_pBmpCanvas[i]->CreateCompatibleBitmap(pThumbnailview->GetDC(),200,200);

		
		g_pBmpOldCanvas[i]=(CBitmap*)g_pMemDC[i]->SelectObject(g_pBmpCanvas[i]);
		g_pMemDC[i]->FillSolidRect(0,0,200,200,RGB(rand()%255,rand()%255,rand()%255));
	}
	
	CEvent * eventone=new CEvent[nCount];
	POSITION npos=webpathlist.GetHeadPosition();
	struct path *temppath;
	temppath=new struct path[nCount];
	for (int n=0;n<nCount;n++)
	{
		CString tempwebpath=webpathlist.GetNext(npos);
		CString strCount;
		strCount.Format("%d",n);		
		temppath[n].x=0;
		temppath[n].y=0;
		temppath[n].pView=pThumbnailview;
		temppath[n].nNumber=n;
		temppath[n].webpath=tempwebpath;
		temppath[n].localpath=strExePath+"\\"+strCount;
		temppath[n].ce=&eventone[n];
		AfxBeginThread(DownlaodFile,&temppath[n]);
	}
	for (int x=0;x<nCount;x++)
	{
		WaitForSingleObject(eventone[x],INFINITE);
	}
// 	for (int m=0;m<nCount;m++)
// 	{
// 		g_pMemDC[m]->SelectObject(g_pBmpOldCanvas[m]);
// 		g_pMemDC[m]->DeleteDC();
// 		g_pBmpCanvas[m]->DeleteObject();
// 		delete[] g_pMemDC[m];
// 		delete[] g_pBmpCanvas[m];
// //		delete[] g_pBmpOldCanvas[m];
// 	}
// 	delete[] g_pMemDC;
// 	delete[] g_pBmpCanvas;
// 	delete[] g_pBmpOldCanvas;
	delete[] eventone;
	delete[] temppath;
	nCount=0;
	return 0;
}


UINT DownlaodFile(LPVOID pParam)
{

	path* pPath=(path*)pParam;
	CSocketForHttp socketForHttp;
	CString strServer,strObject;
	unsigned short nPort;
	DWORD dwServiceType;
	long nLength;
	const char *pRequestHeader=NULL;


//	TRACE("----- %s",pPath->webpath);
	AfxParseURL(pPath->webpath,dwServiceType,strServer,strObject,nPort);
	pRequestHeader=socketForHttp.FormatRequestHeaderWithHead((LPTSTR)(LPCTSTR)strServer,(LPTSTR)(LPCTSTR)strObject,nLength);
	socketForHttp.Socket();
	if (!socketForHttp.Connect((LPTSTR)(LPCTSTR)strServer))
	{
		return 0;
	}
	socketForHttp.SendRequest();
	socketForHttp.SetTimeout(10000,0);

	int nSvrState=socketForHttp.GetServerState();
	if (nSvrState==302)
	{
		char szLocation[100];
		socketForHttp.GetField("Location",szLocation,100);
		CString location =szLocation;
		if (location.Find("http",0)!=-1)
		{	
			pPath->webpath=location;
		}
		else
		{
			int pos = pPath->webpath.ReverseFind('/');
			pPath->webpath=pPath->webpath.Left(pos+1);
			pPath->webpath=pPath->webpath+location;
		}

		
		socketForHttp.CloseSocket();
		DownlaodFile(pPath);
		return 0;

	}
	if (nSvrState==404)
	{
		socketForHttp.CloseSocket();
		return 0;
	}

	if (nSvrState==204)
	{
		socketForHttp.CloseSocket();
		return 0;
	}
	char szLength[30];
	socketForHttp.GetField("Content-Length",szLength,30);
	int nFileSize=atoi(szLength);
	if (nFileSize==0)
	{
		socketForHttp.CloseSocket();
		return 0;
	}
	char szType[30];
	socketForHttp.GetField("Content-Type",szType,30);
	CString strType=szType;
	

	int nnpos=strType.Find(";",0);
	if (nnpos!=-1)
	{
		int npos=strType.Find("image",0);
		strType=strType.Mid(npos,nnpos-npos);
	}
	

	TRACE("***** %s %s",pPath->webpath,strType);
	if (strType=="image/jpeg")
	{
		strType=".jpg";
	} 
	else if(strType=="image/gif")
	{
		strType=".gif";
	}
	else if (strType=="image/png"||strType=="application/x-png")
	{
		strType=".png";
	} 
	else if(strType=="image/x-icon"||strType=="application/x-ico")
	{
		strType=".ico";
	}
	else if(strType=="image/fax")
	{
		strType=".fax";
	} 
	else if(strType=="image/vnd.wap.wbmp")
	{
		strType=".wbmp";
	}
	else if (strType=="image/tiff"||strType=="application/x-tif")
	{
		strType=".tif";
	}
	else if (strType=="image/vnd.rn-realpix")
	{
		strType=".rp";
	}
	else if (strType=="image/pnetvue")
	{
		strType=".net";
	}
	else
	{
		return 0;
	}
	pPath->localpath=pPath->localpath+strType;

	
	
	
// 	CFile fDownload;
// 	
// 	TRACE("@@@@@ %s",pPath->localpath);
// 	fDownload.Open(pPath->localpath,CFile::modeCreate|CFile::modeReadWrite);
// 
// 	char* filedata;
// 	filedata=(char*)malloc(nFileSize);
// 	memset(filedata,0,nFileSize);
// 
// 	int nCompletedSize=0;
// 	char pData[1024*2];
// 	int nReceSize=0;
// 	
// 	while (nCompletedSize<nFileSize)
// 	{
// 		memset(pData,0,1024*2);
// 		nReceSize=socketForHttp.Receive(pData,1024*2);
// 		if (nReceSize==0)
// 		{
// 			AfxMessageBox("服务器已经关闭连接");
// 				break;
// 		}
// 		if (nReceSize==-1)
// 		{
// 			AfxMessageBox("接受数据出错");
// 			break;
// 		}
// // 		try
// // 		{
// // 			TRACE("######### %d %d\r\n",pPath->nNumber,nReceSize);
// // 			fDownload.Write(pData,nReceSize);
// // 			fDownload.Flush();
// // 		}
// // 		catch (CMemoryException* e)
// // 		{
// // 		}
// // 		catch (CFileException* e)
// // 		{
// // 		}
// // 		catch (CException* e)
// // 		{
// // 		}
// 		TRACE("######### %d %d\r\n",pPath->nNumber,nReceSize);
// 		memcpy(filedata+nCompletedSize,pData,nReceSize);
// 		
// 		nCompletedSize+=nReceSize;
//  	}	
// 	fDownload.Write(filedata,nFileSize);
// 	free(filedata);
// 	fDownload.Close();
	
	TRACE("start %d %s %s",pPath->nNumber,pPath->localpath,pPath->webpath);
	int ncount=nFileSize/64/1024+1;

	CFile f;
	
	f.Open(pPath->localpath,CFile::modeCreate|CFile::modeReadWrite);
	
	
	char** data;
	CEvent *cevent;
	struct downloadparam *param;
	data=new char*[ncount];
	cevent=new CEvent[ncount];
	param=new struct downloadparam[ncount];
	for (int i=0;i<ncount;i++)
	{
		param[i].webpath=pPath->webpath;
		param[i].from=i*64*1024;
		param[i].to=(i+1)*64*1024-1;
		if (param[i].to>(nFileSize-1))
		{
			param[i].to=nFileSize-1;
		}
		param[i].n=i;
		param[i].len=param[i].to-param[i].from+1;
		param[i].e=&cevent[i];
		
		data[i]=new char[param[i].len+1];
		data[i][param[i].len]=0;
		param[i].temp=data[i];

		TRACE("##### %d %d %s",param[i].from,param[i].to,param[i].webpath);

		AfxBeginThread(MTDownLoad,&param[i]);
		
	}
	for (int m=0;m<ncount;m++)
	{
		WaitForSingleObject(cevent[m],INFINITE);
	}

	for (int l=0;l<ncount;l++)
	{
		f.Write(data[l],param[l].len);
		delete[] data[l];
	}
	TRACE("end %d",pPath->nNumber);
	f.Close();
	delete[] cevent;
	delete[] param;
	delete[] data;

	OnDrawThumbnailOne(pPath);
	pPath->ce->SetEvent();
	return 0;

}




UINT OnDrawThumbnailOne(LPVOID pParam)
{
// 	cs.Lock();
// 	path* pPath=(path*)pParam;
// 
// 	
// 	CDC* pDC=pPath->pView->m_pDCMem;
// 
// 	Graphics graphics(pDC->m_hDC);
// 
// 	
// 	wchar_t * filename;
// 
// 	filename=pPath->localpath.AllocSysString();
// 	Image image(filename);
// 
// 	int width=image.GetWidth();
// 	int height=image.GetHeight();
// 	CRect rect;
// 	pPath->pView->GetClientRect(&rect);
// 	int n=rect.right/300;
// 	int m=(pPath->nNumber+1)%n;
// 	if(m==0)
// 	{
// 		pPath->x=100+300*(n-1);
// 		pPath->y=100+300*((pPath->nNumber+1)/n-1);
// 	}else
// 	{
// 		pPath->x=100+300*(m-1);
// 		pPath->y=100+300*((pPath->nNumber+1)/n);
// 	}
// 	graphics.DrawImage(&image,pPath->x,pPath->y,200,200);
// 	cs.Unlock();
// 	pPath->pView->Invalidate();


	path* pPath=(path*)pParam;

//	CDC* pDC=pPath->pView->pDCMem[pPath->nNumber];
	CDC* pDC=g_pMemDC[pPath->nNumber];


	Graphics graphics(pDC->m_hDC);

	wchar_t * filename;

	filename=pPath->localpath.AllocSysString();

	Image image(filename);

	int width=image.GetWidth();
	int height=image.GetHeight();
	TRACE("yuanlai %d %d",width,height);
	if (width/height>=1)
	{
		if (width>200)
		{		
			height=height*200/width;
			width=200;
		}
	}
	else
	{
		if (height>200)
		{	
			width=width*200/height;
			height=200;
		}
	}
	
	TRACE("widthheight %d %d",width,height);

// 	if (pPath->localpath.Find(".gif")!=-1)
// 	{
// 		UINT count=0;
// 		count=image.GetFrameDimensionsCount();
// 		GUID *pDimensionIDs=(GUID*)new GUID[count];
// 		image.GetFrameDimensionsList(pDimensionIDs,count);
// 		wchar_t strGuid[39];
// 		StringFromGUID2(pDimensionIDs[0],strGuid,39);
// 		UINT frameCount=image.GetFrameCount(&pDimensionIDs[0]);
// 		delete []pDimensionIDs;
// 		if (frameCount==1)
// 		{
// 			Status s = graphics.DrawImage(&image,0,0,width,height);
// 		}
// 		else
// 		{
// 			UINT sizeone;
// 			UINT totalsize;
// 			image.GetPropertySize(&totalsize,&sizeone);
// 			UINT itemsize=image.GetPropertyItemSize(PropertyTagFrameDelay);
// 			PropertyItem* pItem=NULL;
// 			pItem=(PropertyItem*)malloc(itemsize);
// 			image.GetPropertyItem(PropertyTagFrameDelay,itemsize,pItem);
// 			int fcount=0;
// 			GUID Guid=FrameDimensionTime;
// 			while(TRUE)
// 			{
// 				Status s =graphics.DrawImage(&image,0,0,width,height);
// 				TRACE("Status %d",s);
// 				image.SelectActiveFrame(&Guid,fcount++);
// 				if (fcount==frameCount)
// 				{
// 					fcount=0;
// 				}
// 				long lpause =((long*)pItem->value)[fcount]*10;
// 				Sleep(lpause);
// 			}
// 
// 		}
// 		
// 	}
// 	else
// 	{
// 	 	
// 		Status s = graphics.DrawImage(&image,0,0,width,height);
// 		TRACE("Status %d",s);
// 
// 	}

	Status s = graphics.DrawImage(&image,0,0,width,height);
	TRACE("Status %d",s);

	





// 	CRect rect;
// 	pPath->pView->GetClientRect(&rect);
// 	int n=rect.right/300;
// 	int m=(pPath->nNumber+1)%n;
// 	if(m==0)
// 	{
// 		pPath->x=100+300*(n-1);
// 		pPath->y=100+300*((pPath->nNumber+1)/n-1);
// 	}else
// 	{
// 		pPath->x=100+300*(m-1);
// 		pPath->y=100+300*((pPath->nNumber+1)/n);
// 	}
// 	CSize sizeTotal;
// 	sizeTotal.cx = pPath->x+300;
// 		sizeTotal.cy = pPath->y+300;
// 	pPath->pView->SetScrollSizes(MM_TEXT,sizeTotal);

	pPath->pView->Invalidate();	

	return 0;
}

void CButtonView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CRect rect;
	GetClientRect(&rect);
 	myButton.MoveWindow(rect);
	
}

void CButtonView::DeleteDir(/*wchar_t* lpszDir*/ CString szDir)
{
	WIN32_FIND_DATA wfd;
	CString szFile;
	CString szDelDir;

	HANDLE hFindFile;
	BOOL bFind=TRUE;
	szDelDir=szDir;
	szFile=szDir+"\\*.*";
	char * cpath=NULL;
	wchar_t* wpath=szFile.AllocSysString();
	int nlength=wcslen(wpath);
	
	int nbytes=WideCharToMultiByte(0,0,wpath,nlength,NULL,0,NULL,NULL);
	cpath=(char*)malloc(nbytes+1);
	memset(cpath,0,nbytes+1);
	WideCharToMultiByte(0,0,wpath,nlength,cpath,nbytes,NULL,NULL);

	hFindFile=FindFirstFile(cpath,&wfd);
	
	if (INVALID_HANDLE_VALUE==hFindFile)
	{
		return;
	}
	if (strcmp(wfd.cFileName,".."))
	{
		bFind=FindNextFile(hFindFile,&wfd);
	}
	if (strcmp(wfd.cFileName,"..."))
	{
		bFind=FindNextFile(hFindFile,&wfd);
	}
	
	while (bFind)
	{
		szFile=szDir+"\\"+wfd.cFileName;
		if (wfd.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
		{
			DeleteDir(szFile);
		} 
		else
		{
			DeleteFile(szFile);
		}
		bFind=FindNextFile(hFindFile,&wfd);
	}
	FindClose(hFindFile);
	free(cpath);
}

UINT MTDownLoad(LPVOID pParam)
{
	downloadparam* p=(downloadparam*)pParam;
	CSocketForHttp socketForHttp;
	CString strServer,strObject;
	unsigned short nPort;
	DWORD dwServiceType;
	long nLength;
	const char *pRequestHeader=NULL;
	TRACE("webpath %s",p->webpath);
	long from=p->from;
	long to=p->to;
	TRACE("from %d",from);
	TRACE("to %d",to);
	AfxParseURL(p->webpath,dwServiceType,strServer,strObject,nPort);
	pRequestHeader=socketForHttp.FormatRequestHeader((LPTSTR)(LPCTSTR)strServer,(LPTSTR)(LPCTSTR)strObject,nLength,NULL,NULL,from,to,0);
	socketForHttp.Socket();
	if (!socketForHttp.Connect((LPTSTR)(LPCTSTR)strServer))
	{
		return 0;
	}
	socketForHttp.SendRequest();
	socketForHttp.SetTimeout(10000,0);
	
// 	int n;
// 	char * request;
// 	request=(char*)malloc(2048);
// 	memset(request,0,2048);
// 	socketForHttp.GetRequestHeader(request,2048);
// 	TRACE("request %s",request);
// 	const char * response=socketForHttp.GetResponseHeader(n);
// 	TRACE("response %s",response);
	
	int nSvrState=socketForHttp.GetServerState();
	
	int nFileSize=p->len;
	TRACE("***** %d",nFileSize);
	int nCompletedSize=0;
	
	
	
	// 	data[p->n]=(char*)malloc(nFileSize);
	// 	memset(data[p->n],0,nFileSize);
	//	data[p->n]=new char[nFileSize];
	
	
	char pData[2048];
	int nReceSize=0;
	while (nCompletedSize<nFileSize)
	{
		memset(pData,0,2048);
		nReceSize=socketForHttp.Receive(pData,2048);
		if (nReceSize==0)
		{
			AfxMessageBox("服务器已经关闭连接");
			break;
		}
		if (nReceSize==-1)
		{
			AfxMessageBox("接受数据超时");
			break;
		}
		TRACE("nReceSize %d %d",p->n,nReceSize);
		memcpy(p->temp+nCompletedSize,pData,nReceSize);
		nCompletedSize+=nReceSize;
	}	
	
	BOOL back=p->e->SetEvent();
	if (back)
	{
		TRACE("completed %d",p->n);
	}
	return 0;
	
}