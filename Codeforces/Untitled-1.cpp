#include <bits/stdc++.h>
void swap(int x, int y) 
{
  int t;
  t = x;
  x = y;
  y = t;
  // cout<<"Inside Function a= "<<x<<" b="<<y<<endl;
}

int main()
{
  int a = 10, b = 20;
  // Pass by Values
  swap(a, b); // Actual Parameters
  cout<<"In Function: a= "<<a<<" b="<<b<<endl;
  return 0;
}
