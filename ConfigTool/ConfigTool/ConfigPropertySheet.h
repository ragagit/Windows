#pragma once
#include "ConfigPropPageOne.h"
#include "ConfigPropPageTwo.h"



// CConfigPropertySheet

class CConfigPropertySheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CConfigPropertySheet)

public:
	CConfigPropertySheet(UINT nIDCaption=57344, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CConfigPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CConfigPropertySheet();

protected:
	DECLARE_MESSAGE_MAP()
public:
	// Property page one variable
	//CConfigPropPageOne m_PropPageOne;
	// Property Page Two variable
	//CConfigPropPageTwo m_PropPageTwo;
};


