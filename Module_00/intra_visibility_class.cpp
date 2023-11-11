#include "intra_visibility_class.hpp"
#include <iostream>

Sample::Sample(void) {

  std::cout << "Constructor called" << std::endl;

  this->publicFoo = 0;
  std::cout << "this->publicFoo: " << this->publicFoo << std::endl;

  this->_privateFoo = 0;
  std::cout << "this->_privateFoo: " << this->_privateFoo << std::endl;

  this->publicBar();
  this->_privateBar();

  return;
}

Sample::~Sample(void) {

  std::cout << "Destructor called" << std::endl;
  return;
}

void Sample::publicBar(void) const {

  std::cout << "Member function publicBar called" << std::endl;
  return;
}

void Sample::_privateBar(void) const {

  std::cout << "Member function _privateBar called from Constructor" << std::endl;
  return;
}
