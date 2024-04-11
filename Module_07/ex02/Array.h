#ifndef ARRAY_H
#define ARRAY_H

template <typename T> class Array {
private: 
  T * _array;
  unsigned int _length;

public:

  Array();
  Array(unsigned int length);
  ~Array();

  Array(const Array &source);
  Array &operator=(const Array &source);

  T& operator[](unsigned int index);

  unsigned int size() const;
};

#include "Array.tpp"

#endif // ARRAY_H
