// CPopup.cpp: 구현 파일
//

#include "stdafx.h"
#include "YHKim4_3.h"
#include "CPopup.h"
#include "afxdialogex.h"


// CPopup 대화 상자

IMPLEMENT_DYNAMIC(CPopup, CDialog)

CPopup::CPopup(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_POPUP, pParent)
	, m_n1(0)
	, m_n2(0)
{

}

CPopup::~CPopup()
{
}

void CPopup::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_N1, m_n1);
	DDX_Text(pDX, IDC_EDIT_N2, m_n2);
}


BEGIN_MESSAGE_MAP(CPopup, CDialog)

END_MESSAGE_MAP()


// CPopup 메시지 처리기



