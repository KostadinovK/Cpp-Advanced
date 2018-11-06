#pragma once


#include "File.h"
#include "FileSystemObject.h"
#include "FileSystemObjectsContainer.h"
#include "Directory.h"
#include "Shortcuts.h"

#include <string>
#include <vector>
#include <stack>

class Explorer
{
private:
	std::shared_ptr<FileSystemObjectsContainer> currLocation;
	std::vector<std::shared_ptr<FileSystemObject>>& objects;
	std::stack<std::shared_ptr<FileSystemObject>> clipboard;


	std::shared_ptr<FileSystemObject> getFile(std::string path)
	{
		std::shared_ptr<FileSystemObject> result;
		if(currLocation != nullptr)
		{
			result = *(std::find_if(currLocation->begin(), currLocation->end(), [&](std::shared_ptr<FileSystemObject> file)
			{
				return file->getName() == path;
			}));
		}else
		{
			result = *(std::find_if(objects.begin(), objects.end(), [&](std::shared_ptr<FileSystemObject> file)
			{
				 return file->getName() == path;
			}));
			
		}

		return result;
	}


	void moveFileAtCurrentLocation(const std::shared_ptr<FileSystemObject>& file)
	{
		std::shared_ptr<FileSystemObjectsContainer> fileParent = std::dynamic_pointer_cast<FileSystemObjectsContainer>(file->getParent().lock());
		std::weak_ptr<FileSystemObject> newParent = std::dynamic_pointer_cast<FileSystemObject>(currLocation);
		file->setParent(newParent);
		if(currLocation == nullptr)
		{
			objects.push_back(file);
		}else
		{
			currLocation->add(file);
		}

		if (fileParent != nullptr)
		{
			fileParent->remove(file);
		}
		else
		{
			objects.erase(std::find(objects.begin(), objects.end(), file));
		}
	}

public:
	Explorer(std::vector<std::shared_ptr<FileSystemObject>>& rootObjects) : objects(rootObjects), currLocation(nullptr)
	{
		std::shared_ptr<Shortcuts> shortcuts = std::make_shared<Shortcuts>();
		objects.push_back(shortcuts);
	}

	void createFile(const std::string& filename, const std::string& content)
	{
		std::shared_ptr<File> newFile = std::make_shared<File>(File(filename, content));
		if(currLocation == nullptr)
		{
			objects.push_back(newFile);
		}else
		{
			std::weak_ptr<FileSystemObject> parent = std::dynamic_pointer_cast<FileSystemObject>(currLocation);
			newFile->setParent(parent);
			currLocation->add(newFile);
		}
	}

	void createDirectory(const std::string& name)
	{
		std::shared_ptr<Directory> newDir = std::make_shared<Directory>(Directory(name));
		if (currLocation == nullptr)
		{
			objects.push_back(newDir);
		}
		else
		{
			std::weak_ptr<FileSystemObject> parent = std::dynamic_pointer_cast<FileSystemObject>(currLocation);
			newDir->setParent(parent);
			currLocation->add(newDir);
		}
	}

	void cut(const std::string& name)
	{
		std::shared_ptr<FileSystemObject> file = this->getFile(name);
		this->clipboard.push(file);
	}


	void paste()
	{
		if(!this->clipboard.empty())
		{
			std::shared_ptr<FileSystemObject> file = clipboard.top();
			moveFileAtCurrentLocation(file);
			clipboard.pop();
		}
	}

	void navigate(std::string path)
	{
		if(currLocation == nullptr)
		{
			if(path == "..")
			{
				currLocation = nullptr;
			}else
			{
				std::shared_ptr<FileSystemObject> currLocationAsObject = std::dynamic_pointer_cast<FileSystemObject>(currLocation);
				currLocationAsObject = getFile(path);
				currLocationAsObject->setParent(getFile(path)->getParent());

				currLocation = std::dynamic_pointer_cast<FileSystemObjectsContainer>(currLocationAsObject);
			}
		}else
		{
			if(path == "..")
			{
				std::shared_ptr<FileSystemObject> currLocationAsObject = std::dynamic_pointer_cast<FileSystemObject>(currLocation);
				if(currLocationAsObject->getParent().lock() != nullptr)
				{
					currLocationAsObject = currLocationAsObject->getParent().lock();
					currLocationAsObject->setParent(currLocationAsObject->getParent().lock());
				}else
				{
					
					currLocationAsObject->setParent(currLocationAsObject->getParent().lock());
					currLocationAsObject = nullptr;
				}
				

				currLocation = std::dynamic_pointer_cast<FileSystemObjectsContainer>(currLocationAsObject);
			}else
			{
				std::shared_ptr<FileSystemObject> currLocationAsObject = std::dynamic_pointer_cast<FileSystemObject>(currLocation);
				currLocationAsObject = getFile(path);
				currLocationAsObject->setParent(getFile(path)->getParent());

				currLocation = std::dynamic_pointer_cast<FileSystemObjectsContainer>(currLocationAsObject);
			}
		}
	}

	void createShortcut(const std::string& name)
	{
		std::shared_ptr<FileSystemObject> file = getFile(name);
		std::shared_ptr<FileSystemObject> shortcuts = *(std::find_if(objects.begin(), objects.end(), [&](std::shared_ptr<FileSystemObject> file)
		{
			return file->getName() == "[shortcuts]";
		}));

		std::shared_ptr<FileSystemObjectsContainer> scon = std::dynamic_pointer_cast<FileSystemObjectsContainer>(shortcuts);
		scon->add(file);
	}
};