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
					   // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
					   // �׸��� �޽����� ���ؼ��� CDialog::OnPaint()��(��) ȣ������ ���ʽÿ�.
	dc.TextOutW(100, 100, str);
}
