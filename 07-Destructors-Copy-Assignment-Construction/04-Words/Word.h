#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

class Word {
public:
	static int amount;
	std::string word;
	int count;
	Word() {}
	Word(std::string word) : word(word), count(0) {
		amount++;
	}

	Word(const Word& other) {
		this->word = other.word;
		this->count = other.count + 1;
		amount++;
		std::cout << "Copy constructor called for word: " << this->word << std::endl;
		std::cout << "Amount: " << amount << std::endl;
	}

	/*Word& operator=(const Word& other) {
		this->amount = other.amount + 1;
		this->word = other.word;
		std::cout << "Copy assignment operator called for word: " << this->word << std::endl;
		std::cout << "Amount: " << this->amount << std::endl;
		return *this;

	}*/

	std::string getWord() const {
		return this->word;
	}

	int getCount() const {
		return amount;
	}



	friend std::ostream& operator<<(std::ostream& out, const Word& w);

	~Word() {
		this->count--;
		amount--;
	}
};

int Word::amount = 0;

bool operator<(const Word& word1, const Word& word2) {
	
	return word1.getCount() < word2.getCount();
}