#pragma once

#include "FileSystemObject.h"
#include "FileSystemObjectsContainer.h"
#include "ByteContainer.h"

#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <algorithm>
#include "Directory.h"

std::ostringstream treeView;

std::string getLevelString(int level);

void goDeepInDir(const std::shared_ptr<FileSystemObjectsContainer>& dir, int level);

void sortFiles(std::vector<std::shared_ptr<FileSystemObject>>& vector);

std::string getTreeView(const std::vector<std::shared_ptr<FileSystemObject>>& rootObjects)
{

	int level = 0;
	for(int i = 0;i < rootObjects.size();i++)
	{
		std::shared_ptr<FileSystemObjectsContainer> fileContainer = std::dynamic_pointer_cast<FileSystemObjectsContainer>(rootObjects[i]);
		treeView << getLevelString(level) <<rootObjects[i]->getName() << '\n';
		if(fileContainer != nullptr)
		{
			goDeepInDir(fileContainer,level+1);
		}
		
	}
	
	return treeView.str();
}

void goDeepInDir(const std::shared_ptr<FileSystemObjectsContainer>& dir, int level)
{
	std::vector<std::shared_ptr<FileSystemObject>> filesInDir(dir->begin(), dir->end());
	sortFiles(filesInDir);
	for(int i = 0;i < filesInDir.size();i++)
	{
		std::shared_ptr<FileSystemObjectsContainer> container = std::dynamic_pointer_cast<FileSystemObjectsContainer>(filesInDir[i]);
		if(container != nullptr)
		{
			std::shared_ptr<Directory> directory = std::dynamic_pointer_cast<Directory>(container);
			treeView << getLevelString(level) << directory->getName() << '\n';
			goDeepInDir(directory, level + 1);
		}else
		{
			treeView << getLevelString(level) << filesInDir[i]->getName() << '\n';
		}
	}
}


std::string getLevelString(int level)
{
	std::string identation = "";
	for(int i = 0;i < level;i++)
	{
		identation += "--->";
	}

	return identation;
}

void sortFiles(std::vector<std::shared_ptr<FileSystemObject>>& vector)
{
	std::sort(vector.begin(), vector.end(), [](const std::shared_ptr<FileSystemObject> a, const std::shared_ptr<FileSystemObject> b) {
		return a->getName() < b->getName();
	});
}
