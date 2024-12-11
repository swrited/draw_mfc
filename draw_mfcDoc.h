﻿
// draw_mfcDoc.h: CdrawmfcDoc 类的接口
//


#pragma once

#define GRAPH_BUF_MAX 10
#include "graph.h"
class CdrawmfcDoc : public CDocument
{
protected: // 仅从序列化创建
	CdrawmfcDoc() noexcept;
	DECLARE_DYNCREATE(CdrawmfcDoc)
private:	// 绘图数据缓存
	UINT m_count;
	CGraph* m_pGraphs[GRAPH_BUF_MAX];
// 特性
public:

// 操作
public:
	BOOL AddOneGraph(CGraph* p);
	void CdrawmfcDoc::DrawAllGraph(CDC* pDC);
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
	virtual ~CdrawmfcDoc();
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
