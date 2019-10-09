
// YHKimEx2_4Dlg.h: 헤더 파일
//

#pragma once


// CYHKimEx24Dlg 대화 상자
class CYHKimEx24Dlg : public CDialogEx
{
// 생성입니다.
public:
	CYHKimEx24Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YHKIMEX2_4_DIALOG };
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
	int sum = 0;
	BOOL m_1;
	BOOL m_2;
	BOOL m_3;
	BOOL m_4;
	CComboBox m_ctlCombo;
	afx_msg void OnBnClickedButtOk();
	afx_msg void OnCbnSelchangeCombo();
};
