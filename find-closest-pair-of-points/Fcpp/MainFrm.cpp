
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "Fcpp.h"

#include "MainFrm.h"
#include "FcppDoc.h"
#include "FcppView.h"
#include "MyFormView0.h"

#include<ctime>
#include<cstdlib>
#include<set>
#include<algorithm>

#include "Point.h"
#include "PointPair.h"
#include "Utils.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
//	ON_WM_GETMINMAXINFO()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO:  在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO:  如果不需要可停靠工具栏，则删除这三行
	//m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	//DockControlBar(&m_wndToolBar);

	CenterWindow(NULL);

	//随机数种子初始化
	srand(time(NULL));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.style &= ~WS_MAXIMIZEBOX; //禁止窗口最大化
	cs.style &= ~WS_THICKFRAME;//使窗口不能用鼠标改变大小
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO:  在此添加专用代码和/或调用基类
	CRect rc;
	GetClientRect(&rc);
	//创建一个静态分栏窗口，分为一行二列 
	if (m_splitter.CreateStatic(this, 1, 2) == NULL)
		return FALSE;

	//将CCSplitterWndView连接到0行0列窗格上
	m_splitter.CreateView(0, 0, RUNTIME_CLASS(CFcppView), 
		CSize((rc.right-rc.left)+100, rc.top-rc.bottom), pContext);
	m_splitter.CreateView(0, 1, RUNTIME_CLASS(CMyFormView0), 
		CSize(200, rc.top - rc.bottom), pContext);

	return true;
}