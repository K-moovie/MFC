#include "stdafx.h"
#include "Cpop.h"


Cpop::Cpop()
{
}


Cpop::~Cpop()
{
}
BEGIN_MESSAGE_MAP(Cpop, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


void Cpop::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
	dc.TextOutW(100, 100, str);
}
