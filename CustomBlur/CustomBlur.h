#pragma once

#include "ImageObject.h"

#ifdef CUSTOMBLURLIBRARY_EXPORTS
#define CUSTOMBLURLIBRARY_API __declspec(dllexport)
#else
#define CUSTOMBLURLIBRARY_API __declspec(dllimport)
#endif

namespace customfunction
{
	CUSTOMBLURLIBRARY_API bool ImageBlur(const ImageObject* src, ImageObject* dst, const int kernelSize);
}

