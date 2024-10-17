#include "pch.h"

#define IMAGEOBJECT_DLL_EXPORTS
#include "ImageObject.h"


ImageObject::ImageObject()
{

}


ImageObject::ImageObject(const cv::Mat& img)
	: img_{img.clone()}, width_{ img.cols }, height_{img.rows}
{
    image_buf_ = std::vector<uchar>(img.data, img.data + img.total() * img.elemSize());
}

ImageObject& ImageObject::operator=(const cv::Mat& img)
{
    this->img_ = img.clone();

    this->width_ = this->img_.cols;
    this->height_ = this->img_.rows;

    return *this;
}


void ImageObject::UpdateVec(int const width, int const height, std::vector<uchar>&& img_buf)
{
    width_ = width;
    height_ = height;

    image_buf_ = std::move(img_buf);

    img_ = cv::Mat(height_, width_, CV_8UC1, (uchar*)image_buf_.data());
}


const cv::Mat& ImageObject::CloneMat() const
{
    return img_;
}


const std::vector<uchar>& ImageObject::CloneVec() const
{
    return image_buf_;
}


int ImageObject::Width() const
{
    return width_;
}


int ImageObject::Height() const
{
    return height_;
}


