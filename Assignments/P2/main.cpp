/*****************************************************************************
*                    
*  Author:          ahmed krubally
*  Email:            ahmedkrubally696@gmail.com
*  Label:            P02
*  Title:            AutoComplete in Linear Time
*  Course:           CMPS 3013
* 
* 
*  Description:
*       Contained within this header file is a singly 
linked list that is designed to store strings. The purpose of 
this list is to hold all of the words found within a dictionary text 
file that contains over 100,000 words. It is capable of traversing through 
the list to retrieve the first ten words that begin with a 
specific substring passed into a function.
*****************************************************************************/
#include "Listowords.hpp"
#include "getchfile.hpp"
#include "termco.hpp"
#include "timer.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define RED termcolor::red
/**
 * LoadinWords
 * 
 * Description:
 *     This function will be used to fill a instance of the WordsLL
 *    linked list with all the words found in a file.
 * 
 * Parameters:
 *      N/A
 * 
 * Returns:
 *     WordsLL  
*/






WordsLL LoadinWords() {
  ifstream infile;
  WordsLL words;
  string word;
  infile.open("dictionary.txt");
  infile >> word; 
  while (!infile.eof()) {
    for (auto &c : word) {
      c = tolower(c);
    }
    words.Backsert(word);
    infile >> word;
  }
  for (auto &c : word) {
    c = tolower(c);
  }
  words.Backsert(word);
  return words;
}








/**
 * FindWords
 * 
 * Description:
 *     This function finds all words in a list that contains
 *    a substring and saves it to a new list and displays the first
 *    10 matches found
 * 
 * Parameters:
 *      WordsLL   WordList
 *      string    sub
 * 
 * Returns:
 *     WordsLL   
*/
WordsLL FindWords(WordsLL WordList, string sub) {
  WordsLL match; //list containing all matches 
  size_t found;  //position of substring in the word
  int count = 0; //count to find the first ten matches
  for (int i = 0; i < WordList.Getsize(); i++) {
    found = WordList[i].find(sub); //loactes position of substring in word
    if (found == 0) {
      match.Backsert(WordList[i]); //adds to the matches list
      if (count < 10) {
        // displaying the first 10 matches and highlighting the substring within the matched word
        for (int j = 0; j < WordList[i].length(); j++) {
          if(WordList[i][j] == sub[j]&&j<sub.length()){
            cout << termcolor::bright_red << WordList[i][j] << termcolor::reset;
          }else{
            cout << termcolor::red << WordList[i][j] << termcolor::reset;
          }
        }
        cout << " ";
        count++;
      }
    }
  }
  return match;
}






int main() {
  char k;  // character entered by user 
  string word = ""; // the substring being searched for
  WordsLL Words;  // Linked list containing all the words
  WordsLL Matches; // linked list containing matches 
  Timer T; // Timer variable to check how long a function takes to drun 
  double Seconds; // the time
  Words = LoadinWords();
  cout << "Type the word you would like to search (letter by letter) the search begins after the first three charcters are entered. Type capital Z to quit."
       << endl;


  while ((k = getch()) != 'Z') { // accepting user input
    T.Start();
    if ((int)k == 127) {
      if (word.size() > 0) {
        word = word.substr(0, word.size() - 1);
      }
    } else {
      if (!isalpha(k)) { // making sure the character entered is a letter
        cout << "Letter only!" << endl;
        continue;
      }
      if ((int)k < 97) {
        k += 32;
      }
      word += k; // putting all the user entered characters into a string
    }




    
    // displaying the user entered string 
    cout << termcolor::blue << word << termcolor::reset << endl << endl;
    if (word.length() >= 3) { //making sure the substring is atleast 3 characters long
      Matches = FindWords(Words, word); // finding and printing matches
      cout << endl << endl;
      T.End();
      // displaying total matches
      cout << termcolor::bright_yellow << Matches.Getsize() << termcolor::reset;
      cout << " Matches Found in ";
      // displaying the time it took to find all those matches 
      cout << termcolor::bright_yellow << T.Seconds() << termcolor::reset;
      cout << " Seconds";
      cout << endl << endl;
    }
  }
}