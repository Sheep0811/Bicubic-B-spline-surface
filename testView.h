// testView.h : interface of the CTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTVIEW_H__A63FFD21_F936_4995_B187_6F49C02DB479__INCLUDED_)
#define AFX_TESTVIEW_H__A63FFD21_F936_4995_B187_6F49C02DB479__INCLUDED_

#include "P3D.h" 
#include "P2D.h"
#include "InputDlg.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTestView : public CView
{
protected: // create from serialization only
	CTestView();
	DECLARE_DYNCREATE(CTestView)

// Attributes
public:
	CTestDoc* GetDocument();

// Operations
public:
	void GetMaxY();    //获得屏幕最大y值
	void GetMaxX();   //获得最大x值
	void DrawBezier();              //绘制Bezier曲面
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int MaxX,MaxY;    //屏幕x和y的最大坐标
	P3D P3d[4][4];      //三维点
	P2D P2d[4][4]; 
    P3D T1[4][4];	
	P3D T[4][4];         //临时矩阵
	double MT[4][4];   //M的转置矩阵

// Generated message map functions
protected:
	//{{AFX_MSG(CTestView)
	afx_msg void OnMdraw();
	afx_msg void OnProject();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in testView.cpp
inline CTestDoc* CTestView::GetDocument()
   { return (CTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTVIEW_H__A63FFD21_F936_4995_B187_6F49C02DB479__INCLUDED_)
