#include "HistogramProcesser.h"
#include <iostream>
using namespace std;

void HistogramProcesser::createHistogram(int channel)
{
	int histogramHeight[256] = {};
	for (unsigned int x = 0; x < width; x++)
	{
		for (unsigned int y = 0; y < height; y++)
		{
			histogramHeight[image(x, y, channel)]++;
		}
	}

	int histogramMaxHeight = *max_element(histogramHeight, histogramHeight + 256);
	cimg_library::CImg<unsigned char>* img = new cimg_library::CImg<unsigned char>(256, histogramMaxHeight, 1, 3, 0);
	histogramImage = *img;
	delete img;

	for (unsigned int x = 0; x < 256; x++)
	{
		for (unsigned int y = histogramMaxHeight - 1; y > histogramMaxHeight - histogramHeight[x]; y--)
		{
			histogramImage(x, y, channel) = 255;
		}
	}
}