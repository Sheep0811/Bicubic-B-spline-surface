// testView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "test.h"
#include "testDoc.h"
#include "testView.h"
#include "Transform.h"
#include "P2.h"
#include "math.h"
#define ROUND(a) int(a+0.5)  //四舍五入
P2D b[4][4];
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	//{{AFX_MSG_MAP(CTestView)
	ON_COMMAND(IDD_MDRAW, OnMdraw)
	ON_COMMAND(ID_PROJECT, OnProject)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestView construction/destruction

CTestView::CTestView()
{
	// TODO: add construction code here

}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestView drawing

void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	GetMaxX();
	GetMaxY();
	CPen MyPen3d,MyPen2d,MyPen,*OldPen;
	MyPen3d.CreatePen(PS_SOLID,1,RGB(0,0,0));
	//绘制坐标轴
	OldPen=pDC->SelectObject(&MyPen3d);
	pDC->MoveTo(MaxX/2,MaxY/2);//绘制x轴
	pDC->LineTo(MaxX-25,MaxY/2);	
	pDC->TextOut(MaxX-50,MaxY/2-20,"y");//绘制右箭头　
	pDC->MoveTo(MaxX/2,MaxY/2);//绘制x轴
	pDC->LineTo(MaxX/2,0);	
	pDC->TextOut(MaxX/2-20,10,"z");
	pDC->MoveTo(MaxX/2,MaxY/2);//绘制x轴
	pDC->LineTo(MaxX/2-MaxY/2,MaxY);	
	pDC->TextOut(MaxX/2-MaxY/2+50,MaxY-30,"x");
	pDC->TextOut(MaxX/2-20,MaxY/2-10,"O");
	pDC->SelectObject(OldPen);
	MyPen3d.DeleteObject();
}

