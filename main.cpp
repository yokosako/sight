#pragma comment(lib, "opencv_core2411d.lib")
#pragma comment(lib, "opencv_highgui2411d.lib")

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


struct point_t {
	cv::Point pt0;	// �n�_
	cv::Point pt1;	// �I�_
};


int main() {
	point_t horizon;
	point_t vertical;

	// �摜�ǂݍ���
	cv::Mat img = cv::imread("DSC_4671.TIF");
	
	// �ǂݍ��񂾉摜�̏��\���iwidth, hight�j
	std::cout << "Hight : " << img.rows << "[px]" << std::endl;
	std::cout << "Width : " << img.cols << "[px]" << std::endl;

	// �摜�������̃|�C���g
	horizon.pt0 = cv::Point(0, img.rows / 2);
	horizon.pt1 = cv::Point(img.cols, img.rows / 2);
	
	// �摜�������̃|�C���g
	vertical.pt0 = cv::Point(img.cols / 2, 0);
	vertical.pt1 = cv::Point(img.cols / 2, img.rows);

	// �ǂݍ��񂾉摜�ɒ�����������
	cv::line(img, horizon.pt0, horizon.pt1, cv::Scalar(0, 0, 255));
	cv::line(img, vertical.pt0, vertical.pt1, cv::Scalar(0, 255, 0));

	// �摜���o
	cv::Mat cutImg(img, cv::Rect(3080, 2056, 1200, 800));

	// ���o�摜�\��
	cv::imshow("Sight", cutImg);


	cv::waitKey(0);

	return 0;
}