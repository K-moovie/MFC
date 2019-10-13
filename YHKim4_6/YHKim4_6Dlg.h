
// YHKim4_6Dlg.h: 헤더 파일
//

#pragma once


// CYHKim46Dlg 대화 상자
class CYHKim46Dlg : public CDialogEx
{
// 생성입니다.
public:
	CYHKim46Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YHKIM4_6_DIALOG };
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
	UINT m_editA;
	UINT m_editB;
	BOOL m_readyA;
	BOOL m_readyB;
	afx_msg void OnBnClickedButtStart();
	afx_msg void OnBnClickedButtReadyA();
	afx_msg void OnBnClickedButtSetA();
	afx_msg void OnBnClickedButtReadyB();
	afx_msg void OnBnClickedButtSetB();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
