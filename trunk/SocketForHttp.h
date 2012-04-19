// SocketForHttp.h: interface for the CSocketForHttp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOCKETFORHTTP_H__14CBF4DF_A74C_44A6_81A8_70F599BB0E84__INCLUDED_)
#define AFX_SOCKETFORHTTP_H__14CBF4DF_A74C_44A6_81A8_70F599BB0E84__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// #include <winsock.h>
// #include <afxinet.h>
// #include <afxsock.h>
class CSocketForHttp  
{
public:
	CSocketForHttp();
	virtual ~CSocketForHttp();
public:
	int				GetServerState();						//���ط�����״̬�� -1��ʾ���ɹ�
	int				GetField(const char* szSession,char *szValue,int nMaxLength);	//����ĳ����ֵ,-1��ʾ���ɹ�
	int				GetResponseLine(char *pLine,int nMaxLength);				//��ȡ����ͷ��һ��
	const char*		GetResponseHeader(int &Length);								//��ȡ�����ķ���ͷ
	const char *	FormatRequestHeader(char *pServer,char *pObject,long &Length,
		char* pCookie=NULL,char *pReferer=NULL,
		long nFrom=0,long nTo=0,
		int nServerType=0);									//��ʽ������ͷGet

	const char *	FormatRequestHeaderWithHead(char *pServer,char *pObject,long &Length,
		char* pCookie=NULL,char *pReferer=NULL,
		long nFrom=0,long nTo=0,
		int nServerType=0);									//��ʽ������ͷHead
	int				GetRequestHeader(char *pHeader,int nMaxLength) const;
	BOOL			SendRequest(const char* pRequestHeader = NULL,long Length = 0);
	
	BOOL			SetTimeout(int nTime,int nType=0);
	long			Receive(char* pBuffer,long nMaxLength);
	BOOL			Connect(char* szHostName,int nPort=80);
	BOOL			Socket();
	BOOL			CloseSocket();
	
protected:	
	char m_requestheader[2048];		//����ͷ
	char m_ResponseHeader[2048];	//��Ӧͷ
	int m_port;						//�˿�
	char m_ipaddr[256];				//IP��ַ
	BOOL m_bConnected;
	SOCKET m_s;
	hostent *m_phostent;
	
	int m_nCurIndex;				//GetResponsLine()�������α��¼
	BOOL m_bResponsed;				//�Ƿ��Ѿ�ȡ���˷���ͷ
	int m_nResponseHeaderSize;		//��Ӧͷ�Ĵ�С

};

#endif // !defined(AFX_SOCKETFORHTTP_H__14CBF4DF_A74C_44A6_81A8_70F599BB0E84__INCLUDED_)
