#pragma once
#include <afx.h>
#include <afxwin.h>
class CGraph
{
protected:
	POINT m_ptS;
public:
	virtual void show(CDC*)=0;//����һ�����麯�����������ʵ��

};

class CLine : public CGraph//�̳�
{
	POINT m_ptE;
public :
	CLine(POINT pts, POINT pte);
	virtual void show(CDC*);
};

class CMyText : public CGraph//�̳�
{
	CString m_str;
public:
	CMyText(POINT pts, const CString& str);
	virtual void show(CDC*);
};