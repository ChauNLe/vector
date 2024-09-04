#include "array-inheritance.h"

#include <cstring>
using namespace std;

//Create int array of given size filled with value
IntArray::IntArray(int initSize, int value)
{
  size = initSize;
  arr = new int[size];
  for (int i = 0; i < size; i++)
    arr[i] = value;
}

//Copy constructor
//IntArray arr2 = arr1;
IntArray::IntArray(const IntArray& copy)
{
  size = copy.size;
  arr = new int[size];
  memcpy(arr, copy.arr, size * sizeof(int));
}

//Copy assignment
//arr2.operator=(arr1);
IntArray& IntArray::operator=(const IntArray& copy)
{
  cout << "Copy assignment " << endl;
  if (this != &copy)
  {
    delete[] arr;
    size = copy.size;
    arr = new int[size];
    memcpy(arr, copy.arr, size * sizeof(int));
  }
  return *this;
}

//Destructor
IntArray::~IntArray()
{
  delete[] arr;
}

//Array access
int IntArray::at(int i) const
{
  return arr[i];
}
int IntArray::operator[](int i) const
{
  return arr[i];
}

//Array mutators
//(*ptr) = 6;
int& IntArray::at(int i)
{
  return arr[i];
}
int& IntArray::operator[](int i)
{
  return arr[i];
}

//Array print function
ostream& operator<<(ostream& out, const IntArray& arr)
{
  //[1, 2, 3]
  if (arr.getSize() == 0)
    return out << "[]";
  out << '[' << arr[0];
  for (int i = 1; i < arr.getSize(); i++)
    out << ", " << arr.at(i);
  return out << ']';
}
