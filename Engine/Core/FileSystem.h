#pragma once
#include <SDL.h>
#include <string>

namespace nc
{
	bool ReadFileToString(const std::string& filename, std::string& filestring);
	void SetFilePath(const std::string& pathname);
	std::string GetFilePath();
}

