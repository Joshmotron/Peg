#include "peg.h"

Peg::Peg(int size)
: size(size)
{
	if (size > MAXSIZE) {
		std::cout << "Constructor size greater than " << MAXSIZE << std::endl;
		exit(1);
	}
	
	for (int i = 0; i < MAXSIZE; i++) {
		rings[i] = 0;
	}	
	
	/* rings[0] = size, rings[size - 1] = 1 */
	for (int i = 0, j = size; i < size; i++, j--) {
		rings[i] = j;
	}
}

void Peg::add(const int addedRing)
{
	if (size > 0) {
		if (size == MAXSIZE || addedRing >= rings[size - 1]) {
			std::cout << "Cannot add ring of size: " << addedRing << ". Must be less than: " << rings[size - 1] << "." << std::endl;
			return;
		}
	}
	
	size++;
	rings[size - 1] = addedRing;
}

void Peg::remove()
{
	if (size == 0) {
		std::cout << "Cannot remove any more, no pegs are left." << std::endl;
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
