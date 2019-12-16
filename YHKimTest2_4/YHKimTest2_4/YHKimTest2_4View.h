﻿
// YHKimTest2_4View.h: CYHKimTest24View 클래스의 인터페이스
//

#pragma once


class CYHKimTest24View : public CView
{
protected: // serialization에서만 만들어집니다.
	CYHKimTest24View() noexcept;
	DECLARE_DYNCREATE(CYHKimTest24View)

// 특성입니다.
public:
	CYHKimTest24Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CYHKimTest24View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

private: //추가한 부분
	CPoint pt;
	BOOL isNewDots;
};

#ifndef _DEBUG  // YHKimTest2_4View.cpp의 디버그 버전
inline CYHKimTest24Doc* CYHKimTest24View::GetDocument() const
   { return reinterpret_cast<CYHKimTest24Doc*>(m_pDocument); }
#endif

