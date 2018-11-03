#pragma once
#include "Processer.h"

class HistogramProcesser : public Processer
{
private:
	enum options
	{
		histogram = 18, hpower, cmean, cvariance, cstdev, cvarcoi, casyco, cflatco, cvarcoii, centropy, sedgesharp, orosenfeld
	};
	cimg_library::CImg<unsigned char> histogramImage;
public:
	HistogramProcesser();
	HistogramProcesser(std::string imageName, int option, double value);
	~HistogramProcesser();

	void processImage();
	void createHistogram(int channel);
};

