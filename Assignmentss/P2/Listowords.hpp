/*****************************************************************************
*                    
*  Author:          ahmed krubally

*  Email:           ahmedkrubally696@gmail.com
*  Label:            P02
*  Title:            AutoComplete in Linear Time
*  Course:           CMPS 3013
* 
*  Description:
 Within this header file, there is a Singly Linked
 List that can store strings. Its purpose is to hold all the 
 words extracted from a dictionary text file that contains over 100,000 
 words. This list has the ability to traverse through its contents and 
 display the first ten words that begin with a specified substring,
  passed in as a parameter to a function.ii
*********************************/
#pragma once
// neccessary Libraries
#include <iostream>
#include <string>
#include "termco.hpp"      //used to display colors
using namespace std;
/**
 * WordNode
 * 
 * Description:
 *      Node used to store the words from the dictionary into
 * 		the singly linked list
 * 
 * Public Methods:
 *            WordNode(string data)  // overloaded constructor
 * 
 * Private Methods:
 *    
 *       N/A
 * 
 * Usage: 
 * 
 *     WordNode *temp = new Node(d) //creates and initilizes a new node 
 *      
 */
struct WordNode {
	string word;
	WordNode* next;
/**
 * Public: WordNode
 * 
 * Description:
 *     Constructor that recieves a string creates a new node 
 * 
 * Params:
 *      string	data
 * 
 * Returns:
 *      N/A
*/
	WordNode(string data) {
		next = nullptr;
		word = data;
	}
};
/**
 * WordsLL
 * 
 * Description:
 *      This is a Singly Linked List that will store a list of words that will be 
 * 		passed in from a file. This linked list will allow the user to print all the 
 * 		words stored in the list, remove words from the list, access data through
 * 		the use of indexes and display the first ten words in the list that begins with
 * 		a passed in substring.
 * 
 * Public Methods:   
 * 					WordsLL()
 * 		void		Print()
 * 		void		Backsert(string word)
 * 		void		Remove(string data)
 * 		int 		GetSize();
 * 		string&		operator[](int index)
 * 		void		Print_top_ten(string sub)
 * 
 * Private Methods:
 *      WordNode*	head;
 * 		WordNode*	tail;
 * 		int 		size = 0;
 * 
 * Usage: 
 * 
 *      WordsLL	List1;		//create instance of list
 * 		List1.Backsert("Alleyway");		//Insert word into list
 * 		List1.Backsert("Ally");
 * 		List1.Remove("Alleyway");  // removes alleyway from the list
 * 		List1.Print();		//prints the entire list
 * 		cout << List1[0];	//displays the first item in the list
 * 		int size = List1.Getsize();	//gets the size if the list
 * 
 *      
 */
class WordsLL {
private:
	WordNode* head;		//the head of the list
	WordNode* tail;		//the tail of the list
	int size = 0;		//the amount of items in the list
public:
/**
 * Public: WordsLL
 * 
 * Description:
 *     Default constructor that sets head and tail nodes to NULL 
 * 
 * Params:
 *      N/A
 * 
 * Returns:
 *      N/A
*/
	WordsLL() {
		head = nullptr;
		tail = nullptr;
	}
/**
 * Public: Print
 * 
 * Description:
 *     Displays all words stored in the list
 * 
 * Params:
 *      N/A
 * 
 * Returns:
 *      N/A
*/
void Print() {
	WordNode* traverse = head; // starting traverse at the head of the list
    int count = 1; // the know the items positon in the list
		while (traverse) {
			cout << count << ": " << traverse->word << endl;
      		count++;
			traverse = traverse->next;
		}
	}
/**
 * Public: Backsert
 * 
 * Description:
 *     This method inserts word into the back of the linked list 
 * 
 * Params:
 *      string 		word
 * 
 * Returns:
 *      N/A
*/
	void Backsert(string word) {
		WordNode* temp = new WordNode(word); // creating new node with word
		if (head == nullptr) {
			head = temp;
			tail = temp;
			size++;  // incrementing count
		}
		else {
			tail->next = temp;
			tail = temp;
			temp->next = nullptr;
			size++; //incrementing count
		}
	}
/**
 * Public: Remove
 * 
 * Description:
 *     This method will remove a passed word from the linked list
 * 
 * Params:
 *      string 		word
 * 
 * Returns:
 *      N/A
*/
	void Remove(string word) {
		if (head->word == word) {
			WordNode* temp = head;
			head = head->next;
			delete temp;
		}
		else if (tail->word == word) {
			WordNode* traverse = head;  //setting traverse node as the head of list
			while (traverse->next->next != nullptr) {
				traverse = traverse->next;
			}
			WordNode* temp = tail; // temperary node pointing to tail of list
			tail = traverse;
			tail->next = nullptr;
			delete temp;
		}
		else {
			WordNode* traverse = head;
			while (traverse->next->word != word && traverse->next != nullptr) {
				traverse = traverse->next;
			}
			WordNode* temp = traverse->next;
			traverse->next = traverse->next->next;
			delete temp;
		}
	}
/**
 * Public: Getsize
 * 
 * Description:
 *     This method will return the number of items stored in the list
 * 
 * Params:
 *      N/A
 * 
 * Returns:
 *      int		: 	the number of items in the list 
*/
  int Getsize(){
    return size;
  }
/**
 * Public: operator[]
 * 
 * Description:
 *     overloaded operator that allows you to access data stored in the 
 * 		list using indexing similar to an array 
 * 
 * Params:
 *      int 	index
 * 
 * Returns:
 *      string&		: 	The address of where the string is stored  
*/
string& operator[](int index){
  WordNode* traverse = head; // pointer pointing to head of the list
  if(index > Getsize()){
    cout << "invalid index";
    return;
  }
  else{
    for(int i = 0; i!=index;i++){
      traverse = traverse->next;
    }
    return traverse->word;
  }
}
};