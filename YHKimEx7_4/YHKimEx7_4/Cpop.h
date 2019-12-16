#pragma once
#include <afxwin.h>
class Cpop :
	public CDialog
{
public:
	Cpop();
	~Cpop();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
public:
	CString str;
};

