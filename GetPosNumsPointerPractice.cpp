#include <iostream>

void print_arr(int arr[], int arrSize) {
  for (int idx = 0; idx < arrSize; idx++)
    std::cout<<arr[idx]<<" ";
  std::cout<<std::endl;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
  int elem;
  int* outPosArr = new int[arrSize];
  for (int idx = 0; idx < arrSize; idx++) {
      elem = arr[idx];
      if (elem > 0)
        outPosArr[outPosArrSize++] = elem;
  }

  return outPosArr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
  int pos_nums = 0;
  int elem;
  int* outPosArr = new int[arrSize];
  for (int idx = 0; idx < arrSize; idx++) {
    elem = arr[idx];
    if (elem > 0)
      outPosArr[pos_nums++] = elem;
  }
  *outPosArrSizePtr = pos_nums;

  return outPosArr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
  int elem;
  for (int idx = 0; idx < arrSize; idx++) {
    elem = arr[idx];
    if (elem > 0)
      outPosArr[outPosArrSize++] = elem;
  }
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
  int pos_nums = 0;
  int elem;
  int* outPosArr = new int[arrSize];
  for (int idx = 0; idx < arrSize; idx++) {
    elem = arr[idx];
    if (elem > 0)
      outPosArr[pos_nums++] = elem;
  }
  *outPosArrPtr = outPosArr;
  *outPosArrSizePtr = pos_nums;
}

int main() {
  int arr[] = {3, -1, -3, 0, 6, 4};
  int arrSize = sizeof(arr) / sizeof(arr[0]);
  std::cout<<"original array:"<<std::endl;
  print_arr(arr, arrSize);

  std::cout<<"getPosNums1:"<<std::endl;
  int outPosArrSize = 0;
  int* outPosArr1 = getPosNums1(arr, arrSize, outPosArrSize);
  print_arr(outPosArr1, outPosArrSize);
  delete [] outPosArr1;

  outPosArrSize = 0;
  std::cout<<"getPosNums2:"<<std::endl;
  int* outPosArrSizePtr = &outPosArrSize;
  int* outPosArr2 = getPosNums2(arr, arrSize, outPosArrSizePtr);
  print_arr(outPosArr2, *outPosArrSizePtr);
  delete [] outPosArr2;

  outPosArrSize = 0;
  std::cout<<"getPosNums3:"<<std::endl;
  int* outPosArr3 = new int[arrSize];
  getPosNums3(arr, arrSize, outPosArr3, outPosArrSize);
  print_arr(outPosArr3, outPosArrSize);
  delete [] outPosArr3;

  std::cout<<"getPosNums4:"<<std::endl;
  int* outPosArr4 = nullptr;
  getPosNums4(arr, arrSize, &outPosArr4, outPosArrSizePtr);
  print_arr(outPosArr4, *outPosArrSizePtr);
  delete [] outPosArr4;

  return 0;
}
