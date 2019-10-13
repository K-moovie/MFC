
// YHKim4_6Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "YHKim4_6.h"
#include "YHKim4_6Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CYHKim46Dlg 대화 상자



CYHKim46Dlg::CYHKim46Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_YHKIM4_6_DIALOG, pParent)
	, m_editA(0)
	, m_editB(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CYHKim46Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_A, m_editA);
	DDX_Text(pDX, IDC_EDIT_B, m_editB);
}

BEGIN_MESSAGE_MAP(CYHKim46Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_START, &CYHKim46Dlg::OnBnClickedButtStart)
	ON_BN_CLICKED(IDC_BUTT_READY_A, &CYHKim46Dlg::OnBnClickedButtReadyA)
	ON_BN_CLICKED(IDC_BUTT_SET_A, &CYHKim46Dlg::OnBnClickedButtSetA)
	ON_BN_CLICKED(IDC_BUTT_READY_B, &CYHKim46Dlg::OnBnClickedButtReadyB)
	ON_BN_CLICKED(IDC_BUTT_SET_B, &CYHKim46Dlg::OnBnClickedButtSetB)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CYHKim46Dlg 메시지 처리기

BOOL CYHKim46Dlg::OnInitDialog()
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CYHKim46Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CYHKim46Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CYHKim46Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CYHKim46Dlg::OnBnClickedButtStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_editA = 0;
	m_editB = 0;
	m_readyA = FALSE;
	m_readyB = FALSE;
	UpdateData(FALSE);
}


void CYHKim46Dlg::OnBnClickedButtReadyA()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetTimer(ID_TIMER_A, 50, NULL);
	m_readyA = TRUE;
	
}


void CYHKim46Dlg::OnBnClickedButtSetA()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	KillTimer(ID_TIMER_A);
	if ((m_readyA == TRUE) && (m_readyB ==TRUE))
	{
		if ((m_editA > m_editB))
		{
			AfxMessageBox(_T("A님이 이기셨습니다."));
		}
		else if ((m_editA < m_editB))
		{
			AfxMessageBox(_T("B님이 이기셨습니다."));
		}
		else if ((m_editA == m_editB))
		{
			AfxMessageBox(_T("비기셨습니다."));
		}
	}

}


void CYHKim46Dlg::OnBnClickedButtReadyB()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetTimer(ID_TIMER_B, 50, NULL);
	m_readyB = TRUE;
}


void CYHKim46Dlg::OnBnClickedButtSetB()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	KillTimer(ID_TIMER_B);
	if ((m_readyA == TRUE) && (m_readyB == TRUE))
	{
		if ((m_editA > m_editB))
		{
			AfxMessageBox(_T("A님이 이기셨습니다."));
		}
		else if ((m_editA < m_editB))
		{
			AfxMessageBox(_T("B님이 이기셨습니다."));
		}
		else if ((m_editA == m_editB))
		{
			AfxMessageBox(_T("비기셨습니다."));
		}
	}
}


void CYHKim46Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nIDEvent)
	{
	case 0:
		m_editA += 1;
		if (m_editA == 10) {
			m_editA = 0;
		}
		break;
	case 1:
		m_editB += 1;
		if (m_editB == 10) {
			m_editB = 0;
		}
		break;
	}
	UpdateData(FALSE);
	CDialogEx::OnTimer(nIDEvent);
}
