#include "CuckooHashing.cpp"

int main(void) {

	CuckooIntegerHash chash(10);

	chash.insert(2);
	chash.printBuckets();
	chash.insert(12);
	chash.printBuckets();
	chash.insert(22);
	chash.printBuckets();
	chash.insert(32);
	chash.printBuckets();
	chash.insert(42);
	chash.printBuckets();
	chash.insert(52);
	chash.printBuckets();
	chash.erase(42);
	chash.printBuckets();

	std::cout << chash.loadFactor() << " : current load factor\n";

	return 0;
}