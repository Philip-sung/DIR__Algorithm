#include "BasicHash.cpp"
#include <iostream>

int main(void) {
	basicIntegerHash hashmap(7);
	hashmap.insert(3);
	hashmap.insert(6);
	hashmap.find(6);
	int a = hashmap.find(5);
	std::cout << a << std::endl;
	hashmap.erase(6);
	hashmap.find(6);

	return 0;
}