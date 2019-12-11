
// YHKimSDI2View.cpp: CYHKimSDI2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "YHKimSDI2.h"
#endif

#include "YHKimSDI2Doc.h"
#include "YHKimSDI2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CYHKimSDI2View

IMPLEMENT_DYNCREATE(CYHKimSDI2View, CView)

BEGIN_MESSAGE_MAP(CYHKimSDI2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CYHKimSDI2View 생성/소멸

CYHKimSDI2View::CYHKimSDI2View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	NewDot = true;

}

CYHKimSDI2View::~CYHKimSDI2View()
{
}

BOOL CYHKimSDI2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CYHKimSDI2View 그리기

void CYHKimSDI2View::OnDraw(CDC* pDC)
{
	CYHKimSDI2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	int liCount = pDoc->GetDotCount();
	if (liCount) {
		CDot* pDot;
		for(int i = 0; i < liCount; i++) {
			pDot = pDoc->GetDot(i);
			pDot->Draw(pDC);
		}
	}
	NewDot = TRUE;
}


// CYHKimSDI2View 인쇄

BOOL CYHKimSDI2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CYHKimSDI2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CYHKimSDI2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CYHKimSDI2View 진단

#ifdef _DEBUG
void CYHKimSDI2View::AssertValid() const
{
	CView::AssertValid();
}

void CYHKimSDI2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CYHKimSDI2Doc* CYHKimSDI2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CYHKimSDI2Doc)));
	return (CYHKimSDI2Doc*)m_pDocument;
}
#endif //_DEBUG


// CYHKimSDI2View 메시지 처리기


void CYHKimSDI2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (NewDot) {
		NewDot = FALSE;
		ptF = point;
	}
	else {
		ptT = point;
		CClientDC dc(this);
		CDot *pDot = GetDocument()->AddDot(ptF, ptT);
		pDot->Draw(&dc);
		ptF = ptT;
	}
	CView::OnLButtonUp(nFlags, point);
}


void CYHKimSDI2View::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	NewDot = FALSE;
	ptF = point;
	CView::OnRButtonUp(nFlags, point);
}
