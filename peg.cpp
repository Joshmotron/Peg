#include "peg.h"

Peg::Peg(int size)
{
	if (size > MAXSIZE) {
		std::cout << "Constructor size greater than " << MAXSIZE << std::endl;
		exit(1);
	}
	
	Peg::size = size;

	/* 0 index = size, [size - 1] index = 1 */
	for (int i = 0, j = size; i < size; i++, j--) {
		rings[i] = j;
	}
}

void Peg::add(const int addedRing)
{
	if (size == MAXSIZE || rings[size - 1] == 1 || addedRing >= rings[size - 1]) {
		std::cout << "Cannot add another ring." << std::endl;
		return;
	}
	
	rings[size - 1] = addedRing;
	size++;
}

void Peg::remove()
{
	if (size == 0) {
		std::cout << "Cannot remove any more." << std::endl;
		return;
	}
	
	rings[size - 1] = 0;
	size--;
}

int Peg::count() const
{
	return size;
}

int Peg::topSize() const
{
	return rings[size - 1];
}

std::ostream& operator<<(std::ostream& os, const Peg& peg)
{
	for (int i = 0; i < peg.count(); i++) {
		for (int j = 0; j < peg.rings[i]; j++ ) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	return os;
}
