#pragma once



// CMyFormView0 ������ͼ

class CMyFormView0 : public CFormView
{
	DECLARE_DYNCREATE(CMyFormView0)

protected:
	CMyFormView0();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
//	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};


