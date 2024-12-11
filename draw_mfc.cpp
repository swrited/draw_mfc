
// draw_mfc.cpp: 定义应用程序的类行为。
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "draw_mfc.h"
#include "MainFrm.h"

#include "draw_mfcDoc.h"
#include "draw_mfcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdrawmfcApp

BEGIN_MESSAGE_MAP(CdrawmfcApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CdrawmfcApp::OnAppAbout)
	// 基于文件的标准文档命令
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// 标准打印设置命令
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// CdrawmfcApp 构造

CdrawmfcApp::CdrawmfcApp() noexcept
{

	// TODO: 将以下应用程序 ID 字符串替换为唯一的 ID 字符串；建议的字符串格式
	//为 CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("drawmfc.AppID.NoVersion"));

	// TODO:  在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

// 唯一的 CdrawmfcApp 对象

CdrawmfcApp theApp;


// CdrawmfcApp 初始化

BOOL CdrawmfcApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。  否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// 使用 RichEdit 控件需要 AfxInitRichEdit2()
	// AfxInitRichEdit2();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	LoadStdProfileSettings(4);  // 加载标准 INI 文件选项(包括 MRU)


	// 注册应用程序的文档模板。  文档模板
	// 将用作文档、框架窗口和视图之间的连接
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CdrawmfcDoc),
		RUNTIME_CLASS(CMainFrame),       // 主 SDI 框架窗口
		RUNTIME_CLASS(CdrawmfcView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// 分析标准 shell 命令、DDE、打开文件操作的命令行
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// 启用“DDE 执行”
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);


	// 调度在命令行中指定的命令。  如果
	// 用 /RegServer、/Register、/Unregserver 或 /Unregister 启动应用程序，则返回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// 唯一的一个窗口已初始化，因此显示它并对其进行更新
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// 仅当具有后缀时才调用 DragAcceptFiles
	//  在 SDI 应用程序中，这应在 ProcessShellCommand 之后发生
	// 启用拖/放
	m_pMainWnd->DragAcceptFiles();
	return TRUE;
}

// CdrawmfcApp 消息处理程序


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnDrawChoose();
//	afx_msg void OnDrawCircle();
//	afx_msg void OnDrawLine();
//	afx_msg void OnDrawRect();
//	afx_msg void OnDrawText();
//	afx_msg void OnUpdateDrawChoose(CCmdUI* pCmdUI);
//	afx_msg void OnUpdateDrawCircle(CCmdUI* pCmdUI);
//	afx_msg void OnUpdateDrawLine(CCmdUI* pCmdUI);
//	afx_msg void OnUpdateDrawRect(CCmdUI* pCmdUI);
//	afx_msg void OnUpdateDrawText(CCmdUI* pCmdUI);
//	virtual BOOL OnInitDialog();
//	afx_msg void OnChooseTextcolor();
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_COMMAND(ID_DRAW_CHOOSE, &CAboutDlg::OnDrawChoose)
//	ON_COMMAND(ID_DRAW_CIRCLE, &CAboutDlg::OnDrawCircle)
//	ON_COMMAND(ID_DRAW_LINE, &CAboutDlg::OnDrawLine)
//	ON_COMMAND(ID_DRAW_RECT, &CAboutDlg::OnDrawRect)
//	ON_COMMAND(ID_DRAW_TEXT, &CAboutDlg::OnDrawText)
//	ON_UPDATE_COMMAND_UI(ID_DRAW_CHOOSE, &CAboutDlg::OnUpdateDrawChoose)
//	ON_UPDATE_COMMAND_UI(ID_DRAW_CIRCLE, &CAboutDlg::OnUpdateDrawCircle)
//	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, &CAboutDlg::OnUpdateDrawLine)
//	ON_UPDATE_COMMAND_UI(ID_DRAW_RECT, &CAboutDlg::OnUpdateDrawRect)
//	ON_UPDATE_COMMAND_UI(ID_DRAW_TEXT, &CAboutDlg::OnUpdateDrawText)
//ON_COMMAND(ID_CHOOSE_TEXTCOLOR, &CAboutDlg::OnChooseTextcolor)
END_MESSAGE_MAP()

// 用于运行对话框的应用程序命令
void CdrawmfcApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CdrawmfcApp 消息处理程序





//void CAboutDlg::OnDrawChoose()
//{
	// TODO: 在此添加命令处理程序代码
//	m_DRAWMODE = ID_DRAW_CHOOSE;
//}


//void CAboutDlg::OnDrawCircle()
//{
	// TODO: 在此添加命令处理程序代码
//	m_DRAWMODE = ID_DRAW_CHOOSE;
//}


//void CAboutDlg::OnDrawLine()
//{
	// TODO: 在此添加命令处理程序代码
//	m_DRAWMODE = ID_DRAW_CHOOSE;
//}


//void CAboutDlg::OnDrawRect()
//{
	// TODO: 在此添加命令处理程序代码
//	m_DRAWMODE = ID_DRAW_CHOOSE;
//}


//void CAboutDlg::OnDrawText()
//{
	// TODO: 在此添加命令处理程序代码
//	m_DRAWMODE = ID_DRAW_CHOOSE;
//}


//void CAboutDlg::OnUpdateDrawChoose(CCmdUI* pCmdUI)
//{
	// TODO: 在此添加命令更新用户界面处理程序代码
//	pCmdUI->SetCheck(m_DRAWMODE == ID_DRAW_CHOOSE);
//}


//void CAboutDlg::OnUpdateDrawCircle(CCmdUI* pCmdUI)
//{
	// TODO: 在此添加命令更新用户界面处理程序代码
//	pCmdUI->SetCheck(m_DRAWMODE == ID_DRAW_CHOOSE);
//}


//void CAboutDlg::OnUpdateDrawLine(CCmdUI* pCmdUI)
//{
	// TODO: 在此添加命令更新用户界面处理程序代码
//	pCmdUI->SetCheck(m_DRAWMODE == ID_DRAW_CHOOSE);
//}


//void CAboutDlg::OnUpdateDrawRect(CCmdUI* pCmdUI)
//{
	// TODO: 在此添加命令更新用户界面处理程序代码
//	pCmdUI->SetCheck(m_DRAWMODE == ID_DRAW_CHOOSE);
//}


//void CAboutDlg::OnUpdateDrawText(CCmdUI* pCmdUI)
//{
	// TODO: 在此添加命令更新用户界面处理程序代码
//	pCmdUI->SetCheck(m_DRAWMODE == ID_DRAW_CHOOSE);
//}


//BOOL CAboutDlg::OnInitDialog()
//{
//	CDialogEx::OnInitDialog();
//
	// TODO:  在此添加额外的初始化

//	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
//}


//void CAboutDlg::OnChooseTextcolor()
//{
	// TODO: 在此添加命令处理程序代码
//}
