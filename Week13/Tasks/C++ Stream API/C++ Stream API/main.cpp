#include <iostream>
#include <string>
#include "Stream.hpp"
#include "Vector.hpp"
#include "Array.hpp"
#include "Map.hpp"

bool isEven(const int& num) {
    return num % 2 == 0;
}

bool compareIntsDesc(const int& a, const int& b) {
    return a > b; 
}

std::string intToString(const int& num) {
    return "Number: " + std::to_string(num);
}

int getStringLength(const std::string& str) {
    return str.length();
}

int main() {
    try {
        std::cout << "=== Test 1:===" << std::endl;
        int rawData[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        Array<int> myArray(rawData, 10);

        std::cout << "og arr: ";
        for (int i = 0; i < 10; i++) std::cout << myArray[i] << " ";
        std::cout << "\n";

        Stream<int> stream1 = myArray.stream();
        Array<int> filteredArray = stream1.filter(isEven)
                                          .limit(3)
                                          .toArray();

        std::cout << "filtered and limited (only 3 even): ";
        std::cout << filteredArray[0] << " " << filteredArray[1] << " " << filteredArray[2] << "\n\n";


        std::cout << "=== Test 2:===" << std::endl;
        Vector<int> myVector(5);
        myVector.addElement(15);
        myVector.addElement(3);
        myVector.addElement(42);
        myVector.addElement(8);

        std::cout << "og vector: ";
        for (int i = 0; i < 4; i++) std::cout << myVector[i] << " ";
        std::cout << "\n";

        Vector<std::string> mappedVector = myVector.stream()
            .sort(compareIntsDesc)
            .map<std::string>(intToString)
            .toVector();

        std::cout << "sorted and transformed:\n";
        for (int i = 0; i < 4; i++) {
            std::cout << mappedVector[i] << std::endl;
        }
        std::cout << "\n";


        std::cout << "=== Test 3:  toMap ===" << std::endl;
        std::string words[] = { "C++", "Java", "StreamAPI", "OOP" };
        Array<std::string> wordsArray(words, 4);

        Map<std::string, int> myMap = wordsArray.stream().toMap<int>(getStringLength);

        std::cout << "searching Map:\n";
        std::cout << "len of'StreamAPI': " << myMap.findByKey("StreamAPI") << std::endl;
        std::cout << "len of 'C++': " << myMap.findByKey("C++") << std::endl;
        std::cout << "\n";


        std::cout << "===Test  4:  (Exceptions) ===" << std::endl;
        try {
            std::cout << "" << std::endl;
            int x = myVector[100]; 
        }
        catch (const std::out_of_range& e) {
            std::cout << " " << e.what() << std::endl;
        }

        try {
            std::cout << " " << std::endl;
            int length = myMap.findByKey("Python"); 
        }
        catch (const std::invalid_argument& e) {
            std::cout << "" << e.what() << std::endl;
        }

    }
    catch (const std::exception& e) {
        std::cerr << " " << e.what() << std::endl;
    }

    return 0;
}