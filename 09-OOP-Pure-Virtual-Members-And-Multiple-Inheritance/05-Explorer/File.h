#pragma once

#include "FileSystemObject.h"
#include "ByteContainer.h"

#include <string>

class File : public ByteContainer, public FileSystemObject
{
private:
	std::string filename;
	std::string bytes;
public:
	File(const std::string filename, const std::string bytes) : FileSystemObject(filename),bytes(bytes){}

	size_t getSize() const override
	{
		return this->bytes.size();
	}

	std::string getBytes() const override
	{
		return this->bytes;
	}


};