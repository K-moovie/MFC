
// YHKimTest4Dlg.h: 헤더 파일
//

#pragma once


// CYHKimTest4Dlg 대화 상자
class CYHKimTest4Dlg : public CDialogEx
{
// 생성입니다.
public:
	CYHKimTest4Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YHKIMTEST4_DIALOG };
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
	CString m_ctlEdit;
	CListBox m_ctlList;
	BOOL m_c1;
	BOOL m_c2;
	BOOL m_c3;
	BOOL m_c4;
	afx_msg void OnBnClickedButtAdd();
};
