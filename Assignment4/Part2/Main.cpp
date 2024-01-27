
#include "BinaryHeap.h"
#include <iostream>
using namespace std;

int main()
{
   BinaryHeap<int> *bh = new BinaryHeap<int>();

   int s0 = 4;
   int s1 = 5;
   int s2 = 23;
   int s3 = 11;
   int s4 = 65;
   int s5 = 19;
   bool a1 = bh->insert(s0);
   bool a2 = bh->insert(s1);
   bool a3 = bh->insert(s2);
   bool a4 = bh->insert(s3);
   bool a5 = bh->insert(s4);
   bool a6 = bh->insert(s5);
   cout<<a1<<endl;
   cout<<a2<<endl;
   cout<<a3<<endl;
   cout<<a4<<endl;
   cout<<a5<<endl;
   cout<<a6<<endl;
   cout<<"yay!"<<endl;
   int eC = bh->getElementCount();
   cout << "ElementCount is: "<<eC<<endl;

 
   int d = bh->retrieve();
   cout<<d<<endl;
   return 0;
}