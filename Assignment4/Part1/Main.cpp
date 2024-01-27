
#include "Event.h"
#include "Queue.h"
#include <iostream>
using namespace std;

int main(){

    Event Event1('w', 34);
    Event Event2('y', 35);
    Event Event3('x', 36);
    Event Event4('z', 37);
    Queue<Event> *e = new Queue<Event>();

    cout<<e->isEmpty();
    cout<<endl;
    e->enqueue(Event1);
    e->enqueue(Event2);
    e->enqueue(Event3);
    e->enqueue(Event4);
    Event r = e->peek(); 
    r.print();
    cout<<endl;
    e->dequeue();
    Event r2 = e->peek(); 
    r2.print();
    
    
    
    
}