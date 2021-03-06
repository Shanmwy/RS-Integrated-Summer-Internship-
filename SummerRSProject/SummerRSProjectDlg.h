
// SummerRSProjectDlg.h: 头文件
//

#pragma once

//陈炳如7:2：下面添加窗体的头文件
#include"FineCorrectionDlg.h"

// CSummerRSProjectDlg 对话框
class CSummerRSProjectDlg : public CDialogEx
{
// 构造
public:
	CSummerRSProjectDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SUMMERRSPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 主页面tab控件
	CTabCtrl m_tab;

	//陈炳如7:2：光谱曲线窗体


	//陈炳如7:2：精校正窗体
	FineCorrectionDlg m_dlg_fineCorrection;

	//陈炳如7:2：tab操作函数
	afx_msg void OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult);
};
