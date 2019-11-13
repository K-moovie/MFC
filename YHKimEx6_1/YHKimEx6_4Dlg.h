
// YHKimEx6_4Dlg.h: 헤더 파일
//

#pragma once


// CYHKimEx64Dlg 대화 상자
class CYHKimEx64Dlg : public CDialogEx
{
// 생성입니다.
public:
	CYHKimEx64Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YHKIMEX6_4_DIALOG };
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
	CMySocket m_Csocket;
	CMySocket m_Ssocket;
	int m_iType;
	CString m_strName;
	afx_msg void OnRType();
	int m_iPaintType;
	void OnAccept();
	void OnConnect();
	void OnClose();
	void OnReceive();
	void OnSend();
	afx_msg void OnBnClickedBlisten();
	afx_msg void OnBnClickedBconnect();
	CString m_strMessage;
	CListBox m_ctlSent;
	CListBox m_ctlRecvd;
	afx_msg void OnBnClickedBsend();
};
