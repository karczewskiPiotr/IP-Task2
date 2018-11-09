#pragma once
#include "Processer.h"
#include <vector>

class HistogramProcesser : public Processer
{
private:
	enum Options
	{
		histogram = 18, hpower, cmean, cvariance, cstdev, cvarcoi, casyco, cflatco, cvarcoii, centropy, sedgesharp, orosenfeld
	};

	int histogramHeight[256] = {};
	cimg_library::CImg<unsigned char> histogramImage;
	int kernels[3][9] = { { 0,-1,0, -1,5,-1, 0,-1,0 },  { -1,-1,-1, -1,9,-1, -1,-1,-1 },  { 1,-2,1, -2,5,-2, 1,-2,1 } };

	void getImageHistogram(int channel);
	void createHistogram(int channel);
	double calculateMean();
	double calculateVariance();
	double calculateStandardDeviation();
	double calculateVariationCoefficientI();
	double calculateAssymetryCoefficient();
	double calculateFlatteningCoefficient();
	double calculateVariationCoefficientII();
	double calculateInformationSourceEntropy();
	void edgeSharpening(int variant);
	void optimizedSharpen();
	void edgeDetection(int P);
public:
	HistogramProcesser();
	HistogramProcesser(std::string imageName, int option, double value);
	~HistogramProcesser();

	void processImage();
};

