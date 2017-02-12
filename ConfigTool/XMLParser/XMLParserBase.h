#pragma once
#include <afx.h>
#include <string>
#include <tchar.h>



class CXMLParserBase
{

public:
	CXMLParserBase();
	~CXMLParserBase();

	virtual int initXMLParser() = 0;
	virtual int initXMLParser(CString &szOutputXMlFilename) = 0;
	virtual int parseXMLFile(CString &szXMLFileName) = 0;
	virtual int startXMLParent(CString &szXMLParent) = 0;
	virtual int endXMLParent(CString &szXMLParent) = 0;
	virtual int getXMLElement(CString &szElementName, CString &szElementValue) = 0;
	virtual int setXMLElement(CString &szElementName, CString &szElementValue) = 0;
	virtual int writeXMLFile() = 0;
	//virtual int getAttribute(CString &szAttributeName, CString &szAttributeValue) = 0;
	//virtual int setAttribute(CString &szAttributeName, CString &szAttributeValue) = 0;

};

