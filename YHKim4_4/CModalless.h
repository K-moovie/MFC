#pragma once


// CModalless 대화 상자

class CModalless : public CDialog
{
	DECLARE_DYNAMIC(CModalless)

public:
	CModalless(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CModalless();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MODALLESS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	int lineWidth;
	BOOL lineStyle;
};
