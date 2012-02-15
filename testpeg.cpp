#include "Peg.h"

int main()
{
	Peg bar = Peg(20);
	Peg foo = Peg(30);
	Peg baz = Peg(50);
	baz.remove();
	baz.remove();
	
	for (int i = 0; i < 21; i++) {
		bar.remove();
	}

	for (int i = 20; i > 5; i--) {
		bar.add(i);
	}

	std::cout << "Adding 0 to foo" << std::endl;
	foo.add(0);

	std::cout << "bar.topSize(): " << bar.topSize() << std::endl;
	std::cout << "bar.count(): " << bar.count() << std::endl << std::endl;

	std::cout << "foo.topSize(): " << foo.topSize() << std::endl;
	std::cout << "foo.count(): " << foo.count() << std::endl << std::endl;

	std::cout << "baz.topSize(): " << baz.topSize() << std::endl;
	std::cout << "baz.count(): " << baz.count() << std::endl << std::endl;

	return 0;
}
