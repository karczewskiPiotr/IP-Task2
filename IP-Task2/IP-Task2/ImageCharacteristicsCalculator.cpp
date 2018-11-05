#include "HistogramProcesser.h"

double HistogramProcesser::calculateMean()
{
	int numberOfPixels = width * height;
	double numerator = 0;
	for (int i = 0; i < 256; i++)
	{
		numerator += i * histogramHeight[i];
	}

	return numerator / numberOfPixels;
}

double HistogramProcesser::calculateVariance()
{
	int numberOfPixels = width * height;
	double mean = calculateMean();
	double numerator = 0;
	for (int i = 0; i < 256; i++)
	{
		numerator += pow(i - mean, 2) * histogramHeight[i];
	}

	return numerator / numberOfPixels;
}