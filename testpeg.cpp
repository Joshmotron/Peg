#include "peg.h"

int main()
{
	Peg peg = Peg();
	while (peg.count() > 5) {
		peg.remove();
	}
	peg.add(15);
	peg.add(11);
	peg.add(15);
	peg.add(2);
	std::cout << peg;
	
	return 0;
}