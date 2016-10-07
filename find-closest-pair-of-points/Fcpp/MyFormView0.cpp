// MyFormView0.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Fcpp.h"

#include "MainFrm.h"
#include "FcppDoc.h"
#include "FcppView.h"
#include "MyFormView0.h"

#include "Point.h"
#include "PointPair.h"
#include "Utils.h"


// CMyFormView0

IMPLEMENT_DYNCREATE(CMyFormView0, CFormView)

CMyFormView0::CMyFormView0()
	: CFormView(CMyFormView0::IDD)
{

}

CMyFormView0::~CMyFormView0()
{
}

void CMyFormView0::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyFormView0, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyFormView0::OnBnClickedButton1)
//	ON_WM_GETMINMAXINFO()
ON_BN_CLICKED(IDC_BUTTON2, &CMyFormView0::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON3, &CMyFormView0::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON4, &CMyFormView0::OnBnClickedButton4)
END_MESSAGE_MAP()


// CMyFormView0 ���

#ifdef _DEBUG
void CMyFormView0::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyFormView0::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyFormView0 ��Ϣ�������


void CMyFormView0::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	double t_start = 0.0, t_end = 0.0;
	CString str, s0;
	//��¼��ʼʱ��
	t_start = (double)clock() / CLOCKS_PER_SEC;
	qsort(point_x, cnt, sizeof(int), Utils::cmp_int);
	int closest_distance_square = Utils::find_closest_pair_of_points(point_set, 0, cnt - 1);
	//��¼����ʱ��
	t_end = (double)clock() / CLOCKS_PER_SEC;
	//�������ʱ��
	str = "Calc Time used = ";
	s0.Format("%lf", t_end - t_start);
	str += s0 + _T("\r\n");

	str += "Distancce: ";
	s0.Format("%lf", sqrt((double)closest_distance_square));
	str += s0 + _T("\r\n");

	str += "Closest pair of points:";
	str += _T("\r\n");
	
	CString s1, s2, s3, s4;
	CMainFrame* pAppFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CFcppView *pView = (CFcppView *)pAppFrame->m_splitter.GetPane(0, 0);
	CClientDC dc(pView);
	for (set<PointPair>::iterator it = closest_pair_of_points.begin(); it != closest_pair_of_points.end(); ++it)
	{
		//����
		dc.MoveTo(CPoint(it->A.x, it->A.y));
		dc.LineTo(CPoint(it->B.x, it->B.y));

		s1.Format("%d", it->A.x);
		s2.Format("%d", it->A.y);
		s3.Format("%d", it->B.x);
		s4.Format("%d", it->B.y);
		str += "(" + s1 + "," + s2
			+ ") and (" + s3 + "," + s4 + ")" + _T("\r\n");
		
	}

	SetDlgItemText(IDC_EDIT1, str);
}



void CMyFormView0::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//��ԭ����������0
	cnt = 0;
	//��ȡ��ǰ��ͼ�Ĵ�С
	CRect rc;
	CMainFrame* pAppFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CFcppView *pView = (CFcppView *)pAppFrame->m_splitter.GetPane(0, 0);
	pView->GetClientRect(&rc);
	//�������100�����
	int a = 0, b = 0;
	for (int i = 0; i < 10000; i++)
	{
		a = rand() % (rc.right - rc.left);
		b = rand() % (rc.top - rc.bottom);
		point_x[cnt] = a;
		point_set[cnt++] = Point(a,b);
	}

	//���㲿��
	double t_start = 0.0, t_end = 0.0;
	CString str, s0;
	//��¼��ʼʱ��
	t_start = (double)clock() / CLOCKS_PER_SEC;
	qsort(point_x, cnt, sizeof(int), Utils::cmp_int);
	int closest_distance_square = Utils::find_closest_pair_of_points(point_set, 0, cnt - 1);
	//��¼����ʱ��
	t_end = (double)clock() / CLOCKS_PER_SEC;
	//�������ʱ��
	str = "Calc Time used = ";
	s0.Format("%lf", t_end - t_start);
	str += s0 + _T("\r\n");

	str += "Distancce: ";
	s0.Format("%lf", sqrt((double)closest_distance_square));
	str += s0 + _T("\r\n");

	str += "Closest pair of points:";
	str += _T("\r\n");

	CString s1, s2, s3, s4;
	CClientDC dc(pView);
	for (set<PointPair>::iterator it = closest_pair_of_points.begin(); it != closest_pair_of_points.end(); ++it)
	{
		//����
		dc.MoveTo(CPoint(it->A.x, it->A.y));
		dc.LineTo(CPoint(it->B.x, it->B.y));
		//����
		CBrush brush, *oldbrush;
		brush.CreateSolidBrush(RGB(0xD1, 0xFB, 0xFD));
		oldbrush = dc.SelectObject(&brush);
		dc.Ellipse(it->A.x - 3, it->A.y - 3, it->A.x + 3, it->A.y + 3);
		dc.Ellipse(it->B.x - 3, it->B.y - 3, it->B.x + 3, it->B.y + 3);
		dc.SelectObject(oldbrush);

		s1.Format("%d", it->A.x);
		s2.Format("%d", it->A.y);
		s3.Format("%d", it->B.x);
		s4.Format("%d", it->B.y);
		str += "(" + s1 + "," + s2
			+ ") and (" + s3 + "," + s4 + ")" + _T("\r\n");

	}

	SetDlgItemText(IDC_EDIT1, str);

	//�����ݼ�����
	cnt = 0;
}


