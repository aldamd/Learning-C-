#include <iostream>

void oddsKeepEvensFlip(int arr[], int arrSize) {
  int *odd_arr = new int[arrSize], *even_arr = new int[arrSize];
  int odd_cnt = 0, even_cnt = 0;

  int elem, idx;
  for (idx = 0; idx < arrSize; idx++) {
      elem = arr[idx];
      if (elem % 2 == 0) {
          std::cout<<elem<<" even"<<std::endl;
          even_arr[even_cnt] = elem;
          even_cnt++;
      }
      else {
          std::cout<<elem<<" odd"<<std::endl;
          odd_arr[odd_cnt] = elem;
          odd_cnt++;
      }
  }

  for (idx = 0; idx < odd_cnt; idx++)
      arr[idx] = odd_arr[idx];
  for (idx = 0; idx < even_cnt; idx++) {
      arr[idx + odd_cnt] = even_arr[even_cnt - idx - 1];
  }

  delete [] odd_arr;
  delete [] even_arr;
}

int main() {
  int arr[] = {5, 2, 11, 7, 6, 4};
  int arrSize = sizeof(arr) / sizeof(arr[0]);

  oddsKeepEvensFlip(arr, arrSize);

  for (int idx = 0; idx < arrSize; idx++)
      std::cout<<arr[idx]<<", ";
  std::cout<<std::endl;

  return 0;
}
