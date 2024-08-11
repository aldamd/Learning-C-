#include <iostream>
#include <cmath>

void printDivisors(int num) {
  double squirt = std::sqrt(num);
  int last_asc_div;

  for (int i = 1; i <= squirt; i++) {
    if (num % i == 0)
      std::cout<<i<<" ";
      last_asc_div = i;
  }

  for (int i = squirt; i > 1; i--) {
    if (num % i == 0 && ((num / i) != last_asc_div)) {
        std::cout<<(num / i)<<" ";
    }
  }
}

int main() {
  int n;
  std::cout<<"Please enter a positive integer >= 2: "; std::cin>>n;

  printDivisors(n);

  return 0;
}
