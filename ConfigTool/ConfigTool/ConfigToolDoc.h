
// ConfigToolDoc.h : interface of the CConfigToolDoc class
//


#pragma once
#include "IPWXMLParser.h"

class CConfigToolDoc : public CDocument
{
protected: // create from serialization only
	CConfigToolDoc();
	DECLARE_DYNCREATE(CConfigToolDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS


// Implementation
public:
	virtual ~CConfigToolDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS	

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
	CString m_szConfigFileName;
	CString m_szPPOneLogLevel;
	CString m_szPPOneLogPath;
	CString m_szPPTwoLogLevel;
	CString m_szPPTwoLogPath;
	bool m_bXMLFileLoaded;

public:
	virtual void SetTitle(LPCTSTR lpszTitle);
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
	void getConfigFileName(CString &szConfigFileName);
	void setConfigFileName(CString &szConfigFileName);
	static CConfigToolDoc * CConfigToolDoc::GetDoc();
	int getPPOneLogLevel(CString &szLogLevel);
	int setPPOneLogLevel(CString &szLogLevel);
	int getPPOneLogPath(CString &szLogPath);
	int setPPOneLogPath(CString &szLogPath);
	bool IsXMLFileLoaded();

	CIPWXMLParser *m_pXMLParser;

	int parseXMLFile();
	int readXMLElements();
	int writeXMLElements();

	
};
