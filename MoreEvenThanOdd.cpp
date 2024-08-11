// Write a program that asks the user to input a positive integer n, and print all of the numbers
// from 1 to n that have more even digits than odd digits.

#include <iostream>

int main() {
  int n;
  std::cout<<"Please input a positive integer: "; std::cin>>n;
  
  for (int i = 1; i <= n; i++) {
    int ref = i;
    int even_digits = 0;
    int odd_digits = 0;
    while (ref > 0) {
      int rem = ref % 10;
      
      if (rem % 2 == 0)
        even_digits += 1;
      else
        odd_digits += 1;
      
      ref /= 10;
    }
    
    if (even_digits > odd_digits) {
      std::cout<< i <<std::endl;
    }
  }
  
  return 0;
}
