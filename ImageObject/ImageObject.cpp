#include "pch.h"

#define IMAGEOBJECT_DLL_EXPORTS
#include "ImageObject.h"


ImageObject::ImageObject()
{

}


ImageObject::ImageObject(const cv::Mat& img)
	: img_{img.clone()}, width_{ img.cols }, height_{img.rows}
{
    if (img.isContinuous())
    {        
        image_buf_.assign((int*)img.datastart, (int*)img.dataend);
    }
    else 
    {
        for (int i = 0; i < img.rows; ++i)
        {
            image_buf_.insert(image_buf_.end(), img.ptr<uchar>(i), img.ptr<uchar>(i) + img.cols);
        }
    }

}

ImageObject& ImageObject::operator=(const cv::Mat& other)
{
    this->img_ = other.clone();

    this->width_ = this->img_.cols;
    this->height_ = this->img_.rows;

    return *this;
}


const cv::Mat& ImageObject::Clone() const
{
    return img_;
}