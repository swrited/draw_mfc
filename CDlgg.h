#pragma once
//#include "afxdialogex.h"


// CDlgg 对话框

class CDlgg : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgg)

public:
	CDlgg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEXT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnIddText();
	CString m_edit1;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
