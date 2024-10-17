#pragma once

#include "ImageObject.h"

#ifdef BLURLIBRARY_EXPORTS
#define BLURLIBRARY_API __declspec(dllexport)
#else
#define BLURLIBRARY_API __declspec(dllimport)
#endif


extern "C" BLURLIBRARY_API bool ImageBlur(const ImageObject* src, ImageObject* dst, const int kernelSize);
