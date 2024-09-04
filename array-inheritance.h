#ifndef __ARRAY_H
#define __ARRAY_H

#include <iostream>
using namespace std;

class IntArray
{
  friend ostream& operator<<(ostream&, const IntArray&);
protected:
  int* arr;
  int size;
public:
  IntArray(int initSize, int value = 0);
  IntArray(const IntArray& copy);
  ~IntArray();
  IntArray& operator=(const IntArray& copy);
  int at(int i) const;
  int operator[](int i) const;
  int& at(int i);
  int& operator[](int i);
  virtual int getSize() const { return size; }
};

ostream& operator<<(ostream&, const IntArray&);

#endif //__ARRAY_H