#include "Base.hpp"
#include "A.hpp"

// #include <cstdlib>  // for rand(), srand()
#include <ctime>    // for time()

int main(void) {
	std::srand(std::time(NULL));
	Base* ptr = generate();
	identify(ptr);
	delete(ptr);
	return 0;
}
