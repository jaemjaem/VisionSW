#pragma once

#include <vector>
#include <opencv2/opencv.hpp>

#ifdef IMAGEOBJECT_DLL_EXPORTS
#define IMAGEOBJECTLIBRARY_API __declspec(dllexport)
#else
#define IMAGEOBJECTLIBRARY_API __declspec(dllimport)
#endif


class IMAGEOBJECTLIBRARY_API ImageObject
{
public:
	ImageObject();
	ImageObject(const cv::Mat& img);
	
	ImageObject& operator=(const cv::Mat& img);

	void UpdateVec(int const width, int const height, std::vector<uchar>&& img_buf);

	const cv::Mat& CloneMat() const;
	const std::vector<uchar>& CloneVec() const;

	int Width() const;
	int Height() const;

private:
	std::vector<uchar> image_buf_;

	cv::Mat img_;
	int width_ = 0;
	int height_ = 0;
};