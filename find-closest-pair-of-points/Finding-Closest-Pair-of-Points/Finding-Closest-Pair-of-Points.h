
// Finding-Closest-Pair-of-Points.h : Finding-Closest-Pair-of-Points Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CFindingClosestPairofPointsApp:
// �йش����ʵ�֣������ Finding-Closest-Pair-of-Points.cpp
//

class CFindingClosestPairofPointsApp : public CWinApp
{
public:
	CFindingClosestPairofPointsApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFindingClosestPairofPointsApp theApp;
