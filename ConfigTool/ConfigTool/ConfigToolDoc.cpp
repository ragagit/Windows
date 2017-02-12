
// ConfigToolDoc.cpp : implementation of the CConfigToolDoc class
//

/**

Configuration Tool Document

*/
#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ConfigTool.h"
#endif

#include "ConfigToolDoc.h"
#include "XMLParamStrings.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CConfigToolDoc, CDocument)

BEGIN_MESSAGE_MAP(CConfigToolDoc, CDocument)
	ON_COMMAND(ID_FILE_SAVE, &CConfigToolDoc::OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, &CConfigToolDoc::OnFileOpen)
END_MESSAGE_MAP()


//  ================ CConfigToolDoc construction/destruction =========

/**
	@brief		We initialize all the variables in the config too here
				with default values.
	@param		None
	@return		void
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
CConfigToolDoc::CConfigToolDoc()
{
	m_pXMLParser = NULL;
	m_szPPOneLogLevel = _T("Error");
	m_szPPOneLogPath = _T("C:\\ProgramData");
	m_szPPTwoLogLevel = _T("Error");
	m_szPPTwoLogPath = _T("C:\\ProgramData");
	m_bXMLFileLoaded = false;
	

}

CConfigToolDoc::~CConfigToolDoc()
{
	if (m_pXMLParser != NULL)
		delete m_pXMLParser;
}

/**
	@brief		We override this function. When the ConfigTool is launched it get the last file open 
				if there is then parses it.
	@param		None
	@return		BOOL
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
BOOL CConfigToolDoc::OnNewDocument()
{
	CString szConfigFileName;
	CString szErrorMsg;
	int nRet;

	if (!CDocument::OnNewDocument())
		return FALSE;

	CConfigToolApp *pCTA = reinterpret_cast <CConfigToolApp*> (AfxGetApp());
	pCTA->getRecentFileOpen(szConfigFileName);

	if (szConfigFileName.IsEmpty() == false)
	{
		setConfigFileName(szConfigFileName);

		nRet = parseXMLFile();
		if (nRet != SUCCESS){
			szErrorMsg.Format(_T("Unable to parse %s"), szConfigFileName);
			AfxMessageBox(szErrorMsg);
		}
		else{
			m_bXMLFileLoaded = true;
		}
		
	}

	return TRUE;
}

void CConfigToolDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CConfigToolDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CConfigToolDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CConfigToolDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS


#ifdef _DEBUG
void CConfigToolDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CConfigToolDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG



/**
	@brief		I created this functionto make the Doc template accessible to all
				code inthe application, specially the Propert pages
	@param		None
	@return		void
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
CConfigToolDoc * CConfigToolDoc::GetDoc()
{
	CFrameWnd * pFrame = (CFrameWnd *)(AfxGetApp()->m_pMainWnd);
	return (CConfigToolDoc *)pFrame->GetActiveDocument();
}

// ============= Menu handlers =======================
/**
	@brief		This functionis is the handler of the File-Open menu item.
				It opens the XML file and parses it.
	@param		None
	@return		void
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
void CConfigToolDoc::OnFileOpen()
{

	LPCTSTR pszFilter = _T("XML files (*.xml)|*.xml");
	CString szConfigFileName;
	CString szErrorMsg;
	int nRet;
	
	CFileDialog dlgFile(TRUE, NULL, NULL,
		OFN_HIDEREADONLY,
		pszFilter,
		AfxGetMainWnd());
	
	if (IDOK == dlgFile.DoModal())
	{
		szConfigFileName = dlgFile.GetPathName();
		setConfigFileName(szConfigFileName);
		if( !szConfigFileName.IsEmpty() ){
			nRet = parseXMLFile();
			if (nRet != SUCCESS){
				szErrorMsg.Format(_T("Unable to parse %s"), szConfigFileName);
				AfxMessageBox(szErrorMsg);
			}
			else{
				m_bXMLFileLoaded = true;
				CConfigToolApp *pCT = reinterpret_cast <CConfigToolApp*>(AfxGetApp());
				pCT->addRecentFileOpen(szConfigFileName);
			}
		}
	}

}

/**
@brief		It saves the XML file to disk.
@param		None
@return		void
@author		RG
@date		2014-Aug-19
@remarks
*/
void CConfigToolDoc::OnFileSave()
{
	CString szXMLFileName;
	int nRet = 0;

	getConfigFileName(szXMLFileName);

	if (m_pXMLParser != NULL){
		nRet = writeXMLElements();
		nRet = m_pXMLParser->writeXMLFile();
	}
	else{
		AfxMessageBox(_T("Error. Parser object not initialized"));
	}

}

