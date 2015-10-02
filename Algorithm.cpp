// COMP 215 Algorithm Lab4
// Developer: Shiwei Huang
// Purpose: File input output, operator overloading, class, dynamic array, pointers, selection sort, actual runtime check etc.
// Last edit: Oct1, 2015; 23:19PM;

#include <iostream>
#include <string>
#include <fstream>
#include <pthread.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

void generateFile ();

using namespace std;
//write a class interTriples that contains three public integers: value1, value2 and value3;
class interTriples {
public:

	int value1, value2, value3;
	//overload the operators ==, >, <, >= and <=;
	bool operator == ( interTriples point2 );
	bool operator > ( interTriples point2 );
	bool operator < ( interTriples point2 );
	bool operator <= ( interTriples point2 );
	bool operator >= ( interTriples point2 );
	interTriples(){}; //default contructor;
	//write a constructor for this classs that takes three integers, and give these integers to value1, value2 and value3 in the obvious way;
	interTriples ( int a, int b, int c ) { value1 = a; value2 = b; value3 = c; }; //the second constructor for interTriples;

};

	bool interTriples::operator== ( interTriples anotherPoint ) {
		if ( ( value1 == anotherPoint.value1 ) && ( value2 == anotherPoint.value2 ) && ( value3 == anotherPoint.value3 ) ) {
			return true;
		} else {
			return false;
		}

	}

	bool interTriples::operator > ( interTriples anotherPoint ) {
		if ( ( value1 > anotherPoint.value1 ) || 
		   ( ( value1 == anotherPoint.value1 ) && ( value2 > anotherPoint.value2 ) ) || 
		   ( ( value1 == anotherPoint.value1) && ( value2 == anotherPoint.value2 ) && ( value3 > anotherPoint.value3 ) ) ) {
			return true;
		} else {
			return false;
		}
	}

	bool interTriples::operator < ( interTriples anotherPoint ) {
		if ( ( value1 < anotherPoint.value1 ) || 
			 ( ( value1 == anotherPoint.value1 ) && ( value2 < anotherPoint.value2 ) ) || 
			 ( ( value1 == anotherPoint.value1) && ( value2 == anotherPoint.value2 ) && ( value3 < anotherPoint.value3 ) ) ) {
			return true;
		} else {
			return false;
		}
	}


	bool interTriples::operator <= ( interTriples anotherPoint ) {
		if ( ( value1 <= anotherPoint.value1 ) || 
		   ( ( value1 == anotherPoint.value1 ) && ( value2 <= anotherPoint.value2 ) ) || 
		   ( ( value1 == anotherPoint.value1) && ( value2 == anotherPoint.value2 ) && ( value3 <= anotherPoint.value3 ) ) || 
		   ( ( value1 == anotherPoint.value1 ) && ( value2 == anotherPoint.value2 ) && ( value3 == anotherPoint.value3 ) ) ) {
			return true;
		} else {
			return false;
		}
	}


	bool interTriples::operator >= ( interTriples anotherPoint ) {
		if ( ( value1 >= anotherPoint.value1 ) || 
		   ( ( value1 == anotherPoint.value1 ) && ( value2 >= anotherPoint.value2 ) ) || 
		   ( ( value1 == anotherPoint.value1) && ( value2 == anotherPoint.value2 ) && ( value3 >= anotherPoint.value3 ) ) || 
		   ( ( value1 == anotherPoint.value1 ) && ( value2 == anotherPoint.value2 ) && ( value3 == anotherPoint.value3 ) ) ) {
			return true;
		} else {
			return false;
		}
	}

//write a function generateFile that takes no input and returns no input;
//void generateFile() contains 10,000,000 lines, each containing three random integers;
//random numbers are generated using rand() function to generate 30,000,000 random numbers you will need for the file;
//write three random number per line and 10,000,000 lines;
void generateFile () {

	ofstream myFile;
	myFile.open ("InputNumbers.txt");
	
	int totalGenerateNumber = 10;

	for ( int i = 0; i < totalGenerateNumber; i++ ) {
	   	myFile << rand() << " " << rand() << " " << rand() << endl;
	}

	myFile.close();

}

//write a function readFile that takes an integer nbLines as input;
//allocates an array of interTriples of size nbLines;
//reads the first nbLines from InputNumbers.txt;
//puts them in the array and returns a pointer to that array;
//int nbLines is pass by value here;
interTriples* readFile ( int nbLines ) {
	interTriples *arrayPointer = new interTriples [nbLines]; //arrayPointer only exists in my readFile function; BUT THE ALLOCATED MEMORY EXIST FOREVER UNLESS YOU USED DELETE COMMEND;
	int valueOne, valueTwo, valueThree;
	ifstream file ("InputNumbers.txt");
	if ( file.is_open() ) {
		for ( int i = 0; i < nbLines; i++ ) {
			file >> valueOne >> valueTwo >> valueThree;
			interTriples somePoint ( valueOne, valueTwo, valueThree); //make interTriple somePoint in order to put three values under one point;
			arrayPointer[i] = somePoint;
		}
		/********************************* Beginning part of my test statement under readFile function *********************************/ 
		//in order to see the actual blub containing in my arrayPointer array;
		//this should print the 3 numbers, which is second line from my file "InputNumbers.txt";
		//cout << "test under readFile function:" << arrayPointer[1].value1 << " " << arrayPointer[1].value2 << " " << arrayPointer[1].value3 << endl;
		/********************************* End part of my test statement under readFile function *********************************/ 
	}
	else {
		cout << "Cannot location file." << endl;
	}

	return arrayPointer; //returns a pointer to that array;
}//readFile;


