#pragma once

#include"MyPoint.h"
#include<vector>

// ImageDlg 对话框

class ImageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ImageDlg)

public:
	ImageDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ImageDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_IMAGE };
#endif

protected:
	CMenu m_Menu;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	//陈炳如7:2:打开指定文件
	void OpenFile(CString path,CString windowName);

	//陈炳如7:2获取待定坐标，并将坐标添加到数组
	MyPoint GetPendingPoint();

	//陈炳如7:2删除指定坐标
	void DeletePoint(int n);

	//陈炳如7:2修改指定坐标
	void ModifyPoint(int n,float dx,float dy);

private:
	//陈炳如7:2：文件路径
	CString fileName;

	//陈炳如7:2：坐标数组，红十字标识
	std::vector<MyPoint> m_selectedPoints;

	//陈炳如7:2：待定坐标，绿十字标识
	MyPoint m_pendingPoint;
};
