
// mywebDlg.h : header file
//

#pragma once
#include "explorer1.h"


// CmywebDlg dialog
class CmywebDlg : public CDialog
{
// Construction
public:
	CmywebDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MYWEB_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CExplorer1 m_browser;
	afx_msg void OnBnClickedPrint();
	afx_msg void OnBnClickedButton1();
	CString m_szFileName;
};
