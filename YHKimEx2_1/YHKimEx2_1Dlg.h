﻿
// YHKimEx2_1Dlg.h: 헤더 파일
//

#pragma once


// CYHKimEx21Dlg 대화 상자
class CYHKimEx21Dlg : public CDialogEx
{
// 생성입니다.
public:
	CYHKimEx21Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YHKIMEX2_1_DIALOG };
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
//	BOOL m_radio;
	afx_msg void OnBnClickedButtPush();
	int m_radio;
	afx_msg void OnBnClickedRadioEnable();
	afx_msg void OnBnClickedRadioDisable();
};
