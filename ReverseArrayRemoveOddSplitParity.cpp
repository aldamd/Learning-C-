#include <iostream>

void printArray(int arr[], int arrSize) {
    //prints each element of the array, space delimited
    for (int idx = 0; idx < arrSize; idx++) {
        std::cout<<arr[idx]<<" ";
    }
    std::cout<<std::endl;
}

void shiftLeft(int arr[], int arrSize, int idx) {
    //shifts all elements right of the given index to the left (by one element)
    for (int loc = idx; loc < arrSize; loc++) {
        arr[loc] = arr[loc + 1];
    }
}

void shiftRight(int arr[], int arrSize) {
    //shifts all elements right one space of the 0 index
    for (int idx = arrSize - 1; idx >= 0; idx--) {
        arr[idx + 1] = arr[idx];
    }
    arr[0] = 0;
}

void reverseArray(int arr[], int arrSize) {
    //reverses the order of elements in the array
    int xdi = arrSize - 1;
    int elem;
    for (int idx = 0; idx < arrSize/2; idx++) {
        elem = arr[idx];
        arr[idx] = arr[xdi];
        arr[xdi] = elem;
        xdi--;
    }
}

void removeOdd(int arr[], int& arrSize) {
    //removes odd elements of an array and changes the array size variable accordingly
    int elem;
    for (int idx = 0; idx < arrSize; idx++) {
        elem = arr[idx];
        if (elem % 2 != 0) {
            shiftLeft(arr, arrSize, idx);
            arrSize--;
        }
    }
}

void splitParity(int arr[], int arrSize) {
    //moves all odd elements of the array to the left side of the array
    int elem;
    for (int idx = 1; idx < arrSize; idx++) {
        elem = arr[idx];
        if (elem % 2 != 0) {
            shiftLeft(arr, arrSize, idx);
            shiftRight(arr, arrSize);
            arr[0] = elem;
        }
    }
}

int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;

    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;

    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}