void CMyFormView0::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//��ԭ����������0
	cnt = 0;
	//��ȡ��ǰ��ͼ�Ĵ�С
	CRect rc;
	CMainFrame* pAppFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CFcppView *pView = (CFcppView *)pAppFrame->m_splitter.GetPane(0, 0);
	pView->GetClientRect(&rc);
	//�������100�����
	int a = 0, b = 0;
	for (int i = 0; i < 100000; i++)
	{
		a = rand() % (rc.right - rc.left);
		b = rand() % (rc.top - rc.bottom);
		point_x[cnt] = a;
		point_set[cnt++] = Point(a, b);
	}

	//���㲿��
	double t_start = 0.0, t_end = 0.0;
	CString str, s0;
	//��¼��ʼʱ��
	t_start = (double)clock() / CLOCKS_PER_SEC;
	qsort(point_x, cnt, sizeof(int), Utils::cmp_int);
	int closest_distance_square = Utils::find_closest_pair_of_points(point_set, 0, cnt - 1);
	//��¼����ʱ��
	t_end = (double)clock() / CLOCKS_PER_SEC;
	//�������ʱ��
	str = "Calc Time used = ";
	s0.Format("%lf", t_end - t_start);
	str += s0 + _T("\r\n");

	str += "Distancce: ";
	s0.Format("%lf", sqrt((double)closest_distance_square));
	str += s0 + _T("\r\n");

	str += "Closest pair of points:";
	str += _T("\r\n");

	CString s1, s2, s3, s4;
	CClientDC dc(pView);
	for (set<PointPair>::iterator it = closest_pair_of_points.begin(); it != closest_pair_of_points.end(); ++it)
	{
		//����
		dc.MoveTo(CPoint(it->A.x, it->A.y));
		dc.LineTo(CPoint(it->B.x, it->B.y));
		//����
		CBrush brush, *oldbrush;
		brush.CreateSolidBrush(RGB(0xD1, 0xFB, 0xFD));
		oldbrush = dc.SelectObject(&brush);
		dc.Ellipse(it->A.x - 3, it->A.y - 3, it->A.x + 3, it->A.y + 3);
		dc.Ellipse(it->B.x - 3, it->B.y - 3, it->B.x + 3, it->B.y + 3);
		dc.SelectObject(oldbrush);

		s1.Format("%d", it->A.x);
		s2.Format("%d", it->A.y);
		s3.Format("%d", it->B.x);
		s4.Format("%d", it->B.y);
		str += "(" + s1 + "," + s2
			+ ") and (" + s3 + "," + s4 + ")" + _T("\r\n");

	}

	SetDlgItemText(IDC_EDIT1, str);

	//�����ݼ�����
	cnt = 0;
}


void CMyFormView0::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//��ԭ����������0
	cnt = 0;
	//��ȡ��ǰ��ͼ�Ĵ�С
	CRect rc;
	CMainFrame* pAppFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CFcppView *pView = (CFcppView *)pAppFrame->m_splitter.GetPane(0, 0);
	pView->GetClientRect(&rc);
	//�������100�����
	int a = 0, b = 0;
	for (int i = 0; i < 1000000; i++)
	{
		a = rand() % (rc.right - rc.left);
		b = rand() % (rc.top - rc.bottom);
		point_x[cnt] = a;
		point_set[cnt++] = Point(a, b);
	}

	//���㲿��
	double t_start = 0.0, t_end = 0.0;
	CString str, s0;
	//��¼��ʼʱ��
	t_start = (double)clock() / CLOCKS_PER_SEC;
	qsort(point_x, cnt, sizeof(int), Utils::cmp_int);
	int closest_distance_square = Utils::find_closest_pair_of_points(point_set, 0, cnt - 1);
	//��¼����ʱ��
	t_end = (double)clock() / CLOCKS_PER_SEC;
	//�������ʱ��
	str = "Calc Time used = ";
	s0.Format("%lf", t_end - t_start);
	str += s0 + _T("\r\n");

	str += "Distancce: ";
	s0.Format("%lf", sqrt((double)closest_distance_square));
	str += s0 + _T("\r\n");

	str += "Closest pair of points:";
	str += _T("\r\n");

	CString s1, s2, s3, s4;
	CClientDC dc(pView);
	for (set<PointPair>::iterator it = closest_pair_of_points.begin(); it != closest_pair_of_points.end(); ++it)
	{
		//����
		dc.MoveTo(CPoint(it->A.x, it->A.y));
		dc.LineTo(CPoint(it->B.x, it->B.y));
		//����
		CBrush brush, *oldbrush;
		brush.CreateSolidBrush(RGB(0xD1, 0xFB, 0xFD));
		oldbrush = dc.SelectObject(&brush);
		dc.Ellipse(it->A.x - 3, it->A.y - 3, it->A.x + 3, it->A.y + 3);
		dc.Ellipse(it->B.x - 3, it->B.y - 3, it->B.x + 3, it->B.y + 3);
		dc.SelectObject(oldbrush);

		s1.Format("%d", it->A.x);
		s2.Format("%d", it->A.y);
		s3.Format("%d", it->B.x);
		s4.Format("%d", it->B.y);
		str += "(" + s1 + "," + s2
			+ ") and (" + s3 + "," + s4 + ")" + _T("\r\n");

	}

	SetDlgItemText(IDC_EDIT1, str);

	//�����ݼ�����
	cnt = 0;
}
