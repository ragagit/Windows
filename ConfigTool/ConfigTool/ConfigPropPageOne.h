#pragma once
#include "afxwin.h"
#include "ConfigToolDoc.h"
#include "log.h"


// CConfigPropPageOne dialog

/** This is one of the Config Tool Property pages

More descriptiopn is needed

*/

class CConfigPropPageOne : public CPropertyPage
{
	DECLARE_DYNAMIC(CConfigPropPageOne)

public:
	CConfigPropPageOne();
	virtual ~CConfigPropPageOne();

// Dialog Data
	enum { IDD = IDD_CONFIGPROPPAGEONE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	//virtual BOOL OnSetActive();
	//virtual BOOL OnKillActive();

	DECLARE_MESSAGE_MAP()

public:
	//Functions
	int initLoggingSection();
	afx_msg void OnBnClickedBtnLogPath();
	int getControlsValues();

	//Variables
	CEdit m_ctrEdLogPath;
	CComboBox m_ctrCBLogLevel;
	afx_msg void OnCbnSelchangeComboLogLevel();
	afx_msg void OnEnChangeEditLogPath();
};
