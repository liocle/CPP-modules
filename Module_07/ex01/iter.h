#ifndef ITER_H
# define ITER_H

#include <cstdio>

template <typename T, typename F> void iter(T * ptrToArray, size_t sizeOfArray, F function) {
  for (size_t i = 0; i < sizeOfArray; ++i){
    function(ptrToArray[i]);
  }
}



#endif // ITER_H
