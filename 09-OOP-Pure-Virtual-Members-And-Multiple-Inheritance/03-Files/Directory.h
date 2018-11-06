#pragma once

#include "FileSystemObject.h"
#include "FileSystemObjectsContainer.h"
#include <string>
#include <vector>

class Directory : public FileSystemObject, public FileSystemObjectsContainer
{
private:
	std::vector<std::shared_ptr<FileSystemObject>> files;
public:
	
	Directory(std::string name) : FileSystemObject(name){}

	void add(const std::shared_ptr<FileSystemObject>& obj) override
	{
		files.push_back(obj);
	}

	size_t getSize() const override
	{
		size_t totalSize = 0;
		for(size_t i = 0;i < this->files.size();i++)
		{
			totalSize += this->files[i]->getSize();
		}

		return totalSize;
	}
};