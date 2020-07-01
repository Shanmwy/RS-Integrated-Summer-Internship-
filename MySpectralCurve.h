#pragma once
#include "MyPoint.h"
#include <vector>
#include "stdafx.h"

using namespace std;

//陈奕卓6.30：光谱曲线类
class MySpectralCurve
{
public:
	//原始点
	vector<MyPoint> originalPoints;

	//视图点，将原始点完成了上下翻转、拉伸，ready to draw
	//注意，这里认为原点在图片左上角，而不是在整个窗口的左上角！
	vector<MyPoint> viewPoints;

	//文件名，即路径
	CString fileName;

	//曲线绘制的颜色
	COLORREF color;

	void CalcViewPoints(MyBoundingBox currentBBox, CRect rectPictureControl);

	MyBoundingBox GetBoundingBox();
};

