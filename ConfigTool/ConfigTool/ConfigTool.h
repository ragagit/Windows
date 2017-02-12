
// ConfigTool.h : main header file for the ConfigTool application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols
#include "IPWXMLParser.h"


// CConfigToolApp:
// See ConfigTool.cpp for the implementation of this class
//

class CConfigToolApp : public CWinAppEx
{
public:
	CConfigToolApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();
	int	 getRecentFileOpen(CString &szRecenFileOpen, int nIndex = 0);
	int  addRecentFileOpen(CString &szRecentFileOpen);

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	
};

extern CConfigToolApp theApp;
