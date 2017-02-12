#pragma once


// CConfigPropPageTwo dialog

class CConfigPropPageTwo : public CPropertyPage
{
	DECLARE_DYNAMIC(CConfigPropPageTwo)

public:
	CConfigPropPageTwo();
	virtual ~CConfigPropPageTwo();

// Dialog Data
	enum { IDD = IDD_CONFIGPROPPAGETWO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
