// FineCorrectionDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "SummerRSProject.h"
#include "FineCorrectionDlg.h"
#include "afxdialogex.h"


// FineCorrectionDlg 对话框

IMPLEMENT_DYNAMIC(FineCorrectionDlg, CDialogEx)

FineCorrectionDlg::FineCorrectionDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FineCorrection, pParent)
	, m_x_base(0)
	, m_y_base(0)
	, m_x_wrap(0)
	, m_y_wrap(0)
	, m_num_GCPs(0)
	, m_method(_T(""))
	, m_degree(0)
	, m_resample(_T(""))
	, m_background(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

FineCorrectionDlg::~FineCorrectionDlg()
{
}

void FineCorrectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Text(pDX, IDC_Base_X, m_x_base);
	DDX_Text(pDX, IDC_Base_Y, m_y_base);
	DDX_Text(pDX, IDC_Wrap_X, m_x_wrap);
	DDX_Text(pDX, IDC_wrap_Y, m_y_wrap);
	DDX_Text(pDX, IDC_Num_GCPs, m_num_GCPs);
	DDX_CBString(pDX, IDC_COMBO_METHOD, m_method);
	DDX_CBIndex(pDX, IDC_COMBO_DEGREE, m_degree);
	DDX_CBString(pDX, IDC_COMBO_RESAMPLE, m_resample);
	DDX_Text(pDX, IDC_EDIT1, m_background);
}


BEGIN_MESSAGE_MAP(FineCorrectionDlg, CDialogEx)
	ON_COMMAND(ID_BaseFile, &FineCorrectionDlg::OnBasefile)
	ON_COMMAND(ID_WrapFile, &FineCorrectionDlg::OnWrapfile)
	ON_COMMAND(ID_HELP, &FineCorrectionDlg::OnHelp)
END_MESSAGE_MAP()


// FineCorrectionDlg 消息处理程序


BOOL FineCorrectionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//陈炳如7:2：获取菜单
	menu.LoadMenu(IDR_MENU_FC);  //IDR_MENU_FC为菜单栏ID号
	SetMenu(&menu);

	//陈炳如7:2：初始化窗口指针
	m_base_image = new ImageDlg();
	m_wrap_image = new ImageDlg();


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

//陈炳如7:2：打开配准文件及窗口
void FineCorrectionDlg::OnBasefile()
{
	// TODO: 在此添加命令处理程序代码
	m_base_image->Create(IDD_DIALOG_IMAGE);

	//打开文件
	CFileDialog dlg(TRUE, _T("*.*"), NULL, OFN_HIDEREADONLY, _T("*.*|*.*||"));
	CString csFileName;
	if (dlg.DoModal() == IDOK)
	{
		csFileName = dlg.GetPathName();//选择的文件路径   
	}
	m_base_image->OpenFile(csFileName,_T("Base Image"));

	//显示窗体
	m_base_image->ShowWindow(SW_SHOWNORMAL);

}

//陈炳如7:2：打开待配准文件及窗口
void FineCorrectionDlg::OnWrapfile()
{
	// TODO: 在此添加命令处理程序代码
	m_wrap_image->Create(IDD_DIALOG_IMAGE);

	//打开文件
	CFileDialog dlg(TRUE, _T("*.*"), NULL, OFN_HIDEREADONLY, _T("*.*|*.*||"));
	CString csFileName;
	if (dlg.DoModal() == IDOK)
	{
		csFileName = dlg.GetPathName();//选择的文件路径   
	}
	m_wrap_image->OpenFile(csFileName,_T("Wrap Image"));

	//显示窗体
	m_wrap_image->ShowWindow(SW_SHOWNORMAL);
}

//陈炳如7:2：messageBox，写一些注意事项
void FineCorrectionDlg::OnHelp()
{
	// TODO: 在此添加命令处理程序代码
}

//陈炳如7:2：释放窗口指针
BOOL FineCorrectionDlg::DestroyWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	if(m_base_image!=NULL)delete m_base_image;
	if(m_wrap_image!=NULL)delete m_wrap_image;

	return CDialogEx::DestroyWindow();
}
