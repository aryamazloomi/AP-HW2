#include<iostream>
#include<ctime>
#include<functional>
#include<vector>
#include"libArr.h"
#include"libVec.h"

template <typename callable>
double RunTime(callable func){
  std::clock_t start{};
  double duration{};
  start = std::clock();
  func();
  duration = 1000 * (std::clock() - start)/(double)CLOCKS_PER_SEC;
  return duration;
}

int main(){
  int n{1};
  for(int i{1}; i < 8; i++)
  {
  libArr one{n};
  long int (libArr::*count1)(){&libArr::cnt};

  libVec two{n};
  long int (libVec::*count2)(){&libVec::cnt};
      std::cout << "N is:" <<n << std::endl;
      std::cout << "libArr Run Time is: " << RunTime(std::bind(count1,one)) << " ms"  << std::endl;
      std::cout << "libVec Run Time is: " << RunTime(std::bind(count2,two)) << " ms"  << std::endl;
      n = n * 10;
  }
  return 0;
}
