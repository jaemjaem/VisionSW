#include "pch.h"

#include "OpenCVBlur.h"

// return false �� ��� ó�� �ʿ�
// Ŀ�� �ּ� size 21x21
namespace opencvfunction
{
	bool ImageBlur(const ImageObject* src, ImageObject* dst, const int kernelSize)
	{
		if (src == nullptr)
		{
			return false;
		}

		auto src_img = src->CloneMat();

		if (src_img.empty())
		{
			return false;
		}

		cv::Mat dst_img;

		try
		{
			cv::blur(src_img, dst_img, cv::Size(kernelSize, kernelSize));
		}
		catch (const std::exception& e)
		{
			return false;
		}

		if (dst == nullptr)
		{
			return false;
		}

		*dst = dst_img;

		return true;
	}
}
