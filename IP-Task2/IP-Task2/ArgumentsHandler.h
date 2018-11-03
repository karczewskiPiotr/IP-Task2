#pragma once
#include <string>

class ArgumentsHandler
{
private:
	int argc;
	char** argv;

	std::string option;
	std::string value;
	std::string imageName;
	std::string noisyImageName;
	std::string denoisedImageName;

	std::string options[29]{
		//Task 1 options (17 options) <0, 16>
		"--help", "--brightness", "--contrast", "--negative", "--hflip", "--vflip", "--dflip", "--shrink", "--enlarge", "--min", "--max", "--median", "--mse", "--pmse", "--snr", "--psnr", "--md",
		//Task 2 options (9 options) <17, 28>
		"--histogram", "--hpower", "--cmean", "--cvariance", "--cstdev", "--cvarcoi", "--casyco", "--cflatco", "--cvarcoii", "--centropy", "--sedgesharp", "--orosenfeld"
	};

	std::string optionsRequiringValues[8]{
		"--brightness", "--contrast", "--shrink", "--enlarge", "--min", "--max", "--median", "--histogram"
	};

	bool optionIsValid(std::string option) const;
	bool optionRequiresValue(std::string option) const;
	bool valueIsValid(std::string value) const;
	bool isNameOfFile(std::string name) const;

public:
	ArgumentsHandler(int argc, char* argv[]);
	~ArgumentsHandler();

	enum Processers
	{
		ImageProcesser = 0,
		HistogramProcesser
	};

	struct Arguments
	{
		std::string imageName;
		std::string noisyImageName;
		std::string denoisedImageName;
		int option;
		double value;
		Processers processer;
	};

	bool argumentsAreValid = false;

	int convertToInt(std::string option) const;

	void helpMessage() const;
	void validateArguments();
	Processers get_currentProcesser() const;
	Arguments get_arguments() const;
};