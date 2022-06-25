// InputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "InputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// InputDlg dialog


InputDlg::InputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(InputDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(InputDlg)
	a_x = 200.0;
	a_y = 20.0;
	a_z = 0.0;
	b_x = 150.0;
	b_y = 0.0;
	b_z = 100.0;
	c_x = 50.0;
	c_y = -130.0;
	c_z = 100.0;
	d_x = 0.0;
	d_y = -250.0;
	d_z = 50.0;
	e_x = 150.0;
	e_y = 100.0;
	e_z = 100.0;
	f_x = 100.0;
	f_y = 30.0;
	f_z = 100.0;
	g_x = 50.0;
	g_y = -40.0;
	g_z = 100.0;
	h_x = 0.0;
	h_y = -110.0;
	h_z = 100.0;
	i_x = 140.0;
	i_y = 280.0;
	i_z = 90.0;
	j_x = 80.0;
	j_y = 110.0;
	j_z = 120.0;
	k_x = 30.0;
	k_y = 30.0;
	k_z = 130.0;
	l_x = -50.0;
	l_y = -100.0;
	l_z = 150.0;
	m_x = 150.0;
	m_y = 350.0;
	m_z = 30.0;
	n_x = 50.0;
	n_y = 200.0;
	n_z = 150.0;
	o_x = 0.0;
	o_y = 50.0;
	o_z = 200.0;
	p_x = -70.0;
	p_y = 0.0;
	p_z = 100.0;
	//}}AFX_DATA_INIT
}


void InputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(InputDlg)
	DDX_Text(pDX, IDC_EDIT1, a_x);
	DDX_Text(pDX, IDC_EDIT2, a_y);
	DDX_Text(pDX, IDC_EDIT3, a_z);
	DDX_Text(pDX, IDC_EDIT4, b_x);
	DDX_Text(pDX, IDC_EDIT5, b_y);
	DDX_Text(pDX, IDC_EDIT6, b_z);
	DDX_Text(pDX, IDC_EDIT7, c_x);
	DDX_Text(pDX, IDC_EDIT8, c_y);
	DDX_Text(pDX, IDC_EDIT9, c_z);
	DDX_Text(pDX, IDC_EDIT10, d_x);
	DDX_Text(pDX, IDC_EDIT11, d_y);
	DDX_Text(pDX, IDC_EDIT12, d_z);
	DDX_Text(pDX, IDC_EDIT13, e_x);
	DDX_Text(pDX, IDC_EDIT14, e_y);
	DDX_Text(pDX, IDC_EDIT15, e_z);
	DDX_Text(pDX, IDC_EDIT16, f_x);
	DDX_Text(pDX, IDC_EDIT17, f_y);
	DDX_Text(pDX, IDC_EDIT18, f_z);
	DDX_Text(pDX, IDC_EDIT19, g_x);
	DDX_Text(pDX, IDC_EDIT20, g_y);
	DDX_Text(pDX, IDC_EDIT21, g_z);
	DDX_Text(pDX, IDC_EDIT22, h_x);
	DDX_Text(pDX, IDC_EDIT23, h_y);
	DDX_Text(pDX, IDC_EDIT24, h_z);
	DDX_Text(pDX, IDC_EDIT25, i_x);
	DDX_Text(pDX, IDC_EDIT26, i_y);
	DDX_Text(pDX, IDC_EDIT27, i_z);
	DDX_Text(pDX, IDC_EDIT28, j_x);
	DDX_Text(pDX, IDC_EDIT29, j_y);
	DDX_Text(pDX, IDC_EDIT30, j_z);
	DDX_Text(pDX, IDC_EDIT31, k_x);
	DDX_Text(pDX, IDC_EDIT32, k_y);
	DDX_Text(pDX, IDC_EDIT33, k_z);
	DDX_Text(pDX, IDC_EDIT34, l_x);
	DDX_Text(pDX, IDC_EDIT35, l_y);
	DDX_Text(pDX, IDC_EDIT36, l_z);
	DDX_Text(pDX, IDC_EDIT37, m_x);
	DDX_Text(pDX, IDC_EDIT38, m_y);
	DDX_Text(pDX, IDC_EDIT39, m_z);
	DDX_Text(pDX, IDC_EDIT40, n_x);
	DDX_Text(pDX, IDC_EDIT41, n_y);
	DDX_Text(pDX, IDC_EDIT42, n_z);
	DDX_Text(pDX, IDC_EDIT43, o_x);
	DDX_Text(pDX, IDC_EDIT44, o_y);
	DDX_Text(pDX, IDC_EDIT45, o_z);
	DDX_Text(pDX, IDC_EDIT46, p_x);
	DDX_Text(pDX, IDC_EDIT47, p_y);
	DDX_Text(pDX, IDC_EDIT48, p_z);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(InputDlg, CDialog)
	//{{AFX_MSG_MAP(InputDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// InputDlg message handlers
