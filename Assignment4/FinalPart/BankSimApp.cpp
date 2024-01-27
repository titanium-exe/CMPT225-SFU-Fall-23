#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "EmptyDataCollectionException.h"
#include "Event.h"
#include "PriorityQueue.h"
#include "Queue.h"


int main() {
    
    Queue<Event>bankLineUp; //the queue for the bankline up
    PriorityQueue<Event>PriorityQueue; //the priority queue for the events that are going to happen

    bool tellerAvailable = true; //flag variable to indicate whether a teller is free or not 
    int currentTime; //keeping track of time; once the first person comes into the bank-time "starts"
    int numOfpersonInLines = 0; //keeping track of the # of people who enter the bank
    double waitingDuration = 0; //keeping track of who long it takes until someone gets their turn 
    double averageWaitingTime = 0;
    int timeOfArrival, lengthOfTransaction; //gets the arrival time, and the length of transaction 
    std::string readLine; //variable to store whatever is in the commandline

    while (std::getline(std::cin, readLine)) {
        std::istringstream obj(readLine);

        if (!(obj >> timeOfArrival >> lengthOfTransaction)) {
            continue;
        }

        Event nextArrivalE('A', timeOfArrival, lengthOfTransaction); //a new arrival event
        PriorityQueue.enqueue(nextArrivalE); //enqueue the new event object into the priority queue
    }

    std::cout << "Simulation Begins" << std::endl;
    while (!PriorityQueue.isEmpty()) {
        int timeCustLeft; //tracks when the person left 
        Event nextEvent = PriorityQueue.peek();
        currentTime = nextEvent.getTime(); 

        Event personInLine = nextEvent; 

        if(nextEvent.getType() == 'A'){
            std::cout << "Processing an arrival event at time: " << std::setw(5) << nextEvent.getTime() << std::endl;
            PriorityQueue.dequeue();
            if (bankLineUp.isEmpty() && tellerAvailable) {
                timeCustLeft = currentTime + personInLine.getLength();
                Event customerLeaving('D', timeCustLeft); //this is essentially what the textbook calls "a departure event"
                PriorityQueue.enqueue(customerLeaving);
                tellerAvailable = false;
            } 
            else {
                bankLineUp.enqueue(personInLine); 
            }
        }
       
        else{
            std::cout << "Processing departure event at time: " << std::setw(6) << nextEvent.getTime() << std::endl;
            PriorityQueue.dequeue();
            if (!bankLineUp.isEmpty()) {
                personInLine = bankLineUp.peek();
                bankLineUp.dequeue();
                timeCustLeft = currentTime + personInLine.getLength();
                Event customerLeaving('D', timeCustLeft);
                PriorityQueue.enqueue(customerLeaving);
            } 
            else{
                tellerAvailable = true;
            }
            numOfpersonInLines++;
            waitingDuration += currentTime - personInLine.getTime();
        }
    } //end of while loop

    std::cout << "End of Simulation :)" << std::endl; //this section will just display the results that we wanted
    std::cout << "\nHere are the Final Stats:" << std::endl;
    std::cout << std::endl;
    std::cout << "Total number of people processed: " << numOfpersonInLines << std::endl;
    if (numOfpersonInLines > 0) {
        averageWaitingTime = waitingDuration/numOfpersonInLines;  
        std::cout << "Average time spent waiting is: " << averageWaitingTime << std::endl;
    } 
    else {
        std::cout << "Average amount spent waiting is: N/A since nobody bothered to show up :)" << std::endl;
    }
    return 0;
}



