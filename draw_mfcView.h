
// draw_mfcView.h: CdrawmfcView 类的接口
//

#pragma once


class CdrawmfcView : public CView
{
protected: // 仅从序列化创建
	CdrawmfcView() noexcept;
	DECLARE_DYNCREATE(CdrawmfcView)

private://绘图变量
	UINT m_DRAWMODE;
	UINT m_CHOOSEMODE;
	//绘图中间参数
	POINT m_ptStart;
// 特性
public:
	CdrawmfcDoc* GetDocument() const;
	COLORREF m_LineColor;
	COLORREF m_BrushColor;
	COLORREF m_TextColor;
	LOGFONT m_Font;
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
	virtual ~CdrawmfcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnDrawChoose();
//	afx_msg void OnUpdateDrawChoose(CCmdUI* pCmdUI);
	afx_msg void OnDrawChoose();
	afx_msg void OnDrawCircle();
	afx_msg void OnDrawLine();
	afx_msg void OnDrawRect();
	afx_msg void OnDrawText();
	afx_msg void OnUpdateDrawChoose(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawCircle(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawRect(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawText(CCmdUI* pCmdUI);
	afx_msg void OnChooseFillcolor();
	afx_msg void OnChooseLinecolor();
	afx_msg void OnChooseTextcolor();
	afx_msg void OnChooseTextfont();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnCjhooseFillcolor();
	afx_msg void OnCjhooseLinecolor();
	afx_msg void OnCjhooseTextcolor();
	afx_msg void OnCjhooseTextfont();
	afx_msg void OnUpdateChooseFillcolor(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // draw_mfcView.cpp 中的调试版本
inline CdrawmfcDoc* CdrawmfcView::GetDocument() const
   { return reinterpret_cast<CdrawmfcDoc*>(m_pDocument); }
#endif

