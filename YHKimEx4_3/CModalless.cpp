// CModalless.cpp: 구현 파일
//

#include "stdafx.h"
#include "YHKimEx4_3.h"
#include "CModalless.h"
#include "afxdialogex.h"


// CModalless 대화 상자

IMPLEMENT_DYNAMIC(CModalless, CDialogEx)

CModalless::CModalless(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG, pParent)
{

}

CModalless::~CModalless()
{
}

void CModalless::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CModalless, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CModalless 메시지 처리기


void CModalless::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	dc.TextOutW(50, 20, str1);
}
