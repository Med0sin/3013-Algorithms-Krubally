/*****************************************************************************
*                    
*  Author:           Ahmed krubally
*  Email:            Ahmedkrubally696@gmail.com
*  Label:            P01
*  Title:            Database Indexes
*  Course:           CMPS 3013
* 
*  Description:
*        The purpose of this software is to analyze the performance
of two distinct data structures. The program includes a database 
consisting of eight AVL trees that are optimized for searching various 
types of data, as well as a Singly Linked List. By searching through the 
database and the list, the program measures the duration it takes to complete
 each search and outputs the results on the screen. All data used in this program is 
 extracted from a Json file that contains 100,000 data points.
*  Usage:
*       - create vector with data
*		- fill Linked LList with data
*		- Fill Database
* 		- Search for data in Linked List
*		- Display time that it took
*		
*  Files:           
*        Database.hpp             
*		 Json.hpp		  		   
*		 SLList.hpp		  	   
*		 Timer.hpp		  
*		 Source.cpp		  
*		random_person_data_01
*****************************************************************************/
//neccesary Libraries
#include "Database.hpp"
#include "json.hpp";
#include "SLList.hpp"
#include "Timer.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
// using namespace standard
using namespace std;
// needed to access json files
using json = nlohmann::json;
/**
 * Loaddata
 * Description:
 * 		Used to load data from json file to a vector
 *
 * Parameter
 * 		json	filea
 * 		vector	<jsondata>&data
 * 
 * Return
 * 		N/A
 */
