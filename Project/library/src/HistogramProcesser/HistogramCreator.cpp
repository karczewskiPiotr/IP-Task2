#include "HistogramProcesser.h"

void HistogramProcesser::getImageHistogram(int channel)
{
	for (unsigned int x = 0; x < width; x++)
	{
		for (unsigned int y = 0; y < height; y++)
		{
			histogramHeight[image(x, y, channel)]++;
		}
	}
}

void HistogramProcesser::createHistogram(int channel)
{
	int histogramMaxHeight = *std::max_element(histogramHeight, histogramHeight + 256);
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

	histogramImage.display("Histogram preview", false);
	histogramImage.save("histogram.bmp");
}