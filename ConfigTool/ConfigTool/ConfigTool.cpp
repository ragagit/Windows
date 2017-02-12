
// ConfigTool.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "ConfigTool.h"
#include "MainFrm.h"

#include "ConfigToolDoc.h"
#include "ConfigToolView.h"

#include <afxadv.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CConfigToolApp

BEGIN_MESSAGE_MAP(CConfigToolApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CConfigToolApp::OnAppAbout)
END_MESSAGE_MAP()




CConfigToolApp::CConfigToolApp()
{
	m_bHiColorIcons = TRUE;

	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// If the application is built using Common Language Runtime support (/clr):
	//     1) This additional setting is needed for Restart Manager support to work properly.
	//     2) In your project, you must add a reference to System.Windows.Forms in order to build.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("ConfigTool.AppID.NoVersion"));

}

// The one and only CConfigToolApp object
CConfigToolApp theApp;


// CConfigToolApp initialization
BOOL CConfigToolApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() is required to use RichEdit control	
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("ConfigTool"));
	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)
	InitContextMenuManager();
	InitKeyboardManager();
	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CConfigToolDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CConfigToolView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

// Rdcent Files Open handling code
/**
	@brief		It gets any of the four most recent files open
				By default it returns the latest which has index 0.
				It uses the undocumented variable m_pRecentFileList
				in CWinApp. A call of LoadStdProfileSettings(4) in 
				InitInstance is required. The values are stored in 
				HKEY_CURRENT_USER\SOFTWARE\ConfigTool\Recent Files.
				It gets called by the Doc class
	@param		CString szReecentFileOpen OUT 
				int nIndex IN index of the file
	@return		SUCCESS
	@author		RG
	@date		2014-Aug-19
	@remarks	If inxed goes beyond 4 it returns file index 0;
*/
int	 CConfigToolApp::getRecentFileOpen(CString &szRecentFileOpen, int nIndex)
{
	int nRet = SUCCESS;

	if (nIndex > 3)nIndex = 0;

	szRecentFileOpen = (LPCTSTR)(*m_pRecentFileList)[nIndex];

	return nRet;
}

/**
	@brief		It adds a file open to the Recent File open list variable m_pRecentFileList
				It checks first if the file has been added before.
				It gets called by the Doc class.
	@param		CString szRecentFileOpen IN
	@return		SUCCESS
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int  CConfigToolApp::addRecentFileOpen(CString &szRecentFileOpen)
{
	int nRet = SUCCESS;

	bool bFound = false;
	int nSize = m_pRecentFileList->GetSize();
	CString szFile;

	for (int i=0; i < nSize; i++){
		szFile = (LPCTSTR)(*m_pRecentFileList)[i];
		if (!szRecentFileOpen.CompareNoCase(szFile)){
			bFound = true;
			break;
		}
	}

	if (bFound == false)
	{
		m_pRecentFileList->Add(szRecentFileOpen);
		m_pRecentFileList->WriteList();
	}

	return nRet;
}


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

void CConfigToolApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CConfigToolApp customization load/save methods

void CConfigToolApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void CConfigToolApp::LoadCustomState()
{
}

void CConfigToolApp::SaveCustomState()
{
}










