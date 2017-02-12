// ConfigPropertySheet.cpp : implementation file
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "ConfigPropertySheet.h"


// CConfigPropertySheet

IMPLEMENT_DYNAMIC(CConfigPropertySheet, CPropertySheet)

CConfigPropertySheet::CConfigPropertySheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	//AddPage(&m_PropPageOne);
	//AddPage(&m_PropPageTwo);
}

CConfigPropertySheet::CConfigPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	//AddPage(&m_PropPageOne);
	//AddPage(&m_PropPageTwo);
}

CConfigPropertySheet::~CConfigPropertySheet()
{
}


BEGIN_MESSAGE_MAP(CConfigPropertySheet, CPropertySheet)
END_MESSAGE_MAP()


// CConfigPropertySheet message handlers
