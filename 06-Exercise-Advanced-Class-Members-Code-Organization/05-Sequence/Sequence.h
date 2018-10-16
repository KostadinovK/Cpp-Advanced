#pragma once

#include <vector>

template<typename T> class SequenceIter;

template<typename T, typename Generator>
class Sequence {
private:
	std::vector<T> elements;
	Generator generator;
public:
	void generateNext(const int& numsToGenerate) {
		for (int i = 0; i < numsToGenerate;i++) {
			T next = generator();
			elements.push_back(next);
		}
	}

	friend class SequenceIter<T>;
	
	SequenceIter<T> begin() {
		SequenceIter<T> iter(elements);
		return iter.begin();
	}

	SequenceIter<T> end() {
		SequenceIter<T> iter(elements);
		return iter.end();
	}
};



template <typename T>
class SequenceIter {
private:
	int index;
	std::vector<T>& elements;
public:
	SequenceIter(std::vector<T>& elements) : elements(elements) {}
	SequenceIter(std::vector<T>& elements, int& index) : elements(elements), index(index) {}

	bool operator== (const SequenceIter<T>& other) {
		if (*(this->elements) == *(other.elements) && this->index == other.index) {
			return true;
		}
		return false;
	}
	
	bool operator!= (const SequenceIter<T>& other) {
		if (*(this->elements) != *(other.elements) || this->index != other.index) {
			return false;
		}

		return true;
			
	}

	T& operator*() { return elements[index]; }

	SequenceIter<T>& operator++() { ++index; return *this; }

	SequenceIter<T> begin() {
		return SequenceIter<T>(*this->elements,0);
	}

	SequenceIter<T> end() {
		return SequenceIter<T>(*this->elements,this->elements.size());
	}
};


