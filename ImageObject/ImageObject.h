#pragma once

#include <vector>

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
	
	ImageObject& operator=(const cv::Mat& other);
	const cv::Mat& Clone() const;

private:
	std::vector<uchar> image_buf_;

	cv::Mat img_;
	int width_ = 0;
	int height_ = 0;
};