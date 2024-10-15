#include "pch.h"

#define IMAGEOBJECT_DLL_EXPORTS
#include "ImageObject.h"


ImageObject::ImageObject(int const width, int const height)
	: width_{ width }, height_{ height }
{

}


int ImageObject::Width() const 
{ 
	return width_; 
}


int ImageObject::Height() const
{ 
	return height_; 
}