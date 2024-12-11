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
	POINT m_ptE;
public :
	CLine(POINT pts, POINT pte);
	virtual void show(CDC*);
};

class CMyText : public CGraph//继承
{
	CString m_str;
public:
	CMyText(POINT pts, const CString& str);
	virtual void show(CDC*);
};