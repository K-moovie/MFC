// CPopup.cpp: 구현 파일
//

#include "stdafx.h"
#include "YHKimTest5.h"
#include "CPopup.h"
#include "afxdialogex.h"


// CPopup 대화 상자

IMPLEMENT_DYNAMIC(CPopup, CDialogEx)

CPopup::CPopup(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG, pParent)
	, m_input(0)
{

}

CPopup::~CPopup()
{
}

void CPopup::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT, m_input);
}


BEGIN_MESSAGE_MAP(CPopup, CDialogEx)
END_MESSAGE_MAP()


// CPopup 메시지 처리기
