#pragma once
#include <afx.h>
class CDot :
	public CObject
{
	DECLARE_SERIAL(CDot);
public:
	CDot();
	~CDot();
	CDot(CPoint ptF, CPoint ptT);
	void Draw(CDC *pDc);
	void Serialize(CArchive &ar);
private:
	CPoint m_ptF, m_ptT;
}; 