/**
	@brief		It parses an XML file. It uses IPWXMLParse library
				The XML file to be parsed out is set with the Open menu item
				or at Application start up
	@param		None
	@return		int SUCCESS or FAIL
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int CConfigToolDoc::parseXMLFile()
{
	CString szConfigFileName;
	int nRet = 0;
	
	getConfigFileName(szConfigFileName);
	
	if (m_pXMLParser != NULL)
		delete m_pXMLParser;

	m_pXMLParser = new CIPWXMLParser();
	
	if (m_pXMLParser != NULL){
		m_pXMLParser->initXMLParser(szConfigFileName);
		nRet = m_pXMLParser->parseXMLFile(szConfigFileName);		
		if (nRet == SUCCESS){
			nRet = readXMLElements();
		}
		else{//Something bad happend parsing the file			
			nRet = FAIL;
		}
	}
	else{ 
		nRet = FAIL; 
	}
		
	return nRet;
}


// ============= XML routines ========================
/**
	@brief		It reads the XML elements from a XML file.
				It uses XPath convention
	@param		None
	@return		int
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int CConfigToolDoc::readXMLElements()
{
	int nRet = 0;
	CString szXMLElement;
	CString szXMLParent;

	//Getting log level 
	szXMLElement = XML_CONFIG_PROPONE_LOGLEVEL;
	m_pXMLParser->getXMLElement(szXMLElement, m_szPPOneLogLevel);

	szXMLElement = XML_CONFIG_PROPTWO_LOGLEVEL;
	m_pXMLParser->getXMLElement(szXMLElement, m_szPPTwoLogLevel);

	//Getting Log Path
	szXMLElement = XML_CONFIG_PROPONE_LOGPATH;
	m_pXMLParser->getXMLElement(szXMLElement, m_szPPOneLogPath);

	szXMLElement = XML_CONFIG_PROPTWO_LOGPATH;
	m_pXMLParser->getXMLElement(szXMLElement, m_szPPTwoLogPath);

	return nRet;
}

/**
	@brief		It write XML elements. It uses XPath convention.
				It goes like this
				<parent>
					<parent1>
						<child1>value</child1>
						<child2>value</chile2>
					<parent1>
					<parent2>
						<child1>value</child1>
					<parent2>
				<parent>
				First we open the <parent> with startXMLparent()
				then <parent1> we use setXMLElemnt to ad an element
				we use endXMLElement() to close <parent1>. We open <parent2>
				add elements. The last call to endXML Parent closes all pending
				elements plus parents
	@param		None
	@return		int
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int CConfigToolDoc::writeXMLElements()
{
	int nRet = 0;
	CString szXMLElement;
	CString szXMLParent;


	m_pXMLParser->writeXMLDeclaration();

	//Opening ConfigTool Parent
	szXMLParent = XML_CONFIG_TOOL;
	m_pXMLParser->startXMLParent(szXMLParent);

		//Opening Property Page One
		szXMLParent = XML_PROPERTYPAGE_ONE;
		m_pXMLParser->startXMLParent(szXMLParent);
		
			//logLevel Element
			szXMLElement = XML_LOGLEVEL;
			m_pXMLParser->setXMLElement( szXMLElement, m_szPPOneLogLevel);

			//logPath
			szXMLElement = XML_LOGPATH;
			m_pXMLParser->setXMLElement(szXMLElement, m_szPPOneLogPath);

		//Closing Property Page One
		m_pXMLParser->endXMLParent(szXMLParent);

		//Opening Property Page Two
		szXMLParent = XML_PROPERTYPAGE_TWO;
		m_pXMLParser->startXMLParent(szXMLParent);

			//logLevel Element
			szXMLElement = XML_LOGLEVEL;
			m_pXMLParser->setXMLElement( szXMLElement, m_szPPTwoLogLevel);

			//logPath
			szXMLElement = XML_LOGPATH;
			m_pXMLParser->setXMLElement(szXMLElement, m_szPPTwoLogPath);


		//Closing Property Page two
		m_pXMLParser->endXMLParent(szXMLParent);

	//Closing Config Tool
	m_pXMLParser->endXMLParent(szXMLParent);
	
	return nRet;
}


//============== Setters and getters ================

/**
	@brief		This function sets the config file name coming from Open File Dlg
	@param		szConfigFileName CString XML file name
	@return		void
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
void CConfigToolDoc::setConfigFileName(CString &szConfigFileName){

	m_szConfigFileName = szConfigFileName;
}

/**
	@brief		It returns the XML configuration file name
	@param		CString szConfigFileName OUT
	@return		void
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
void CConfigToolDoc::getConfigFileName(CString &szConfigFileName){

	szConfigFileName = m_szConfigFileName;
}

/**
	@brief		It sets the title for the Doc window
	@param		LPCTSTR lpszTitle title
	@return		void
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
void CConfigToolDoc::SetTitle(LPCTSTR lpszTitle)
{

	CDocument::SetTitle(lpszTitle);
}

/**
	@brief		It gets the Log level 
	@param		cString szlogLevel OUT
	@return		int SUCCESS or FAIL
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int CConfigToolDoc::getPPOneLogLevel(CString &szLogLevel)
{
	int nRet = SUCCESS;

	szLogLevel = m_szPPOneLogLevel;

	return nRet;
}

/**
	@brief		It sets the log level in member variable after a rad to the XML config file
	@param		CString szLogLevel IN
	@return		int SUCCESS or FAIL
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int CConfigToolDoc::setPPOneLogLevel(CString &szLogLevel)
{
	int nRet = SUCCESS;

	m_szPPOneLogLevel = szLogLevel;

	return nRet;
}

/**
	@brief		It returns the path to the log file
	@param		CString szLogPath OUT
	@return		int
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int CConfigToolDoc::getPPOneLogPath(CString &szLogPath)
{
	int nRet = SUCCESS;

	szLogPath = m_szPPOneLogPath;

	return nRet;
}

/**
	@brief		It sets the log path to log file
	@param		CString szLogPath IN
	@return		int SUCCESS or FAIL
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int CConfigToolDoc::setPPOneLogPath(CString &szLogPath)
{
	int nRet = SUCCESS;

	m_szPPOneLogPath = szLogPath;

	return nRet;

}

/**
	@brief		It return if an XML files has been loaded or not	
	@param		None
	@return		bool
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
bool CConfigToolDoc::IsXMLFileLoaded()
{
	return m_bXMLFileLoaded;
}
