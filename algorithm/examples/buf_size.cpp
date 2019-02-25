#include "buf_size.h"

long copyFile(const std::string& infilename, const std::string& outfilename, size_t insize, size_t outsize)
{
	int c;
	clock_t starttime;
	clock_t donetime;
	FILE* infile;
	FILE* outfile;

	if ((infile = fopen(infilename.c_str(), "rb")) == NULL)
	{
		printf("Cannot open %s\n", infilename.c_str());
		exit(1);
	}

	if (setvbuf(infile, NULL, _IOFBF, insize))
	{
		printf("Could not set infile buffer to %d bytes.\n", int(insize));
		exit(1);
	}

	if ((outfile = fopen(outfilename.c_str(), "wb")) == NULL)
	{
		printf("Cannot open %s\n", outfilename.c_str());
		exit(1);
	}

	if (setvbuf(outfile, NULL, _IOFBF, outsize))
	{
		printf("Could not set outfile buffer to %d bytes.\n", int(outsize));
		exit(1);
	}

	// do copy
	starttime = clock();
	while ((c = fgetc(infile)) != EOF)
		fputc(c, outfile);
	donetime = clock();
	fclose(infile);
	fclose(outfile);
	return donetime - starttime;
}

void testCopyFile()
{
	std::string infile("I:\\projects\\Algorithm\\data\\haarcascade_frontalface_alt.xml");
	std::string outfile("I:\\projects\\Algorithm\\data\\K3.txt");

	size_t bufsizes[] = { 16, 128, 512, 1024, 2048 };
	int nbuf = sizeof(bufsizes) / sizeof(bufsizes[0]);
	
	for (int k = 0; k < nbuf; ++k)
	{
		printf("testing buffer size = %d\n", int(bufsizes[k]));
		long total, average, lo, hi, elapsed;
		total = hi = 0;
		lo = LONG_MAX;

		size_t bsize = bufsizes[k];
		for (int i = 0; i < 5; ++i)
		{
			elapsed = copyFile(infile, outfile, bsize, bsize);
			if (elapsed > hi)
				hi = elapsed;
			if (elapsed < lo)
				lo = elapsed;
			total += elapsed;
		}
		average = total / 5;
		// output info
		// printf("buffer size = %d\n", bsize);
		printf("average time = %ld\n", average);
	}
}

