#pragma once

#include "FileSystemObject.h"
#include "FileSystemObjectsContainer.h"
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

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

	void setParent(const std::weak_ptr<FileSystemObject>& parent) override
	{
		FileSystemObject::setParent(parent);
	}

	std::weak_ptr<FileSystemObject> getParent() const override
	{
		return FileSystemObject::getParent();
	}

	std::vector<std::shared_ptr<FileSystemObject>>::const_iterator begin() const override
	{
		return this->files.begin();
	}

	std::vector<std::shared_ptr<FileSystemObject>>::const_iterator end() const override
	{
		return this->files.end();
	}

	void remove(std::shared_ptr<FileSystemObject> obj) override
	{
		this->files.erase(std::find(files.begin(), files.end(), obj));
	}
};