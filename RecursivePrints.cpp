#include <iostream>

void printTriangle(int n) {
  if (n == 1)
    std::cout<<"*"<<std::endl;
  else {
    printTriangle(n - 1);

    for (int idx = 0; idx < n; idx++)
      std::cout<<"*";
    std::cout<<std::endl;
  }
}

void printOppositeTriangles(int n) {
  if (n == 1)
    std::cout<<"*"<<std::endl;
  else {
    for (int idx = 0; idx < n; idx++)
      std::cout<<"*";
    std::cout<<std::endl;

    printOppositeTriangles(n - 1);

    for (int idx = 0; idx < n; idx++)
      std::cout<<"*";
    std::cout<<std::endl;
  }
}

void printRuler(int n) {
  if (n == 0)
    return;
  else {
    printRuler(n - 1);

    for (int idx = 0; idx < n; idx++)
      std::cout<<"-";
    std::cout<<std::endl;

    printRuler(n - 1);
  }
}

int main() {
  int n = 4;

  std::cout<<"printTriangle("<<n<<"):"<<std::endl;
  printTriangle(n);

  std::cout<<"\nprintOppositeTriangles("<<n<<"):"<<std::endl;
  printOppositeTriangles(n);

  std::cout<<"\nprintRuler("<<n<<"):"<<std::endl;
  printRuler(n);

  return 0;
}
