#include <iostream>

template<class ItemType>
int partition(ItemType arr[], int first, int last) {
    int mid = first + (last - first) / 2;
    if(arr[first] > arr[mid]) {
        std::swap(arr[first], arr[mid]);
    }
    if(arr[mid] > arr[last]) {
        std::swap(arr[mid], arr[last]);
    }
    if(arr[first] > arr[mid]) {
        std::swap(arr[first], arr[mid]);
    }

    std::swap(arr[mid], arr[last - 1]);
    int pivotIndex = last - 1;
    ItemType pivot = arr[pivotIndex];
    
    int indexFromLeft = first + 1;
    int indexFromRight = last - 2;

    bool sorted = false;

    while(!sorted) {
        while(arr[indexFromLeft] < pivot) {
            indexFromLeft = indexFromLeft + 1;
        }
        while(arr[indexFromRight] > pivot) {
            indexFromRight = indexFromRight - 1;
        }
        if(indexFromLeft < indexFromRight) {
            std::swap(arr[indexFromRight], arr[indexFromLeft]);
            indexFromLeft = indexFromLeft + 1;
            indexFromRight = indexFromRight - 1;
        } else {
            sorted = true;
        }
    }

    std::swap(arr[pivotIndex], arr[indexFromLeft]);
    pivotIndex = indexFromLeft;
    return pivotIndex;
}

template<class ItemType>
void quickSort(ItemType arr[], int first, int last) {
    if(first < last) {
        int pivotIndex = partition(arr, first, last);

        quickSort(arr, first, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, last);
    }
}

int main() {
    int arr[6] = {5,3,2,6,1,4};
    quickSort(arr, 0, 5);
    for(auto item: arr) {
        std::cout << item << "\n";
    }
    return 0;
}