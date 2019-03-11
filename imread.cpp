#include<opencv2/opencv.hpp>
#include<iostream>


using namespace cv;
using namespace std;

char OUTPUT_WIN[] = "output image";
int main(int argc, char** argv) {
	Mat src;
	src = imread("H:/images/flower.jpg");
	if (!src.data) {
		cout << "could not load image..." << endl;
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);
	Mat dst;
	//boxFilter(src, dst, -1, Size(5, 5), Point(-1, -1));
	//blur(src, dst, Size(7, 7));//��ֵ�˲�
	//GaussianBlur(src, dst, Size(3, 3), 0, 0);//��˹�˲�
	medianBlur(src, dst, 7);//��ֵ�˲��Խ���������ȥ������Ч��ʮ������
	bilateralFilter(src, dst, 25, 25 * 2, 25 / 2);
	namedWindow(OUTPUT_WIN, CV_WINDOW_AUTOSIZE);
	imshow(OUTPUT_WIN, dst);
	waitKey(0);
	destroyAllWindows();
	return 0;
}

