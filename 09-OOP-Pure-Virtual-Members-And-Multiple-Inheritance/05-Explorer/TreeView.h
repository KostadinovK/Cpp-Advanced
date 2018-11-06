#pragma once

#include "FileSystemObject.h"
#include "FileSystemObjectsContainer.h"
#include "ByteContainer.h"
#include "Shortcuts.h"

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
	std::shared_ptr<FileSystemObjectsContainer> shortcutsContainer = std::dynamic_pointer_cast<FileSystemObjectsContainer>(rootObjects[0]);
	std::vector<std::shared_ptr<FileSystemObject>> shortcuts(shortcutsContainer->begin(),shortcutsContainer->end());
	if(shortcuts.size() == 0)
	{
		for (int i = 1; i < rootObjects.size(); i++)
		{

			treeView << getLevelString(level) << rootObjects[i]->getName() << '\n';

			std::shared_ptr<FileSystemObjectsContainer> container = std::dynamic_pointer_cast<FileSystemObjectsContainer>(rootObjects[i]);
			if (container != nullptr)
			{
				goDeepInDir(container, level + 1);
			}
		}
	}else
	{
		for (int i = 0; i < rootObjects.size(); i++)
		{

			treeView << getLevelString(level) << rootObjects[i]->getName() << '\n';

			std::shared_ptr<FileSystemObjectsContainer> container = std::dynamic_pointer_cast<FileSystemObjectsContainer>(rootObjects[i]);
			if (container != nullptr)
			{
				goDeepInDir(container, level + 1);
			}
		}
	}
	

	return treeView.str();
}

void goDeepInDir(const std::shared_ptr<FileSystemObjectsContainer>& container, int level)
{
	std::vector<std::shared_ptr<FileSystemObject>> filesInContainer(container->begin(),container->end());
	sortFiles(filesInContainer);
	for(int i = 0;i < filesInContainer.size();i++)
	{
		std::shared_ptr<FileSystemObjectsContainer> container = std::dynamic_pointer_cast<FileSystemObjectsContainer>(filesInContainer[i]);
		if (container != nullptr)
		{
			std::shared_ptr<FileSystemObject> directory = std::dynamic_pointer_cast<FileSystemObject>(container);
			treeView << getLevelString(level) << directory->getName() << '\n';
			goDeepInDir(container, level + 1);
		}
		else
		{
			treeView << getLevelString(level) << filesInContainer[i]->getName() << '\n';
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
	std::sort(vector.begin(), vector.end(), [](std::shared_ptr<FileSystemObject>& a, std::shared_ptr<FileSystemObject>& b)
	{
		return a->getName() < b->getName();
	});
}
