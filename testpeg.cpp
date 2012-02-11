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
	Peg peg = Peg();
	while (peg.count() > 5) {
		peg.remove();
	}
	peg.add(2);
	std::cout << peg;
	
	return 0;
}