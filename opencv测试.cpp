#include <iostream>
#include<opencv2/opencv.hpp>

using namespace cv;

int main()
{
	//读取图片，这里修改为你的图片路径，注意需要将单斜杠写成双斜杠
	Mat img = imread("C://Users//hp//Pictures//Camera Roll//QQ图片20210429234831.jpg");
	imshow("IMG", img); //显示图片
	waitKey(0);
	return 0;
}