
// draw_mfcView.cpp: CdrawmfcView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "draw_mfc.h"
#endif

#include "draw_mfcDoc.h"
#include "draw_mfcView.h"
#include "CDlgg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdrawmfcView

IMPLEMENT_DYNCREATE(CdrawmfcView, CView)

BEGIN_MESSAGE_MAP(CdrawmfcView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_COMMAND(ID_DRAW_CHOOSE, &CdrawmfcView::OnDrawChoose)
//ON_UPDATE_COMMAND_UI(ID_DRAW_CHOOSE, &CdrawmfcView::OnUpdateDrawChoose)
ON_COMMAND(ID_DRAW_CHOOSE, &CdrawmfcView::OnDrawChoose)
ON_COMMAND(ID_DRAW_CIRCLE, &CdrawmfcView::OnDrawCircle)
ON_COMMAND(ID_DRAW_LINE, &CdrawmfcView::OnDrawLine)
ON_COMMAND(ID_DRAW_RECT, &CdrawmfcView::OnDrawRect)
ON_COMMAND(ID_DRAW_TEXT, &CdrawmfcView::OnDrawText)
ON_UPDATE_COMMAND_UI(ID_DRAW_CHOOSE, &CdrawmfcView::OnUpdateDrawChoose)
ON_UPDATE_COMMAND_UI(ID_DRAW_CIRCLE, &CdrawmfcView::OnUpdateDrawCircle)
ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, &CdrawmfcView::OnUpdateDrawLine)
ON_UPDATE_COMMAND_UI(ID_DRAW_RECT, &CdrawmfcView::OnUpdateDrawRect)
ON_UPDATE_COMMAND_UI(ID_DRAW_TEXT, &CdrawmfcView::OnUpdateDrawText)
ON_COMMAND(ID_CHOOSE_FILLCOLOR, &CdrawmfcView::OnChooseFillcolor)
ON_COMMAND(ID_CHOOSE_LINECOLOR, &CdrawmfcView::OnChooseLinecolor)
ON_COMMAND(ID_CHOOSE_TEXTCOLOR, &CdrawmfcView::OnChooseTextcolor)
ON_COMMAND(ID_CHOOSE_TEXTFONT, &CdrawmfcView::OnChooseTextfont)
ON_WM_RBUTTONUP()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_COMMAND(ID_CJHOOSE_FILLCOLOR, &CdrawmfcView::OnCjhooseFillcolor)
ON_COMMAND(ID_CJHOOSE_LINECOLOR, &CdrawmfcView::OnCjhooseLinecolor)
ON_COMMAND(ID_CJHOOSE_TEXTCOLOR, &CdrawmfcView::OnCjhooseTextcolor)
ON_COMMAND(ID_CJHOOSE_TEXTFONT, &CdrawmfcView::OnCjhooseTextfont)
ON_UPDATE_COMMAND_UI(ID_CHOOSE_FILLCOLOR, &CdrawmfcView::OnUpdateChooseFillcolor)
END_MESSAGE_MAP()

// CdrawmfcView 构造/析构

CdrawmfcView::CdrawmfcView() noexcept
{
	// TODO: 在此处添加构造代码
	m_LineColor=RGB(0,0,0);
	m_BrushColor = RGB(0, 0, 0);
	m_TextColor = RGB(0, 0, 0);
	//GetObject(m_Font);
	//m_ptStart.x = 0;
	//m_ptStart.y = 0;


}

CdrawmfcView::~CdrawmfcView()
{
}

BOOL CdrawmfcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CdrawmfcView 绘图

void CdrawmfcView::OnDraw(CDC* pDC)
{
	CdrawmfcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->DrawAllGraph(pDC);
}


// CdrawmfcView 打印

BOOL CdrawmfcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CdrawmfcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CdrawmfcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CdrawmfcView 诊断

#ifdef _DEBUG
void CdrawmfcView::AssertValid() const
{
	CView::AssertValid();
}

void CdrawmfcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdrawmfcDoc* CdrawmfcView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdrawmfcDoc)));
	return (CdrawmfcDoc*)m_pDocument;
}
#endif //_DEBUG




void CdrawmfcView::OnDrawChoose()
{
	// TODO: 在此添加命令处理程序代码
	m_DRAWMODE = ID_DRAW_CHOOSE;
}


void CdrawmfcView::OnDrawCircle()
{
	// TODO: 在此添加命令处理程序代码
	m_DRAWMODE = ID_DRAW_CIRCLE;
}


