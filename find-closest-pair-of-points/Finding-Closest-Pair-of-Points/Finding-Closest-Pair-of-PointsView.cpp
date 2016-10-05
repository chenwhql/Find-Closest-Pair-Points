
// Finding-Closest-Pair-of-PointsView.cpp : CFindingClosestPairofPointsView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CFindingClosestPairofPointsView 构造/析构

CFindingClosestPairofPointsView::CFindingClosestPairofPointsView()
{
	// TODO:  在此处添加构造代码

}

CFindingClosestPairofPointsView::~CFindingClosestPairofPointsView()
{
}

BOOL CFindingClosestPairofPointsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CFindingClosestPairofPointsView 绘制

void CFindingClosestPairofPointsView::OnDraw(CDC* /*pDC*/)
{
	CFindingClosestPairofPointsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CFindingClosestPairofPointsView 打印

BOOL CFindingClosestPairofPointsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CFindingClosestPairofPointsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CFindingClosestPairofPointsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CFindingClosestPairofPointsView 诊断

#ifdef _DEBUG
void CFindingClosestPairofPointsView::AssertValid() const
{
	CView::AssertValid();
}

void CFindingClosestPairofPointsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFindingClosestPairofPointsDoc* CFindingClosestPairofPointsView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFindingClosestPairofPointsDoc)));
	return (CFindingClosestPairofPointsDoc*)m_pDocument;
}
#endif //_DEBUG


// CFindingClosestPairofPointsView 消息处理程序
