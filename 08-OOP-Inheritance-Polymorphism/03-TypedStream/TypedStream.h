#pragma once

#include <sstream>
#include <string>
#include <vector>
#include "Vector2D.h"
template<typename T>
class TypedStream {
public:
	std::istringstream stream;

	TypedStream(const std::string& input){
		this->stream.str(input);
	}
	
	virtual TypedStream<T>& operator>>(T& v) {
		return *this;
	}
	
	std::vector<T> readToEnd() {
		std::vector<T> res;
		T toRead;
		while (this->operator>>(toRead).stream.good()) {
			res.push_back(toRead);
		}
		
		return res;
	}
};
