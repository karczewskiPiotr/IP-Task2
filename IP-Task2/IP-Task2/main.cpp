#include <iostream>
#include "ArgumentsHandler.h"
#include "ImageProcesser.h"
#include "HistogramProcesser.h"

using namespace std;

int main(int argc, char* argv[])
{
	ArgumentsHandler ArgumentsHandler(argc, argv);

	ArgumentsHandler.validateArguments();

	if (!ArgumentsHandler.argumentsAreValid) return 0;

	ArgumentsHandler::Arguments arguments = ArgumentsHandler.get_arguments();
	switch (arguments.processer)
	{

		case ArgumentsHandler::Processers::ImageProcesser:
		{
			ImageProcesser ImageProcesser(arguments.imageName, arguments.option, arguments.value, arguments.noisyImageName, arguments.denoisedImageName);
			ImageProcesser.processImage();
			break;
		}

		case ArgumentsHandler::Processers::HistogramProcesser:
		{
			HistogramProcesser HistogramProcesser(arguments.imageName, arguments.option, arguments.value);
			HistogramProcesser.processImage();
			break;
		}
	}

	return 0;
}

