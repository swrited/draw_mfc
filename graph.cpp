#include "pch.h"


#include "graph.h"

void CLine::show(CDC* pDC)
{
	CPen pen(PS_SOLID, 1, m_LineColor);
	CPen *pPenOld = pDC->SelectObject(&pen);
	pDC->MoveTo(m_ptS);
	pDC->LineTo(m_ptE);
	pDC->SelectObject(pPenOld);
}
CLine::CLine(POINT pts, POINT pte, COLORREF c)
{
	m_ptS = pts;
	m_ptE = pte;
	m_LineColor = c;
}


void CMyText::show(CDC* pDC)
{
	pDC->TextOutW(m_ptS.x, m_ptS.y, m_str);
}

CMyText::CMyText(POINT pts, const CString& str, COLORREF c, LOGFONT font)
{
	m_ptS = pts;
	m_str = str;
	m_TextColor = c;
	m_lgFont = font;
}

CMyRect::CMyRect(POINT pts, POINT pte, COLORREF l, COLORREF b)
{
	m_ptS = pts;
	m_ptE = pte;
	m_LineColor = l;
	m_BrushColor = b;
}
void CMyRect::show(CDC* pDC)
{
	CPen pen(PS_SOLID, 1, m_LineColor);
	CPen* pPenOld = pDC->SelectObject(&pen);
	CBrush brush(m_BrushColor);
	CBrush* pBrushOld = pDC->SelectObject(&brush);
	pDC->Rectangle(m_ptS.x, m_ptS.y, m_ptE.x, m_ptE.y);
	pDC->SelectObject(pPenOld);
	pDC->SelectObject(pBrushOld);
}