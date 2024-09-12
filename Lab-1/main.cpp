#include <iostream>
#include <cassert>

int factorial(int);
int fibonacci(int);
int towers(int, char, char, char);
void testFactorial();
void testFibonacci();
void testTowers();


int main() {
    testFactorial();
    testFibonacci();
    testTowers();
}

int factorial(int num) {
    if (num <= 1) {
        return 1;
    }
    return num * factorial(num - 1);
}

int fibonacci(int num) {
    if (num < 2) {
        return num;
    }
    return fibonacci(num - 1) + fibonacci(num - 2);
}

int towers(int layers, char source, char destination, char spare) { 
    int count = 1;
    if(layers == 1) {
        //std::cout << "Move disc from " << source << " to " << destination << std::endl;
        return count;
    }
    else {
        count += towers(layers - 1, source, spare, destination);
        towers(1, source, destination, spare);
        count += towers(layers - 1, spare, destination, source);
    }
}


void testFactorial() {
    int result = factorial(4);
    std::cout << "factorial(4) should equal 24: ";
    assert(result == 24);
    std::cout << "True" << std::endl;
    result = factorial(0);
    std::cout << "factorial(0) should equal 1: ";
    assert(result == 1);
    std::cout << "True" << std::endl;
}

void testFibonacci() {
    int result = fibonacci(5);
    std::cout << "fibonacci(5) should equal 5: ";
    assert(result == 5);
    std::cout << "True" << std::endl;
    result = fibonacci(7);
    std::cout << "fibonacci(7) should equal 13: ";
    assert(result == 13);
    std::cout << "True" << std::endl;
}

void testTowers() {
    int result = towers(5, 'A', 'B', 'C');
    std::cout << "towers(5) should equal 31: ";
    assert(result == 31);
    std::cout << "True" << std::endl;
    result = towers(3, 'A', 'B', 'C');
    std::cout << "towers(3) should equal 7: ";
    assert(result == 7);
    std::cout << "True" << std::endl;
}