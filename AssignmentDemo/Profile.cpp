/*
 * Profile.cpp
 * 
 * Class Description: Models the profile of a user of the social network FriendsBook.
 *                    This profile contains the following characteristics:
 *                    userName, name (first and last name), email address and birthday.
 *       
 * Class Invariant: The "userName" of a user is a valid string (it is not an empty string)
 *                  and it starts with a letter (a to z or A to Z). 
 *                  This is to say that "userName" can be used as a unique identifier (i.e. a search key).
 *
 * Author: AL
 * Last modified: Sept. 2023
 */

#include <iostream>
#include <string>
#include <locale>         // std::locale, std::isalpha
#include "Profile.h"

using std::cout;
using std::endl;
using std::locale;
using std::ostream;


// Default Constructor
// Description: Create a profile. 
// Postcondition: userName, name, email and birthday set to "TBD".        
Profile::Profile() : userName("TBD"), name("TBD"), email("TBD"), birthday("TBD") {

   //cout << "Profile::default constructor" << endl;   // For testing purposes ... and curiosity
               
}

// Parameterized Constructor
// Description: Create a profile with the given userName.
// Postcondition: If userName starts with a letter, then it is set to this given string.
//                Otherwise, it is set to "TBD".
//                All other member attributes are set to "TBD".           
Profile::Profile(string aUserName) : name("TBD"), email("TBD"), birthday("TBD") {

    this->setUserName(aUserName); 
               
}

// Parameterized Constructor
// Description: Create a member with the given userName, name, email and birthday.
// Postcondition: If aUserName is not valid, then it set to "TBD".
Profile::Profile(string aUserName, string aName, string anEmail, string aBirthday) : 
                 name(aName), email(anEmail), birthday(aBirthday) {
    this->setUserName(aUserName);                 
}    
    
// Getters and setters
// Description: Returns profile's userName.
string Profile::getUserName() const {
    return userName;
}
    
// Description: Returns profile's name.
string Profile::getName() const {
    return name;
}

// Description: Returns profile's email.
string Profile::getEmail() const {
    return email;
}

// Description: Returns profile's birthday.
string Profile::getBirthday() const {
    return birthday;
}

// Utility methods
// Description: Returns the uppercase version of the first letter of the userName.
char Profile::getFirstLetter( ) const {

    // Make sure we consider the UPPER case version of the first letter of the userName.
    return toupper(this->getUserName()[0]);
    
} // end getFirstLetter

 
// Description: Sets the profile's userName.
// Postcondition: userName is set to aUserName if aUserName 
//                is valid, otherwise it is set to "TBD".
void Profile::setUserName(const string aUserName) {
    locale loc;
    if ( !aUserName.empty() && (isalpha(aUserName[0], loc) ) )
        userName.assign(aUserName);
    else
        userName.assign("TBD");                   
}

// Description: Sets the profile's name.
// Postcondition: name is set to aName. No need to validate aName.
void Profile::setName(const string aName) {
    name.assign(aName);
}

// Description: Sets the profile's email.
// Postcondition: email is set to anEmail. No need to validate anEmail.
void Profile::setEmail(const string anEmail) {
    email.assign(anEmail);
}

// Description: Sets the profile's birthday.
// Postcondition: birthday is set to aBirthday. No need to validate aBirthday.
void Profile::setBirthday(const string aBirthday) {
    birthday.assign(aBirthday);
}

// Overloaded Operators
// Description: Comparison (equality) operator. Compares "this" Profile object with "rhs" Profile object.
//              Returns true if both Profile objects have the same userName.
bool Profile::operator==(const Profile & rhs) {
    
    // Compare both Profile objects
    return ( this->userName == rhs.getUserName() ); 

} // end of operator==


// Description: Greater than operator. Compares "this" Profile object with "rhs" Profile object.
//              Returns true if the userName of "this" Profile object is > the userName of "rhs" 
//              Profile object, i.e., the userName of "this" Profile object goes after 
//              the userName of "rhs" Profile object when ordered in ascending alpha order.
bool Profile::operator > (const Profile & rhs) {

   return ( this->userName > rhs.getUserName() ); 
} 

// Description: Lesser than operator. Compares "this" Profile object with "rhs" Profile object.
//              Returns true if the userName of "this" Profile object is < the userName of "rhs" 
//              Profile object, i.e., the userName of "this" Profile object goes before 
//              the userName of "rhs" Profile object when ordered in ascending alpha order.
bool Profile::operator < (const Profile & rhs) {
    
   return ( this->userName < rhs.getUserName() ); 
} 


// Description: Prints the content of "this" as follows:
//              <userName>, <name>, <email>, <birthday>
ostream & operator<<(ostream & os, const Profile & p) {

    os << p.userName << ", " << p.name << ", " << p.email << " born on " << p.birthday << endl;    
    return os;
    
} // end of operator<<

// end of Profile.cpp