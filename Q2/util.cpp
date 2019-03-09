#include<ctime>
#include"util.h"
#include<functional>

template <typename callable>

double RunTime(callable func){
  std::clock_t start{};
  double duration{};
  start = std::clock();
  func();
  duration = 1000 * (std::clock() - start)/(double)CLOCKS_PER_SEC;
  return duration;
}
