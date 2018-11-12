#pragma once

#include <memory>
#include <string>
#include <istream>

#include "CommandInterface.h"
#include "TextTransform.h"


std::string clipboard = "";
class CutPasteCommandInterface : public CommandInterface
{
private:
	class ToUpperTransform : public TextTransform {
	public:
		virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
			for (int i = startIndex; i < endIndex; i++) {
				text[i] = toupper(text[i]);
			}
		}
	};


	class CutTransform : public TextTransform
	{
	public:
		virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
			clipboard = text.substr(startIndex, endIndex - startIndex);
			if (startIndex != endIndex) {
				text = text.erase(startIndex, endIndex - startIndex);
			}
			else {
				clipboard = "";
			}
		}
	};

	class PasteTransform : public TextTransform
	{
	public:
		void invokeOn(std::string& text, int startIndex, int endIndex) override {
			if (startIndex != endIndex) {
				text = text.replace(startIndex, endIndex - startIndex, clipboard);
			}
			else {
				text = text.replace(startIndex, 1, clipboard + text[startIndex]);
			}
		}
	};
public:
	CutPasteCommandInterface(std::string& text) : CommandInterface(text) {}

	std::vector<Command> initCommands() override {
		std::vector<Command> commands;
		commands.push_back(Command("uppercase", std::make_shared<ToUpperTransform>()));
		commands.push_back(Command("cut", std::make_shared<CutTransform>()));
		commands.push_back(Command("paste", std::make_shared<PasteTransform>()));
		return commands;
	}

};
