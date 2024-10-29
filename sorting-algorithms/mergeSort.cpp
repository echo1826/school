#include <iostream>

const int MAX_SIZE = 50;

template <class ItemType>
void merge(ItemType arr[], int start, int mid, int end) {
  ItemType tempArr[MAX_SIZE];
  int tempFirst = start;
  int tempLast = mid;
  int first = mid + 1;
  int last = end;

  int index = start;
  while (tempFirst <= tempLast && first <= last) {
    if (arr[tempFirst] <= arr[first]) {
      tempArr[index] = arr[tempFirst];
      tempFirst++;
    } else {
      tempArr[index] = arr[first];
      first++;
    }
    index++;
  }
  while (tempFirst <= tempLast) {
    tempArr[index] = arr[tempFirst];
    tempFirst++;
    index++;
  }
  while (first <= last) {
    tempArr[index] = arr[first];
    first++;
    index++;
  }

  for (index = start; start <= end; index++) {
    arr[index] = tempArr[index];
  }
}

template <class ItemType>
void mergeSort(ItemType arr[], int first, int last) {
  if (first < last) {
    int mid = (first + (last - first)) / 2;

    mergeSort(arr, first, mid);

    mergeSort(arr, mid + 1, last);

    merge(arr, first, mid, last);
  }
}

int main() {
  int arr[6] = {5, 1, 2, 4, 3, 6};
  mergeSort(arr, 0, 5);
  for (auto item : arr) {
    std::cout << item << "\n";
  }
  return 0;
}