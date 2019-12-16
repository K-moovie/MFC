#include "stdafx.h"
#include "CDots.h"
#include"YHKimTest2_4.h"
IMPLEMENT_SERIAL(CDots,CObject,1)

CDots::CDots()
{

}

CDots::CDots(CPoint pt)
{
	m_pt = pt;
}

CDots::~CDots()
{
}

void CDots::Draw(CDC *pDC) {

	pDC->Ellipse(m_pt.x, m_pt.y, m_pt.x + 10, m_pt.y + 10);
}

void CDots::Serialize(CArchive &ar) {

	if (ar.IsStoring()) { //�����ϴ� �Լ�
		ar << m_pt;
	}
	else { //�ҷ�����
		ar >> m_pt;
	}
}
