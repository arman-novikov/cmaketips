#include "leaky_implementation.hpp"

int do_some_work() {

  // we allocate an array
  volatile double *my_array = new double[1000];
  double res;

  for (int i = 0; i < 1000; ++i)
  {
  	res += my_array[i];
  }

  // do some work
  // ...

  // we forget to deallocate it
  //delete[] my_array;

  return static_cast<int>(res);
}
