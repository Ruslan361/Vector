#include "Vector.hpp"
#include "iostream"

int main() try {
	Vector<int> vector(5);
	for (size_t i = 0; i < 5; i++)
	{
		vector[i] = i;
	}
	Vector<int> temp = vector;
	std::cout << vector << std::endl;
	temp += vector;
	std::cout << temp << std::endl;
	std::cout << (temp * vector) << std::endl;
	std::cout << (temp -= vector) << std::endl;
	std::cout << (3 * temp) << std:: endl;
	std::cout << (temp *= 3) << std::endl;
	std::cout << (temp /= 3) << std::endl;
	Vector<int> manual(5);
	std::cin >> manual;
	std::cout << manual << std::endl;
	if (manual == temp) {
		std::cout << "You are lucky" << std::endl;
	}
	if (manual != temp) {
		std::cout << "You are not lucky" << std::endl;
	}
	if (manual < temp) std::cout << '<' << std::endl;
	if (manual <= temp) std::cout << "<=" << std::endl;
	if (manual > temp) std::cout << '>' << std::endl;
	if (manual >= temp) std::cout << ">=" << std::endl;
	std::cout << temp++ << std::endl;
	std::cout << ++temp << std::endl;
	std::cout << temp << std::endl;
	std::cout << temp.getBack() << std::endl;
	std::cout << temp.getFront() << std::endl;
	std::cout << temp.getSize() << std::endl;
	temp.resize(8);
	std::cout << temp << std::endl;
	temp.resize(7);
	std::cout << temp << std::endl;
	temp.at(5) = 0;
	std::cout << temp.at(5) << std::endl;
	std::cout << temp[2] << std::endl;
	temp.push_back(100);
	std::cout << temp << std::endl;
}
catch (Exception error) {
	std::cout << error;
}