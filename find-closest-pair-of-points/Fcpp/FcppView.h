
// FcppView.h : CFcppView ��Ľӿ�
//

#pragma once

class CFcppView : public CView
{
protected: // �������л�����
	CFcppView();
	DECLARE_DYNCREATE(CFcppView)

// ����
public:
	CFcppDoc* GetDocument() const;

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
	virtual ~CFcppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // FcppView.cpp �еĵ��԰汾
inline CFcppDoc* CFcppView::GetDocument() const
   { return reinterpret_cast<CFcppDoc*>(m_pDocument); }
#endif

