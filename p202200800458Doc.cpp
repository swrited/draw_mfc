
// p202200800458Doc.cpp: Cp202200800458Doc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "p202200800458.h"
#endif

#include "p202200800458Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cp202200800458Doc

IMPLEMENT_DYNCREATE(Cp202200800458Doc, CDocument)

BEGIN_MESSAGE_MAP(Cp202200800458Doc, CDocument)
END_MESSAGE_MAP()


// Cp202200800458Doc 构造/析构

Cp202200800458Doc::Cp202200800458Doc() noexcept
{
	// TODO: 在此添加一次性构造代码

}

Cp202200800458Doc::~Cp202200800458Doc()
{
}

BOOL Cp202200800458Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}
BOOL Cp202200800458Doc::AddOnePro(pro* p)
{
	pros.Add(p);
	TRACE1("新增了一个app，现在总个数：%d\r\n", pros.GetCount());
	SetModifiedFlag();
	return TRUE;
}
int sum = 0;
int bi = 0;
extern int pai;
void Cp202200800458Doc::DrawAllPro(CDC* pDC)
{
	UINT count = pros.GetCount();
	if (pai == 1)
	{
		for (UINT i = 0; i < count; i++)
		{
			for (UINT j = 0; j < count; j++)
				if (pros[i]->get_cheng() > pros[j]->get_cheng())
				{
					pro* temp;
					temp = pros[j];
					pros[j] = pros[i];
					pros[i] = temp;

				}
		}
	}
	else if (pai == 2)
	{
		for (UINT i = 0; i < count; i++)
		{
			for (UINT j = 0; j < count; j++)
				if (pros[i]->get_name()[0] < pros[j]->get_name()[0])
				{
					pro* temp;
					temp = pros[j];
					pros[j] = pros[i];
					pros[i] = temp;

				}
		}
	}
	sum = 0;
	for (UINT i = 0; i < count; i++)
	{
		sum += pros[i]->get_cheng();
	}
	if (count == 0)
		bi = 0;
	else
		bi = sum / count;
	TCHAR a[100];
	wsprintf(a, TEXT("当前总项目数:%d     总研发投入金额%d      项目平均投入金额%d"), count,sum,bi);
	pDC->TextOut(200, 0, a);
	for (UINT i = 0; i < count; i++)
	{
		pros[i]->show(pDC, i);
		pros[i]->show_rect(pDC, i);
	}
}
BOOL Cp202200800458Doc::FreeAllPro()
{
	UINT count = pros.GetCount();

	for (UINT u = 0; u < count; u++)
	{
		delete pros[u];
	}
	pros.RemoveAll();
	return 1;
}



// Cp202200800458Doc 序列化

void Cp202200800458Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		UINT count = pros.GetCount();
		ar << count;
		for (UINT u = 0; u < count; u++)
		{
			pros[u]->Save(ar);
		}
	}
	else
	{
		// TODO: 在此添加加载代码
		UINT count = 0;
		ar >> count;
		for (UINT u = 0; u < count; u++)
		{
			pro* p = NULL;
			p = new pro();
			ASSERT(p != NULL);
			if (p != NULL)
			{
				p->Load(ar);
				pros.Add(p);
			}
		}
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void Cp202200800458Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void Cp202200800458Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void Cp202200800458Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Cp202200800458Doc 诊断

#ifdef _DEBUG
void Cp202200800458Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cp202200800458Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cp202200800458Doc 命令
