#pragma once
#include "resource.h"

// CPowDlg 대화 상자

class AFX_EXT_CLASS CPowDlg : public CDialog
{
	DECLARE_DYNAMIC(CPowDlg)

public:
	CPowDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CPowDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POWDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_input;
	afx_msg void OnBnClickedButtResult();
};
