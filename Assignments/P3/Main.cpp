/*****************************************************************************
*                    
*  Author:           Ahmed krubally
*  Email:            Ahmedkrubally696@gmail.com
*  Label:            P03
*  Title:            Processing in Trie Tree Time
*  Description:
*     This program functions similarly to the one in P02 
for performing lookups, but with one key difference: instead of 
utilizing a linked list for storage and search, it stores the data 
in a Trie Tree, thereby enhancing the efficiency of finding matches. 
It accepts a JSON file of words along with their definitions and character 
by character, stores all the keywords in the Trie Tree. As the user enters characters, 
the program in real-time searches the Trie Tree for all the words that begin with the
 entered string. After three characters have been input, it displays the first ten matches
  along with the total number of matches found and the time taken by the program to complete 
  the search.
*    
*  Usage:
*    - Hit run
*    - enter a character (ONLY LETTER CHARACTERS!!)
*    - enter 3 characters and wait for program to display result of searc
* 
*  Files:           
*        TrieTrunk.hpp		:	 Singly Linked List header file
*        timer.hpp      :  timer header file
*        Getchfile.hpp    :  Getch header file
*        hellainfo.hpp       :  Json header file
*        main.cpp       :  main driver
*****************************************************************************/
// all header files
#include "TrieTrunk.hpp"
#include "hellainfo.hpp"
#include "Getchfile.hpp"
#include "timer.hpp"//stolen from Griffin
//all neccesary libraries 
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
// allows for the use of json 
using json = nlohmann::json;
/**
 * Convert_to_seconds
 * 
 * Description:
 *     This function converts nano seconds into seconds 
 * 
 * Params:
 *      int     seconds 
 * 
 * Returns:
 *     double  :   the result of the conversion 
*/
double Convert_to_seconds(int seconds) { return seconds * pow(10, -9); }
// Main Driver
int main() {

  Trie Words;         // intitializing Trie Tree 
  Timer T;            // declaring timer
  char k;             // the character enetered by the user
  string word = "";   // the srting created by the user
  int matches;        // the number of words that start with the user entered string
  int nano;           // the nano seconds it took to find the matches
  ifstream f("dict_w_defs.json"); // opening json file
  json data = json::parse(f);     // json variable to access all items in the json file

  // for loop to collect all words and store them into the Trie tree
  for (auto &word : data.items()) {
    Words.insert(word.key());
  }
  // prompting the user to enter a character
  cout << "Type the word you would like to search (letter by letter) the "
          "search begins after the first three charcters are entered. Type "
          "capital Z to quit."
       << endl;
  // getting the user endered character
  while ((k = getch()) != 'Z') {
    T.Start(); // starting timer
    if ((int)k == 127) {
      if (word.size() > 0) {
        word = word.substr(0, word.size() - 1);
      }
    } else {
      if (!isalpha(k)) {  // checking to make sure the user entered character is a letter
        cout << "Letter only!" << endl;
        continue;
      }
      if ((int)k < 97) {
        k += 32;
      }
      word += k; // joining the user entered character into a string
    }
    // displaying the user entered string 
    cout << termcolor::blue << word << termcolor::reset << endl << endl;
    if (word.length() >= 3) {
      // finding all the words that start with the word the user and displaying the first ten
      matches = Words.Matches(word); 
      T.End(); // ending timer
      nano = T.NanoSeconds(); // getting the timer results in nanoseconds
      cout << endl;
      // displaying the number of matches 
      cout << termcolor::yellow << matches << termcolor::reset;
      cout << " Matches Found in ";
      // displaying the time in seconds
      cout << termcolor::yellow << Convert_to_seconds(nano)
           << termcolor ::reset;
      cout << " Seconds." << endl << endl;
    }
  }
}