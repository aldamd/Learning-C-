#include <iostream>

int find_cost_R(int arr[], int low, int high) {
  if (low >= high - 2)  {
    if (low == high)
      return 0;
    return arr[high];
  }
  else {
    int elem1 = arr[low + 1];
    int elem2 = arr[low + 2];
    if (elem1 < elem2) 
      return elem1 + find_cost_R(arr, low + 1, high);
    else 
      return elem2 + find_cost_R(arr, low + 2, high);
  }
}

void print_arr(int arr[], int high) {
  std::cout<<"["<<arr[0];
  for (int idx = 1; idx <= high; idx++)
    std::cout<<" "<<arr[idx];
  std::cout<<"]"<<std::endl;
}

int main() {
  int arr1[] = {0, 3, 80, 6, 57, 10};
  int low1 = 0, high1 = 5;
  int res1 = find_cost_R(arr1, low1, high1);
  print_arr(arr1, high1);
  std::cout<<"result: "<<res1<<std::endl<<std::endl;

  int arr2[] = {0, 12, 83, 4, 1, 17, 28};
  int low2 = 0, high2 = 6;
  int res2 = find_cost_R(arr2, low2, high2);
  print_arr(arr2, high2);
  std::cout<<"result: "<<res2<<std::endl<<std::endl;

  int arr3[] = {0, 3, 28, 1, 73, 14, 69, 12, 18, 39, 642, 0, 17, 4};
  int low3 = 0, high3 = 13;
  int res3 = find_cost_R(arr3, low3, high3);
  print_arr(arr3, high3);
  std::cout<<"result: "<<res3<<std::endl<<std::endl;

  return 0;
}
