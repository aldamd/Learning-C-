// Write a program that reads from the user a positive integer (in a decimal representation), and
// prints its binary (base 2) representation.

#include <iostream>
#include <cmath>

int main() {
  int input_int;
  std::cout<<"Enter decimal number:"<<std::endl;
  std::cin>>input_int;
  int ref = input_int;

  int binary = 0;
  int count = 0;
  while (input_int != 0) {
    int rem = input_int % 2;
    binary += rem * std::pow(10.0, (double)count);
    input_int /= 2;
    count++;
  }

  std::cout<<"The binary representation of "<< ref <<" is "<< binary <<std::endl;

  return 0;
}
