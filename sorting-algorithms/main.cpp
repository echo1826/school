#include <iostream>

template<class ItemType>
void selectionSort(ItemType arr[], int size) {
    for(int i = 0; i < size; i++) {
        int smallest = i;
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[smallest]) {
                smallest = j;
            }
        }
        std::swap(arr[smallest], arr[i]);
    }
}

template<class ItemType>
void bubbleSort(ItemType arr[], int size) {
    bool noswap = true;
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
                noswap = false;
            }
            if(noswap) {
                break;
            }
        }
    }
}

template<class ItemType>
void insertionSort(ItemType arr[], int size) {
    for(int unsorted = 1; unsorted < size; unsorted++) {
        ItemType nextItem = arr[unsorted];
        int location = unsorted;
        while(location > 0 && arr[location - 1] > nextItem) {
            arr[location] = arr[location - 1];
            location--;
        }
        arr[location] = nextItem;
    }
}

template<class ItemType>
void printArray(const ItemType& arr) {
    for(auto item: arr) {
        std::cout << item << "\n";
    }
}

int main() {
    int arr[6] = {5,1,2,3,7,4};
    selectionSort(arr, 6);
    std::cout << "Selection Sort:\n";
    printArray(arr);
    int arr2[6] = {5,1,2,3,7,4};
    bubbleSort(arr2, 6);
    std::cout << "Bubble Sort:\n";
    printArray(arr2);
    int arr3[6] = {5,1,2,3,7,4};
    insertionSort(arr3, 6);
    std::cout << "Insertion Sort:\n";
    printArray(arr3);
    return 0;
}