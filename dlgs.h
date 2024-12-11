#pragma once
//#include "afxdialogex.h"


// CDlgTextInput 对话框

class CDlgTextInput : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTextInput)

public:
	CDlgTextInput(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgTextInput();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEXTINPUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
