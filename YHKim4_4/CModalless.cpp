// CModalless.cpp: 구현 파일
//

#include "stdafx.h"
#include "YHKim4_4.h"
#include "CModalless.h"
#include "afxdialogex.h"


// CModalless 대화 상자

IMPLEMENT_DYNAMIC(CModalless, CDialog)

CModalless::CModalless(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_MODALLESS, pParent)
{

}

CModalless::~CModalless()
{
}

void CModalless::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CModalless, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CModalless 메시지 처리기


void CModalless::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
	CPen pEn;
	if (lineStyle == TRUE)
	{
		pEn.CreatePen(PS_DOT, lineWidth, RGB(0, 0, 0));
	}
	else
	{
		pEn.CreatePen(PS_SOLID, lineWidth, RGB(0, 0, 0));
	}
	dc.SelectObject(pEn);
	dc.MoveTo(0, 100);
	dc.LineTo(200, 100);
	pEn.DeleteObject();
}
