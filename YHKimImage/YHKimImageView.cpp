
// YHKimImageView.cpp: CYHKimImageView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "YHKimImage.h"
#endif

#include "YHKimImageDoc.h"
#include "YHKimImageView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CYHKimImageView

IMPLEMENT_DYNCREATE(CYHKimImageView, CView)

BEGIN_MESSAGE_MAP(CYHKimImageView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CYHKimImageView 생성/소멸

CYHKimImageView::CYHKimImageView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CYHKimImageView::~CYHKimImageView()
{
}

BOOL CYHKimImageView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CYHKimImageView 그리기

void CYHKimImageView::OnDraw(CDC* pDC)
{
	CYHKimImageDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	for (int i= 0; i < 256; i++) {
		for (int j = 0; j < 256; j++) {
			unsigned char val = pDoc->m_Image[i][j];
			pDC->SetPixel(j, i, RGB(val, val, val));
		}
	}
}


// CYHKimImageView 인쇄

BOOL CYHKimImageView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CYHKimImageView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CYHKimImageView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CYHKimImageView 진단

#ifdef _DEBUG
void CYHKimImageView::AssertValid() const
{
	CView::AssertValid();
}

void CYHKimImageView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CYHKimImageDoc* CYHKimImageView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CYHKimImageDoc)));
	return (CYHKimImageDoc*)m_pDocument;
}
#endif //_DEBUG


// CYHKimImageView 메시지 처리기
