
// YHKimEx4_4Dlg.h: 헤더 파일
//

#pragma once


// CYHKimEx44Dlg 대화 상자
class CYHKimEx44Dlg : public CDialogEx
{
// 생성입니다.
public:
	CYHKimEx44Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YHKIMEX4_4_DIALOG };
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
	CComboBox m_ctlCombo;
	afx_msg void OnExit();
	afx_msg void OnCbnSelchangeCombo1();
	int x = 1;
};
