#include "stdafx.h"
#include "CDot.h"

IMPLEMENT_SERIAL(CDot, CObject, 1);

CDot::CDot()
{
}


CDot::~CDot()
{
}

CDot::CDot(CPoint ptF, CPoint ptT) {
	m_ptF = ptF;
	m_ptT = ptT;
}

void CDot::Draw(CDC *pDc) {
	pDc->MoveTo(m_ptF);
	pDc->LineTo(m_ptT);
}

void CDot::Serialize(CArchive &ar) {
	if (ar.IsStoring()){
		ar<<m_ptF<<m_ptT;
	}
	else {
		ar >> m_ptF >> m_ptT;
	}
}