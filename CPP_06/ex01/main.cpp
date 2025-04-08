#include "Serializer.hpp"

int main(void) {
	Data data;
	data.number = 42;
	data.text = "Hello, World!";
	std::cout << "data.address = " << &data << "\n";
	std::cout << "data.number = " << data.number << "\n";
	std::cout << "data.text   = " << data.text << "\n\n";

	uintptr_t ptr = Serializer::serialize(&data);
	std::cout << "ptr         = " << ptr << "\n\n";


	Data *raw = Serializer::deserialize(ptr);
	std::cout << "raw         = " << raw << "\n";
	std::cout << "raw->number = " << raw->number << "\n";
	std::cout << "raw->text   = " << raw->text << "\n\n";

	Data* nullData = nullptr;
	uintptr_t nullPtr = Serializer::serialize(nullData);
	Data* back = Serializer::deserialize(nullPtr);
	std::cout << "\nNull pointer test:\n";
	std::cout << "nullPtr = " << nullPtr << "\n";
	std::cout << "back    = " << back << "\n";

	return (0);
}
