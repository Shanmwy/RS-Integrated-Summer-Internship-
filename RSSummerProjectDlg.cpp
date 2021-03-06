
// RSSummerProjectDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "RSSummerProject.h"
#include "RSSummerProjectDlg.h"
#include "afxdialogex.h"
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRSSummerProjectDlg 对话框



CRSSummerProjectDlg::CRSSummerProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RSSUMMERPROJECT_DIALOG, pParent)
	, y0(_T(""))
	, y1(_T(""))
	, y2(_T(""))
	, y3(_T(""))
	, y4(_T(""))
	, y5(_T(""))
	, y6(_T(""))
	, y7(_T(""))
	, y8(_T(""))
	, y9(_T(""))
	, y10(_T(""))
	, IDC_X0(_T(""))
	, IDC_Y0(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRSSummerProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT1, y0);
	DDX_Text(pDX, IDC_EDIT2, y1);
	DDX_Text(pDX, IDC_EDIT3, y2);
	DDX_Text(pDX, IDC_EDIT4, y3);
	DDX_Text(pDX, IDC_EDIT5, y4);
	DDX_Text(pDX, IDC_EDIT6, y5);
	DDX_Text(pDX, IDC_EDIT7, y6);
	DDX_Text(pDX, IDC_EDIT8, y7);
	DDX_Text(pDX, IDC_EDIT9, y8);
	DDX_Text(pDX, IDC_EDIT10, y9);
	DDX_Text(pDX, IDC_EDIT11, y10);
	DDX_Text(pDX, IDC_X_CURRENT, IDC_X0);
	DDX_Text(pDX, IDC_Y_CURRENT, IDC_Y0);
}

BEGIN_MESSAGE_MAP(CRSSummerProjectDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CRSSummerProjectDlg::OnLvnItemchangedList1)
	ON_WM_MOUSEMOVE()
//	ON_EN_CHANGE(IDC_EDIT10, &CRSSummerProjectDlg::OnEnChangeEdit10)
ON_COMMAND(ID_OPENFILE, &CRSSummerProjectDlg::OnOpenfile)
ON_COMMAND(ID_CLOSEFILE, &CRSSummerProjectDlg::OnClosefile)
ON_COMMAND(ID_EXPORT, &CRSSummerProjectDlg::OnExport)
END_MESSAGE_MAP()


// CRSSummerProjectDlg 消息处理程序

BOOL CRSSummerProjectDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	m_Menu.LoadMenu(IDR_MENU1);

	SetMenu(&m_Menu);

	//陈奕卓6.30：初始化currentRect，初始化成不可能的值
	m_currentBBox.ymin = 0;
	m_currentBBox.ymax = 1;
	m_currentBBox.xmin = 0;
	m_currentBBox.xmax = 2500;

	//陈奕卓6.30：初始化colorRepo
	m_colorRepo.push(RGB(255, 255, 0));
	m_colorRepo.push(RGB(0, 255, 255));
	m_colorRepo.push(RGB(255, 0, 255));
	m_colorRepo.push(RGB(255, 0, 0));
	m_colorRepo.push(RGB(0, 255, 0));
	m_colorRepo.push(RGB(0, 0, 255));
	m_colorRepo.push(RGB(0, 0, 0));
	m_defaultColor = RGB(127, 127, 127);

	//获取坐标轴在窗口的位置
	//CRect rectCtrl;
	//CStatic *p = (CStatic*)GetDlgItem(IDC_STATIC);
	//p->MoveWindow(400, 50, 600, 300);

	////"D:\3170102772\RSSummerProject\RSSummerProject\res\bottom.jpg"


	//CImage myImage;

	//CFileDialog fileDlg(TRUE, NULL, NULL, OFN_ALLOWMULTISELECT, _T("Picture Files (*.bmp *.jpg)|*bmp;;*jpg||"), AfxGetMainWnd());

	//CString pathName = (_T("D:\3170102772\RSSummerProject\RSSummerProject\res\bottom.bmp"));



	//

	//CRect Rect1;

	//CWnd *pWnd = GetDlgItem(IDC_STATIC);

	//CDC *pDC = pWnd->GetDC();

	////第1个控件

	//pWnd->GetClientRect(&Rect1); //取得客户区尺寸

	//pDC->SetStretchBltMode(STRETCH_HALFTONE); //保持图片不失真

	//myImage.Draw(pDC->m_hDC, Rect1); //已控件尺寸大小来绘图

	//ReleaseDC(pDC);

	//myImage.Destroy();


	/*GetDlgItem(IDC_STATIC)->GetWindowRect(&rectCtrl);
	ScreenToClient(&rectCtrl);
	CString str;
	str.Format(L"%d,%d,%d,%d", rectCtrl.left, rectCtrl.bottom, rectCtrl.Width(), rectCtrl.Height());*/
	///MessageBox(str);
	
	
	/*CString temp;
	int i = 119;
	temp.Format(L"%d",i);
	y2 = temp;
	UpdateData(false);
*/

	/*m_list.GetClientRect(&rectCtrl);

	m_list.InsertColumn(0, _T("地物编号"), LVCFMT_CENTER, rectCtrl.Width() / 2, 0);

	m_list.InsertColumn(1, _T("颜色"), LVCFMT_CENTER, rectCtrl.Width() / 2, 1);*/

	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CRSSummerProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRSSummerProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}
	

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CRSSummerProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void CRSSummerProjectDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

