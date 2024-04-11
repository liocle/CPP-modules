// Array.tpp

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include <stdexcept>

template <typename T> Array<T>::Array() : _array(nullptr), _length(0){};

template <typename T>
Array<T>::Array(unsigned int length) : _array(new T[length]), _length(length){};

template <typename T> Array<T>::~Array() { delete[] _array; }

template <typename T>
Array<T>::Array(const Array &source) : _length(source._length) {
  if (_length > 0) {
    _array = new T[source._length];
    for (unsigned int i = 0; i < _length; ++i) {
      this->_array[i] = source._array[i];
    }
  } else {
    _array = nullptr;
  }
}

template <typename T> Array<T> &Array<T>::operator=(const Array &source) {
  if (this != &source) {
    if (_array) {
      delete[] _array;
    }
    _array = new T[source._length];
    _length = source._length;
    for (unsigned int i = 0; i < _length; ++i) {
      _array[i] = source._array[i];
    }
  }
  return (*this);
}

template <typename T> T &Array<T>::operator[](unsigned int index) {
  if (index < _length) {
    return _array[index];
  }
  throw std::out_of_range("Index out of bounds");
}

template <typename T> unsigned int Array<T>::size() const { return (_length); }

#endif
