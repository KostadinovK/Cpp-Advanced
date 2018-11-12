#pragma once

#include <memory>
#include <string>
#include <istream>

#include "CommandInterface.h"
#include "CutPasteCommandInterface.h"

std::shared_ptr<CommandInterface> buildCommandInterface(std::string& text)
{
	std::shared_ptr<CommandInterface> ciPtr = std::make_shared<CutPasteCommandInterface>(text);
	ciPtr->init();
	return ciPtr;
}