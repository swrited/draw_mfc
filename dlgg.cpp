// dlgg.cpp: 实现文件
//

#include "pch.h"
#include "p202200800458.h"
#include "afxdialogex.h"
#include "dlgg.h"


// dlgg 对话框

IMPLEMENT_DYNAMIC(dlgg, CDialogEx)

dlgg::dlgg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, edit1(_T(""))
	, edit2(_T(""))
	, edit3(_T(""))
	, edit4(_T(""))
	, edit5(_T(""))
	, edit6(_T(""))
	, edit7(_T(""))
	, edit8(_T(""))
{

}

dlgg::~dlgg()
{
}

void dlgg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, edit1);
	DDX_Text(pDX, IDC_EDIT2, edit2);
	DDX_Text(pDX, IDC_EDIT3, edit3);
	DDX_Text(pDX, IDC_EDIT4, edit4);
	DDX_Text(pDX, IDC_EDIT5, edit5);
	DDX_Text(pDX, IDC_EDIT6, edit6);
	DDX_Text(pDX, IDC_EDIT7, edit7);
	DDX_Text(pDX, IDC_EDIT8, edit8);
}


BEGIN_MESSAGE_MAP(dlgg, CDialogEx)
END_MESSAGE_MAP()


// dlgg 消息处理程序
