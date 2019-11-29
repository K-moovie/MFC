
// NetworkDlg.h: 헤더 파일
//

#pragma once
#include "CMySocket.h"

// CNetworkDlg 대화 상자
class CNetworkDlg : public CDialogEx
{
// 생성입니다.
public:
	CNetworkDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NETWORK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	afx_msg void OnRType();
	static CMySocket m_Csocket;
	static CMySocket m_Ssocket;

	void OnAccept();
	void OnConnect();
	void OnClose();
	void OnReceive();
	void OnSend();

	afx_msg void OnBnClickedBlisten();
	afx_msg void OnBnClickedBdiscon();
	afx_msg void OnBnClickedBconnect();
	BOOL m_iType;
	long m_x1;
	long m_y1;
	long m_x2;
	long m_y2;
	int rCount;
	afx_msg void OnBnClickedBenter();
	int count;
	CPoint setPoint[2];
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
