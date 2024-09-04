#include <iostream>
using namespace std;

#include "array-inheritance.h"
#include "vector.h"

int sum(const IntArray& arr)
{
  int sum(0);
  for (int i = 0; i < arr.getSize(); i++)
    sum += arr[i];
  return sum;
}

int main()
{
  Vector one(5, 1);
  Vector two(5, 2);
  
  cout << "Vector 1: " << one << endl;
  cout << "Vector 2: " << two << endl;
  cout << "Empty vector:  " << Vector() << endl;

  //* Test copy constructor
  Vector copy = one;
  cout << "Vector 1: " << one << endl;
  cout << "Copy: " << copy << endl;
  one[3] = -1;
  cout << "Vector 1 after modification: " << one << endl;
  cout << "Copy: " << copy << endl;
  copy = one;
  cout << "Copy after assignment: " << copy << endl;
  //*/
  
  //* Test push_back
  Vector count;
  for (int i = 0; i < 8; i++)
    count.push_back(i+1);
  cout << "Vector with 1-8: " << count << endl;
  for (int i = 8; i < 12; i++)
    count.push_back(i+1);
  cout << "Vector with 1-12: " << count << endl;
  //*/
  
  //* Test pop_back
  for (int i = two.getSize() - 1; i > 0; i--)
    two.pop_back();
  cout << "Vector 2 after popping all but one: " << two << endl;
  two.pop_back();
  cout << "After popping last element: " << two;
  if (two.empty())
    cout << " (empty)" << endl;
  else
    cout << " (size " << two.getSize() << ')' << endl;
  two.push_back(7);
  cout << "After pushing 7: " << two << endl;
  //*/
  
  //* Test sum function
  cout << "Sum of " << count << " = " << sum(count) << endl;  
  IntArray arr = one;
  cout << "Sum of " << arr << " = " << sum(arr) << endl;
  //*/

  return 0;
}