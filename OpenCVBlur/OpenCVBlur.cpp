#include "pch.h"

#include "OpenCVBlur.h"
#include "ImageObject.h"

void Imshow()
{
	cv::Mat img = cv::imread("lena.bmp");

	cv::imshow("image", img);
	cv::waitKey();
}

void test()
{
	ImageObject test{ 10, 20 };

	std::cout << test.Width() << std::endl;
	std::cout << test.Height() << std::endl;
}