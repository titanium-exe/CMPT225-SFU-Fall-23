/*
 * Profile.h
 * 
 * Class Description: Models the profile of a user of the social network FriendsBook.
 *                    This profile contains the following characteristics:
 *                    userName, name (first and last name), email address and birthday.
 *       
 * Class Invariant: The "userName" of a user is a valid string (it is not an empty string).
 *                  and it starts with a letter (a to z or A to Z). 
 *                  This is to say that "userName" can be used as a unique identifier (i.e. a search key).
 *
 * Author: AL
 * Last modified: Sept. 2023
 */

#ifndef PROFILE_H
#define PROFILE_H

#include <string>

using std::string;
using std::ostream;


class Profile {
    
/* You cannot change this file, i.e., the definition of this Profile class. */
     
private:

    string userName;
    string name; 
    string email;
    string birthday;

    // Description: Sets the profile's userName - Private method
    // Reflection: Why is this method not part of the public interface?
    void setUserName(const string aUserName);
    
    
public:

    // Default Constructor
    // Description: Create a profile. 
    // Postcondition: userName, name, email and birthday set to "TBD".        
    Profile();

    // Parameterized Constructor
    // Description: Create a profile with the given userName.
    // Postcondition: If userName starts with a letter, then it is set to this given string.
    //                Otherwise, it is set to "TBD".
    //                All other member attributes are set to "TBD".
    Profile(string aUserName);
    
    // Parameterized Constructor
    // Description: Create a member with the given userName, name, email and birthday.
    // Postcondition: If aUserName is not valid, then it set to "TBD".
    Profile(string aUserName, string aName, string anEmail, string aBirthday);


    // Getters and setters
    
    // Description: Returns profile's userName.
    string getUserName() const;
    
    // Description: Returns profile's name.
    string getName() const;

    // Description: Returns profile's email.
    string getEmail() const;

    // Description: Returns profile's birthday.
    string getBirthday() const;

    // Utility methods
    // Description: Returns the uppercase version of the first letter of the userName.
    char getFirstLetter() const;

    // Description: Sets the profile's name.
    // Postcondition: name is set to aName. No need to validate aName.
    void setName(const string aName);

    // Description: Sets profile's email.
    // Postcondition: email is set to anEmail. No need to validate anEmail.
    void setEmail(const string anEmail);

    // Description: Sets the profile's birthday.    
    // Postcondition: birthday is set to aBirthday. No need to validate aBirthday.
    void setBirthday(const string aBirthday);


    // Overloaded Operators
    // Description: Comparison (equality) operator. Compares "this" Profile object with "rhs" Profile object.
    //              Returns true if both Profile objects have the same userName.
    bool operator==(const Profile & rhs);

    // Description: Greater than operator. Compares "this" Profile object with "rhs" Profile object.
    //              Returns true if the userName of "this" Profile object is > the userName of "rhs" 
    //              Profile object, i.e., the userName of "this" Profile object goes after 
    //              the userName of "rhs" Profile object when ordered in ascending alpha order.
    bool operator > (const Profile & rhs);

    // Description: Lesser than operator. Compares "this" Profile object with "rhs" Profile object.
    //              Returns true if the userName of "this" Profile object is < the userName of "rhs" 
    //              Profile object, i.e., the userName of "this" Profile object goes before 
    //              the userName of "rhs" Profile object when ordered in ascending alpha order.
    bool operator < (const Profile & rhs);

    
    // Description: Prints the content of "this" as follows:
    //              <userName>, <name>, <email>, <birthday>
    friend ostream & operator<<(ostream & os, const Profile & p);

};
// end of Profile.h
#endif