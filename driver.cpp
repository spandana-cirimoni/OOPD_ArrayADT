#include "Array.h"
#include <iostream>
using namespace std;

int main (int argc, char * argv [])
{
  // TODO Add code here to test your Array class.
  Array a(5,'a');
  Array b(a);
  Array c(10);
  Array d;
  Array e(10,'!');
  Array f(10,'@');
  Array g(10,'@');
  cout<<d.size()<<endl;
  d=a;
  cout<<d.size();
  cout<<d.get(2)<<endl;
  cout<<a.size()<<endl;
  cout<<a.get(3)<<endl;
  cout<<b.size()<<endl;
  cout<<b.get(3)<<endl;
  c.set(1,'s');
  cout<<c[1]<<endl;
  c.fill('V');
  c.set(2,'S');
  cout<<c.get(6)<<endl;
  cout<<c.find('S')<<endl;
  for(int i=0;i<c.size();i++)
  cout<<c.get(i)<<"  ";
  c.reverse();
  cout<<endl;
  for(int i=0;i<c.size();i++)
  cout<<c.get(i)<<"  ";
  if(f==g)
  cout<<"true";
  else
  cout<<"false";
  if(f==e)
  cout<<"true";
  else
  cout<<"false";
  return 0;
}
