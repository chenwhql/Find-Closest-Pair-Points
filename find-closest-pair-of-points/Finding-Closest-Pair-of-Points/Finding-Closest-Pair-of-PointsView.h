
// Finding-Closest-Pair-of-PointsView.h : CFindingClosestPairofPointsView 类的接口
//

#pragma once


class CFindingClosestPairofPointsView : public CView
{
protected: // 仅从序列化创建
	CFindingClosestPairofPointsView();
	DECLARE_DYNCREATE(CFindingClosestPairofPointsView)

// 特性
public:
	CFindingClosestPairofPointsDoc* GetDocument() const;

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
	virtual ~CFindingClosestPairofPointsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Finding-Closest-Pair-of-PointsView.cpp 中的调试版本
inline CFindingClosestPairofPointsDoc* CFindingClosestPairofPointsView::GetDocument() const
   { return reinterpret_cast<CFindingClosestPairofPointsDoc*>(m_pDocument); }
#endif

