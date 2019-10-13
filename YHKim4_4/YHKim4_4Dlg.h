
// YHKim4_4Dlg.h: 헤더 파일
//
#include "CModalless.h"
#pragma once


// CYHKim44Dlg 대화 상자
class CYHKim44Dlg : public CDialogEx
{
// 생성입니다.
public:
	CYHKim44Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	CModalless *m_pDlg;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YHKIM4_4_DIALOG };
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
	int m_width;
	BOOL m_style;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnChangeEditWidthx();
};
