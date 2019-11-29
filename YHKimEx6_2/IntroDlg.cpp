// IntroDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Network.h"
#include "IntroDlg.h"
#include "afxdialogex.h"
#include "CMySocket.h"
#include "NetworkDlg.h"


// IntroDlg 대화 상자

IMPLEMENT_DYNAMIC(IntroDlg, CDialog)

IntroDlg::IntroDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_INTRO, pParent)
{

}

IntroDlg::~IntroDlg()
{
}

void IntroDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(IntroDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
	ON_STN_CLICKED(IDC_START, &IntroDlg::OnStnClickedStart)
END_MESSAGE_MAP()


// IntroDlg 메시지 처리기



BOOL IntroDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	start_toggle = false;
	
	theme_font.CreateFont(25, 25, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("RixVideoGame Bold"));
	GetDlgItem(IDC_TITLE1)->SetFont(&theme_font);
	GetDlgItem(IDC_TITLE2)->SetFont(&theme_font);
	GetDlgItem(IDC_START)->SetFont(&theme_font);
	GetDlgItem(IDC_NAME1)->SetFont(&theme_font);
	GetDlgItem(IDC_NAME2)->SetFont(&theme_font);
	GetDlgItem(IDC_NAME3)->SetFont(&theme_font);
	SetTimer(1, 500, NULL);
	SetTimer(2, 2000, NULL);
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.

}




void IntroDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
	
}


BOOL IntroDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//return CDialog::OnEraseBkgnd(pDC);
	CBrush backBrush(RGB(0, 0, 0));
	CBrush* pOldBrush = pDC->SelectObject(&backBrush);
	CRect rect; pDC->GetClipBox(&rect);
	pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOldBrush);
	return TRUE;
}




HBRUSH IntroDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	if (pWnd->GetDlgCtrlID() == IDC_TITLE1)
	{
		pDC->SetTextColor(RGB(255, 0, 0));
		pDC->SetBkColor(RGB(0, 0, 0));
		//pDC->SetBkMode(TRANSPARENT);
	}
	if (pWnd->GetDlgCtrlID() == IDC_TITLE2)
	{
		pDC->SetTextColor(RGB(255, 0, 0));
		pDC->SetBkColor(RGB(0, 0, 0));
	}
	if (pWnd->GetDlgCtrlID() == IDC_START)
	{
		pDC->SetTextColor(RGB(0, 0, 255));
		pDC->SetBkColor(RGB(0, 0, 0));
	}
	if (pWnd->GetDlgCtrlID() == IDC_NAME1)
	{
		pDC->SetTextColor(RGB(0, 255, 0));
		pDC->SetBkColor(RGB(0, 0, 0));
	}
	if (pWnd->GetDlgCtrlID() == IDC_NAME2)
	{
		pDC->SetTextColor(RGB(0, 255, 0));
		pDC->SetBkColor(RGB(0, 0, 0));
	}
	if (pWnd->GetDlgCtrlID() == IDC_NAME3)
	{
		pDC->SetTextColor(RGB(0, 255, 0));
		pDC->SetBkColor(RGB(0, 0, 0));
	}
	return hbr;
}



void IntroDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialog::OnTimer(nIDEvent);
	switch (nIDEvent) {
	case 1:
		start_toggle = !start_toggle;
		if (start_toggle)
			GetDlgItem(IDC_START)->ShowWindow(TRUE);
		else
			GetDlgItem(IDC_START)->ShowWindow(FALSE);
		break;
	case 2:
		//GetDlgItem(IDD_NETWORK_DIALOG)->ShowWindow(SW_MINIMIZE);
		KillTimer(2);
		break;
	}
	


}


void IntroDlg::OnStnClickedStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	//CNetworkDlg * a = (CNetworkDlg*)::AfxGetMainWnd();
	

	int iSent;
	const char* strMsg("rect");
	int iLen = strlen(strMsg) + 1;
	iSent = CNetworkDlg::m_Csocket.Send(LPCTSTR(strMsg), iLen);
	CString str;
	str.Format(_T("%d"), iSent);
	MessageBox(str);
	//iSent = ((CNetworkDlg *)GetParent())->m_Csocket.Send(LPCTSTR(strMsg), iLen);
	if (iSent == SOCKET_ERROR) {
		AfxMessageBox(_T("에러"));
	}
}
