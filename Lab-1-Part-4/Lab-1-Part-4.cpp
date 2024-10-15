#include <iostream>
#include <cassert>
#include <algorithm>

using std::cout;
using std::endl;

#define MIN_ARRAY_LEN 2

// Warning must delete[] returned array.
int* copyArray(const int arr[], int n) {
    int* r = new int[n];
    for (int i = 0; i < n; ++i) {
        r[i] = arr[i];
    }
    return r;
}

int choosePivotIndex(int arr[], int start, int end) {
    // Random for now.
    int n = (end + 1) - start;
    return start + std::rand() % n;
}

// Moves the given index in s2 to the left of the pivot. It does
// this with at most two swap operations. Making this
// an O(1) or constant time operation and very fast.
// Returns the new pivot location which has shifted to the right.
//
// s2: An index in the s2 portion of a partitioned array.
// pivot: The pivot index.
// arr: A mutable reference to an array.
// Returns: The new pivot location which has shifted to the left.
int moveLeft(int s2, int pivot, int arr[]) {
    assert(s2 > pivot);
    if (pivot + 1 != s2) {
        // swap with element to the right of the pivot
        std::swap(arr[pivot + 1], arr[s2]);
    }

    // swap with pivot
    std::swap(arr[pivot], arr[pivot + 1]);

    // move pivot index to the right.
    return pivot + 1;
}

// Moves the given index in s1 to the right of the pivot. It
// does this with at most two swap operations. Making this
// an O(1) or constant time operation and very fast.
//
// s1: An index in the s1 portion of a partitioned array.
// pivot: The pivot index.
// arr: A mutable reference to an array.
// Returns: The new pivot location which has shifted to the left.
int moveRight(int s1, int pivot, int arr[]) {
    assert(s1 < pivot);
    if (pivot - 1 != s1) {
        // swap with element to the left of the pivot
        std::swap(arr[pivot - 1], arr[s1]);
    }

    // swap with pivot
    std::swap(arr[pivot], arr[pivot - 1]);

    return pivot - 1;
}

// Partitions an array into segments s1, and s2 where s1 contains all the values less
// than or equal to the pivot value, and s2 contains the values greater or equal to the pivot.
// The pivot is not included in s1 or s2, although there can be other elements equal to the pivot
// in s1 or s2.
//
// pivotIndex: Index whose value is used to partition the input array.
// start: The index in the array to start at.
// end: The inclusive index in the array to end at.
//
// Returns: Index where the pivotIndex has moved to and the input array arr partitioned.
int partitionArrayAboutPivotIndex(int pivotIndex, int arr[], int start, int end) {
    int n = (end + 1) - start;
    std::swap(arr[pivotIndex], arr[end]);
    assert(n != 0 && pivotIndex >= start && pivotIndex <= end);

    if (n == 1) {
        return pivotIndex;
    }

    // TODO: Use the move functions to move elements to the left or right of the pivot.
    //
    //       Hints:
    //       * The pivot value determines what needs to move to the left or right of the pivot.
    //       * When we move array elements so they're on the opposite side of the pivot, this will move the pivot
    //         in the opposite direction. The pivot and value doesn't change, just it's location in the array.
    //       * Don't forget to update pivotIndex with the return value from the move functions.
    //       * You may dispense with the move functions and use swap directly.
    //       * You can do this multiple ways; one pass, two passes, from center out, from ends in.
    int i = start;
    int pivotValue = arr[pivotIndex];
    std::swap(arr[pivotIndex], arr[end]);
    for (int j = start; j < end; j++) {
        if (arr[j] < pivotValue) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[end]);
    
    return i;
}

// Quickly finds the k-th smallest value without sorting the entire array.
//
// k: 0 based index k into array arr
// arr: mutable pointer to an array
// start: start index of the array
// end: end index of the array
int findKthSmallestValue(int k, int arr[], int start, int end) {
    int n = (end + 1) - start;
    if (n == 0 || k >= n) {
        throw std::runtime_error("Invalid input.");
    }

    // Return the single value in an array of length 1.
    if (n == 1) {
        return arr[start];
    }

    int chosenPivotIndex = choosePivotIndex(arr, start, end);

    int pivotIndex = partitionArrayAboutPivotIndex(chosenPivotIndex, arr, start, end);

    int s1 = pivotIndex - start;

    // Base case where s1 == k.
    if (s1 == k) {
        // TODO: Replace -1 with the value for the base case.
        return arr[pivotIndex];
    }

    // Figure out which segment the kth smallest is in and recurse.
    // Note that the pivot is not included in s1 or s2. This guarantees that the problem reduces while recursing.
    // TODO: Replace true with a boolean expression that determines which segment to recurse into.
    if (k < pivotIndex) {
        // TODO: Replace -1 with a recursive call to findKthSmallestValue.
        return findKthSmallestValue(k, arr, start, pivotIndex - 1);
    }
    else {
        // TODO: Replace -1 with a recursive call to findKthSmallestValue.
        return findKthSmallestValue(k, arr, pivotIndex + 1, end);
    }
}

// Used to test our results. Warning: Sorts the input array in place.
int findKthSmallestValueViaSorting(int k, int arr[], int start, int end) {
    int n = (end + 1) - start;
    if (n == 0 || k >= n) {
        throw std::runtime_error("Invalid input.");
    }

    if (n == 1) {
        return arr[start];
    }

    std::sort(arr, arr + n);

    return arr[k];
}

// Tests findKthSmallestValue for an array of length n.
void testFindKthSmallestValueForArraySizeN(int n) {
    if (n == 0 || n == 1) {
        throw std::runtime_error("Invalid input.");
    }

    int* arr = new int[n];

    // Populate the array with random numbers
    for (int i = 0; i < n; ++i) {
        int x = std::rand() % 100;
        arr[i] = x; // Random number between 0 and 99
    }

    for (int k = 0; k < n; ++k) {
        int* copyArray1 = copyArray(arr, n);
        int expectedResult = findKthSmallestValueViaSorting(k, copyArray1, 0, n - 1);
        delete[] copyArray1;

        int* copyArray2 = copyArray(arr, n);
        int result = findKthSmallestValue(k, copyArray2, 0, n - 1);
        delete[] copyArray2;

        if (result != expectedResult) {
            delete[] arr;
            throw std::runtime_error("Test failed.");
        }
        else {
            cout << "Success for input array of size " << n << endl;
        }
    }

    delete[] arr;
}

void testFindKthSmallestValue(int repetitions, int maxArraySize) {
    if (maxArraySize < MIN_ARRAY_LEN) {
        throw std::runtime_error("Invalid input.");
    }

    for (int n = MIN_ARRAY_LEN; n <= maxArraySize; ++n) {
        for (int i = 0; i < repetitions; ++i) {
            testFindKthSmallestValueForArraySizeN(n);
        }
    }
}

int main() {
    // Seed the random number generator
    std::srand(0);

    // Only need to test the first few array sizes to fully test thanks to the minimal testing equivalence class.
    testFindKthSmallestValue(3, 5);
    return 0;
}
