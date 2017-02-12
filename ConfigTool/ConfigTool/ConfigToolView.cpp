
// ConfigToolView.cpp : implementation of the CConfigToolView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ConfigTool.h"
#endif

#include "ConfigToolDoc.h"
#include "ConfigToolView.h"
#include "stdafx.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CConfigToolView

IMPLEMENT_DYNCREATE(CConfigToolView, CView)

BEGIN_MESSAGE_MAP(CConfigToolView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	//ON_COMMAND(ID_FILE_SAVE, &CConfigToolView::OnFileSave)
END_MESSAGE_MAP()

// CConfigToolView construction/destruction

/**
	@brief

	@param
	@return
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
CConfigToolView::CConfigToolView()
{
	m_PropSheet.AddPage(&m_PropPageOne);
	m_PropSheet.AddPage(&m_PropPageTwo);

}

CConfigToolView::~CConfigToolView()
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
BOOL CConfigToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

// CConfigToolView drawing

void CConfigToolView::OnDraw(CDC* /*pDC*/)
{
	CConfigToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CConfigToolView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CConfigToolView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CConfigToolView diagnostics

#ifdef _DEBUG
void CConfigToolView::AssertValid() const
{
	CView::AssertValid();
}

void CConfigToolView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CConfigToolDoc* CConfigToolView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CConfigToolDoc)));
	return (CConfigToolDoc*)m_pDocument;
}
#endif //_DEBUG

/**
	@brief		In this function we attach the PropertySheet and PropertyPages
	@param
	@return
	@author		RG
	@date		2014-Aug-19
	@remarks
*/
void CConfigToolView::OnInitialUpdate()
{
	//CConfigToolView::OnInitialUpdate();

	CSize sizeTotal;

	// TODO: Add your specialized code here and/or call the base class

	if (m_PropSheet.m_psh.hwndParent != NULL) {
		// Property Sheet has already been created
		return;
	}

	DWORD style = WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE | WS_EX_DLGMODALFRAME;
	//DWORD exStyle = WS_EX_RIGHTSCROLLBAR;

	//BOOL result = m_PropSheet.Create(this, style, exStyle);
	BOOL result = m_PropSheet.Create(this, style);


	// Place PropertySheet in the upper-left corner of the client zone.
	// Notice that we also place it at the top of the Z-order (wndTop)
	RECT rcClient;
	GetClientRect(&rcClient);
	m_PropSheet.SetWindowPos(&wndTop, (int)rcClient.left, (int)rcClient.top, 0, 0, SWP_NOSIZE);

	// Get PropertySheet size 
	CRect rcWnd;
	m_PropSheet.GetWindowRect(&rcWnd);
	rcWnd.right = rcWnd.right + 20;
	rcWnd.bottom = rcWnd.bottom + 110;

	// Set scrolling characteristics (mapping mode and size)
	//sizeTotal.cx = rcWnd.Width();
	//sizeTotal.cy = rcWnd.Height();
	//SetScrollSizes(MM_TEXT, sizeTotal);

	GetParentFrame()->MoveWindow(rcWnd);

	//GetParentFrame()->RecalcLayout();
	//ResizeParentToFit(FALSE);	// Resize the frame window exactly

	// Center the application's main window
	// This is placed just after the final wnd size is known. 
	AfxGetMainWnd()->CenterWindow();

	//Update the app title
	//CConfigToolDoc* pDoc = GetDocument();
	//ASSERT(pDoc);
	//pDoc->SetTitle(_T("Configuration Tool"));

	
}


