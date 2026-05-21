// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cmath>
#include <functional>
#include "Calculator.h"
const double e = 2.72;
int main()
{
	Calculator c;
	std::string input;
	while (true) {

		std::getline(std::cin, input);

		if (input == "exit") { break; }
		if (input.empty()) { continue; }

		try {
			double res = c.evaluate(input);
			std::cout << "Result: " << res << "\n";
		}
		catch (const InvalidCommand& e) {
			std::cout << "Error: " << e.what() << "\n";
		}
		catch (const std::invalid_argument& e) {
			std::cout << "Error: " << e.what() << "\n";
		}
	}
}
