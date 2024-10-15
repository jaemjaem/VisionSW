#pragma once


#ifdef BLURLIBRARY_EXPORTS
#define BLURLIBRARY_API __declspec(dllexport)
#else
#define BLURLIBRARY_API __declspec(dllimport)
#endif


extern "C" BLURLIBRARY_API void Imshow();
extern "C" BLURLIBRARY_API void test();