void CRSSummerProjectDlg::InitListControl() {

	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;// 选中某行使整行高亮（仅仅适用与report 风格的listctrl ） 
	dwStyle |= LVS_EX_GRIDLINES;// 网格线（仅仅适用与report 风格的listctrl ） 
	//dwStyle |= LVS_EX_CHECKBOXES;//item 前生成checkbox 控件 
	m_list.SetExtendedStyle(dwStyle); // 设置扩展风格 
	dwStyle |= LVS_EX_FULLROWSELECT;// 选中某行使整行高亮（仅仅适用与report 风格的listctrl ）
	//设置列表控件的报表显示方式
	//m_BgListCtr.ModifyStyle(LVS_ICON | LVS_SMALLICON | LVS_LIST, LVS_REPORT);

	//设置列表控件显示网格线
	//m_BgListCtr.SetExtendedStyle(LVS_EX_GRIDLINES);

	CRect rectCtrl;

	m_list.GetClientRect(&rectCtrl);


	m_list.InsertColumn(0, _T("地物编号"), LVCFMT_CENTER, rectCtrl.Width() / 2);

	m_list.InsertColumn(1, _T("颜色"), LVCFMT_CENTER, rectCtrl.Width() / 2);

	UpdateData(false);

	return;

}

//王铮6.30：鼠标移动计算当前坐标
//陈奕卓6.30：修改，计算当前坐标
void CRSSummerProjectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	//陈奕卓6.30：获取PC的位置
	CStatic *p = (CStatic*)GetDlgItem(IDC_STATIC);
	p->GetWindowRect(&m_rectPictureControl);
	ScreenToClient(&m_rectPictureControl);

	//如果鼠标在PC里
	if (point.x > m_rectPictureControl.left && point.x < m_rectPictureControl.right && point.y > m_rectPictureControl.top && point.y < m_rectPictureControl.bottom)
	{
		CString str;
		float x1 = point.x - m_rectPictureControl.left;
		float y1 = m_rectPictureControl.bottom - point.y;
		x1 = x1 * m_currentBBox.Width() / m_rectPictureControl.Width() + m_currentBBox.xmin;
		y1 = y1 * m_currentBBox.Height() / m_rectPictureControl.Height() + m_currentBBox.ymin;

		str.Format(_T("%.3f"), x1);
		this->GetDlgItem(IDC_X_CURRENT)->SetWindowText(str);
		str.Format(_T("%.3f"), y1);
		this->GetDlgItem(IDC_Y_CURRENT)->SetWindowText(str);
	}
	else {
		CString str;
		str.Format(_T("   "));
		this->GetDlgItem(IDC_X_CURRENT)->SetWindowText(str);
		this->GetDlgItem(IDC_Y_CURRENT)->SetWindowText(str);
	}
	//CDialog::OnMouseMove(nFlags, point);
}


