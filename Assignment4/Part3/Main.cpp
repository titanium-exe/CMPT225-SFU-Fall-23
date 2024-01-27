#include "BinaryHeap.h"
#include "PriorityQueue.h"

int main(){
    PriorityQueue<int>* pq = new PriorityQueue<int>();
   int s0 =4;
   int s1 = 5;
   int s2 = 23;
   int s3 = 11;
   int s4 = 65;
   int s5 = 19;
   bool a1 = pq->enqueue(s0);
   bool a2 = pq->enqueue(s1);
   bool a3 = pq->enqueue(s2);
   bool a4 = pq->enqueue(s3);
   bool a5 = pq->enqueue(s4);
   bool a6 = pq->enqueue(s5);
   cout<<a1<<endl;
   cout<<a2<<endl;
   cout<<a3<<endl;
   cout<<a4<<endl;
   cout<<a5<<endl;
   cout<<a6<<endl;

 
   int d = pq->peek();
   cout<<d<<endl;
   return 0;
}