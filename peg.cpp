#include "peg.h"

Peg::Peg(int size)
: size(size)
{
	if (size > MAXSIZE) {
		std::cout << "Constructor size " << size << " greater than " << MAXSIZE << std::endl;
		exit(1);
	}
	
	if (size < 0) {
		std::cout << "Constructor size less than 0." << std::endl;
		exit(1);
	}
	
	for (int i = 0; i < MAXSIZE; i++) {
		rings[i] = 0;
	}	
	
	/* rings[0] = size, rings[size - 1] = 1 */
	for (int i = 0, j = size; i < size; i++, j--) {
		rings[i] = j;	/* ring of size j at position i */
	}
}

void Peg::add(const int addedRing)
{
	/* If number of rings equals zero, add one, then check 
	 * any ring after count() > 1 */
	if (count() > 0) {
		if (count() == MAXSIZE + 1) {
			std::cout << "Cannot add another ring. Peg full." << std::endl;
			return;
		}

		/* Ring size must be exclusive and in order. Check to make sure
		 * new ring is smaller than previous ring */
		if (addedRing >= rings[count() - 1]) {
			std::cout << "Cannot add ring of size: " << addedRing << ". Must be less than: " << rings[count() - 1] << "." << std::endl;
			return;
		}

		if (addedRing <= 0) {
			std::cout << "Ring must be of positive value." << std::endl;
		}
	}				

	rings[size++] = addedRing;
}

void Peg::remove()
{
	if (count() == 0) {
		std::cout << "Cannot remove any more, no pegs are left." << std::endl;
		return;
	}

	rings[--size] = 0;
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
	for (int i = peg.count() - 1; i >= 0; i--) {
		std::cout << std::string(peg.rings[i], '*') << std::endl;
	}
	return os;
}
