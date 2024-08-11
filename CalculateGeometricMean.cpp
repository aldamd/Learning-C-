// Write two versions of a program that reads a sequence of positive integers from the user,
// calculates their geometric mean, and print the geometric mean.

#include <iostream>
#include <cmath>

int main() {
  int seq_len;
  std::cout<<"Please enter the length of the sequence: "; std::cin>>seq_len;
  std::cout<<"Please enter your sequence:"<<std::endl;
  
  int product = 1;
  for (int i = 1; i <= seq_len; i++) {
    int num;
    std::cin>>num;
    product *= num;
  }

  double geometric_mean = std::pow((double)product, ((double)1 / (double)3));

  std::cout<<"The geometric mean is: "<< geometric_mean << std::endl;

  std::cout<<"Please enter a non-empty sequence of positive integers, each one in a separate line. ";
  std::cout<<"End your sequence by typing -1:"<<std::endl;

  int product = 1;
  while (true) {
    int num;
    std::cin>>num;
    if (num == -1)
      break;
    product *= num;
  }

  double geometric_mean = std::pow((double)product, ((double)1 / (double)3));

  std::cout<<"The geometric mean is: "<< geometric_mean << std::endl;
    
  return 0;
}
