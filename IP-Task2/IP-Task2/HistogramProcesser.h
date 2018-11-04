#pragma once
#include "Processer.h"

class HistogramProcesser : public Processer
{
private:
	enum Options
	{
		histogram = 18, hpower, cmean, cvariance, cstdev, cvarcoi, casyco, cflatco, cvarcoii, centropy, sedgesharp, orosenfeld
	};

	int histogramHeight[256] = {};
	cimg_library::CImg<unsigned char> histogramImage;

	void getImageHistogram(int channel);
	void createHistogram(int channel);
	double calculateMean();
	double calculateVariance();
public:
	HistogramProcesser();
	HistogramProcesser(std::string imageName, int option, double value);
	~HistogramProcesser();

	void processImage();
};

