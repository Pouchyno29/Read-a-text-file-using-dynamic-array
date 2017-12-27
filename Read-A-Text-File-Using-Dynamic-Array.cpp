/**
   Programmer's name    : Stanley
   Class                : BCS 230 Foundations of Computer Programming II
   Date                 : 11/17/2017
   Lab                  : Lab 11 Assignment
   Professor's name     : Moaath Alrajab
   Software uses        : Code:blocks
**/

/**
    Download the attached datafile.txt. Read the file and then create a
    dynamic array that stores its elements.
    Your code should use pointers. Find the sum and the average of all numbers.

**/

#include <iostream>
#include <fstream>
#include <string>
int getNumberOfLine();
void getNumbers(double *myList, int &size);
void printList(double *myList, int size);
double *calculateAverage(double *myList, int size);
using namespace std;

int main()
{
    // Allocate a memory for an integer variable
    int *size = new int;

    // Get the number of line from the file and save it to that memory that was allocate
    *size = getNumberOfLine();

    // Allocate a block of memory of type double
    double *myList;

    // specifies the size of that block of memory
    myList = new double[*size];

    // Retrieve all the numbers from the file and save them in the block of memory
    getNumbers(myList, *size);

    // Print out all the numbers from the file
    printList(myList, *size);

    // Pointer initialized with NULL
    double *average = NULL;

    // Request memory for that variable
    average = new double;

    // Return the address of the average from the function
    average = calculateAverage(myList, *size);

    // Print out the sum of the numbers
    // And use pointer dereference to print out the average of the numbers
    cout << "The average"<< string(6, ' ')<<":" << *average << endl;

    delete size;
    delete average;
    delete[] myList;
    size = NULL;
    average = NULL;
    myList = NULL;

    return 0;
}

// This function is to get the numbers of lines from the file
// Therefore, the numbers of line will determine how many numbers
// That will be sum up to calculate the average.
// I know the is a different way to accomplish this task which is faster and better
// Using tellg() function from the fstream library, but i still prefer to do it
// The manual way.
int getNumberOfLine(){

    ifstream myFile;
    // Variable to save the number of line
    int numberOfLine = 0;
    myFile.open("dataFile.txt");
    // If the file is opened
    if(myFile.is_open()){
        // Variable to read each line from the file
        string line;
        while( getline(myFile, line)){ numberOfLine++; }
        // Close the file when we reach the end of the file or if there is no more lines to read.
        myFile.close();
    }else{
        cout << "The file cant be opened!!!" << endl;
    }

    // Return the number of line found
    return numberOfLine;

}

// This function will save all the numbers from the file to the pointer
// and save and return the new size of the pointer
void getNumbers(double *myList, int &size){

    ifstream myFile;

    myFile.open("dataFile.txt");

    //If the file is opened
    if(myFile.is_open()){

        size = 0;
        // Read until the end of the file
        while( !myFile.eof()){
            // Save each number to one slot on the block memory
            myFile >> *(myList + size);
            // Print each number that are found
            //cout << size << " - " << *(myList + size) << endl;
            // Add one to the size
            size++;
        }
        //Close the file when we reach the end of the file or if there is no more lines.
        myFile.close();

    }else{
        cout << "The file cant be opened!!!" << endl;
    }
}

// This function will print out the array
void printList(double *myList, int size){
    cout << "The numbers from the file" << endl;
    cout << "=========================" << endl;
    for(int index = 0; index < size; index++){
        cout << string(20, ' ')/*<< "\t"*/ << *(myList + index) << endl;
    }
}

// return a pointer from a function
double *calculateAverage(double *myList, int size){

    double *sum = NULL;
    sum = new double;
    //double sum = 0.0;
    for(int index = 0; index < size; index++){
          *sum += *(myList + index);
         //cout << "Sum = " << sum << endl;
    }
    cout << "=========================" << endl;
    cout << "The sum"<< string(10, ' ')<<":" <<  *sum << endl;

    // set the floating point precision of the output to two decimal places
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);

     double *ave = new double;
     *ave = (*sum/size);

 return ave;
}
