﻿
// YHKim2_3Dlg.h: 헤더 파일
//

#pragma once


// CYHKim23Dlg 대화 상자
class CYHKim23Dlg : public CDialogEx
{
// 생성입니다.
public:
	CYHKim23Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YHKIM2_3_DIALOG };
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
//	CString m_Output;
	CString m_Input;
	CString m_Output;
	afx_msg void OnBnClickedButtOk();
};
