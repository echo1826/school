#include <iostream>

unsigned fact(unsigned n) {
    // base case of n == 0
    if (n == 0) {
        return 1;
    }
    // recursively call fact with n - 1 argument
    return n * fact(n - 1);


    
}

void writeArrayBackward(const char array[], int first, int last) {
    if(first <= last) {
        std::cout << array[last] << " ";

        writeArrayBackward(array, first, last - 1);
    }
}

void writeArrayBackward2(const char array[], int first, int last) {
    if(first <= last) {
        writeArrayBackward2(array, first + 1, last);
        std::cout << array[first] << " ";
    }
}

int binarySearch(int array[], int first, int last, int target) {
    if (first > last) {
        return -1;
    }
    int mid = first + (last - first) / 2; // the first + (last - first) is used to not overflow the stack

    if(target == array[mid]) {
        return mid;
    } else if(target < array[mid]) {
        binarySearch(array, first, mid - 1, target);
    } else {
        binarySearch(array, mid + 1, last, target);
    }
}

int findMaxValue(int array[], int first, int last) {
    int arrayLength = last - first + 1;
    int mid = first + (last - first) / 2;
    if(arrayLength == 1) {
        return array[mid];
    }
    // recursively finish the left side of array first
    int leftValue = findMaxValue(array, first, mid);
    int rightValue = findMaxValue(array, mid + 1, last);
    // like Math.max(), once all of the array has been divided it will be compared left to right first
    return std::max(leftValue, rightValue);
}

void towersOfHanoi(int layers, char source, char destination, char spare) {
    if(layers == 1) {
        std::cout << "Move remaining disk to pole " << source << " to pole " << destination << std::endl;
        return;
    } else {
        towersOfHanoi(layers - 1, source, spare, destination);
        towersOfHanoi(1, source, destination, spare);
        towersOfHanoi(layers - 1, spare, destination, source);
    }
}

int fibonacci(int n) {
    if(n <= 2) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    // std::cout << "fact(0): " << fact(0) << std::endl;
    // std::cout << "fact(1): " << fact(1) << std::endl;
    // std::cout << "fact(2): " << fact(2) << std::endl;

    // const char array[] = {'f', '0', '0'};
    // writeArrayBackward2(array, 0, 2);

    int array[] = {1,20,30,24,17,80,1};
    // std::cout << "Binary Search Result: " << binarySearch(array, 0, 2, 30);
    std::cout << "Max Value in Array: " << findMaxValue(array, 0, 6);

    return 0;
}