// CPowDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "CPowDlg.h"
#include "afxdialogex.h"


// CPowDlg 대화 상자

IMPLEMENT_DYNAMIC(CPowDlg, CDialog)

CPowDlg::CPowDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_POWDLG, pParent)
	, m_input(0)
{

}

CPowDlg::~CPowDlg()
{
}

void CPowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INPUT, m_input);
}


BEGIN_MESSAGE_MAP(CPowDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTT_RESULT, &CPowDlg::OnBnClickedButtResult)
END_MESSAGE_MAP()


// CPowDlg 메시지 처리기


void CPowDlg::OnBnClickedButtResult()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	int result = pow(2., m_input);
	CString str;
	str.Format(_T("2의 %d승은 %d 입니다."), m_input, result);
	AfxMessageBox(str);
}
