
// Finding-Closest-Pair-of-PointsView.cpp : CFindingClosestPairofPointsView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Finding-Closest-Pair-of-Points.h"
#endif

#include "Finding-Closest-Pair-of-PointsDoc.h"
#include "Finding-Closest-Pair-of-PointsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFindingClosestPairofPointsView

IMPLEMENT_DYNCREATE(CFindingClosestPairofPointsView, CView)

BEGIN_MESSAGE_MAP(CFindingClosestPairofPointsView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CFindingClosestPairofPointsView ����/����

CFindingClosestPairofPointsView::CFindingClosestPairofPointsView()
{
	// TODO:  �ڴ˴���ӹ������

}

CFindingClosestPairofPointsView::~CFindingClosestPairofPointsView()
{
}

BOOL CFindingClosestPairofPointsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CFindingClosestPairofPointsView ����

void CFindingClosestPairofPointsView::OnDraw(CDC* /*pDC*/)
{
	CFindingClosestPairofPointsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CFindingClosestPairofPointsView ��ӡ

BOOL CFindingClosestPairofPointsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CFindingClosestPairofPointsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CFindingClosestPairofPointsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CFindingClosestPairofPointsView ���

#ifdef _DEBUG
void CFindingClosestPairofPointsView::AssertValid() const
{
	CView::AssertValid();
}

void CFindingClosestPairofPointsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFindingClosestPairofPointsDoc* CFindingClosestPairofPointsView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFindingClosestPairofPointsDoc)));
	return (CFindingClosestPairofPointsDoc*)m_pDocument;
}
#endif //_DEBUG


// CFindingClosestPairofPointsView ��Ϣ�������
