#include "peg.h"

void f(int a)
{
	std::cout << a << std::endl;
}

void f(std::string a)
{
	std::cout << a << std::endl;
}

template<typename T>
inline void callWithMax(const T& a, const T&b)
{
	f(a > b ? a : b);
}

int main()
{
	Peg peg = Peg(14);
	Peg foo = Peg(5);
	std::cout << "peg.count(): " << peg.count() << std::endl;
	std::cout << "peg.topSize(): " << peg.topSize() << std::endl;

	for (int i = 0; i < 15; i++) {
		peg.remove();
	}

	peg.add(31);
	std::cout << "peg.topSize(): " << peg.topSize() << "\tcount: " << peg.count() << std::endl;
	peg.add(22);
	peg.add(1);
	
	std::cout << peg;
	std::cout << foo;
	
	return 0;
}