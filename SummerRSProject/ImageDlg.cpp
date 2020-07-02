// ImageDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "SummerRSProject.h"
#include "ImageDlg.h"
#include "afxdialogex.h"


// ImageDlg 对话框

IMPLEMENT_DYNAMIC(ImageDlg, CDialogEx)

ImageDlg::ImageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_IMAGE, pParent)
{

}

ImageDlg::~ImageDlg()
{
}

void ImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ImageDlg, CDialogEx)
END_MESSAGE_MAP()


// ImageDlg 消息处理程序


BOOL ImageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_Menu.LoadMenu(IDR_MENU_IMG);
	SetMenu(&m_Menu);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void ImageDlg:: OpenFile(CString path, CString windowName)
{
	fileName = path;
	this->SetWindowText(windowName);

	//打开

}
