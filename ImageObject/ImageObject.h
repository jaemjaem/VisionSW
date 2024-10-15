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
	ImageObject(int const width, int const height);

	int Width() const;
	int Height() const;

private:
	std::vector<int> image_buf_;

	int width_;
	int height_;
};