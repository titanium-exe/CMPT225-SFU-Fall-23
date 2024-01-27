/*
MyADTTestDriver.cpp - Assignment 1

Class Description: Test ADT class.

Created on: Sept 29 2023
Author: Ekamleen Maan
Code adapted from Anne Lavergne, all credit goes to the original author. 
*/

#include <iostream>
#include <string>
#include <cctype>
#include "Profile.h"
#include "MyADT.h"

using std::cout;
using std::endl;

int main() {

    cout << "Testing default constructor of MyADT:" << endl;
    MyADT * members = new MyADT();
    cout << "memory address of members is " << &members << endl;
    cout << "memory adress stored in members is " << members << endl;

    cout << "Just created MyADT members. It has " << members -> getElementCount() << " elements." << endl;

    Profile theMemberA[] = {Profile("amy"), Profile("allan"), Profile("alex"), Profile("anton"), Profile("aaaaa")};
    Profile theMemberD[] = {Profile("diana"), Profile("dick"), Profile("doy"), Profile("dawson"), Profile("dzzzzz")};
    Profile theMemberQ[] = {Profile("qi"), Profile("quest"), Profile("qong"), Profile("quang"), Profile("qaaaa")};

    cout << "***Testing insert() of MyADT - inserting 1 element in each of the 3 empty array: " << endl;
    for (unsigned int index = 0; index < 1; index++) {
        if (!members->insert(theMemberA[index])) cout << "Insert failed!" << endl;
        if (!members->insert(theMemberD[index])) cout << "Insert failed!" << endl;
        if (!members->insert(theMemberQ[index])) cout << "Insert failed!" << endl;
    }

    cout << "MyADT members. It has " << members -> getElementCount() << " elements." << endl;
    cout << "Here is what my MyADT members contains: ";
    members -> print();

    cout << "***Testing insert() of MyADT - inserting the same 3 elements: " << endl;
    for (unsigned int index = 0; index < 1; index++) {
        if (!members->insert(theMemberA[index])) cout << "Insert failed!" << endl;
        if (!members->insert(theMemberD[index])) cout << "Insert failed!" << endl;
        if (!members->insert(theMemberQ[index])) cout << "Insert failed!" << endl;
    }

    cout << "***Testing insert() of MyADT - inserting all remaining elements: " << endl;
    for (unsigned int index = 0; index < 5; index++) {
        if (!members->insert(theMemberA[index])) cout << "Insert failed!" << endl;
        if (!members->insert(theMemberD[index])) cout << "Insert failed!" << endl;
        if (!members->insert(theMemberQ[index])) cout << "Insert failed!" << endl;
    }

    cout << "MyADT members. It has " << members -> getElementCount() << " elements." << endl;
    cout << "Here is what my MyADT members contains: ";
    members -> print();

    cout << "Testing remove dick - already there - in the middle" << endl;
    if (!members -> remove(Profile("dick"))) cout << "Remove failed!" << endl;

    cout << "MyADT members. It has " << members -> getElementCount() << " elements." << endl;
    cout << "Here is what my MyADT members contains: ";
    members -> print();

    cout << "Testing remove quest - already there - last" << endl;
    if (!members -> remove(Profile("quest"))) cout << "Remove failed!" << endl;

    cout << "MyADT members. It has " << members -> getElementCount() << " elements." << endl;
    cout << "Here is what my MyADT members contains: ";
    members -> print();

    cout << "Testing remove aaaaa - already there - in the middle" << endl;
    if (!members -> remove(Profile("aaaaa"))) cout << "Remove failed!" << endl;

    cout << "MyADT members. It has " << members -> getElementCount() << " elements." << endl;
    cout << "Here is what my MyADT members contains: ";
    members -> print();

    cout << "Searching for qong" << endl;
    Profile * toBeRemoved = nullptr;
    toBeRemoved = members -> search(Profile("qong"));
    if (toBeRemoved == nullptr) {
        cout << "qong NOT found" << endl;
    } else {
        cout << "qong found" << endl;
    }

    cout << "Searching for quest" << endl;
    toBeRemoved = nullptr;
    toBeRemoved = members -> search(Profile("quest"));
    if (toBeRemoved == nullptr) {
        cout << "quest NOT found" << endl;
    } else {
        cout << "quest found" << endl;
    }

    MyADT * membersCopied = new MyADT(*members);

    cout << "MyADT members. It has " << members -> getElementCount() << " elements." << endl;
    cout << "Here is what my MyADT members contains: ";
    members -> print();

    cout << "members is at mem address: " << members << endl;
    cout << "&members is at mem address: " << &members << endl;

    cout << "MyADT membersCopied. It has " << membersCopied -> getElementCount() << endl;
    cout << "Here is what my MyADT membersCopied contains: ";
    membersCopied -> print();

    cout << "membersCopied is at mem address: " << membersCopied << endl;
    cout << "&membersCopied is at mem address: " << &membersCopied << endl;

    cout << "members -> removeAll()" << endl;
    members -> removeAll();

    cout << "membersCopied -> removeAll()" << endl;
    membersCopied -> removeAll();

    cout << "MyADT membersCopied. It has " << membersCopied -> getElementCount() << endl;
    cout << "Here is what my MyADT membersCopied contains: ";
    membersCopied -> print();

    cout << "delete membersCopied" << endl;
    delete membersCopied;
    membersCopied = nullptr;

    cout << "delete members" << endl;
    delete members;
    members = nullptr;

    return 0;
}