//implementation of basic linked-list hash

//Copyright (c) Philip Sung of Korea

#ifndef _BASIC_HASH_
#define _BASIC_HASH_

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class basicIntegerHash {
private:
	std::vector<std::list<int>> data;

public:
	basicIntegerHash(size_t n) {
		data.resize(n);
	}

	bool insert(int n) {
		bool result = false;
		int size = data.size();
		data.at(n % size).push_back(n);
		std::cout << n << " has been added to hash map.\n";
		result = true;

		return result;
	}

	bool erase(int n) {
		bool result = false;
		int size = data.size();
		auto& list = data.at(n % size);
		auto iter = std::find(list.begin(), list.end(), n);
		
		if (iter != list.end()) {
			list.erase(iter);
			std::cout << n << " has been removed from hash map.\n";
			result = true;
		}
		else if (iter == list.end()) {
			std::cout << n << " doesn't exist in hash map.\n";
		}

		return result;
	}
	
	int find(int n) {
		int result = -1;
		int size = data.size();
		auto& list = data.at(n % size);
		auto iter = std::find(list.begin(), list.end(), n);

		if (iter != list.end()) {
			result = *iter;
			std::cout << n << " is in hashmap.\n";
		}
		else {
			std::cout << n << " is not in hashmap.\n";
		}

		return result;
	}

	float loadFactor(void) {
		float table = data.size();
		float key = 0;
		float result = 0;

		for (std::list<int> l : data) {
			if (l.size() > 0) {
				key++;
			}
		}

		result = key / table;

		return result;
	}
};

#endif