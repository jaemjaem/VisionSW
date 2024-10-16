#include "pch.h"

#include "OpenCVBlur.h"

// return false �� ��� ó�� �ʿ�
// Ŀ�� �ּ� size 21x21
bool ImageBlur(const ImageObject* src, ImageObject* dst, const int kernelSize)
{
	if (src == nullptr)
	{
		return false;
	}
	
	auto src_img = src->Clone();

	cv::Mat dst_img;

	cv::blur(src_img, dst_img, cv::Size(kernelSize, kernelSize));

	if (dst == nullptr)
	{
		return false;
	}

	*dst = dst_img;

	return true;
}