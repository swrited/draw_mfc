#pragma once
#include "afxdialogex.h"


// dlgg 对话框

class dlgg : public CDialogEx
{
	DECLARE_DYNAMIC(dlgg)

public:
	dlgg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~dlgg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString edit1;
	CString edit2;
	CString edit3;
	CString edit4;
	CString edit5;
	CString edit6;
	CString edit7;
	CString edit8;
};


