
// p202200800458Doc.h: Cp202200800458Doc 类的接口
//


#pragma once

#include "proo.h"
class Cp202200800458Doc : public CDocument
{
protected: // 仅从序列化创建
	Cp202200800458Doc() noexcept;
	DECLARE_DYNCREATE(Cp202200800458Doc)

	// 特性
public:	// 绘图数据缓存
	CArray<pro*, pro*>  pros;
public:

	// 操作
public:
	BOOL Cp202200800458Doc::AddOnePro(pro* p);
	void Cp202200800458Doc::DrawAllPro(CDC* pDC);
	BOOL Cp202200800458Doc::FreeAllPro();

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~Cp202200800458Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
