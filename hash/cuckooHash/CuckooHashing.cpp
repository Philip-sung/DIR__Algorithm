//implementation of basic linked-list hash

//Copyright (c) Philip Sung of Korea 2023.05.04

#ifndef _CUCKOO_INT_HASH_
#define _CUCKOO_INT_HASH_

#include <vector>
#include <climits>
#include <iostream>

#define INT_MIN 0

class CuckooIntegerHash {
private:
	int size = 0;
	std::vector<int> bucketA;
	std::vector<int> bucketB;

	int hashA(int key) {
		int result = key % size;
		
		return result;
	}

	int hashB(int key) {
		int keyPow = key * 8;
		int result = (keyPow - (keyPow / 10)) % size;

		return result;
	}

	bool insertImpl(int n, int count, int table) {
		bool result = false;
		int keyA = hashA(n);
		int keyB = hashB(n);

		if (count > n) {
			std::cout << "Circulation referencing occurred.\n";
			return false;
		}

		if (table == 1) {
			if (bucketA.at(keyA) == INT_MIN) {
				bucketA.at(keyA) = n;
				std::cout << n << " inserted into bucketA\n";
				result = true;
			}
			else if (bucketA.at(keyA) != INT_MIN) {
				int old = bucketA.at(keyA);
				bucketA.at(keyA) = n;
				result = insertImpl(old, count + 1, 2);
			}
		}

		else if (table == 2) {
			if (bucketB.at(keyB) == INT_MIN) {
				bucketB.at(keyB) = n;
				std::cout << n << " inserted into bucketB\n";
				result = true;
			}
			else if (bucketB.at(keyB) != INT_MIN) {
				int old = bucketA.at(keyB);
				bucketA.at(keyB) = n;
				result = insertImpl(old, count + 1, 1);
			}
		}

		return result;
	}

public:
	CuckooIntegerHash(int sizeval) {
		bucketA.resize(sizeval, INT_MIN);
		bucketB.resize(sizeval, INT_MIN);
		size = sizeval;
	}

	int find(int n) {
		int result = 0;
		int keyA = hashA(n);
		int keyB = hashB(n);

		if (bucketA.at(keyA) != INT_MIN) {
			std::cout << n << " exists in bucketA.\n";
			result = 1;
		}
		else if (bucketB.at(keyB) != INT_MIN) {
			std::cout << n << " exists in bucketB.\n";
			result = 2;
		}

		return result;
	}

	bool erase(int n) {
		bool result = false;
		int keyA = hashA(n);
		int keyB = hashB(n);

		if (bucketA.at(keyA) == n) {
			bucketA.at(keyA) = INT_MIN;
			std::cout << n << " has been erased from bucketA\n";
			result = true;
		}
		else if (bucketB.at(keyB) == n) {
			bucketB.at(keyB) = INT_MIN;
			std::cout << n << " has been erased from bucketB\n";
			result = true;
		}
		else {
			std::cout << n << " doesn't exists in both bucket.\n";
		}

		return result;
	}

	bool insert(int n) {
		bool result = false;

		if (n == INT_MIN) {
			std::cout << "ERROR!INT_MIN cannot be accepted on this function.\n";
		}
		result = insertImpl(n, 0, 1);

		return result;
	}


	float loadFactor(void) {
		float countA = 0;
		float countB = 0;
		float result = 0;

		for (int i : bucketA) {
			if (i != INT_MIN)
				countA++;
		}
		for (int i : bucketB) {
			if (i != INT_MIN)
				countB++;
		}

		result = (countA + countB) / (float)(size * 2);

		return result;
	}

	void printBuckets(void) {
		std::cout << "In Bucket A : \n";
		for (int a : bucketA) {
			std::cout << a << " ";
		}
		std::cout << std::endl;

		std::cout << "In Bucket B : \n";
		for (int b : bucketB) {
			std::cout << b << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;

		return;
	}
};

#endif