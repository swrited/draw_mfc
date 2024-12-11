#pragma once
#include <afx.h>
#include <afxwin.h>
class CGraph
{
protected:
	POINT m_ptS;
public:
	virtual void show(CDC*)=0;//这是一个纯虚函数，子类必须实现

};

class CLine : public CGraph//继承
{
protected:
	POINT m_ptE;
	COLORREF m_LineColor;
public :
	CLine(POINT pts, POINT pte, COLORREF c);
	virtual void show(CDC*);
};

class CMyText : public CGraph//继承
{
protected:
	CString m_str;
	COLORREF m_TextColor;
	LOGFONT m_lgFont;
public:
	CMyText(POINT pts, const CString& str, COLORREF c, LOGFONT font);
	virtual void show(CDC*);
};

class CMyRect : public CGraph//继承
{
protected:
	POINT m_ptE;
	COLORREF m_LineColor;
	COLORREF m_BrushColor;
public:
	CMyRect(POINT pts, POINT pte, COLORREF l, COLORREF b);
	virtual void show(CDC*);

};