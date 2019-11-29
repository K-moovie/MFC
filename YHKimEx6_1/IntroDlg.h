#pragma once


// IntroDlg 대화 상자

class IntroDlg : public CDialog
{
	DECLARE_DYNAMIC(IntroDlg)

public:
	IntroDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~IntroDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INTRO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	CFont theme_font;
	CBrush theme_brush;
	bool start_toggle;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnStnClickedStart();
};
