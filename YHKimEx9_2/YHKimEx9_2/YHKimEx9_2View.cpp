﻿
// YHKimEx9_2View.cpp: CYHKimEx92View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "YHKimEx9_2.h"
#endif

#include "YHKimEx9_2Doc.h"
#include "YHKimEx9_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CYHKimEx92View

IMPLEMENT_DYNCREATE(CYHKimEx92View, CView)

BEGIN_MESSAGE_MAP(CYHKimEx92View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CYHKimEx92View 생성/소멸

CYHKimEx92View::CYHKimEx92View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CYHKimEx92View::~CYHKimEx92View()
{
}

BOOL CYHKimEx92View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CYHKimEx92View 그리기

void CYHKimEx92View::OnDraw(CDC* /*pDC*/)
{
	CYHKimEx92Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CYHKimEx92View 인쇄

BOOL CYHKimEx92View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CYHKimEx92View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CYHKimEx92View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CYHKimEx92View 진단

#ifdef _DEBUG
void CYHKimEx92View::AssertValid() const
{
	CView::AssertValid();
}

void CYHKimEx92View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CYHKimEx92Doc* CYHKimEx92View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CYHKimEx92Doc)));
	return (CYHKimEx92Doc*)m_pDocument;
}
#endif //_DEBUG


// CYHKimEx92View 메시지 처리기