void CRSSummerProjectDlg::RefreshAll()
{
}

void CRSSummerProjectDlg::CalcBBox()
{
	//目前暂时只考虑动态改变y轴
	MyBoundingBox bb;
	m_currentBBox.ymin = 2;
	m_currentBBox.ymax = -1;
	for (int i = 0; i < m_spectralCurves.size(); i++)
	{
		bb = m_spectralCurves[i].GetBoundingBox();
		m_currentBBox.ymin = min(bb.ymin, m_currentBBox.ymin);
		m_currentBBox.ymax = max(bb.ymax, m_currentBBox.ymax);
	}
	//给y取个整，取到0.1
	m_currentBBox.ymin = floor(m_currentBBox.ymin * 10) / 10;
	m_currentBBox.ymax = ceil(m_currentBBox.ymax * 10) / 10;

	//重新算viewPoints
	for (int i = 0; i < m_spectralCurves.size(); i++)
	{
		m_spectralCurves[i].CalcViewPoints(m_currentBBox, m_rectPictureControl);
	}

}

//陈奕卓6.30：打开文件消息响应
void CRSSummerProjectDlg::OnOpenfile()
{
	// 设置过滤器   
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|ASC文件(*.asc)|*.asc|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;

	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		std::ifstream file;
		file.open(strFilePath, ios::in);
		char wasted[201];
		float x, y;
		MySpectralCurve curve;
		curve.fileName = strFilePath;
		if (fileDlg.GetFileExt() == "txt")
		{
			while (!file.eof())
			{
				file >> wasted >> wasted >> x >> y;
				curve.originalPoints.push_back(MyPoint(x, y));
			}
		}
		else if (fileDlg.GetFileExt() == "asc")
		{
			for (int i=0;i<16;i++)
				file.getline(wasted, 200);
			while (!file.eof())
			{
				file >> x >> y >> wasted;
				if (y < 0)
					continue;
				curve.originalPoints.push_back(MyPoint(x, y));
			}
		}
		else
		{
			MessageBox(_T("Not a valid spectral file."));
			return;
		}
		
		//设置颜色
		if (m_colorRepo.empty())
		{
			curve.color = m_defaultColor;
		}
		else
		{
			curve.color = m_colorRepo.top();
			m_colorRepo.pop();
		}

		m_spectralCurves.push_back(curve);

		//重新计算BBox
		CalcBBox();

		//重绘
		RefreshAll();
	}
}

//陈奕卓6.30：关闭文件消息响应
void CRSSummerProjectDlg::OnClosefile()
{
	//归还颜色
	for (int i = m_spectralCurves.size()-1; i >=0; i--)
	{
		m_colorRepo.push(m_spectralCurves[i].color);
		m_spectralCurves.pop_back();
	}
	RefreshAll();
}

//陈奕卓6.30：输出图片消息响应
void CRSSummerProjectDlg::OnExport()
{
	// 设置过滤器   
	TCHAR szFilter[] = _T("bmp文件(*.bmp)|*.bmp|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(FALSE, _T("txt"), _T("export"), 0, szFilter, this);
	CString strFilePath;

	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		CRect rect;
		GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
		CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
		CImage Image;
		Image.Create(rect.Width(), rect.Height(), 24);
		::BitBlt(Image.GetDC(), 0, 0, rect.Width(), rect.Height(), pDC->m_hDC, 0, 0, SRCCOPY);
		Image.Save(fileDlg.GetPathName());
		Image.ReleaseDC();
		Image.Destroy();
	}

}
