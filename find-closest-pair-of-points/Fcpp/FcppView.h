
// FcppView.h : CFcppView 类的接口
//

#pragma once

class CFcppView : public CView
{
protected: // 仅从序列化创建
	CFcppView();
	DECLARE_DYNCREATE(CFcppView)

// 特性
public:
	CFcppDoc* GetDocument() const;

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
	virtual ~CFcppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // FcppView.cpp 中的调试版本
inline CFcppDoc* CFcppView::GetDocument() const
   { return reinterpret_cast<CFcppDoc*>(m_pDocument); }
#endif

