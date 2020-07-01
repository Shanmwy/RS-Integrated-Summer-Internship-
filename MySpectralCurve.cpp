#include "stdafx.h"
#include "MySpectralCurve.h"

void MySpectralCurve::CalcViewPoints(MyBoundingBox currentBBox, CRect rectPictureControl)
{
	int size = originalPoints.size();
	viewPoints.clear();
	for (int i = 0; i < size; i++)
	{
		float x = (originalPoints[i].x - currentBBox.xmin) / (currentBBox.xmax - currentBBox.xmin)*rectPictureControl.Width();
		float y = rectPictureControl.Height() - (originalPoints[i].y - currentBBox.ymin) / (currentBBox.ymax - currentBBox.ymin)*rectPictureControl.Height();
		viewPoints.push_back(MyPoint(x, y));
	}
}

MyBoundingBox MySpectralCurve::GetBoundingBox()
{
	int size = originalPoints.size();
	MyBoundingBox res(originalPoints[0].x, originalPoints[size - 1].x, originalPoints[0].y, originalPoints[0].y);
	for (int i = 0; i < size; i++)
	{
		if (originalPoints[i].y > res.ymax)
			res.ymax = originalPoints[i].y;
		if (originalPoints[i].y < res.ymin)
			res.ymin = originalPoints[i].y;
	}
	return res;
}
