#include "HistogramProcesser.h"
#include <iostream>
#include <chrono>

using namespace std;

HistogramProcesser::HistogramProcesser()
{
}

HistogramProcesser::HistogramProcesser(std::string imageName, int option, double value)
	:Processer(imageName, option, value)
{
}


HistogramProcesser::~HistogramProcesser()
{
}

void HistogramProcesser::processImage()
{
	cimg_library::CImg<unsigned char> initialImage;
	try
	{
		initialImage.load(imageName.c_str());
	}
	catch (cimg_library::CImgException)
	{
		cout << endl << "Image could not be loaded. Please check whether the filename is correct." << endl;
		return;
	}

	if (!initialImage) return;

	image = initialImage;
	height = image.height();
	width = image.width();

	if (option < 27) getImageHistogram((int)value);

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

	switch (option)
	{
		case histogram:
			createHistogram((int)value);
			break;
		case hpower:
			performHPower(0, 255);
			break;
		case cmean:
			cout << "Mean is: " << calculateMean() << endl;
			break;
		case cvariance:
			cout << "Variance is: " << calculateVariance() << endl;
			break;
		case cstdev:
			cout << "Standard deviation is: " << calculateStandardDeviation() << endl;
			break;
		case cvarcoi:
			cout << "Variation coefficient I is: " << calculateVariationCoefficientI() << endl;
			break;
		case casyco:
			cout << "Assymetry coefficient is: " << calculateAssymetryCoefficient() << endl;
			break;
		case cflatco:
			cout << "Flattening coefficient is: " << calculateFlatteningCoefficient() << endl;
			break;
		case cvarcoii:
			cout << "Variation coefficient I is: " << calculateVariationCoefficientII() << endl;
			break;
		case centropy:
			cout << "Information source entropy is: " << calculateInformationSourceEntropy() << endl;
			break;
		case sedgesharp:
			if ((int)value == 3) optimizedSharpen();
			else edgeSharpening((int)value);
			break;
		case orosenfeld:
			edgeDetection((int)value);
			break;
		default:
			break;
	}

	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count() / (double)1000000;
	cout << "Algorithm duration: " << duration << " seconds";

	image.save("processedImage.bmp");
	image.display("Processed image", false);
}
