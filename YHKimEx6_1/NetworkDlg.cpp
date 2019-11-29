
// NetworkDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Network.h"
#include "NetworkDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CMySocket CNetworkDlg::m_Csocket;
CMySocket CNetworkDlg::m_Ssocket;

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CNetworkDlg 대화 상자



CNetworkDlg::CNetworkDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NETWORK_DIALOG, pParent)
	, m_strName(_T(""))
	, m_iType(FALSE)
	, m_input(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNetworkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ESERVERNAME, m_strName);
	//  DDX_Radio(pDX, IDC_RSERVER, m_iType);
	//  DDX_Radio(pDX, IDC_RSERVER, m_iType);
	DDX_Radio(pDX, IDC_RSERVER, m_iType);
	DDX_Text(pDX, IDC_EDIT1, m_input);
}

BEGIN_MESSAGE_MAP(CNetworkDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RSERVER, &CNetworkDlg::OnRType)
	ON_BN_CLICKED(IDC_RCLIENT, &CNetworkDlg::OnRType)
	ON_BN_CLICKED(IDC_BLISTEN, &CNetworkDlg::OnBnClickedBlisten)
	ON_BN_CLICKED(IDC_BDISCON, &CNetworkDlg::OnBnClickedBdiscon)
	ON_BN_CLICKED(IDC_BCONNECT, &CNetworkDlg::OnBnClickedBconnect)
	ON_BN_CLICKED(IDC_BENTER, &CNetworkDlg::OnBnClickedBenter)
END_MESSAGE_MAP()


// CNetworkDlg 메시지 처리기

BOOL CNetworkDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_strName = "localhost";
	UpdateData(FALSE);
	m_Csocket.SetParent(this);
	m_Ssocket.SetParent(this);
	m_iPaintType = 0;
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CNetworkDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CNetworkDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CClientDC dc(this);

		CDialogEx::OnPaint();
		if (m_iPaintType == 1)
			dc.Rectangle(250 - 100, 300 - 100, 250 + 100, 300 + 100);
		else if (m_iPaintType == 2)
			dc.Ellipse(250 - 100, 300 - 100, 250 + 100, 300 + 100);
		else if (m_iPaintType == 3) {
			dc.MoveTo(250 - 100, 300);
			dc.LineTo(250 + 100, 300);
		}
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CNetworkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNetworkDlg::OnRType()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (!m_iType)
	{
		GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
		GetDlgItem(IDC_BLISTEN)->EnableWindow(TRUE);
	}
	else if(m_iType)
	{
		
		GetDlgItem(IDC_BCONNECT)->EnableWindow(TRUE);
		GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	}
}

void CNetworkDlg::OnAccept() {
	m_Ssocket.Accept(m_Csocket);
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	GetDlgItem(IDC_NEXT)->EnableWindow(TRUE);
	GetDlgItem(IDC_BENTER)->EnableWindow(TRUE);
}

void CNetworkDlg::OnConnect() {

	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	GetDlgItem(IDC_NEXT)->EnableWindow(TRUE);
	GetDlgItem(IDC_BENTER)->EnableWindow(TRUE);
}

void CNetworkDlg::OnClose() {
	m_Csocket.Close();
	GetDlgItem(IDC_NEXT)->EnableWindow(FALSE);

	if (m_iType == 0)
	{
		GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
		GetDlgItem(IDC_BLISTEN)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_BCONNECT)->EnableWindow(TRUE);
		GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	}
}

void CNetworkDlg::OnReceive() {
	char *pBuf = new char[1025];
	int iBufSize = 1024;
	int iRcvd;
	iRcvd = m_Csocket.Receive(pBuf, iBufSize);
	CString str;
	str.Format(_T("%d"), iRcvd);
	if (iRcvd == SOCKET_ERROR)
	{
	}
	else
	{
		pBuf[iRcvd - 1] = NULL;
		if (strcmp(pBuf, "R") == 0)
			m_iPaintType = 1;
		else if(strcmp(pBuf, "C") == 0)
			m_iPaintType = 2;
		else if (strcmp(pBuf, "L") == 0)
			m_iPaintType = 3;
		else 
			m_iPaintType = 0;
		Invalidate(TRUE);
	}

}

void CNetworkDlg::OnSend() {

}

void CNetworkDlg::OnBnClickedBlisten()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	m_Ssocket.Create(4000);
	m_Ssocket.Listen();
}


void CNetworkDlg::OnBnClickedBdiscon()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_Csocket.Close();
	m_Ssocket.Close();
}


void CNetworkDlg::OnBnClickedBconnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	GetDlgItem(IDC_NEXT)->EnableWindow(TRUE);
	UpdateData(TRUE);
	m_Csocket.Create();
	m_Csocket.Connect(m_strName, 4000);
}

void CNetworkDlg::OnBnClickedBenter()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	int iSent;
	int iLen = m_input.GetLength();

	iSent = m_Csocket.Send(m_input, iLen+1);
	if (iSent == SOCKET_ERROR) {
		AfxMessageBox(_T("에러"));
	}
}
