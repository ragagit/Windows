// ConfigPropPageOne.cpp : implementation file
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "ConfigPropPageOne.h"
#include "afxdialogex.h"
#include "resource.h"

IMPLEMENT_DYNAMIC(CConfigPropPageOne, CPropertyPage)

CConfigPropPageOne::CConfigPropPageOne()
	: CPropertyPage(CConfigPropPageOne::IDD)
{
	
}

CConfigPropPageOne::~CConfigPropPageOne()
{
}

void CConfigPropPageOne::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_LOG_LEVEL, m_ctrCBLogLevel);
	DDX_Control(pDX, IDC_EDIT_LOG_PATH, m_ctrEdLogPath);
}


BEGIN_MESSAGE_MAP(CConfigPropPageOne, CPropertyPage)
	ON_BN_CLICKED(IDC_BTN_LOG_PATH, &CConfigPropPageOne::OnBnClickedBtnLogPath)
	ON_CBN_SELCHANGE(IDC_COMBO_LOG_LEVEL, &CConfigPropPageOne::OnCbnSelchangeComboLogLevel)
	ON_EN_CHANGE(IDC_EDIT_LOG_PATH, &CConfigPropPageOne::OnEnChangeEditLogPath)
END_MESSAGE_MAP()




/**
	@brief		It calls all the initialization functions for
				this property page
	@param		None
	@return		BOOL
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
BOOL CConfigPropPageOne::OnInitDialog()
{
	BOOL bRet = true;

	CDialog::OnInitDialog();

	initLoggingSection();

	return bRet;

}
	 
/**
	@brief		It initializes the loggin section in the property page.
				Build the log combo box option and initializes with values
				read from the XML config file.
	@param		None
	@return		SUCCESS
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int CConfigPropPageOne::initLoggingSection()
{
	int nRet = SUCCESS;

	CString szLogLevel;
	CString szLogPath;
	CConfigToolDoc *pDoc = CConfigToolDoc::GetDoc();

	// Log Level
	m_ctrCBLogLevel.InsertString(0, EMERGENCY);
	m_ctrCBLogLevel.InsertString(1, ALERT);
	m_ctrCBLogLevel.InsertString(2, CRITICAL);
	m_ctrCBLogLevel.InsertString(3, ERR);
	m_ctrCBLogLevel.InsertString(4, WARNING);
	m_ctrCBLogLevel.InsertString(5, NOTICE);
	m_ctrCBLogLevel.InsertString(6, INFORMATIONAL);
	m_ctrCBLogLevel.InsertString(7, DBG );

	pDoc->getPPOneLogLevel(szLogLevel);

	if (!szLogLevel.CompareNoCase(EMERGENCY))
		m_ctrCBLogLevel.SetCurSel(0);
	if (!szLogLevel.CompareNoCase(ALERT))
		m_ctrCBLogLevel.SetCurSel(1);
	if (!szLogLevel.CompareNoCase(CRITICAL))
		m_ctrCBLogLevel.SetCurSel(2);
	if (!szLogLevel.CompareNoCase(ERR))
		m_ctrCBLogLevel.SetCurSel(3);
	if (!szLogLevel.CompareNoCase(WARNING))
		m_ctrCBLogLevel.SetCurSel(4);
	if (!szLogLevel.CompareNoCase(NOTICE))
		m_ctrCBLogLevel.SetCurSel(5);
	if (!szLogLevel.CompareNoCase(INFORMATIONAL))
		m_ctrCBLogLevel.SetCurSel(6);
	if (!szLogLevel.CompareNoCase(DBG))
		m_ctrCBLogLevel.SetCurSel(7);

	// Log Path
	pDoc->getPPOneLogPath(szLogPath);
	m_ctrEdLogPath.SetWindowTextW(szLogPath);
	
	return nRet;
}
	 
/**
	@brief		It sets the values of teh variables in the Doc 
	@param		None
	@return		SUCCESS
	@author		RG
	@date		2014-Aug-19
	@remarks	Not currently used
*/
int CConfigPropPageOne::getControlsValues()
{
	int nRet = SUCCESS;
	CString szValue;
	int nVal;
	CConfigToolDoc *pDoc = CConfigToolDoc::GetDoc();

	//Log Level
	nVal = m_ctrCBLogLevel.GetCurSel();
	switch (nVal)
	{
	case 0:
		szValue = EMERGENCY;
	case 1:
		szValue = ALERT;
	case 2:
		szValue = CRITICAL;
	case 3:
		szValue = ERR;
	case 4:
		szValue = WARNING;
	case 5:
		szValue = NOTICE;
	case 6:
		szValue = INFORMATIONAL;
	case 7:
		szValue = DBG;
	}
	pDoc->setPPOneLogLevel(szValue);

	//Log Path
	m_ctrEdLogPath.GetWindowText(szValue);
	pDoc->setPPOneLogPath(szValue);



	return nRet;
}
	 
/**
	@brief		It launches the File dialog to choose the location 
				and name of the log file
	@param		None
	@return		void
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
void CConfigPropPageOne::OnBnClickedBtnLogPath()
{
	LPCTSTR pszFilter = _T("Log files (*.log)|*.log");
	CString szConfigFileName;

	CFileDialog dlgFile(TRUE, NULL, NULL,
		OFN_HIDEREADONLY,
		pszFilter,
		AfxGetMainWnd());

	if (IDOK == dlgFile.DoModal())
	{
		szConfigFileName = dlgFile.GetPathName();

		if (!szConfigFileName.IsEmpty()){
			CConfigToolDoc *pDoc = CConfigToolDoc::GetDoc();
			pDoc->setPPOneLogPath(szConfigFileName);
		}
	}

}
		 
/**
	@brief		Even handler for the log level combo box.
				It updates Doc template log level variable
	@param		None
	@return		void
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
void CConfigPropPageOne::OnCbnSelchangeComboLogLevel()
{
	CString szValue;
	int nVal;
	CConfigToolDoc *pDoc = CConfigToolDoc::GetDoc();

	nVal = m_ctrCBLogLevel.GetCurSel();

	switch (nVal)
	{
	case 0:
		szValue = EMERGENCY;
		break;
	case 1:
		szValue = ALERT;
		break;
	case 2:
		szValue = CRITICAL;
		break;
	case 3:
		szValue = ERR;
		break;
	case 4:
		szValue = WARNING;
		break;
	case 5:
		szValue = NOTICE;
		break;
	case 6:
		szValue = INFORMATIONAL;
		break;
	case 7:
		szValue = DBG;
		break;
	}
	pDoc->setPPOneLogLevel(szValue);
}
	 
/**
	@brief		Handler of the log path. Get the path and name of the log file
	@param		None
	@return		void
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
void CConfigPropPageOne::OnEnChangeEditLogPath()
{
	CString szValue;
	CConfigToolDoc *pDoc = CConfigToolDoc::GetDoc();

	m_ctrEdLogPath.GetWindowText(szValue);
	pDoc->setPPOneLogPath(szValue);

}
