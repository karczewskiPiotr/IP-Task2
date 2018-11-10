#include "HistogramProcesser.h"
#include <vector>
#include <iostream>

void HistogramProcesser::edgeSharpening(int variant)
{
	unsigned short int channels = image.spectrum();
	cimg_library::CImg<unsigned char> imageCopy = image;
	struct Window
	{
		short int x0;
		short int x1;
		short int y0;
		short int y1;
	};

	Window window;
	unsigned short int x;
	unsigned short int y;
	unsigned short int channel;
	unsigned short int i;
	unsigned short int j;
	unsigned short int index;
	int value;

	for (x = 0; x < width; x++)
	{
		window.x0 = x - 1;
		window.x1 = x + 1;

		if (window.x0 < 0)
		{
			window.x0 = 0;
		}
		else if (window.x1 > width - 1)
		{
			window.x1 = width - 1;
		}

		for (y = 0; y < height; y++)
		{
			window.y0 = y - 1;
			window.y1 = y + 1;
			if (window.y0 < 0)
			{
				window.y0 = 0;
			}
			else if (window.y1 > height - 1)
			{
				window.y1 = height - 1;
			}

			for (channel = 0; channel < channels; channel++)
			{
				value = 0;
				index = 0;
				for (j = window.y0; j <= window.y1; j++)
				{
					for (i = window.x0; i <= window.x1; i++)
					{
						value += image(i, j, channel) * kernels[variant][index];
						index++;
					}
				}
				imageCopy(x, y, channel) = truncate(value);
			}
		}
	}
	image = imageCopy;
	image.save("sharpened.bmp");
}

void HistogramProcesser::optimizedSharpen()
{
	unsigned short int channels = image.spectrum();
	cimg_library::CImg<unsigned char> imageCopy = image;
	struct Window
	{
		short int x0;
		short int x1;
		short int y0;
		short int y1;
	};

	Window window;
	unsigned short int x;
	unsigned short int y;
	unsigned short int channel;
	unsigned short int i;
	unsigned short int j;
	unsigned short int index;
	int value;



	for (x = 0; x < width; x++)
	{
		window.x0 = x - 1;
		window.x1 = x + 1;

		if (window.x0 < 0)
		{
			window.x0 = 0;
		}
		else if (window.x1 > width - 1)
		{
			window.x1 = width - 1;
		}

		for (y = 0; y < height; y++)
		{
			window.y0 = y - 1;
			window.y1 = y + 1;
			if (window.y0 < 0)
			{
				window.y0 = 0;
			}
			else if (window.y1 > height - 1)
			{
				window.y1 = height - 1;
			}

			for (channel = 0; channel < channels; channel++)
			{
				value = 0;
				index = 0;
				for (j = window.y0; j <= window.y1; j++)
				{
					for (i = window.x0; i <= window.x1; i++)
					{
						if (kernels[0][index] == 0)
						{
							index++;
							continue;
						}
						else if (index == 4)
						{
							value += image(i, j, channel) * 5;
							index++;
							continue;
						}
						else
						{
							value += image(i, j, channel) * -1;
							index++;
						}
						
					}
				}
				imageCopy(x, y, channel) = truncate(value);
			}
		}
	}
	image = imageCopy;
	image.save("sharpened.bmp");
}
