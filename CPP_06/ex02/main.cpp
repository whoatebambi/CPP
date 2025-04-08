#include "Base.hpp"

int main(void) {
	std::srand(std::time(NULL));
	Base* ptr = generate();
	identify(ptr);
	delete(ptr);

	// // Pointer failure
	// Base* basePtr1 = reinterpret_cast<Base*>(new NotDerived());
	// identify(basePtr1);
	// delete reinterpret_cast<NotDerived*>(basePtr1);

	// // Reference failure
	// Base* basePtr2 = reinterpret_cast<Base*>(new NotDerived());
	// try {
	// 	Base& baseRef = *basePtr2;
	// 	identify(baseRef);
	// } catch (const std::exception& e) {
	// 	std::cout << "Caught exception during reference identify(): " << e.what() << std::endl;
	// }
	// delete reinterpret_cast<NotDerived*>(basePtr2);

	return 0;
}
