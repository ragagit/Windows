#include "stdafx.h"
#include "IPWXMLParser.h"
#include "XMLParserBase.h"
#include "XMLParamStrings.h"




CIPWXMLParser::CIPWXMLParser()
{
}


CIPWXMLParser::~CIPWXMLParser()
{
}

/**
	@brief

	@param
	@return
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int CIPWXMLParser::initXMLParser()
{
	int nRet = 0;

	return nRet;
}

/**
	@brief		Initializes the XML parser by setting the output file name
				It needs to be set before any XML writing operation otherwise
				any change gets written in buffred
	@param		CString szOutputXMLFileName
	@return		int error code
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int CIPWXMLParser::initXMLParser( CString &szOutputXMLFileName)
{
	int nRet = 0;
	std::wstring szFile = szOutputXMLFileName;

	//nRet = SetBuildDOM(true);
	nRet = SetOutputFile((LPWSTR)szFile.c_str());

	return nRet;
}

/**
	@brief		It parses an XML file
	@param		CString XML file name
	@return		int error code from ipworks
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int CIPWXMLParser::parseXMLFile(CString &szXMLFileName)
{
	int nRet = 0;
	std::wstring szFileName = szXMLFileName;

	/** We are using here ipworks library */
	nRet = ParseFile((LPWSTR)szFileName.c_str());

	/** Value returned from ipworks. Whatever we get from ipworks is what we return  */
	return nRet;
}

/**
	@brief		It start XML element Parent 

	@param		CString szXMLParent IN
	@return		int eror code
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int CIPWXMLParser::startXMLParent(CString &szXMLParent){

	int nRet = 0;
	std::wstring szParent = szXMLParent;

	nRet = StartElement((LPWSTR)szParent.c_str(), NULL);

	return nRet;
}

/**
	@brief		It closes a parent XML tag
	@param		CString &szXMLParent
	@return		int error code
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int CIPWXMLParser::endXMLParent(CString &szXMLParent){

	int nRet = 0;
	
	//ipworks
	EndElement();

	return nRet;
}

/**
	@brief		It gets the value of a XML element in XPath format
	@param		CString element name
				CString element returned value
	@return
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int CIPWXMLParser::getXMLElement( CString &szElementName, CString &szElementValue)
{
	int nRet = 0;
	std::wstring szXElement = szElementName;

	nRet=SetXPath((LPWSTR)szXElement.c_str());
	std::wstring tmp = GetXPath();
	szElementValue = GetXText();

	return nRet;
}

/**
	@brief		It gets the value of a XML element
	@param		CString element name
				CString element returned value
	@return
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int CIPWXMLParser::setXMLElement(CString &szElementName, CString &szElementValue)
{
	int nRet = 0;

	std::wstring szXElement = szElementName;
	std::wstring szXValue = szElementValue;

	nRet = WriteElement((LPWSTR)szXElement.c_str(), NULL, (LPWSTR)szXValue.c_str());
	//nRet = EndElement();


	return nRet;
}

/**
	@brief		It writes XML elements to a file. Element should be specified in XPath format
	@param		None
	@return		int
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int CIPWXMLParser::writeXMLFile()
{
	int nRet=0;

	//std::wstring buff = GetOutputData();

	nRet = Close();

	return nRet;
}

/**
	@brief		It writes the first line declaration of the XML file
	@param		None
	@return		int error code
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int CIPWXMLParser::writeXMLDeclaration(){
	int nRet = 0;

	nRet = WriteXMLDeclaration(_T("1.0"), true, true);

	return nRet;
}

/**
	@brief		This function gets fired when there is the start of a new XML element (ipworks)

	@param		XMLpStartElementEventParamsW *e
	@return		int
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int CIPWXMLParser::FireStartElement(XMLpStartElementEventParamsW *e)
{
	std::wstring szElementName, szElementValue;

	szElementName = e->Element;
	szElementValue = GetXText();

	return 0;
}

/**
	@brief		This function gets fired when there is the end of a new XML element (ipworks)
	@param
	@return
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
int CIPWXMLParser::FireEndElement(XMLpEndElementEventParamsW *e)
{
	std::wstring szElementName, szElementValue;

	szElementName = e->Element;
	szElementValue = GetXText();

	return 0;
}
