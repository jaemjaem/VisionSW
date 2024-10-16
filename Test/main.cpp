#include <iostream>
#include <memory>
#include <opencv2/opencv.hpp>

#include "OpenCVBlur.h"

int main()
{
	cv::Mat img = cv::imread("lena.bmp", cv::IMREAD_GRAYSCALE);

	std::unique_ptr<ImageObject> src_img_obj = std::make_unique<ImageObject>(img);
	std::unique_ptr<ImageObject> dst_img_obj = std::make_unique<ImageObject>();

	ImageBlur(src_img_obj.get(), dst_img_obj.get(), 10);
	
	const cv::Mat& dst_img = dst_img_obj->Clone();

	cv::imshow("test", dst_img);
	cv::waitKey();

	return 0;
}