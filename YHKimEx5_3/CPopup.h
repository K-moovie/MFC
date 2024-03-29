﻿#pragma once


// CPopup 대화 상자

class CPopup : public CDialogEx
{
	DECLARE_DYNAMIC(CPopup)

public:
	CPopup(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CPopup();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	UINT m_input;
};
