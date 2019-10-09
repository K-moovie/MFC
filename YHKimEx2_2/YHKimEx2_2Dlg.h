
// YHKimEx2_2Dlg.h: 헤더 파일
//

#pragma once


// CYHKimEx22Dlg 대화 상자
class CYHKimEx22Dlg : public CDialogEx
{
// 생성입니다.
public:
	CYHKimEx22Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YHKIMEX2_2_DIALOG };
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
	afx_msg void OnBnClickedButtPlus();
	afx_msg void OnBnClickedButtSub();
	afx_msg void OnBnClickedButtMul();
	afx_msg void OnBnClickedButtDiv();
	afx_msg void OnBnClickedButtOk();
	afx_msg void OnBnClickedButtReset();
	int m_input;
	bool plus = FALSE;
	bool sub = FALSE;
	bool mul = FALSE;
	bool div = FALSE;
	int op1 = 0;
	int op2 = 0;
};
