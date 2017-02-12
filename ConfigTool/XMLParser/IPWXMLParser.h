/** \file IPWXMLParser.h
	\brief This file is the header for IPWXMLParser

	On a further note this is using IPWorks
*/

#pragma once
#include "XMLParserBase.h"
#include "ipworks.h"
#include <afx.h>

class CIPWXMLParser :
	public CXMLParserBase, XMLpW, XMLwW
{
public:
	CIPWXMLParser();
	virtual ~CIPWXMLParser();

	virtual int initXMLParser();
	virtual int initXMLParser(CString &szOutputXMLFileName );
	virtual int parseXMLFile(CString &szXMLFileName);
	virtual int endXMLParent(CString &szXMLFileName);
	virtual int startXMLParent(CString &szXMLParent);
	virtual int getXMLElement(CString &szElementName, CString &szElementValue);
	virtual int setXMLElement(CString &szElementName, CString &szElementValue);
	virtual int writeXMLDeclaration();
	virtual int writeXMLFile();

	virtual int FireStartElement(XMLpStartElementEventParamsW *e);
	virtual int FireEndElement(XMLpEndElementEventParamsW *e);
};

