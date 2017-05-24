/***************************************************************************
 * File: String.cpp
 * Author: Jeffrey Cocklin
 * Function: Creates a String class
 * Input: 
 * Output:                                                                   *
 ***************************************************************************/
#include<iostream>
#include<cstdlib>
using namespace std;

#include "String.h"

/*Default Constructor
 * parameter: none.
 * function: creates an empty string.
 */

String::String(){ // moded // tested well 

	data= new char[0];
	clear(); 

}

/*Alternative Constructor
 * parameter: one cString 
 * function: creates an String object from a cString.
 */

String::String(const char str[]) { // moded // test well 

	int size = getCharArraySize(str); // subtract one to exclude null char. 
	//cout<< "getcharsize from constructor: "<< size <<endl;
	data= new char[size];
        
	char chara;
	clear();
        
	do{        
		chara= str[_length];
		if(chara != '\0'){

			data[ _length]= chara;
			//cout<< "char at:"<<_length<<" is: "<< chara<< endl;
		        _length++;

		}

	}while (chara != '\0');
	// _length--; // null char not counted. 
}


/*Copy Constructor
 * parameter: one String 
 * function: creates a deep copy String object from anotherString object.
 */

String::String(const String &toCopy) {

	this->_length = toCopy.length();
	this->data = new char[this->_length]; 

	for(int i=0; i < toCopy.length(); i++){
		this->data[i]= toCopy.data[i];

	}


}

/*Deconstructor
 * parameter: none
 * function: release pointer memory.
 */

String::~String(){ 

	delete [] data;
}


/*length
 * precondition: String has been created. 
 * postcondition: length of that string is returned.
 *
 * function: returns length of String.
 * return: int-representing the number of elements in th String.
 */

int String::length()const{ 

	return this->_length;
}	      

/*clear
 * precondition: String has been created.
 * postconction: String is filled by null character '\0'.
 *
 * function: resets length to zero and fills Strings with '\0'.
 * return: void.
 */

void String::clear(){ 

	this->_length=0;
}

/*print (Depreciated)
 * precondition: String is not empty.
 * postcondition: String is displayed to stdn out.
 *
 * function: prints a String.
 * return: void.
 */

void String::print()const{ // looks okay as is. //tested well    

	if(empty()){
		cout << "NULL";
	}		  
	else{ 
		for(int i=0; i< _length; i++){

			cout << data[i];
		} 	
	}
	cout << endl;
}

/*Overloaded <<
 * precondition: String is not empty.
 * postcondition: String is displayed to stdn out.
 *
 * function: prints a String.
 * return: ostream object containg string.
 */

ostream& operator<<(ostream& outPut, const String& arg){


	if(arg.empty()){
		outPut <<"Null";
	}
	else{

		for(int i=0; i < arg.length(); i++){
			outPut << arg.data[i];
		}

	}
	return outPut;
}

/*empty
 * precondition: String has been created.
 * postcondition: String a boolean value is returned.
 *
 * function: will return a boolean true if String is empty.
 * return: bool-representing whether String is empty.
 */

bool String::empty()const{
	if( _length == 0){
		return true;
	}	
	else
		return false;	
}

/*Overloaded []
 * parameter: int- representing an index of the String.
 * precondition: String is filled.
 * postcondition: returns a char value.
 *
 * function: returns char value at index, returns '\0'
 * if index out of bounds.
 * return: char-representing value at index.
 */

char String::operator [](int index)const{ 

	if(index < 0 || index >= _length){

		cerr<< "Error: Index Out of bounds, exiting."<<endl;
		exit(0);
	}
	else{
		return data[index];
	}
}



/*Overloaed +
 * parameter: String.
 * precondition: 2 Strings have been created.
 * postcondition: 1 Concatenated String.
 *
 * function: Concatenates the String with parameter. allows for cascading  
 * return: String-representing the result of the concatenation. 
 *
 */

String String::operator +(const String &two)const { //moded // tested well

	String toReturn;
	toReturn._length= this->_length + two._length;
	delete [] toReturn.data;
	toReturn.data = new char[toReturn._length];


	for(int i=0; i < this->_length; i++ ){

		toReturn.data[i] = this->data[i];
	}


	for(int j= this->_length, k=0; j < toReturn._length; j++ , k++){

		toReturn.data[j]= two.data[k]; 
	}

	return toReturn;

}


/*getCharArraySize
 * parameter: 1 cString.
 * precondition: returns number of elements in cString.
 *
 * function: counts the number of elements in a cString.
 * return: int-value representing number of elements in cString. 
 */

int String::getCharArraySize(const char arr[])const{ //tested well

	char chara='9';
	int num=0;
    
        while(chara != '\0'){
           chara= arr[num]; 
           
	   if (chara != '\0'){
               num++;
	   } 
	}

	return num; 

}

/*find
 * parameter: 1 cString, integer reperesenting where to start.
 * precondition: String exists, start index is legal.
 * postcondition: an integer is returned.
 *
 * function: looks for a substring with a String.
 * return: int- representing start index of substring, 
 *  if index is illegal or if substring is not found return is -1.
 */

int String::find(char substr[], int startIndex)const{ //moded //tested well.


	if(startIndex < 0 || startIndex >= _length){
		cout <<"\nError: Index Out of bounds, exiting."<<endl;
		exit(0);
	}

	int i= startIndex; 
	bool contMatch =false;
	bool checked =false;

	int charArraySize= getCharArraySize(substr);
	int begins;
	int j=0;

	for( i; i < _length; i++ ){

		if(j == charArraySize ) {
			break;
		}
recheck: if(data[i] == substr[j]){

		 if(contMatch ==false){

			 begins= i;
			 contMatch= true;
		 }

		 j++;
	 }
		else if(data[i] != substr[j]){

			contMatch= false;
			begins= -1;
			// cout << "\nj is" << j << endl;
			j=0;

			if(checked == false){

				checked = true;
				goto recheck;
			}
		}

		checked =false;   
	}
	// cout<<"\nfinal j "<< j <<endl;
	// cout<<"\nfinal charArraySize -1 "<< charArraySize -1  <<endl;

	if(j < charArraySize ){

		return -1;
	}
	else{
		return begins;
	}
}


/*Overloaded ==
 * precondition: two Strings instantiated
 * postcondition: returns boolean
 *  
 * function: returns boolean describing the equality of two strings.
return: bool- true if Strings match.
 */

bool String::operator ==(const String &two){

	bool isEqual;
	if( _length != two.length()){

		isEqual= false;
		return isEqual;

	}
	else{

		for (int i=0; i < _length; i++ ){

			if(data[i] != two.data[i] ){


				isEqual= false;
				return isEqual;
			}
		}

		isEqual= true;
		return isEqual;             
	}


}

/*Overloaded =
 * precondition: two Strings instantiated
 * postcondition:calling string is now euavalent to argument two.
 *  
 * function: Changes calling string to argument String two, allows for cascades.
return: Reference to calling string. 
 */

String& String::operator =(const String &two){

	clear();
	delete [] this->data;

	this->data = new char[two.length()];
	this->_length= two.length();


	for(int i=0; i< two.length(); i++){

		this->data[i]= two.data[i];
	}


	return *this;

}


