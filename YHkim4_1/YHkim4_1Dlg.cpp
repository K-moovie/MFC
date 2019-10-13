
// YHkim4_1Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "YHkim4_1.h"
#include "YHkim4_1Dlg.h"
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
public:
	
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()


// CYHkim41Dlg 대화 상자



CYHkim41Dlg::CYHkim41Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_YHKIM4_1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CYHkim41Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CYHkim41Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MINUS, &CYHkim41Dlg::OnMinus)
	ON_COMMAND(ID_EXIT, &CYHkim41Dlg::OnExit)
	ON_COMMAND(ID_HELLO, &CYHkim41Dlg::OnHello)
	ON_COMMAND(ID_PLUS, &CYHkim41Dlg::OnPlus)
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()


// CYHkim41Dlg 메시지 처리기

BOOL CYHkim41Dlg::OnInitDialog()
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

void CYHkim41Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CYHkim41Dlg::OnPaint()
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
		CClientDC dc(this);
		CString str;
		if (value == 1)
		{
			str.Format(_T("안녕하세요"));
			dc.TextOut(165, 50, str);
		}
		else if (value == 2)
		{
			int a = 10;
			int b = 5; 
			int c = a + b;
			str.Format(_T("덧셈은 %d입니다. "), c);
			dc.TextOutW(165, 150, str);
		}
		else if (value == 3)
		{
			int a = 10;
			int b = 5;
			int c = a - b;
			str.Format(_T("뺼셈은 %d입니다. "), c);
			dc.TextOutW(165, 150, str);
		}
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CYHkim41Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CYHkim41Dlg::OnMinus()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	value = 3;
	Invalidate();
}


void CYHkim41Dlg::OnExit()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnOK();
}


void CYHkim41Dlg::OnHello()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	value = 1;
	Invalidate();
}


void CYHkim41Dlg::OnPlus()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	value = 2;
	Invalidate();
}


void CYHkim41Dlg::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CMenu* menu_bar = AfxGetMainWnd()->GetMenu();
	CMenu* start_menu = menu_bar->GetSubMenu(0);
	ASSERT(start_menu);
	start_menu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
}
