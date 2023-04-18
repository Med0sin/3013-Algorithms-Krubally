
/*****************************************************************************
*                    
*  Author:           Ahmed krubally
*  Email:            Ahmedkrubally696@gmail.com 
*  Title:            Circular Array

* 
*  Description:
*        The program incorporates a class that enables the creation
 of a circular array, which facilitates the addition and removal of 
 values from the list via the pop and push methods. However, if the 
 array is at full capacity, then it becomes impossible to add any more values.
*
*  Usage:
*        all the usage is within main.
* 
*  Files:           
        main.cpp
*****************************************************************************/


#include <iostream>

using namespace std;


/**
 * CircularArrayQue
 * 
 * Description:
 *      This class implements a circular array queue, which can 
 *      used to hold integers and is able to add/remove values.
 * 
 * Public Methods:
 *                  CircularArrayQue()
 *                  CircularArrayQue(int size)
 *     void         Push(int item)
 *     int          Pop()
 *     
 * Private Methods:
 *     void         init(int size = 0)
 *     bool         Full()
 * 
 * Usage:
 * 
 * CircularArrayQue C(size)                 // Create instance of CircularArrayQue
 *                                             and assign size based on input
 * 
 * Push(item)                               // Add an item to the array by taking
 *                                             in an item input
 * 
 *Pop()                                     // Remove an item from the Head of the
 *                                             list
 */

class CircularArrayQue {
private:
    int *Container;                        // Pointer to allocate array
    int Head;                             // Head of the Array
    int back;                              // Back of the Array
    int QueSize;                           // items in the queue
    int CurrentSize;                       // The current size of the array

/**
 *
 * Private : init
 * 
 * Description:
 *      Initializes the Head, back, and current to 0,
 *      and then sets the QueSize equal to the input integer
 * 
 * parameters:
 *      int     : size of the array
 * 
 * Returns:
 *      void    : there is no return type
 *
 */


    void init(int size = 0) {
        Head = back = CurrentSize = 0;
        QueSize = size;
    }


    /**
 *
 * Private : Full
 * 
 * Description:
 *      Determines whether the array is full and then
 *      return either true or false
 * 
 * parameters:
 *      no parameters
 * 
 * Returns:
 *      bool    : return true if full, otherwise return false
 *
 */

    bool Full() {
        return CurrentSize == QueSize;
    }


public:

/**
 *
 * Public : CircularArrayQue
 * 
 * Description:
 *      constructor method made to initialize an instance of
 *      CircularArrayQue, used when no size is given, defaulting
 *      to an array with an index of 10
 * 
 * parameters:
 *      no parameters
 * 
 * Returns:
 *      no returns
 *
 */

    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }

/**
 *
 * Public : CircularArrayQue
 * 
 * Description:
 *      constructor method made to initialize an instance of
 *      CircularArrayQue, making the size equal to the input size
 * 
 * parameters:
 *      int     : size of the array
 * 
 * Returns:
 *      void    : there is no return type
 *
 */

    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

/**
 *
 * Public : Push
 * 
 * Description:
 *      Add an item to the array, checking 
 *      if it is full beforehand
 * 
 * parameters:
 *      int     : item to be add to the array
 * 
 * Returns:
 *      void    : there is no return type
 *
 */

    void Push(int item) {
        if (!Full()) {                      // Array is not full
            Container[back] = item;
            back = (back + 1) % QueSize;
            CurrentSize++;
        } else {                            // Array is full
            cout << "FULL!!!!" << endl;
        }
    }

/**
 *
 * Public : Pop
 * 
 * Description:
 *        Remove an item from the array, making it shorter
 * 
 * 
 * parameters:
 *      no parameters
 * 
 * Returns:
 *      int     : returns removed item
 *
 */

    int Pop() {
        int temp = Container[Head];
        Head = (Head + 1) % QueSize;
        CurrentSize--;                  //Reduce size of Array
        return temp;
    }

    //ostream function, made friends with the CircularArrayQue class
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

/**
 *
 * Public : &operator
 * 
 * Description:
 *      ostream overloaded to allow for cout to be used to print class instance
 * 
 * parameters:
 *      ostream               : output stream to facilitate cout printing
 *      CircularArrayQue      : class instance to print out
 * 
 * Returns:
 *      void    : there is no return type
 *
 */

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Head; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";                     // print out each item in array
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}