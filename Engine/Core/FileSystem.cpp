#include "FileSystem.h"

#include <filesystem>
#include <fstream>
#include <sstream>

namespace nc
{
	void SetFilePath(const std::string& pathname)
	{
		std::filesystem::current_path(pathname);

	}

	bool ReadFileToString(const std::string& filename, std::string& filestring)
	{
		std::ifstream fileStream(filename, std::ios::in);
		if (!fileStream)
		{
			//need to fix
			SDL_Log("Error: Failed to open file: %s", filename.c_str());
			return false;
		}
		//https://newbedev.com/how-to-read-file-content-into-istringstream
		std::stringstream stream;
//		<use rdbuf() on file stream to read file into string stream>
		stream << fileStream.rdbuf();
		//<use stream str() method to return stream string>
		filestring = stream.str();
		fileStream.close();
		return true;
	}

	std::string GetFilePath()
	{
		return std::filesystem::current_path().string();
	}
}