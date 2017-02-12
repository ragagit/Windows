
// ConfigToolView.h : interface of the CConfigToolView class
//

#pragma once
#include "ConfigPropertySheet.h"
#include "ConfigPropPageOne.h"
#include "ConfigPropPageTwo.h"

class CConfigToolView : public CView
{
protected: // create from serialization only
	CConfigToolView();
	DECLARE_DYNCREATE(CConfigToolView)

// Attributes
public:
	CConfigToolDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
protected:

	CConfigPropertySheet m_PropSheet;
	// Property page one variable
	CConfigPropPageOne m_PropPageOne;
	// Property Page Two variable
	CConfigPropPageTwo m_PropPageTwo;

// Implementation
public:
	virtual ~CConfigToolView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileSave();
};

#ifndef _DEBUG  // debug version in ConfigToolView.cpp
inline CConfigToolDoc* CConfigToolView::GetDocument() const
   { return reinterpret_cast<CConfigToolDoc*>(m_pDocument); }
#endif