/////////////////////////////////////////////////////////////////////////////
// CTestView printing

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestView diagnostics

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestView message handlers
void CTestView::GetMaxX()   //获得屏幕宽度
{ 
         CRect Rect;
         GetClientRect(&Rect);
         MaxX=Rect.right;
}
void CTestView::GetMaxY()   //获得屏幕高度
{ 
         CRect Rect;
         GetClientRect(&Rect);
         MaxY=Rect.bottom;
}
void CTestView::OnMdraw()
{
	 InputDlg dlg;    //调用对话框模块，判断是否单机OK按钮
	if(dlg.DoModal()==IDOK) 
	{		//对话框参数进行赋值
	  P3d[0][0].x=dlg.a_x;P3d[0][0].y=dlg.a_y;P3d[0][0].z=dlg.a_z;
      P3d[0][1].x=dlg.b_x;P3d[0][1].y=dlg.b_y;P3d[0][1].z=dlg.b_z;
      P3d[0][2].x=dlg.c_x;P3d[0][2].y=dlg.c_y;P3d[0][2].z=dlg.c_z;
      P3d[0][3].x=dlg.d_x;P3d[0][3].y=dlg.d_y;P3d[0][3].z=dlg.d_z;
      P3d[1][0].x=dlg.e_x;P3d[1][0].y=dlg.e_y;P3d[1][0].z=dlg.e_z;
      P3d[1][1].x=dlg.f_x;P3d[1][1].y=dlg.f_y;P3d[1][1].z=dlg.f_z;
      P3d[1][2].x=dlg.g_x;P3d[1][2].y=dlg.g_y;P3d[1][2].z=dlg.g_z;
      P3d[1][3].x=dlg.h_x;P3d[1][3].y=dlg.h_y;P3d[1][3].z=dlg.h_z;
      P3d[2][0].x=dlg.i_x;P3d[2][0].y=dlg.i_y;P3d[2][0].z=dlg.i_z;
      P3d[2][1].x=dlg.j_x;P3d[2][1].y=dlg.j_y;P3d[2][1].z=dlg.j_z;
      P3d[2][2].x=dlg.k_x;P3d[2][2].y=dlg.k_y;P3d[2][2].z=dlg.k_z;
      P3d[2][3].x=dlg.l_x;P3d[2][3].y=dlg.l_y;P3d[2][3].z=dlg.l_z;
      P3d[3][0].x=dlg.m_x;P3d[3][0].y=dlg.m_y;P3d[3][0].z=dlg.m_z;
      P3d[3][1].x=dlg.n_x;P3d[3][1].y=dlg.n_y;P3d[3][1].z=dlg.n_z;
      P3d[3][2].x=dlg.o_x;P3d[3][2].y=dlg.o_y;P3d[3][2].z=dlg.o_z;
      P3d[3][3].x=dlg.p_x;P3d[3][3].y=dlg.p_y;P3d[3][3].z=dlg.p_z;
	}
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	{	//将输入的三维坐标点转化为二维坐标点，用于绘画控制网格
        b[i][j].x=P3d[i][j].y-P3d[i][j].x/sqrt(2);
	    b[i][j].y=-P3d[i][j].z+P3d[i][j].x/sqrt(2);
	}
	
	RedrawWindow();
	GetMaxX();GetMaxY();
	AfxGetMainWnd()->SetWindowText("B样条曲面");
	DrawBezier();   //调用画曲面的函数
}
void CTestView::DrawBezier()
{
	CClientDC dc(this);
	CPen MyPen,*POldPen;   //画笔预设
	MyPen.CreatePen(PS_SOLID,0.1,RGB(0,0,0));
	POldPen=dc.SelectObject(&MyPen);
	double x,y,u,v,u1,u2,u3,u4,v1,v2,v3,v4;
	double M[4][4];  //基函数
	M[0][0]=-1;M[0][1]=3;M[0][2]=-3;M[0][3]=1;
	M[1][0]=3;M[1][1]=-6;M[1][2]=3;M[1][3]=0;
	M[2][0]=-3;M[2][1]=0;M[2][2]=3;M[2][3]=0;
	M[3][0]=1;M[3][1]=4;M[3][2]=1;M[3][3]=0;
	double Mt[4][4];//转置后的基数矩阵
	Mt[0][0]=-1;Mt[0][1]=3;Mt[0][2]=-3;Mt[0][3]=1;
	Mt[1][0]=3;Mt[1][1]=-6;Mt[1][2]=0;Mt[1][3]=4;
	Mt[2][0]=-3;Mt[2][1]=3;Mt[2][2]=3;Mt[2][3]=1;
	Mt[3][0]=1;Mt[3][1]=0;Mt[3][2]=0;Mt[3][3]=0;
//	Mt[0][0]=-1/6;Mt[0][1]=3/6;Mt[0][2]=-3/6;Mt[0][3]=1/6;
//	Mt[1][0]=3/6;Mt[1][1]=-6/6;Mt[1][2]=0;Mt[1][3]=4/6;
//	Mt[2][0]=-3/6;Mt[2][1]=3/6;Mt[2][2]=3/6;Mt[2][3]=1/6;
//	Mt[3][0]=1/6;Mt[3][1]=0;Mt[3][2]=0;Mt[3][3]=0;
	//此处将基函数系数矩阵与坐标点值算出来存入矩阵中，得到系数为1的UV三次函数
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)//将三维坐标点与矩阵左乘，保存在矩阵T中
	{
		T[i][j].x=M[i][0]*P3d[0][j].x+M[i][1]*P3d[1][j].x+M[i][2]*P3d[2][j].x+M[i][3]*P3d[3][j].x;
		T[i][j].y=M[i][0]*P3d[0][j].y+M[i][1]*P3d[1][j].y+M[i][2]*P3d[2][j].y+M[i][3]*P3d[3][j].y;
		T[i][j].z=M[i][0]*P3d[0][j].z+M[i][1]*P3d[1][j].z+M[i][2]*P3d[2][j].z+M[i][3]*P3d[3][j].z;
	}
	for(int i1=0;i1<4;i1++)
	for(int j1=0;j1<4;j1++)  //再与转置矩阵进行矩阵右乘，保存在矩阵T1中
	{
		T1[i1][j1].x=T[i1][0].x*Mt[0][j1]+T[i1][1].x*Mt[1][j1]+T[i1][2].x*Mt[2][j1]+T[i1][3].x*Mt[3][j1];
		T1[i1][j1].y=T[i1][0].y*Mt[0][j1]+T[i1][1].y*Mt[1][j1]+T[i1][2].y*Mt[2][j1]+T[i1][3].y*Mt[3][j1];
		T1[i1][j1].z=T[i1][0].z*Mt[0][j1]+T[i1][1].z*Mt[1][j1]+T[i1][2].z*Mt[2][j1]+T[i1][3].z*Mt[3][j1];
	}
	
	for(int i9=0;i9<4;i9++)//将x、y、z各除36
		for(int j9=0;j9<4;j9++){
			T1[i9][j9].x/=36;
			T1[i9][j9].y/=36;
			T1[i9][j9].z/=36;
		}
	for(int i2=0;i2<4;i2++)//将得到相乘后新的三维坐标值转换为二维坐标
	for(int j2=0;j2<4;j2++)
	{
        P2d[i2][j2].x=T1[i2][j2].y-T1[i2][j2].x/sqrt(2);
	    P2d[i2][j2].y=-T1[i2][j2].z+T1[i2][j2].x/sqrt(2);
	}
	//两次循环先控制u不变，画处v变化的曲线
	for(u=0;u<=1;u+=0.05)
	{
		u1=u*u*u;u2=u*u;u3=u;u4=1;
		x=(u1*P2d[0][0].x+u2*P2d[1][0].x+u3*P2d[2][0].x+u4*P2d[3][0].x);
	//	+(u1*P2d[0][1].x+u2*P2d[1][1].x+u3*P2d[2][1].x+u4*P2d[3][1].x);
	//	+(u1*P2d[0][2].x+u2*P2d[1][2].x+u3*P2d[2][2].x+u4*P2d[3][2].x);
	//	+(u1*P2d[0][3].x+u2*P2d[1][3].x+u3*P2d[2][3].x+u4*P2d[3][3].x);
		y=(u1*P2d[0][0].y+u2*P2d[1][0].y+u3*P2d[2][0].y+u4*P2d[3][0].y);
	//	+(u1*P2d[0][1].y+u2*P2d[1][1].y+u3*P2d[2][1].y+u4*P2d[3][1].y);
	//	+(u1*P2d[0][2].y+u2*P2d[1][2].y+u3*P2d[2][2].y+u4*P2d[3][2].y);
	//	+(u1*P2d[0][3].y+u2*P2d[1][3].y+u3*P2d[2][3].y+u4*P2d[3][3].y);
		dc.MoveTo(ROUND(MaxX/2+x),ROUND(MaxY/2+y));
	for(v=0;v<=1;v+=0.05)
	{
		v1=v*v*v;v2=v*v;v3=v;v4=1;
		x=(u1*P2d[0][0].x+u2*P2d[1][0].x+u3*P2d[2][0].x+u4*P2d[3][0].x)*v1
		+(u1*P2d[0][1].x+u2*P2d[1][1].x+u3*P2d[2][1].x+u4*P2d[3][1].x)*v2
		+(u1*P2d[0][2].x+u2*P2d[1][2].x+u3*P2d[2][2].x+u4*P2d[3][2].x)*v3
		+(u1*P2d[0][3].x+u2*P2d[1][3].x+u3*P2d[2][3].x+u4*P2d[3][3].x)*v4;
		y=(u1*P2d[0][0].y+u2*P2d[1][0].y+u3*P2d[2][0].y+u4*P2d[3][0].y)*v1
		+(u1*P2d[0][1].y+u2*P2d[1][1].y+u3*P2d[2][1].y+u4*P2d[3][1].y)*v2
		+(u1*P2d[0][2].y+u2*P2d[1][2].y+u3*P2d[2][2].y+u4*P2d[3][2].y)*v3
		+(u1*P2d[0][3].y+u2*P2d[1][3].y+u3*P2d[2][3].y+u4*P2d[3][3].y)*v4;
	//	dc.SetPixel(ROUND(MaxX/2+x),ROUND(MaxY/2+y),RGB(155,155,0));
		dc.LineTo(ROUND(MaxX/2+x),ROUND(MaxY/2+y));
		Sleep(1);
	}
	}
	//两次循环先控制v不变，画处u变化的曲线
	//两次画线得到网状结构
		for(v=0;v<=1;v+=0.05)
	{
		v1=v*v*v;v2=v*v;v3=v;v4=1;
		x=(v1*P2d[0][0].x+v2*P2d[1][0].x+v3*P2d[2][0].x+v4*P2d[3][0].x);
	//	+(v1*P2d[0][1].x+v2*P2d[1][1].x+v3*P2d[2][1].x+v4*P2d[3][1].x);
	//	+(v1*P2d[0][2].x+v2*P2d[1][2].x+v3*P2d[2][2].x+v4*P2d[3][2].x);
	//	+(v1*P2d[0][3].x+v2*P2d[1][3].x+v3*P2d[2][3].x+v4*P2d[3][3].x);
		y=(v1*P2d[0][0].y+v2*P2d[1][0].y+v3*P2d[2][0].y+v4*P2d[3][0].y);
	//	+(v1*P2d[0][1].y+v2*P2d[1][1].y+v3*P2d[2][1].y+v4*P2d[3][1].y);
	//	+(v1*P2d[0][2].y+v2*P2d[1][2].y+v3*P2d[2][2].y+v4*P2d[3][2].y);
	//	+(v1*P2d[0][3].y+v2*P2d[1][3].y+v3*P2d[2][3].y+v4*P2d[3][3].y);
		dc.MoveTo(ROUND(MaxX/2+x),ROUND(MaxY/2+y));
		for(u=0;u<=1;u+=0.05)
	{
		u1=u*u*u;u2=u*u;u3=u;u4=1;
		x=(u1*P2d[0][0].x+u2*P2d[1][0].x+u3*P2d[2][0].x+u4*P2d[3][0].x)*v1
		+(u1*P2d[0][1].x+u2*P2d[1][1].x+u3*P2d[2][1].x+u4*P2d[3][1].x)*v2
		+(u1*P2d[0][2].x+u2*P2d[1][2].x+u3*P2d[2][2].x+u4*P2d[3][2].x)*v3
		+(u1*P2d[0][3].x+u2*P2d[1][3].x+u3*P2d[2][3].x+u4*P2d[3][3].x)*v4;
		y=(u1*P2d[0][0].y+u2*P2d[1][0].y+u3*P2d[2][0].y+u4*P2d[3][0].y)*v1
		+(u1*P2d[0][1].y+u2*P2d[1][1].y+u3*P2d[2][1].y+u4*P2d[3][1].y)*v2
		+(u1*P2d[0][2].y+u2*P2d[1][2].y+u3*P2d[2][2].y+u4*P2d[3][2].y)*v3
		+(u1*P2d[0][3].y+u2*P2d[1][3].y+u3*P2d[2][3].y+u4*P2d[3][3].y)*v4;
	//	dc.SetPixel(ROUND(MaxX/2+x),ROUND(MaxY/2+y),RGB(155,155,0));
		dc.LineTo(ROUND(MaxX/2+x),ROUND(MaxY/2+y));
		Sleep(1);
			}
	}
		dc.SelectObject(POldPen);
	MyPen.DeleteObject();
}
//画控制网格
void CTestView::OnProject()
{
	GetMaxX();GetMaxY();
	CClientDC dc(this);
	CPen MyPen,MyPen1,*POldPen;
	CString str;
	MyPen.CreatePen(PS_SOLID,2,RGB(255,0,0));
	MyPen1.CreatePen(PS_SOLID,2,RGB(255,0,0));
	POldPen=dc.SelectObject(&MyPen);
	CPoint p[4],p1[4]; //将控制点存放在两个数组中
	for(int i=0;i<4;i++)
	{
	   for(int j=0;j<4;j++)
	{
	   p[j]=CPoint(ROUND(MaxX/2+b[i][j].x),ROUND(MaxY/2+b[i][j].y)); //存放相同一行点
	   p1[j]=CPoint(ROUND(MaxX/2+b[j][i].x),ROUND(MaxY/2+b[j][i].y));//存放相同一列点
	}
	for(int k=0;k<4;k++)         //每行第一个点开始画线
		if(k==0)                 
		     dc.MoveTo(p[0]);    	  		
		else
		      dc.LineTo(p[k]);
		Sleep(10);
			POldPen=dc.SelectObject(&MyPen1);
		for(int l=0;l<4;l++)      //每列第一个点开始画线
		if(l==0)
		     dc.MoveTo(p1[0]);	   			
		else
		      dc.LineTo(p1[l]);
		Sleep(10);
	}
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(0,0,255));
	for(int i1=0;i1<4;i1++)
	{
	   for(int j1=0;j1<4;j1++)
	{
	str.Format("P%d,%d",i1,j1);               //在每个控制点附近位置添加名称
	dc.TextOut(ROUND(MaxX/2+b[i1][j1].x+20),ROUND(MaxY/2+b[i1][j1].y)+5,str);
	}
	dc.SelectObject(POldPen);
	MyPen.DeleteObject();
}
}
