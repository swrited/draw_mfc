﻿
// p202200800458View.h: Cp202200800458View 类的接口
//

#pragma once


class Cp202200800458View : public CView
{
protected: // 仅从序列化创建
	Cp202200800458View() noexcept;
	DECLARE_DYNCREATE(Cp202200800458View)

// 特性
public:
	Cp202200800458Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Cp202200800458View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRu();
	afx_msg void OnPaiName();
	afx_msg void OnPaiNum();
};

#ifndef _DEBUG  // p202200800458View.cpp 中的调试版本
inline Cp202200800458Doc* Cp202200800458View::GetDocument() const
   { return reinterpret_cast<Cp202200800458Doc*>(m_pDocument); }
#endif

