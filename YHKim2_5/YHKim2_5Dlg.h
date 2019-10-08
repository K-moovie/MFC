
// YHKim2_5Dlg.h: 헤더 파일
//

#pragma once


// CYHKim25Dlg 대화 상자
class CYHKim25Dlg : public CDialogEx
{
// 생성입니다.
public:
	CYHKim25Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YHKIM2_5_DIALOG };
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
	int m_start;
	int m_result;
	int m_end;
	BOOL m_even;
	BOOL m_odd;
	afx_msg void OnBnClickedButton1();
};
