
// p202200800458View.cpp: Cp202200800458View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "p202200800458.h"
#endif

#include "p202200800458Doc.h"
#include "p202200800458View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "dlgg.h"
#include "proo.h"

// Cp202200800458View

IMPLEMENT_DYNCREATE(Cp202200800458View, CView)

BEGIN_MESSAGE_MAP(Cp202200800458View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_RU, &Cp202200800458View::OnRu)
	ON_COMMAND(ID_PAI_NAME, &Cp202200800458View::OnPaiName)
	ON_COMMAND(ID_PAI_NUM, &Cp202200800458View::OnPaiNum)
END_MESSAGE_MAP()

// Cp202200800458View 构造/析构

Cp202200800458View::Cp202200800458View() noexcept
{
	// TODO: 在此处添加构造代码

}

Cp202200800458View::~Cp202200800458View()
{
}

BOOL Cp202200800458View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cp202200800458View 绘图

void Cp202200800458View::OnDraw(CDC* pDC)
{
	Cp202200800458Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->SetTextColor(RGB(255, 0, 0));
	pDC->TextOut(0, 0, TEXT("202200800458 王梦娣"));
	pDC->TextOut(0,  50, TEXT("项目名称"));
	pDC->TextOut(100, 50, TEXT("起始时间"));
	pDC->TextOut(200, 50, TEXT("终止时间"));
	pDC->TextOut(300,  50, TEXT("参与人数"));
	pDC->TextOut(400, 50, TEXT("项目成本"));
	pDoc->DrawAllPro(pDC);
	// TODO: 在此处为本机数据添加绘制代码
}


// Cp202200800458View 打印

BOOL Cp202200800458View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cp202200800458View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cp202200800458View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cp202200800458View 诊断

#ifdef _DEBUG
void Cp202200800458View::AssertValid() const
{
	CView::AssertValid();
}

void Cp202200800458View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cp202200800458Doc* Cp202200800458View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp202200800458Doc)));
	return (Cp202200800458Doc*)m_pDocument;
}
#endif //_DEBUG


// Cp202200800458View 消息处理程序


void Cp202200800458View::OnRu()
{
	// TODO: 在此添加命令处理程序代码
	dlgg ob;
	if (ob.DoModal() == IDOK)
	{

		pro* my_pro = new pro(ob.edit1,ob.edit2,ob.edit5,ob.edit6,ob.edit3,ob.edit7,ob.edit8,ob.edit4);
		if (GetDocument()->AddOnePro(my_pro))
		{
			InvalidateRect(NULL);
		}
	}
}
int pai = 1;

void Cp202200800458View::OnPaiName()
{
	// TODO: 在此添加命令处理程序代码
	pai = 2;
	InvalidateRect(NULL);
}


void Cp202200800458View::OnPaiNum()
{
	// TODO: 在此添加命令处理程序代码
	pai = 1;
	InvalidateRect(NULL);
}
