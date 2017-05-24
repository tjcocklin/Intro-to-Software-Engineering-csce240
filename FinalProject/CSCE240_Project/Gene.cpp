/**************
*File: Gene.cpp
*Author: Jeffrey Cocklin
*Function: defines Gene Class.
*Input:
*Output:
***************/


#include<iostream>
using namespace std;
#include "Gene.h"

// Constructors/Destructors
//  

/* Default Gene Constructor
 *
 */
Gene::Gene ():String(){

}

/* Alternate Gene Constructor
 *
 */
Gene::Gene(const char str[]) : String(str) {

}

/* Deconstructor for Gene
 *
 */
Gene::~Gene(){ 

}

/*getData
 * mutator used to retreive a char from data at index.
 */

char Gene::getData(int index)const{

	return data[index];
}

/*getMatch
 * mutator used to return match value.
 */
int Gene::getMatch()const{
	return this->match;
}


/*setMatch 
 * mutator used to change value of match.
 *  
 */
void Gene::setMatch(int num){
	this->match = num;
}

/*operator == 
 * Compares a gene sequence to the left side of currentSequence and returns 
 * the number of matching characters.
 */
int Gene::operator == (const char gene2[]){//left of curSeq matching.

	int gItr=0, cItr=0; 
	this->setMatch(0);

	for(int i=0; i< 100; i++){

		gItr=i;

		if( cItr < this->length() && this->getData(cItr) == gene2[gItr]){

			gItr++;
			cItr++;
			//curSeq.setMatch(curSeq.getMatch()+1);
			this->match++;

			for(int j= cItr; j < this->length(); j++){

				if(gItr < 100 && this->getData(j) == gene2[gItr]){

					this->match++;
					gItr++;
				}  
				else{
					if(this->getMatch() < 20){

						this->setMatch(0);
					}

					cItr= 0;
					j= this->length();//terminate loop
				}

			}

		}

		if( this->getMatch() >= 20){
			i= 101;//terminate outerloop.
		}

	}

	return this->getMatch();

}

/**friend operator ==
 * Compares the right side of the CurrentSequence with 
 * the left side of a gene sequence, and 
 * returns number of mathcing characters.
 */
int operator == (const char gene2[], Gene &curSeq){//right of curSeq matching.
	int gItr=0, cItr=0; 
	curSeq.setMatch(0);

	for(int i=0; i< curSeq.length(); i++){

		cItr=i;

		if( gItr< 100 && curSeq.getData(cItr) == gene2[gItr]){

			gItr++;
			cItr++;
			curSeq.setMatch(curSeq.getMatch()+1);

			for(int j= gItr; j < 100; j++){

				if( cItr < curSeq.length() && curSeq.getData(cItr) == gene2[j]){

					curSeq.setMatch(curSeq.getMatch()+1);
					cItr++;
				}  
				else{
					if(curSeq.getMatch() < 20){

						curSeq.setMatch(0);
					}

					gItr= 0;
					j= 101;//terminate loop
				}

			}

		}

		if( curSeq.getMatch() >= 20){
			i= curSeq.length();//terminate outerloop.
		}

	}

	return curSeq.getMatch();

}

/*Operator =
 * assigns the calling gene the value of the parameter. 
 */
Gene& Gene::operator = (const Gene &gene2){

	this->clear();
	delete [] this->data;

	this->data= new char[gene2.length()];
	this->_length= gene2.length();

	for(int i=0; i < this->_length; i++){
		this->data[i]= gene2[i];
	}

	return *this;
}

/*operator +
 * Concatenates the left side of CurrentSequence with a gene, and returns
 * the result as a new Gene object.
 */
Gene Gene::operator + (const char gene2[]){// concat on left of curSeq

	//cout<<"\ncalling gene + "<<endl;
	int newSize=( this->length() + 101)-this->match;

	char toBeGene[newSize];

	int i=0;
	for( i; i<100; i++ ){
		toBeGene[i]= gene2[i];
	}

	for( int j=0; j< this->length(); j++ ){

		if(this->match <=0){

			toBeGene[i]= this->data[j]; 
			i++;
		}
		else{
			this->match--;
		}
	}

	toBeGene[newSize-1]= '\0';
	Gene geneToReturn(toBeGene); 
	return geneToReturn;
}

/**friend operator +
 * Concatenates the Right side of CurrentSequence with a gene and returns
 * the results as a new Gene object.
 */
Gene operator + (const char gene2[], Gene &curSeq){ //concats on right of curSeq

	//cout<<"\ncalling friend +"<<endl;
	////cout<<"before cat size of curSeq: "<<curSeq.length();
	////cout<<"before cat size of gene2: "<< temp<<endl; 


	int newSize= (curSeq.length() + 101) - curSeq.getMatch();

	char toBeGene[newSize];

	int i=0;
	for(i; i< curSeq.length(); i++ ){
		toBeGene[i]= curSeq.getData(i);
	}

	for(int j=0; j< 100; j++){

		if(curSeq.getMatch() <= 0){

			toBeGene[i]= gene2[j];
			i++;

		}
		else{
			curSeq.setMatch(curSeq.getMatch()-1);
		}

	}

	toBeGene[newSize-1]='\0';
	Gene geneToReturn(toBeGene); 
	return geneToReturn;

}

/**friend Operator <
 * Outputs a gene to an ofstream object, for file writing.
 */
ofstream& operator < (ofstream &fOut, const Gene &gene){

	if(gene.length() == 0){

		fOut<<"Null";

	}
	else{   

		for(int i=0; i <gene.length(); i++ ){
			fOut<<gene.getData(i); 

		}
	}
	return fOut;

}
