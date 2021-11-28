#include <fstream>
#include <string>

#include "renderer.h"

using namespace renderer;

std::string renderer::readShader(const char* filepath) 
{
	std::ifstream fileReader;
	fileReader.open(filepath);

	std::string output;
	std::string line;
	while (std::getline(fileReader, line)) 
	{
		output.append(line + "\n");
	}

	fileReader.close();

	return output;
}