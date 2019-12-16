// Ex7_4DLL.h : Ex7_4DLL DLL의 주 헤더 파일
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"		// 주 기호입니다.


// CEx74DLLApp
// 이 클래스 구현에 대해서는 Ex7_4DLL.cpp를 참조하세요.
//

class CEx74DLLApp : public CWinApp
{
public:
	CEx74DLLApp();

// 재정의입니다.
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern "C" __declspec(dllimport) void msg1(CString str);
extern "C" __declspec(dllimport) void msg2(CString str);