//Write a function findMax which, given an array (IN THE FORM OF A POINTER) WHICH IS PASS BY REFERENCE of interTriples
//findMax function return value: 
//1. returns the largest interTriples together with the INDEX of the largest interTriples;
//Note: since the function returns two outpus, INDEX of the largest interTriples is PASS BY REFERENCE
interTriples findMax ( interTriples *secondPointerToArray, int nbLines, int &indexOfMax ) { 
	interTriples maxSoFar = secondPointerToArray[0]; //maxSoFar is currently my first blub in my array;
	indexOfMax = 0;
	for ( int i = 1; i < nbLines; i++ ) { //comparing maxSoFar starting from the second element in my array;
		if ( maxSoFar < secondPointerToArray[i] ) {
			maxSoFar = secondPointerToArray[i];
			indexOfMax = i;
		}
	}
	return maxSoFar; //Return the largest point from interTriples class;
}


interTriples swap ( interTriples *fourthPointerToArray, int location1, int location2 ) {
	interTriples temp;
	temp = fourthPointerToArray[location1];
	fourthPointerToArray[location1] = fourthPointerToArray[location2];
	fourthPointerToArray[location2] = temp;
}

//write a function print which, give an array (IN THE FORM OF A POINTER) of interTriples and its size n;
//prints the content of the array on screen, one triple per line;
//this function should not return anything;
void print ( interTriples *thirdPointerToArray, int nbLines ) {
	for ( int i = 0; i < nbLines; i++ ) {
		cout << "(" << thirdPointerToArray[i].value1 << ", " << thirdPointerToArray[i].value2 << ", " << thirdPointerToArray[i].value3 << ")" << endl;
	}
}

//Write a function ourSort, which given an array (IN THE FORM OF A POINTER) of interTriples and its size nbLines
//This function sorts the values of the array as follows;
//This sort perform as selection sort which is similar function on the book p1189;
interTriples ourSort ( interTriples *sixthPointerToArray, int nbLines ) {
	int maxIndexSixthPointerToArray;
	// find the maximum element among all n elements of the array and its index i;
	// int maxIndexSixthPointerToArray should be the index number for the current maximum number;
	int loc;
	//first find the maximum element among all n elements of the array and its index i;
	//swap the ith and nth element of the array so that the maximum element of the array IS NOW AT THE END;
	//do this with the first (n-1) elements of the array and its index i;
	//swap the ith and (n-1)st element of the array so that the two maximum element of the array are now at the end;
	//continun the steps until all the way down to element 1; 
	for ( loc = nbLines; loc > 0; loc-- ) {
		findMax ( sixthPointerToArray, loc, maxIndexSixthPointerToArray);
		swap ( sixthPointerToArray, loc-1, maxIndexSixthPointerToArray ); //array[loc-1] would be the last element in the array;
	}
}

//ourSortTiming function is used to determine how long it takes to sort arrays of various sizes;
void ourSortTiming ( int size ) {
	
	interTriples *array; //declearing a pointer to the array called *array, IN THE FORM OF POINTER;
	//use the function readFile to get a pointer to an array of size interTriples; 
	array = readFile(size); //STORE THE POINTER OF ARRAY OF SIZE INTERTRIPLES TO *ARRAY VARIABLE;
	int startTime = clock(); //starts the clock;
	// cout << "testing before sort: " << startTime << endl;
	ourSort ( array, size ); //uses the function ourSort to sort the element of the array in increasing order;
	int endTime = clock(); //stops the clock;
	// cout << "testing after sort: " << endTime << endl;
	int difference = endTime - startTime; 
	cout  << "time difference: " << difference << endl; //prints on screen the number of clock ticks taken to sort the array;

	delete array; //delete the array of interTriples;
}




int main () {
	
    generateFile ();   
    cout << "Please tell me how many lines you want to have in your InputNumbers.dat file?" << endl;
    int nbLines;
    cin >> nbLines;
	//pointer to interTriple; //now it points to readFile function that has a return statement; return the array of intergertriples; 
    interTriples *arrayInMainLocation = readFile (nbLines);//readFile function returns a pointer to that array; I put the pointer store in the interTriples *array variable;
    
    int indexMax;//a placeholder to hold the max point;
    int indexMin;
    int indexMinTrial;

    interTriples maxPoint = findMax ( arrayInMainLocation, nbLines, indexMax ); //indexMax is pass by reference. However, the syntax in main is just index; while you are calling the function, you are saying &indexMax (which indicates pass by reference)
    
    cout << "********************************BEFORE SORT********************************" << endl;
    print ( arrayInMainLocation, nbLines );
    cout << " " << endl;
    cout << " " << endl;
    
    ourSort ( arrayInMainLocation, nbLines );
    cout << "********************************AFTER SORT********************************" << endl;

    print ( arrayInMainLocation, nbLines );
    ourSortTiming (nbLines);

}

	
