#pragma once



// CMyFormView0 窗体视图

class CMyFormView0 : public CFormView
{
	DECLARE_DYNCREATE(CMyFormView0)

protected:
	CMyFormView0();           // 动态创建所使用的受保护的构造函数
	virtual ~CMyFormView0();

public:
	enum { IDD = IDD_DIALOG1 };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
//	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};


