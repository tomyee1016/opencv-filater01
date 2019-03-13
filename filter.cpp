#include<opencv2/opencv.hpp>
#include<iostream>


using namespace cv;
using namespace std;

 
//------[全局变量声明部分]----------------
//       描述：全局变量声明
//-----------------------------------------

Mat
srcimage, dstimage1, dstimage2, dstimage3, dstimage4, dstimage5;
int BoxFilterValue = 6;//方框滤波器内核值
int BlurValue = 10;//均值滤波内核值
int GaussianBlurValue = 6;//高斯滤波器内核值
int MedianBlurValue = 10;//中值滤波参数值
int BilateralFilterValue = 10;//双边滤波器参数值


//----------[全局函数声明部分]------------------
//        描述：全局函数声明
//-----------------------------------------------
//轨迹条回调函数
void on_BoxFilter(int, void *);//方框滤波
void on_Blur(int, void *);//均值滤波
void on_GaussianBlur(int, void *);//高斯滤波
void on_MedianBlur(int, void *);
void on_BilateralFilter(int, void *);

//---------------------------------------------
//      描述：主函数
//----------------------------------------------
int main(int argc, char** argv) {
	srcimage = imread("H:/images/flower.jpg");
	if (srcimage.empty()) {
		cout << "can not load the image" << endl;
		return -1;
	}
	srcimage.copyTo(dstimage1);
	dstimage2 = srcimage.clone();
	dstimage3 = srcimage.clone();
	dstimage4 = srcimage.clone();
	dstimage5 = srcimage.clone();

	//显示原图
	namedWindow("input image");
	imshow("input image", srcimage);


	//-----------------方框滤波--------------
	//创建窗口
	namedWindow("方框滤波", 1);
	//创建轨迹条
	createTrackbar("内核值", "方框滤波", &BoxFilterValue, 50, on_BoxFilter);
	on_BoxFilter(BoxFilterValue, 0);//回调函数,第一个参数是轨迹条的位置，void*类型的userdata，其也有默认值0

	//-----------------均值滤波--------------
	namedWindow("均值滤波");
		//创建轨迹条
	createTrackbar("内核值：", "均值滤波", &BlurValue,50,on_Blur);
	on_Blur(BlurValue, 0);
	//创建窗口
	namedWindow("高斯滤波");
	//创建轨迹条
	createTrackbar("内核值", "高斯滤波", &GaussianBlurValue, 50, on_GaussianBlur);
	on_GaussianBlur(GaussianBlurValue, 0);

   //-------------------中值滤波----------------
	namedWindow("中值滤波");
	createTrackbar("参数值", "中值滤波", &MedianBlurValue, 50, on_MedianBlur);
	on_MedianBlur(MedianBlurValue, 0);

	//----------------双边滤波-------------------
	namedWindow("双边滤波");
	//创建轨迹条
	createTrackbar("参数值：", "双边滤波", &BilateralFilterValue, 50, on_BilateralFilter);
	on_BilateralFilter(BilateralFilterValue, 0);
	waitKey(0);
	return 0;
}

//--------------------on_BoxFilter()函数---------------------
//             描述：方框滤波操作的回调函数
//------------------------------------------------------------
void on_BoxFilter(int, void *) {
	//方框滤波操作
	boxFilter(srcimage, dstimage1, -1, Size(BoxFilterValue + 1, BoxFilterValue + 1));
	imshow("方框滤波",dstimage1);
}

//-------------------on_Blur()函数------------------------------
//             描述：平均滤波操作的回调函数
//--------------------------------------------------------------
void on_Blur(int, void *) {
	blur(srcimage, dstimage2, Size(BlurValue + 1, BlurValue + 1), Point(-1, -1));
	imshow("均值滤波", dstimage2);
}

//--------------------on_GaussianBlur()--------------------------
//              描述：高斯滤波操作的回调函数
//---------------------------------------------------------------
void on_GaussianBlur(int, void *) {
	GaussianBlur(srcimage, dstimage3, Size(GaussianBlurValue * 2 + 1, GaussianBlurValue * 2 + 1), 0, 0);
	imshow("高斯滤波", dstimage3);
}


//-------------------------on_MedianBlur()-----------------------
//              描述：中值滤波操作的回调函数
//---------------------------------------------------------------
void on_MedianBlur(int, void *) {
	medianBlur(srcimage, dstimage4, MedianBlurValue * 2 + 1);
	imshow("中值滤波",dstimage4);
}

//--------------------------on_BilateralFilter()------------------
//              描述：双边滤波操作的回调函数
//-----------------------------------------------------------------

void on_BilateralFilter(int, void *) {
	bilateralFilter(srcimage, dstimage5, BilateralFilterValue, BilateralFilterValue * 2, BilateralFilterValue / 2);
	imshow("双边滤波", dstimage5);
}
