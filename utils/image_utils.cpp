#include "image_utils.h"
#include <fstream>

namespace algo
{
	std::string getFileExt(const std::string& file_name)
	{
		size_t index = file_name.find_last_of('.');
		if (index < file_name.size())
			return file_name.substr(index + 1, file_name.size() - index - 1);
		else
			return "";
	}

	bool getImageWH(const std::string& image_path, int& width, int& height)
	{
		// PROBLEM !!
		std::ifstream ffin(image_path, std::ios::binary);
		if (!ffin)
			return false;

		std::string ext = getFileExt(image_path);
		char s1[2] = { 0 };
		char s2[2] = { 0 };
		if (ext == "gif")
		{
			ffin.seekg(6);
			ffin.read(s1, 2);
			ffin.read(s2, 2);
		}
		else if (ext == "jpg")
		{
			ffin.seekg(164);
			ffin.read(s1, 2);
			ffin.read(s2, 2);
		}
		else if (ext == "png")
		{
			ffin.seekg(17);
			ffin.read(s1, 2);
			ffin.seekg(2, std::ios::cur);
			ffin.read(s2, 2);
		}
		else if (ext == "bmp")
		{
			ffin.seekg(18);
			ffin.read(s1, 2);
			ffin.seekg(2, std::ios::cur);
			ffin.read(s2, 2);
		}
		else
		{
			ffin.close();
			return false;
		}

		width = (unsigned int)(s1[1]) << 8 | (unsigned int)(s1[0]);
		height = (unsigned int)(s2[1]) << 8 | (unsigned int)(s2[0]);
		ffin.close();
		return true;
	}
}
