#ifndef IMAGE_UTILS_H
#define IMAGE_UTILS_H

#include <string>

namespace algo
{
	std::string getFileExt(const std::string& file_name);
	bool getImageWH(const std::string& image_path, int& width, int& height);
}

#endif
