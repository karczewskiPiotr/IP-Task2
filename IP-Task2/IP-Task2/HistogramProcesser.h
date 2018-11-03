#pragma once
#include "Processer.h"

class HistogramProcesser : public Processer
{
private:
	enum options
	{
		histogram = 18, hpower, cmean, cvariance, cstdev, cvarcoi, casyco, cflatco, cvarcoii, centropy, sedgesharp, orosenfeld
	};

public:
	HistogramProcesser();
	HistogramProcesser(std::string imageName, int option);
	~HistogramProcesser();

	void processImage();
};

