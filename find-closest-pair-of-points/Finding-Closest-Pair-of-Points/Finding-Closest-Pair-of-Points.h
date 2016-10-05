
// Finding-Closest-Pair-of-Points.h : Finding-Closest-Pair-of-Points 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CFindingClosestPairofPointsApp:
// 有关此类的实现，请参阅 Finding-Closest-Pair-of-Points.cpp
//

class CFindingClosestPairofPointsApp : public CWinApp
{
public:
	CFindingClosestPairofPointsApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFindingClosestPairofPointsApp theApp;
