
// YHKimTest2_4View.cpp: CYHKimTest24View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "YHKimTest2_4.h"
#endif

#include "YHKimTest2_4Doc.h"
#include "YHKimTest2_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CYHKimTest24View

IMPLEMENT_DYNCREATE(CYHKimTest24View, CView)

BEGIN_MESSAGE_MAP(CYHKimTest24View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CYHKimTest24View 생성/소멸

CYHKimTest24View::CYHKimTest24View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	isNewDots == TRUE;
}

CYHKimTest24View::~CYHKimTest24View()
{
}

BOOL CYHKimTest24View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CYHKimTest24View 그리기

void CYHKimTest24View::OnDraw(CDC* pDC) //주석 풀기
{
	CYHKimTest24Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	int liCount = pDoc->GetDotsCount();
	if (liCount) // count!=0
	{
		int liPos;
		CDots *lptDots;
		for (liPos = 0; liPos < liCount; liPos++)
		{
			lptDots = pDoc->GetDots(liPos);
			lptDots->Draw(pDC);
		}
	}
	isNewDots = TRUE;
}


// CYHKimTest24View 인쇄

BOOL CYHKimTest24View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CYHKimTest24View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CYHKimTest24View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CYHKimTest24View 진단

#ifdef _DEBUG
void CYHKimTest24View::AssertValid() const
{
	CView::AssertValid();
}

void CYHKimTest24View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CYHKimTest24Doc* CYHKimTest24View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CYHKimTest24Doc)));
	return (CYHKimTest24Doc*)m_pDocument;
}
#endif //_DEBUG


// CYHKimTest24View 메시지 처리기


void CYHKimTest24View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (isNewDots == TRUE) { 
		isNewDots = FALSE; 
		pt = point; 
	}
	else { 
		pt = point; 
		CClientDC dc(this); 
		CDots *pDots = GetDocument()->AddDots(pt);
		pDots->Draw(&dc);
	}
	CView::OnLButtonDown(nFlags, point);
}
