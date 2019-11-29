#pragma once
#include <afxsock.h>
class CMySocket :
	public CAsyncSocket
{
public:
	CMySocket();
	virtual ~CMySocket();
	void SetParent(CDialog* pWnd);
private:
	CDialog *m_pWnd;
public:
	virtual void OnAccept(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnSend(int nErrorCode);
};