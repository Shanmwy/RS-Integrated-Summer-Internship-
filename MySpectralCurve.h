#pragma once
#include "MyPoint.h"
#include <vector>
#include "stdafx.h"

using namespace std;

//����׿6.30������������
class MySpectralCurve
{
public:
	//ԭʼ��
	vector<MyPoint> originalPoints;

	//��ͼ�㣬��ԭʼ����������·�ת�����죬ready to draw
	//ע�⣬������Ϊԭ����ͼƬ���Ͻǣ����������������ڵ����Ͻǣ�
	vector<MyPoint> viewPoints;

	//�ļ�������·��
	CString fileName;

	//���߻��Ƶ���ɫ
	COLORREF color;

	void CalcViewPoints(MyBoundingBox currentBBox, CRect rectPictureControl);

	MyBoundingBox GetBoundingBox();
};

