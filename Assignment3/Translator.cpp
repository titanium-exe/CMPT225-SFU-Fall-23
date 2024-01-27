/*
 * Translator.cpp 
 * 
 * Description: It is a use case of Dictionary class. It makes Dictionary class's 
 * object and make it do all file reading, insertions and retrieving the words.
 * It is basically a test driver for Dictionary.cpp and BST.cpp
 * 
 * Author: EKAMLEEN MAAN and  TANVIR SAMRA 
 * Date of last modification: November 2, 2023
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BST.h"
#include "WordPair.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"
#include "Dictionary.h"

using std::cin;
using std::cout;
using std::ifstream;

void display(WordPair& anElement) {
  cout << anElement;
} 

int main(int argc, char *argv[]) { //The beginning of the code is from the Prof's BSTTestDriver (to read from a file)
    Dictionary* testTranslator = new Dictionary();
      
    string aLine = "";
    string aWord = "";
    string englishW = "";
    string translationW = "";
    string filename = "myDataFile.txt";
    string delimiter = ":";
    size_t pos = 0;
    WordPair translated;
    
    ifstream myfile(filename);
    if (myfile.is_open()) {
        cout << "Reading from a file:" << endl;
        while (getline(myfile, aLine)) {
            pos = aLine.find(delimiter);
            englishW = aLine.substr(0, pos);
            aLine.erase(0, pos + delimiter.length());
            translationW = aLine;
            WordPair aWordPair(englishW, translationW); //makes the wordPair object once words have been read from file
            try {
                testTranslator->put(aWordPair); //uses the put function to insert wordPair into the tree
            } catch (const ElementAlreadyExistsException &e) { //if the wordpair already exists, then throw an exception
                cout << "Element already exists: " << endl;
            }
        }
        myfile.close();

        if ((argc > 1) && (strcmp(argv[1], "display") == 0)) {
            testTranslator->displayContent(display);
        }
        else {
            // Prompt user for input and translate continuously until Ctrl+D is entered.
            cout << "Enter a word to translate (Ctrl+D to exit):" << endl;
            while (getline(cin, aWord)) {
                WordPair aWordPair(aWord);
                try {
                    WordPair &translation = testTranslator->get(aWordPair); //gets the WordPair using the get function (Throws exceptions for the following cases below)
                    cout << "Translation: " << translation << endl;
                } catch (const ElementDoesNotExistException &e) {
                    cout << "Translation not found." << endl;
                } catch (const EmptyDataCollectionException &e) {
                    cout << "Dictionary is empty." << endl;
                }
                cout << "Enter a word to translate (Ctrl+D to exit):" << endl;
            }
        }
    }
    else {
        cout << "Unable to open file";
    }

    delete testTranslator; //delete the object
    return 0;
}
