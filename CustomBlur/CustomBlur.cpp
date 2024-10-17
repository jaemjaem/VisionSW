#include "pch.h"

#include "CustomBlur.h"

#include <execution> // 병렬 처리를 위한 헤더


namespace customfunction
{
	bool ImageBlur(const ImageObject* src, ImageObject* dst, const int kernelSize)
	{
		if (src == nullptr)
		{
			return false;
		}

		if (dst == nullptr)
		{
			return false;
		}

		auto img_buf = src->CloneVec();
		
        int radius = kernelSize / 2;

        std::vector<uchar> output;
        output.resize(img_buf.size());

        int height = src->Height();
        int width = src->Width();

        // 4중 for 문 너무 느림..
        /*for (int y = 0; y < height; ++y) 
        {
            for (int x = 0; x < width; ++x) 
            {
                int sum = 0;
                int count = 0;

                for (int ky = -radius; ky <= radius; ++ky) 
                {
                    for (int kx = -radius; kx <= radius; ++kx) 
                    {
                        int ny = y + ky;
                        int nx = x + kx;

                        if (ny >= 0 && ny < height && nx >= 0 && nx < width) 
                        {
                            sum += img_buf[ny * width + nx];
                            count++;
                        }
                    }
                }

                std::cout << y * width + x << std::endl;
                output[y * width + x] = static_cast<uchar>(sum / count);
            }
        }*/

        std::for_each(std::execution::par, output.begin(), output.end(), [&](uchar& output_pixel)
        {
            int index = &output_pixel - &output[0];
            int x = index % width;
            int y = index / width;

            int sum = 0;
            int count = 0;

            for (int ky = -radius; ky <= radius; ++ky) 
            {
                for (int kx = -radius; kx <= radius; ++kx) 
                {
                    int ny = y + ky;
                    int nx = x + kx;
                    
                    if (ny >= 0 && ny < height && nx >= 0 && nx < width) 
                    {
                        sum += img_buf[ny * width + nx];
                        count++;
                    }
                }
            }
            output[index] = (count > 0) ? static_cast<uchar>(sum / count) : 0;

           });


        dst->UpdateVec(width, height, std::move(output));

		return true;
	}
}