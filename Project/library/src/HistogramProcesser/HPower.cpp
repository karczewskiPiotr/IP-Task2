#include "HistogramProcesser.h"

void HistogramProcesser::performHPower(int minBrightness, int maxBrightness)
{
	int numberOfPixels = width * height;
	unsigned short int channels = image.spectrum();
	double base = 0;
	double exponent = (double)1 / 3;
	for (unsigned int x = 0; x < width; x++)
	{
		for (unsigned int y = 0; y < height; y++)
		{
			for (int channel = 0; channel < channels; channel++)
			{
				double sum = 0;
				for (unsigned char i = 0; i < image(x, y, channel); i++)
				{
					sum += histogramHeight[i];
				}
				base = pow(minBrightness, exponent) + (pow(maxBrightness, exponent) - pow(minBrightness, exponent))*sum / numberOfPixels;
				image(x, y, channel) = truncate((int)pow(base, 3));
			}
		}
	}
}