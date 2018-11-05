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

double HistogramProcesser::calculateStandardDeviation()
{
	return sqrt(calculateVariance());
}

double HistogramProcesser::calculateVariationCoefficientI()
{
	return calculateStandardDeviation() / calculateMean();
}

double HistogramProcesser::calculateAssymetryCoefficient()
{
	int numberOfPixels = width * height;
	double mean = calculateMean();
	double standardDeviation = calculateStandardDeviation();
	double numerator = 0;
	for (int i = 0; i < 256; i++)
	{
		numerator += pow(i - mean, 3) * histogramHeight[i];
	}

	return numerator / (numberOfPixels * pow(standardDeviation, 3));
}

double HistogramProcesser::calculateFlatteningCoefficient()
{
	int numberOfPixels = width * height;
	double mean = calculateMean();
	double standardDeviation = calculateStandardDeviation();
	double numerator = 0;
	for (int i = 0; i < 256; i++)
	{
		numerator += pow(i - mean, 4) * histogramHeight[i];
	}

	return (numerator - 3) / (numberOfPixels * pow(standardDeviation, 4));
}

double HistogramProcesser::calculateVariationCoefficientII()
{
	int numberOfPixels = width * height;
	double numerator = 0;
	for (int i = 0; i < 256; i++)
	{
		numerator += pow(histogramHeight[i], 2);
	}
	return numerator / pow(numberOfPixels, 2);
}

double HistogramProcesser::calculateInformationSourceEntropy()
{
	int numberOfPixels = width * height;
	double numerator = 0;
	for (int i = 0; i < 256; i++)
	{
		if (histogramHeight[i] > 0)
		{
			numerator += histogramHeight[i] * log2(histogramHeight[i] / numberOfPixels);
		}
	}
	return numerator / numberOfPixels;
}

