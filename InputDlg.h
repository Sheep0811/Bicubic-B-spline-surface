#if !defined(AFX_INPUTDLG_H__F26DDB06_CC74_444A_AF6E_66254F35D2C8__INCLUDED_)
#define AFX_INPUTDLG_H__F26DDB06_CC74_444A_AF6E_66254F35D2C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InputDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// InputDlg dialog

class InputDlg : public CDialog
{
// Construction
public:
	InputDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(InputDlg)
	enum { IDD = IDD_DIALOG1 };
	double	a_x;
	double	a_y;
	double	a_z;
	double	b_x;
	double	b_y;
	double	b_z;
	double	c_x;
	double	c_y;
	double	c_z;
	double	d_x;
	double	d_y;
	double	d_z;
	double	e_x;
	double	e_y;
	double	e_z;
	double	f_x;
	double	f_y;
	double	f_z;
	double	g_x;
	double	g_y;
	double	g_z;
	double	h_x;
	double	h_y;
	double	h_z;
	double	i_x;
	double	i_y;
	double	i_z;
	double	j_x;
	double	j_y;
	double	j_z;
	double	k_x;
	double	k_y;
	double	k_z;
	double	l_x;
	double	l_y;
	double	l_z;
	double	m_x;
	double	m_y;
	double	m_z;
	double	n_x;
	double	n_y;
	double	n_z;
	double	o_x;
	double	o_y;
	double	o_z;
	double	p_x;
	double	p_y;
	double	p_z;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(InputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(InputDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTDLG_H__F26DDB06_CC74_444A_AF6E_66254F35D2C8__INCLUDED_)
