#include "pch.h"


#include "graph.h"

void CLine::show(CDC* pDC)
{
	pDC->MoveTo(m_ptS);
	pDC->LineTo(m_ptE);
}
CLine::CLine(POINT pts, POINT pte)
{
	m_ptS = pts;
	m_ptE = pte;
}


void CMyText::show(CDC* pDC)
{
	pDC->TextOutW(m_ptS.x, m_ptS.y, m_str);
}

CMyText::CMyText(POINT pts, const CString& str)
{
	m_ptS = pts;
	m_str = str;
}