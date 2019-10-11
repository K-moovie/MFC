
// YHKimEx3_1Dlg.h: 헤더 파일
//

#pragma once


// CYHKimEx31Dlg 대화 상자
class CYHKimEx31Dlg : public CDialogEx
{
// 생성입니다.
public:
	CYHKimEx31Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YHKIMEX3_1_DIALOG };
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
	afx_msg void OnBnClickedButtPaint();
	afx_msg void OnBnClickedButtClean();
	afx_msg void OnBnClickedButtExit();
	CString m_sx;
	CString m_sy;
	CString m_ex;
	CString m_ey;
	CString m_width;
	CString m_red;
	CString m_green;
//	CEdit m_blue;
	CString m_blue;
};
