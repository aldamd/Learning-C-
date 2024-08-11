// Write a program that asks the user to input a positive integer n, and prints a textual image of an
// hourglass made of 2n lines with asterisks.
// For example if n=4, the program should print:
// *******
//  *****
//   ***
//    *
//    *
//   ***
//  *****
// *******
//
//iterate through n lines
  //(row-1)space, 2n-(2*row - 1)*'s

#include <iostream>

int main() {
  int num_rows;
  std::cout<<"Please enter a positive integer: "; std::cin>>num_rows;
  
  //Print top of hourglass
  for (int r = 1; r <= num_rows; r++) {
    //Print spaces
    for (int space = 1; space < r; space ++) {
      std::cout<<" ";
    }
    //Print stars
    for (int star = 1; star <= (2 * num_rows) - ((2 * r) - 1); star++) {
      std::cout<<"*";
    }
    std::cout<<std::endl;
  }
  //Print bottom of hourglass
  for (int r = num_rows; r > 0; r--) {
    //Print spaces
    for (int space = 1; space < r; space ++) {
      std::cout<<" ";
    }
    //Print stars
    for (int star = 1; star <= (2 * num_rows) - ((2 * r) - 1); star++) {
      std::cout<<"*";
    }
    std::cout<<std::endl;
  }

  return 0;
}
