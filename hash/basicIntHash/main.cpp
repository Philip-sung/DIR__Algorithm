#include "BasicHash.cpp"
#include <iostream>

int main(void) {
	basicIntegerHash hashmap(10);
	hashmap.insert(3);
	hashmap.insert(6);
	hashmap.find(6);
	int a = hashmap.find(5);
	std::cout << "Return value for none existing key : " << a << std::endl;
	hashmap.erase(6);
	hashmap.find(6);
	hashmap.insert(4);
	hashmap.insert(14);
	hashmap.insert(1);

	std::cout << "load factor : " << hashmap.loadFactor() << std::endl;

	return 0;
}