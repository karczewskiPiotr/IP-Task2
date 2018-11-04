#include "HistogramProcesser.h"
#include <iostream>

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

	getImageHistogram((int)value);

	switch (option)
	{
		case histogram:
			createHistogram((int)value);
			break;
		case hpower:
			cout << "Function under developement" << endl;
			break;
		case cmean:
			cout << "Mean is: " << calculateMean() << endl;
			break;
		case cvariance:
			cout << "Variance is: " << calculateVariance() << endl;
			break;
		case cstdev:
			cout << "Function under developement" << endl;
			break;
		case cvarcoi:
			cout << "Function under developement" << endl;
			break;
		case casyco:
			cout << "Function under developement" << endl;
			break;
		case cflatco:
			cout << "Function under developement" << endl;
			break;
		case cvarcoii:
			cout << "Function under developement" << endl;
			break;
		case centropy:
			cout << "Function under developement" << endl;
			break;
		case sedgesharp:
			cout << "Function under developement" << endl;
			break;
		case orosenfeld:
			cout << "Function under developement" << endl;
			break;
		default:
			break;
	}
}
