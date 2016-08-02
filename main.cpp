#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


struct point_t {
	cv::Point pt0;	// 始点
	cv::Point pt1;	// 終点
};


int main() {
	point_t horizon;
	point_t vertical;

	// 画像読み込み
	cv::Mat img = cv::imread("yokosako.JPG");
	
	// 読み込んだ画像の情報表示（width, hight）
	std::cout << "Hight : " << img.rows << "[px]" << std::endl;
	std::cout << "Width : " << img.cols << "[px]" << std::endl;

	// 画像水平線のポイント
	horizon.pt0 = cv::Point(0, img.rows / 2);
	horizon.pt1 = cv::Point(img.cols, img.rows / 2);
	
	// 画像垂直線のポイント
	vertical.pt0 = cv::Point(img.cols / 2, 0);
	vertical.pt1 = cv::Point(img.cols / 2, img.rows);

	// 読み込んだ画像に中央線を引く
	cv::line(img, horizon.pt0, horizon.pt1, cv::Scalar(0, 0, 255));
	cv::line(img, vertical.pt0, vertical.pt1, cv::Scalar(0, 255, 0));

	// 画像抽出
	//	cv::Mat cutImg(img, cv::Rect(3080, 2056, 1200, 800));

	// 抽出画像表示
	cv::imshow("Sight", img);


	cv::waitKey(0);

	return 0;
}
