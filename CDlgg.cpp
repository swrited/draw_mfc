// CDlgg.cpp: 实现文件
//

#include "pch.h"
#include "draw_mfc.h"
//#include "afxdialogex.h"
#include "CDlgg.h"


// CDlgg 对话框

IMPLEMENT_DYNAMIC(CDlgg, CDialogEx)

CDlgg::CDlgg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEXT, pParent)
	, m_edit1(_T(""))
{

}

CDlgg::~CDlgg()
{
}

void CDlgg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
}


BEGIN_MESSAGE_MAP(CDlgg, CDialogEx)
	ON_COMMAND(IDD_TEXT, &CDlgg::OnIddText)
	ON_BN_CLICKED(IDOK, &CDlgg::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgg 消息处理程序


void CDlgg::OnIddText()
{
	// TODO: 在此添加命令处理程序代码
}


BOOL CDlgg::OnInitDialog()
{
	//动态内存交换
	CDialogEx::OnInitDialog();
	m_edit1 = TEXT("修改");
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDlgg::OnBnClickedOk()
{
	UpdateData();

	CDialogEx::OnOK();
}
