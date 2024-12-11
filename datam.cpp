#include "pch.h"
#include "datam.h"



void showdata(HWND hWnd)
{
	CDatManage<int> ob;
	ob.setvalue(100, 120);
	ob.Add();
	CDatManage<double> ob1;
	ob1.setvalue(111.9, 12.6);
	ob1.Add();
	CString str;
	str.Format(TEXT("计算结果：%d"), ob.Add());
	MessageBox(hWnd, str, TEXT("计算结果"), MB_OK);
	str.Format(TEXT("双精度计算结果：%.2lf"), ob1.Add());
	MessageBox(hWnd, str, TEXT("计算结果"), MB_OK);
}