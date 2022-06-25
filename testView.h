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
	void GetMaxY();    //�����Ļ���yֵ
	void GetMaxX();   //������xֵ
	void DrawBezier();              //����Bezier����
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
	int MaxX,MaxY;    //��Ļx��y���������
	P3D P3d[4][4];      //��ά��
	P2D P2d[4][4]; 
    P3D T1[4][4];	
	P3D T[4][4];         //��ʱ����
	double MT[4][4];   //M��ת�þ���

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
