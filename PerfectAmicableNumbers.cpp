#include <iostream>
#include <cmath>

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs) {
  double squirt = std::sqrt(num);
  int last_asc_div;

  for (int i = 1; i <= squirt; i++) {
    if (num % i == 0) {
      // std::cout<<i<<" ";
      outCountDivs++;
      outSumDivs += i;
      last_asc_div = i;
    }
  }

  for (int i = squirt; i > 1; i--) {
    if (num % i == 0 && ((num / i) != last_asc_div)) {
        // std::cout<<(num / i)<<" ";
        outCountDivs++;
        outSumDivs = outSumDivs + (num / i);
    }
  }
  // std::cout<<std::endl<<"num: "<<num<<" | sum: "<<outSumDivs<<" | cnt: "<<outCountDivs<<std::endl;
}

bool isPerfect(int num) {
  int outCountDivs = 0, outSumDivs = 0;

  analyzeDivisors(num, outCountDivs, outSumDivs);
  
  if (num == outSumDivs)
    return true;
  else
    return false;
}

int amicablePair(int num) {
  int firstcount = 0, firstsum = 0, secondcount = 0, secondsum = 0;
  analyzeDivisors(num, firstcount, firstsum);
  analyzeDivisors(firstsum, secondcount, secondsum);
  // std::cout<<"num: "<<num<<" | pair: "<<firstsum<<" | secondpair: "<<secondsum<<std::endl;
  if (num == secondsum && num != firstsum)
    return firstsum;
  else
    return 0; 
}

int main() {
  int M;
  std::cout<<"Please enter a positive integer >= 2: "; std::cin>>M;
  std::cout<<"Perfect numbers: "<<std::endl;
  for (int i = 2; i <= M; i++) {
    if (isPerfect(i)) {
      std::cout<<i<<" ";
    }
  }
  std::cout<<std::endl;

  int pair;
  std::cout<<"Amicable number pairs: "<<std::endl;
  for (int i = 2; i <= M; i++) {
    pair = amicablePair(i);
    if (pair && pair <= M) {
      std::cout<<"("<<i<<","<<pair<<") ";
    }
  }
  std::cout<<std::endl;

  return 0;
}
