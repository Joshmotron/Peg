#include "peg.h"

int main()
{
	Peg peg = Peg(12);
	std::cout << "peg.count(): " << peg.count() << std::endl;
	std::cout << "peg.topSize(): " << peg.topSize() << std::endl;
	std::cout << "Main" << std::endl;
	peg.remove();
	peg.remove();
	peg.remove();
	peg.remove();
	peg.add(1);
	peg.add(1);
	std::cout << peg;
	
	return 0;
}