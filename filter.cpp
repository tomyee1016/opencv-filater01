#include<opencv2/opencv.hpp>
#include<iostream>


using namespace cv;
using namespace std;

 
//------[ȫ�ֱ�����������]----------------
//       ������ȫ�ֱ�������
//-----------------------------------------

Mat
srcimage, dstimage1, dstimage2, dstimage3, dstimage4, dstimage5;
int BoxFilterValue = 6;//�����˲����ں�ֵ
int BlurValue = 10;//��ֵ�˲��ں�ֵ
int GaussianBlurValue = 6;//��˹�˲����ں�ֵ
int MedianBlurValue = 10;//��ֵ�˲�����ֵ
int BilateralFilterValue = 10;//˫���˲�������ֵ


//----------[ȫ�ֺ�����������]------------------
//        ������ȫ�ֺ�������
//-----------------------------------------------
//�켣���ص�����
void on_BoxFilter(int, void *);//�����˲�
void on_Blur(int, void *);//��ֵ�˲�
void on_GaussianBlur(int, void *);//��˹�˲�
void on_MedianBlur(int, void *);
void on_BilateralFilter(int, void *);

//---------------------------------------------
//      ������������
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

	//��ʾԭͼ
	namedWindow("input image");
	imshow("input image", srcimage);


	//-----------------�����˲�--------------
	//��������
	namedWindow("�����˲�", 1);
	//�����켣��
	createTrackbar("�ں�ֵ", "�����˲�", &BoxFilterValue, 50, on_BoxFilter);
	on_BoxFilter(BoxFilterValue, 0);//�ص�����,��һ�������ǹ켣����λ�ã�void*���͵�userdata����Ҳ��Ĭ��ֵ0

	//-----------------��ֵ�˲�--------------
	namedWindow("��ֵ�˲�");
		//�����켣��
	createTrackbar("�ں�ֵ��", "��ֵ�˲�", &BlurValue,50,on_Blur);
	on_Blur(BlurValue, 0);
	//��������
	namedWindow("��˹�˲�");
	//�����켣��
	createTrackbar("�ں�ֵ", "��˹�˲�", &GaussianBlurValue, 50, on_GaussianBlur);
	on_GaussianBlur(GaussianBlurValue, 0);

   //-------------------��ֵ�˲�----------------
	namedWindow("��ֵ�˲�");
	createTrackbar("����ֵ", "��ֵ�˲�", &MedianBlurValue, 50, on_MedianBlur);
	on_MedianBlur(MedianBlurValue, 0);

	//----------------˫���˲�-------------------
	namedWindow("˫���˲�");
	//�����켣��
	createTrackbar("����ֵ��", "˫���˲�", &BilateralFilterValue, 50, on_BilateralFilter);
	on_BilateralFilter(BilateralFilterValue, 0);
	waitKey(0);
	return 0;
}

//--------------------on_BoxFilter()����---------------------
//             �����������˲������Ļص�����
//------------------------------------------------------------
void on_BoxFilter(int, void *) {
	//�����˲�����
	boxFilter(srcimage, dstimage1, -1, Size(BoxFilterValue + 1, BoxFilterValue + 1));
	imshow("�����˲�",dstimage1);
}

//-------------------on_Blur()����------------------------------
//             ������ƽ���˲������Ļص�����
//--------------------------------------------------------------
void on_Blur(int, void *) {
	blur(srcimage, dstimage2, Size(BlurValue + 1, BlurValue + 1), Point(-1, -1));
	imshow("��ֵ�˲�", dstimage2);
}

//--------------------on_GaussianBlur()--------------------------
//              ��������˹�˲������Ļص�����
//---------------------------------------------------------------
void on_GaussianBlur(int, void *) {
	GaussianBlur(srcimage, dstimage3, Size(GaussianBlurValue * 2 + 1, GaussianBlurValue * 2 + 1), 0, 0);
	imshow("��˹�˲�", dstimage3);
}


//-------------------------on_MedianBlur()-----------------------
//              ��������ֵ�˲������Ļص�����
//---------------------------------------------------------------
void on_MedianBlur(int, void *) {
	medianBlur(srcimage, dstimage4, MedianBlurValue * 2 + 1);
	imshow("��ֵ�˲�",dstimage4);
}

//--------------------------on_BilateralFilter()------------------
//              ������˫���˲������Ļص�����
//-----------------------------------------------------------------

void on_BilateralFilter(int, void *) {
	bilateralFilter(srcimage, dstimage5, BilateralFilterValue, BilateralFilterValue * 2, BilateralFilterValue / 2);
	imshow("˫���˲�", dstimage5);
}
