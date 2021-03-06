#pragma once
#include"ImageDlg.h"

// FineCorrectionDlg 对话框

class FineCorrectionDlg : public CDialogEx
{
	DECLARE_DYNAMIC(FineCorrectionDlg)

public:
	FineCorrectionDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~FineCorrectionDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FineCorrection };
#endif

protected:
	HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	//陈炳如7:2，menu相关函数等
	CMenu menu;
	afx_msg void OnBasefile();
	afx_msg void OnWrapfile();
	afx_msg void OnHelp();
	// 陈炳如7:2：GCP列表
	CListCtrl m_list;
	float m_x_base;
	float m_y_base;
	float m_x_wrap;
	float m_y_wrap;
	int m_num_GCPs;

	//陈炳如7:2：图像窗体指针
	ImageDlg *m_base_image;
	ImageDlg *m_wrap_image;

	//陈炳如7:2：释放窗口指针
	virtual BOOL DestroyWindow();
	// 模式
	CString m_method;
	// 级数
	int m_degree;
	// 重采样
	CString m_resample;
	// 背景
	float m_background;
};
