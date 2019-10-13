// CPopup.cpp: 구현 파일
//

#include "stdafx.h"
#include "YHKimEx4_2.h"
#include "CPopup.h"
#include "afxdialogex.h"


// CPopup 대화 상자

IMPLEMENT_DYNAMIC(CPopup, CDialog)

CPopup::CPopup(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_POPUP, pParent)
	, m_input(0)
{

}

CPopup::~CPopup()
{
}

void CPopup::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_INPUT, m_input);
}


BEGIN_MESSAGE_MAP(CPopup, CDialog)
END_MESSAGE_MAP()


// CPopup 메시지 처리기
