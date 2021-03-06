
// RSSummerProjectDlg.h: 头文件
//

#pragma once

#include "MySpectralCurve.h"
#include <stack>


// CRSSummerProjectDlg 对话框
class CRSSummerProjectDlg : public CDialog
{
// 构造
public:
	CRSSummerProjectDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RSSUMMERPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	CMenu m_Menu;

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
	afx_msg void InitListControl();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_list;
	CString y0;
	CString y1;
	CString y2;
	CString y3;
	CString y4;
	CString y5;
	CString y6;
	CString y7;
	CString y8;
	CString y9;
	CString y10;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	
	CString IDC_X0;
	CString IDC_Y0;
//	afx_msg void OnEnChangeEdit10();

	//陈奕卓6.30：用来指示PictureControl的位置
	CRect m_rectPictureControl;

	//陈奕卓6.30：用来指示当前绘制曲线的横坐标的最小值最大值，纵坐标的最小值最大值
	MyBoundingBox m_currentBBox;

	//陈奕卓6.30：目前所有的曲线们
	std::vector<MySpectralCurve> m_spectralCurves;

	//陈奕卓6.30：所有能用的COLOR
	std::stack<COLORREF> m_colorRepo;

	//陈奕卓6.30：默认颜色
	COLORREF m_defaultColor;

	//陈奕卓6.30，listControl，PC，坐标轴全部重绘，初始化、打开、关闭asd文件时调用
	void RefreshAll();

	//陈奕卓6.30：只重绘十字准星与label，单击时调用
	void RefreshCross();

	//陈奕卓6.30：获得BoundingBox，并以此修改掉所有的viewPoints
	void CalcBBox();
	
	afx_msg void OnOpenfile();
	afx_msg void OnClosefile();
	afx_msg void OnExport();
};