void Loaddata(json filea, vector <jsondata>& data) {
	jsondata temp;
	for (int i = 0; i < 100000; i++) {
		temp.id = filea[i]["id"];
		temp.first_name = filea[i]["first_name"];
		temp.last_name = filea[i]["last_name"];
		temp.email = filea[i]["email"];
		temp.address = filea[i]["address"];
		temp.city = filea[i]["city"];
		temp.state = filea[i]["state"];
		temp.latitude = filea[i]["latitude"];
		temp.longitude = filea[i]["longitude"];
		temp.car = filea[i]["car"];
		temp.car_model = filea[i]["car_model"];
		temp.car_color = filea[i]["car_color"];
		temp.favorite_movie = filea[i]["favorite_movie"];
		temp.pet = filea[i]["pet"];
		temp.job_title = filea[i]["job_title"];
		temp.phone_number = filea[i]["phone_number"];
		temp.stocks.push_back(filea[i]["stocks"]["stock1"]);
		temp.stocks.push_back(filea[i]["stocks"]["stock2"]);
		temp.stocks.push_back(filea[i]["stocks"]["stock3"]);
		temp.stocks.push_back(filea[i]["stocks"]["stock4"]);
		temp.stocks.push_back(filea[i]["stocks"]["stock5"]);
		temp.stocks.push_back(filea[i]["stocks"]["stock6"]);
		temp.stocks.push_back(filea[i]["stocks"]["stock7"]);
		data.push_back(temp);
		temp.stocks.clear();

	}
}
int main() {
	Timer T;    								//timer variable
	double seconds; 							 // used to store the seconds from the timer variable
	long Milliseconds; 							 // used to store the millisecond the timet variable
	vector <jsondata> data; 					 // vector storing data from json file
	ifstream A("random_person_data_01.json"); 	// accessing json file
	json filea = json::parse(A);				
	Loaddata(filea, data);						// loading data to the vector
	cout << "completed task: Loading to vector" << endl;
	LList SLL;
	for (int i = 0; i < data.size(); i++) {      //filing the singly linked list with data
		SLL.Insert(data[i]);
	}
	cout << "completed task,  filling Linked List " << endl;
	Database Dbase(data);   					// filing database
	cout << "completed task,  filling Database (AVL trees) " << endl;
	bool Located ;
	cout << endl;

	/**
	 * Searching for ID# in the database and Linked list and 
	 * timing how long it takes to find these data
	 * 
	 */
	T.Start();
	Located  = Dbase.FindID(72532);
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (Located ) {
		cout << "Located  the ID#: 678475 after checking " << Dbase.GetIDnodes() << "in AVL tree " << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not Located ";
		cout << endl;
		cout << endl;
	}
	T.Start();
	Located  = SLL.FindallID(72532);
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (Located ) {
		cout << "Located  the ID#: 678475 after checking " << SLL.GetNodesChecked() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not Located ";
		cout << endl;
		cout << endl;
	}
	/**
	 * Searching for First Name in the database and Linked list and 
	 * timing how long it takes to find these data
	 * 
	 */
	T.Start();
	Located  = Dbase.FindFN("Matt");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (Located ) {
		cout << "Located  the First name: Matt after checking " << Dbase.GetFNnodes() << "in AVL tree " << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not Located ";
	}
	T.Start();
	Located  = SLL.FindallFN("Matt");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (Located ) {
		cout << "Located  the First name Matt after checking " << SLL.GetNodesChecked() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not Located ";
		cout << endl;
		cout << endl;
	}
/**
	 * Searching for Last Name in the database and Linked list and 
	 * timing how long it takes to find these data
	 * 
	 */
	T.Start();
	Located  = Dbase.FindLN("Daimon");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (Located ) {
		cout << "Success! Located  the Last name: Daimon after checking " << Dbase.GetLNnodes() << "in AVL tree " << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not Located ";
	}
	T.Start();
	Located  = SLL.FindallLN("Daimon");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (Located ) {
		cout << "Success! Located  the Last name: Daimon after checking " << SLL.GetNodesChecked() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not Located ";
		cout << endl;
		cout << endl;
	}
/**
* Searching for Email in the database and Linked list and 
* timing how long it takes to find these data
* 
*/
	T.Start();
	Located  = Dbase.FindEM("Raginaestrda@filgy.com");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (Located ) {
		cout << "Located  the Email: Raginaestrda@filgy.com after checking " << Dbase.GetEMnodes() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not Located ";
	}
	T.Start();
	Located  = SLL.FindallEM("Raginaestrda@filgy.com");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (Located ) {
		cout << "Located  the Email: Raginaestrda@filgy.com after checking " << SLL.GetNodesChecked() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not Located ";
		cout << endl;
		cout << endl;
	}
/**
* Searching for Phone Number in the database and Linked list and 
* timing how long it takes to find these data
* 
*/
	T.Start();
	Located  = Dbase.FindPH("(590) 2345739");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (Located ) {
		cout << "Located  the Phone Number: (590) 2345739 after checking " << Dbase.GetPHnodes() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not Located ";
	}
	T.Start();
	Located  = SLL.FindallPH("(590) 2345739");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (Located ) {
		cout << "Located  the Phone Number: (590) 2345739 after checking " << SLL.GetNodesChecked() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not Located ";
		cout << endl;
		cout << endl;
	}
/**
* Searching for Address in the database and Linked list and 
* timing how long it takes to find these data
* 
*/
	T.Start();
	Located  = Dbase.FindAD("43 shadowbrook trail");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (Located ) {
		cout << "Located  the Address: 43 shadowbrook trail after checking " << Dbase.GetADnodes() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not Located ";
	}
	T.Start();
	Located  = SLL.FindallAD("43 shadowbrook trail");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (Located ) {
		cout << "Located  the Address: 43 shadowbrook trail after checking " << SLL.GetNodesChecked() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not Located ";
		cout << endl;
		cout << endl;
	}
/**
* Searching for Job Tittle in the database and Linked list and 
* timing how long it takes to find these data
* 
*/
	T.Start();
	Located  = Dbase.FindJT("senior QA II");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (Located ) {
		cout << "Located  the Job Title: senior QA II after checking " << Dbase.GetJTnodes() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not Located ";
	}
	T.Start();
	Located  = SLL.FindallJT("senior QA II");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (Located ) {
		cout << "Located  the Job Title: senior QA II checking " << SLL.GetNodesChecked() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not Located ";
		cout << endl;
		cout << endl;
	}
	T.Start();
	Located  = Dbase.FindCM("Bentley coop");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (Located ) {
		cout << "Located  the Car Model: Bentley coop after checking " << Dbase.GetCMnodes() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not Located ";
	}
/**
* Searching for Car Model in the database and Linked list and 
* timing how long it takes to find these data
* 
*/
	T.Start();
	Located  = SLL.FindallCM("Bentley coop");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (Located ) {
		cout << "Located  the Car Model: Bentley coop checking " << SLL.GetNodesChecked() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not Located ";
		cout << endl;
		cout << endl;
	}
}