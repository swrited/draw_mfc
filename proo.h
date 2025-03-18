#pragma once
#include "pch.h"
extern int sum;
int cha(int year1, int month1, int day1, int year2, int month2, int day2);
class pro
{
protected:
	CString name;
	CString time1;
	int year1;
	int month1;
	int day1;
	CString time2;
	int year2;
	int month2;
	int day2;
	CString num1;
	int num_num;
	int cheng;//³É±¾
public:
	pro() {};
	pro(CString pro_name, CString year11, CString month11, CString day11, CString year21, CString month21, CString day21, CString pro_num)
	{
		name = pro_name;
		time1 = year11 + '.' + month11 + '.' + day11;
		time2 = year21 + '.' + month21 + '.' + day21;
		num1 = pro_num;
		num_num = StrToInt(num1);
		year1 = StrToInt(year11);
		year2 = StrToInt(year21);
		month1 = StrToInt(month11);
		month2 = StrToInt(month21);
		day1 = StrToInt(day11);
		day2 = StrToInt(day21);
		cheng = cha(year1, month1, day1, year2, month2, day2)*num_num*500;
		//cheng=MonthCal_GetCalendarBorder()
	};
	int get_cheng() { return cheng; }
	CString get_name() { return name; }
	void show(CDC* pDC, int num)
	{
		pDC->TextOut(0, (num + 2) * 50, name);
		pDC->TextOut(100, (num + 2) * 50, time1);
		pDC->TextOut(200, (num + 2) * 50, time2);
		pDC->TextOut(300, (num + 2) * 50, num1);
		TCHAR a[100];
		wsprintf(a, TEXT("%d"),cheng);
		pDC->TextOut(400, (num + 2) * 50, a);
		//pDC->MoveTo(0, (num + 2) * 50 + 30);	pDC->LineTo(300, (num + 2) * 50 + 30);
	}
	void show_rect(CDC* pDC, int num)
	{
		CPen pen(0, 1, RGB(0, 0, 0));
		CPen* pPenOld = pDC->SelectObject(&pen);
		CBrush brush(RGB(0, 0, 0));
		CBrush* pBrushOld = pDC->SelectObject(&brush);
		float bai = 0;
		if (sum == 0)
			bai = 0;
		else
			bai = float(cheng) / sum;
		pDC->Rectangle(500 + num * 100, 200, 580 + num * 100, 200 - bai * 100);
		TCHAR a[100];
		swprintf(a, 100, L"%d", cheng);
		pDC->TextOut(500 + num * 100, 200 - (bai + 0.2) * 100, a);
		pDC->TextOut(500 + num * 100, 200, name);
		pDC->SelectObject(pPenOld);
		pDC->SelectObject(pBrushOld);
	}
	void Save(CArchive& ar)
	{
		ar << name << time1<<time2<<year1<<month1<<day1<<year2<<month2<<day2 << num1<<num_num;
	}
	void Load(CArchive& ar)
	{
		ar >> name >> time1 >> time2 >> year1 >> month1 >> day1 >> year2 >> month2 >> day2 >> num1>>num_num;
		cheng = cha(year1, month1, day1, year2, month2, day2) * num_num * 500;
	}
};