void CdrawmfcView::OnDrawLine()
{
	// TODO: 在此添加命令处理程序代码
	m_DRAWMODE = ID_DRAW_LINE;
}


void CdrawmfcView::OnDrawRect()
{
	// TODO: 在此添加命令处理程序代码
	m_DRAWMODE = ID_DRAW_RECT;
}


void CdrawmfcView::OnDrawText()
{
	// TODO: 在此添加命令处理程序代码
	m_DRAWMODE = ID_DRAW_TEXT;
}


void CdrawmfcView::OnUpdateDrawChoose(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_DRAWMODE == ID_DRAW_CHOOSE);
}


void CdrawmfcView::OnUpdateDrawCircle(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_DRAWMODE == ID_DRAW_CIRCLE);
}


void CdrawmfcView::OnUpdateDrawLine(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_DRAWMODE == ID_DRAW_LINE);
}


void CdrawmfcView::OnUpdateDrawRect(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_DRAWMODE == ID_DRAW_RECT);
}


void CdrawmfcView::OnUpdateDrawText(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_DRAWMODE == ID_DRAW_TEXT);
}


void CdrawmfcView::OnChooseFillcolor()
{
	// TODO: 在此添加命令处理程序代码
	m_CHOOSEMODE = ID_CHOOSE_FILLCOLOR;
	CColorDialog ob;
	ob.m_cc.rgbResult = m_BrushColor;
	if (ob.DoModal() == IDOK)
	{
		m_BrushColor = ob.GetColor();

	}
}


void CdrawmfcView::OnChooseLinecolor()
{
	// TODO: 在此添加命令处理程序代码
	m_CHOOSEMODE = ID_CHOOSE_LINECOLOR;
	CColorDialog ob;
	ob.m_cc.rgbResult = m_LineColor;
	if (ob.DoModal() == IDOK)
	{
		m_LineColor = ob.GetColor();

	}
}


void CdrawmfcView::OnChooseTextcolor()
{
	// TODO: 在此添加命令处理程序代码
	m_CHOOSEMODE = ID_CHOOSE_TEXTCOLOR;
	CColorDialog ob;
	ob.m_cc.rgbResult = m_TextColor;
	if (ob.DoModal() == IDOK)
	{
		m_TextColor = ob.GetColor();

	}
}


void CdrawmfcView::OnChooseTextfont()
{
	// TODO: 在此添加命令处理程序代码
	m_CHOOSEMODE = ID_CHOOSE_TEXTFONT;
}


void CdrawmfcView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDlgg ob;
	ob.m_edit1 = TEXT("选择课程信息");
	ob.DoModal();

	MessageBox(ob.m_edit1);
	CView::OnRButtonUp(nFlags, point);
}


void CdrawmfcView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//void showdata(HWND hWnd);
	//showdata(this->m_hWnd);
	m_ptStart = point;
	if (m_DRAWMODE == ID_DRAW_TEXT)
	{
		CDlgg ob;
		if (ob.DoModal() == IDOK)
		{
			CMyText* pText = new CMyText(m_ptStart, ob.m_edit1,this->m_TextColor, m_Font);
			if (GetDocument()->AddOneGraph(pText))
			{
				InvalidateRect(NULL);
			}
		}
	}
	CView::OnLButtonDown(nFlags, point);
}


void CdrawmfcView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_DRAWMODE == ID_DRAW_LINE)
	{
		CLine* pLine = new CLine(m_ptStart,point,m_LineColor);
		if (GetDocument()->AddOneGraph(pLine))
		{
			InvalidateRect(NULL);
		}
			
	}
	//绘制矩形
	if (m_DRAWMODE == ID_DRAW_RECT)
	{
		CMyRect* pRect = new CMyRect(m_ptStart, point, m_LineColor,m_BrushColor);
		if (GetDocument()->AddOneGraph(pRect))
		{
			InvalidateRect(NULL);
		}

	}
	CView::OnLButtonUp(nFlags, point);
}


void CdrawmfcView::OnCjhooseFillcolor()
{

	// TODO: 在此添加命令处理程序代码
}


void CdrawmfcView::OnCjhooseLinecolor()
{
	// TODO: 在此添加命令处理程序代码
}


void CdrawmfcView::OnCjhooseTextcolor()
{
	// TODO: 在此添加命令处理程序代码
}


void CdrawmfcView::OnCjhooseTextfont()
{
	// TODO: 在此添加命令处理程序代码
}


void CdrawmfcView::OnUpdateChooseFillcolor(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
}
