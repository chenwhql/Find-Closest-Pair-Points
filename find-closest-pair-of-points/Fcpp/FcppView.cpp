
// FcppView.cpp : CFcppView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CFcppView 构造/析构

CFcppView::CFcppView()
{
	// TODO:  在此处添加构造代码

}

CFcppView::~CFcppView()
{
}

BOOL CFcppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CFcppView 绘制

void CFcppView::OnDraw(CDC* /*pDC*/)
{
	CFcppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CFcppView 打印

BOOL CFcppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CFcppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CFcppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CFcppView 诊断

#ifdef _DEBUG
void CFcppView::AssertValid() const
{
	CView::AssertValid();
}

void CFcppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFcppDoc* CFcppView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFcppDoc)));
	return (CFcppDoc*)m_pDocument;
}
#endif //_DEBUG


// CFcppView 消息处理程序


void CFcppView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	//界面上绘制点
	CClientDC dc(this);
	CBrush brush, *oldbrush;
	brush.CreateSolidBrush(RGB(0xD1, 0xFB, 0xFD));
	oldbrush = dc.SelectObject(&brush);
	dc.Ellipse(point.x - 4, point.y - 4, point.x + 4, point.y + 4);
	dc.SelectObject(oldbrush);

	//将点存储下来
	point_x[cnt] = point.x;
	point_set[cnt++] = Point(point.x, point.y);

	CView::OnLButtonDown(nFlags, point);
}
