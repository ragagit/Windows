// ConfigPropPageTwo.cpp : implementation file
//

#include "stdafx.h"
#include "ConfigTool.h"
#include "ConfigPropPageTwo.h"
#include "afxdialogex.h"


// CConfigPropPageTwo dialog

IMPLEMENT_DYNAMIC(CConfigPropPageTwo, CPropertyPage)

CConfigPropPageTwo::CConfigPropPageTwo()
	: CPropertyPage(CConfigPropPageTwo::IDD)
{

}

CConfigPropPageTwo::~CConfigPropPageTwo()
{
}

void CConfigPropPageTwo::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConfigPropPageTwo, CPropertyPage)
END_MESSAGE_MAP()


// CConfigPropPageTwo message handlers
