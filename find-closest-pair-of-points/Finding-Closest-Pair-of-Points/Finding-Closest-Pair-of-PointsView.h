
// Finding-Closest-Pair-of-PointsView.h : CFindingClosestPairofPointsView ��Ľӿ�
//

#pragma once


class CFindingClosestPairofPointsView : public CView
{
protected: // �������л�����
	CFindingClosestPairofPointsView();
	DECLARE_DYNCREATE(CFindingClosestPairofPointsView)

// ����
public:
	CFindingClosestPairofPointsDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CFindingClosestPairofPointsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Finding-Closest-Pair-of-PointsView.cpp �еĵ��԰汾
inline CFindingClosestPairofPointsDoc* CFindingClosestPairofPointsView::GetDocument() const
   { return reinterpret_cast<CFindingClosestPairofPointsDoc*>(m_pDocument); }
#endif

