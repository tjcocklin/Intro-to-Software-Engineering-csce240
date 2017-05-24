/***************************************************************************
 * File: String.h
 * Author: Casey Cole
 * Function: 
 * Input: 
 * Output:                                                                        *
 ***************************************************************************/


#ifndef STRING_H
#define STRING_H



#include<iostream>
using namespace std;

class String 
{
	
	protected:
		int _length;
		char *data;
	
	
	private:
		
		int getCharArraySize(const char arr[])const;
    
	public:
	
		String();
		String(const char str[]);
		String(const String &);
		virtual ~String(); //Destructor should delete your data pointer.
    
		void print()const;
		int length()const;
		void clear(); 
		bool empty()const;
		int find(char substr[], int startIndex)const;
		
		bool operator==(const String& two); //Should replace your equal() method. 
		String operator+(const String& two)const; /*Should replace your add() method. 
		Should append the char* in two to the object doing the calling. 
		Return true if you were able to add the two together, false if not.*/ 
		
		String& operator=(const String& two); //Should assign two to the calling object. 
		char operator[](int index)const; //Should replace your at() method. 
                friend ostream& operator<<(ostream& outPut, const String& arg);

		
                		
};

#endif // STRING_H
