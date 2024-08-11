//Write a program that, prints a ‘pine tree’ consisting of triangles of increasing sizes, filled
//with a character (eg. ‘*’ or ’+’ or ‘$’ etc).
//Your program should interact with the user to read the number of triangles in the tree and
//the character filling the tree.

#include <iostream>

void printShiftedTriangle(int n, int m, char symbol) {
    for (int i = 1; i <= n; i++) {
        //print offset
        for (int j = 1; j <= m; j++)
            std::cout<<" "; 
        //print spaces
        for (int j = 1; j <= (n - i); j++)
            std::cout<<" ";
        //print symbols
        for (int j = 1; j <= (2 * i - 1); j++)
            std::cout<<symbol;
        //print newline
        std::cout<<std::endl;
    }
}

void pineTree(int n, char symbol) {
    for (int i = 1; i <= n; i++) {
      printShiftedTriangle((1 + i), (n - i), symbol);
    }
}

int main() {
    int n;
    char symbol;
    std::cout<<"Please enter the number of triangles in the tree: "; std::cin>>n;
    std::cout<<"Please enter the character filling the tree: "; std::cin>>symbol;

    pineTree(n, symbol);

    return 0;
}
