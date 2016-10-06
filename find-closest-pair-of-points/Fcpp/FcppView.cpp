
// FcppView.cpp : CFcppView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Fcpp.h"
#endif

#include "FcppDoc.h"
#include "FcppView.h"


#include "Point.h"
#include "PointPair.h"
#include "Utils.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFcppView

IMPLEMENT_DYNCREATE(CFcppView, CView)

BEGIN_MESSAGE_MAP(CFcppView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CFcppView ����/����

CFcppView::CFcppView()
{
	// TODO:  �ڴ˴���ӹ������

}

CFcppView::~CFcppView()
{
}

BOOL CFcppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CFcppView ����

void CFcppView::OnDraw(CDC* /*pDC*/)
{
	CFcppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CFcppView ��ӡ

BOOL CFcppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CFcppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CFcppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CFcppView ���

#ifdef _DEBUG
void CFcppView::AssertValid() const
{
	CView::AssertValid();
}

void CFcppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFcppDoc* CFcppView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFcppDoc)));
	return (CFcppDoc*)m_pDocument;
}
#endif //_DEBUG


// CFcppView ��Ϣ�������


void CFcppView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//�����ϻ��Ƶ�
	CClientDC dc(this);
	CBrush brush, *oldbrush;
	brush.CreateSolidBrush(RGB(0xD1, 0xFB, 0xFD));
	oldbrush = dc.SelectObject(&brush);
	dc.Ellipse(point.x - 4, point.y - 4, point.x + 4, point.y + 4);
	dc.SelectObject(oldbrush);

	//����洢����
	point_x[cnt] = point.x;
	point_set[cnt++] = Point(point.x, point.y);

	CView::OnLButtonDown(nFlags, point);
}
