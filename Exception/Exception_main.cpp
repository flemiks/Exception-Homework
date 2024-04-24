#include <iostream>
#include <fstream>
#include <new>  
#include "Exceptions.h"

void openAndReadFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        if (!file.is_open()) {
            throw FileNotFoundException(filename);
        }
        else {
            throw FileAccessException(filename);
        }
    }

    std::string line;
    while (getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw DivisionByZeroException();
    }
    return numerator / denominator;
}

double safeSqrt(double value) {
    if (value < 0) {
        throw NegativeSqrtException();
    }
    return sqrt(value);
}

void processData(size_t size) {
    try {
        int* largeArray = new int[size];
        for (size_t i = 0; i < size; i++) {
            largeArray[i] = i;
        }
        delete[] largeArray; 
    }
    catch (const std::bad_alloc&) {
        throw MemoryException();
    }
}

int main() {
    std::string filename = "data.txt";
    try {
        openAndReadFile(filename);
    }
    catch (const FileNotFoundException& e) {
        std::cout << "File error: " << e.what() << std::endl;
    }
    catch (const FileAccessException& e) {
        std::cout << "Access error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "An unexpected error occurred: " << e.what() << std::endl;
    }
    try {
        std::cout << "Dividing 10 by 2 gives: " << divide(10, 2) << std::endl;
        std::cout << "Dividing 10 by 0 gives: ";
        std::cout << divide(10, 0) << std::endl;  
    }
    catch (const DivisionByZeroException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Square root of 16 is: " << safeSqrt(16) << std::endl;
        std::cout << "Square root of -1 is: ";
        std::cout << safeSqrt(-1) << std::endl;  
    }
    catch (const NegativeSqrtException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    try {
        processData(10000000000);
    }
    catch (const MemoryException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
