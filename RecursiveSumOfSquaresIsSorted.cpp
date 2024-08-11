#include <iostream>

int sumOfSquares(int arr[], int arrSize) {
  if (arrSize == 1) {
    int elem = arr[0];
    return elem * elem;
  }
  else {
    int elem = arr[arrSize - 1];
    return (elem * elem) + sumOfSquares(arr, arrSize - 1);
  }
}

bool isSorted(int arr[], int arrSize) {
  if (arrSize == 1 || arrSize == 2) {
    if (arrSize == 1)
      return true;
    else 
      return (arr[0] <= arr[1]);
  }
  else 
    return ((arr[arrSize - 2] <= arr[arrSize - 1]) && isSorted(arr, arrSize - 1));
}

int main() {
  int arr[4] = {2, -1, 3, 11};
  std::cout<<sumOfSquares(arr, 4)<<std::endl;

  // int arr[6] = {1, 2, 3, 4, 5, 6};
  // std::cout<<isSorted(arr, 6)<<std::endl;

  return 0;
}
