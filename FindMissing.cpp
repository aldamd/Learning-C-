#include <iostream>

void print_arr(int arr[], int arrSize) {
  for (int idx = 0; idx < arrSize; idx++)
    std::cout<<arr[idx]<<" ";
  std::cout<<std::endl;
}

int* findMissing(int arr[], int n, int& resArrSize) {
  resArrSize = 0;

  int* occurrence_arr = new int[n + 1];
  for (int idx = 0; idx < n + 1; idx++) {
    occurrence_arr[idx] = 0;
  }
  for (int idx = 0; idx < n; idx++) {
    occurrence_arr[arr[idx]]++;
  }
  
  int elem;
  int* missingArr = new int[n];
  for (int idx = 0; idx < n + 1; idx++) {
    elem = occurrence_arr[idx];
    if (!elem) {
      missingArr[resArrSize++] = idx;
    }
  }
  
  delete [] occurrence_arr;
  
  return missingArr;
}

int main() {
  int arr[] = {1, 4, 8, 2, 3, 8, 6, 9, 1};
  int arrSize = sizeof(arr) / sizeof(arr[0]);

  int missingArrSize;
  int* missingArr = findMissing(arr, arrSize, missingArrSize);
  print_arr(missingArr, missingArrSize);

  delete [] missingArr;

  return 0;
}
