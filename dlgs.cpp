// dlgs.cpp: 实现文件
//

#include "pch.h"
#include "draw_mfc.h"
#include "afxdialogex.h"
#include "dlgs.h"


// CDlgTextInput 对话框

IMPLEMENT_DYNAMIC(CDlgTextInput, CDialogEx)

CDlgTextInput::CDlgTextInput(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEXTINPUT, pParent)
{

}

CDlgTextInput::~CDlgTextInput()
{
}

void CDlgTextInput::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgTextInput, CDialogEx)
END_MESSAGE_MAP()


// CDlgTextInput 消息处理程序
