/*
 * FriendsBook.cpp - Assignment 1
 * 
 * Class Description: Social network application (partial implementation).
 *
 * In this version, we use our MyADT.
 *
 * ***You cannot remove/change the code provided in this file.***
 *
 * Author: Ekamleen Maan 
 * Modified on: Sept 29, 2023
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Profile.h"
#include "MyADT.h"

using std::cout;
using std::ws;
using std::cin;
using std::endl;


void join(MyADT & theMembers) {

   string username, name,email, birthday;
   cout<<"please enter a username: \n";   // Asking for username of the person 
   cin>>username;
   cin.ignore();
   cout<<"please enter a name: \n";
   getline(cin, name);
  
   cout<<"please enter a email: \n";
   cin>>email;
   cin.ignore();
   cout<<"please enter a birthday: \n";
   getline(cin, birthday);
  
   Profile newUser(username,name, email, birthday);  //making a profile object.
   if(theMembers.insert(newUser)){     //if .insert method returns true profile is added to the letter specific array
         cout<<"You Joined the App"<<endl; 
   }else{
      cout<<"you couldn't join"<<endl;  // if it method returns nullptr ; Profile can't join hte array
   }
}

void leave(MyADT & theMembers) {
   string username;
   cout<<"please enter a username"<<endl;
   cin>>username;
   Profile leaver(username);    // leaver: profile that is is removed
   if(theMembers.remove(leaver)){
      cout<<"You Left :("<<endl;
   }
   else{
      cout<<"you haven't left yet! "<<endl;
   }
}

void search(MyADT & theMembers) {
   string username;
   cout<<"please enter a username: ";
   cin >> ws;
   getline(cin, username);
   const Profile searchUser(username);   //made a profile using username via the constructor in profile.h
   Profile* temp = theMembers.search(searchUser);  //temp takes the address returned by the search method
   
   
   if(temp != nullptr){
      cout<<"Profile exists. "<<endl;  
       
   }
   else{
      cout<<"Profile not found! "<<endl;
      
   }
}

void modify(MyADT & theMembers) {

   string username ,name,email,birthday;
   cout<<"please enter a username: ";
   cin>>username;
   char select;

   Profile modifyObj(username);
   Profile* temp = theMembers.search(modifyObj);
   if(temp == nullptr){ // if the profile is not returned by search function then person wont be able to modify
      cout<<"profile not found"<<endl;   
      
   }else{
   cout<<"Select 'n' to modify name"<<endl;
   cout<<"Select 'e' to modify email"<<endl;
   cout<<"Select 'b' to modify birthday"<<endl;
   cin>>select;
   cin.ignore();
   if(select == 'n'){
      cout<<"please enter new name: \n";
      getline(cin,name);
      temp->setName(name);
   }
   else if(select == 'e'){
      cout<<"please enter new email: "<<endl;
      cin>>email;
      temp->setEmail(email);
   }
   else if(select == 'b'){
      cout<<"please enter new birthday: "<<endl;
      getline(cin,birthday);
      temp->setBirthday(birthday);
   }
   else{
      cout<<"You can't modify this profile"<<endl;
   }
   }
}

void print(MyADT & theMembers) {
   if(theMembers.getElementCount() == 0){   //if there are no elements in arrays.
      cout<<"the app doesn't have any users right now :("<<endl;
   }
   theMembers.print();
}

int main() {

    // Variables declaration
    MyADT members = MyADT();  // Object MyADT on the stack, its arrays on the heap
    bool done = false;
    char input = 0;
        
    // Keep going until the user exits
    while (not done) {
        // Print menu to stdout
        cout << "\n----Welcome to FriendsBook!" << endl << endl;
        cout << endl << "Enter ..." << endl;
        cout << "j -> to join FriendsBook by Put your code here by creating a profile." << endl;
        cout << "l -> to leave FriendsBook." << endl;
        cout << "s -> to search for a friend on FriendsBook." << endl;
        cout << "m -> to modify your profile on FriendsBook." << endl;
        cout << "p -> to print all members on FriendsBook." << endl;
        cout << "x -> to exit FriendsBook." << endl << endl;


        cout << "Your choice: ";
        cin >> input;
        cout << endl;
        input = tolower(input);
        switch(input) {
            case 'j': join(members); break;
            case 'l': leave(members); break;
            case 's': search(members); break;
            case 'm': modify(members); break;
            case 'p': print(members); break;
            case 'x': cout << "\n----Bye!\n" << endl; 
                      done = true; break;
            default: cout << "Not sure what you mean! Please, try again!" << endl;
        }
    }

    return 0;
}
