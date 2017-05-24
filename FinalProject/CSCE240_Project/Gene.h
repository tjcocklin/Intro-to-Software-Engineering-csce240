
#ifndef GENE_H
#define GENE_H

#include"String.h"
#include<fstream>

/**  File: Gene.h 
 *  Author: Jeffrey Cocklin
 *  Function: Declares Gene interface. 
 *  Input:
 *  Output:
 */

class Gene : public String
{
	private:
		//attributes   
		//
		int match;
	public:

		// Constructors/Destructors
		//  


		/**
		 * Default Constructor
		 */
		Gene();

		/**
		 * Constructor for read in.
		 */
		Gene(const char str[]); 

		/**
		 * Deconstructor
		 */
		virtual ~Gene ();

		/**
		 * Methods 
		 *
		 */


		int operator == (const char gene2[]); 

		friend int operator == (const char gene2[], 
				Gene &curSeq); 

		Gene& operator = (const Gene &gene2);

		Gene operator + (const char gene2[]);

		friend Gene operator + (const char gene2[], 
				Gene &curSeq);

		friend ofstream& operator < (ofstream &fOut, const Gene &gene);

		char getData( int index)const;                 

		int getMatch()const;

		void setMatch(int num);  


};

#endif // GENE_H
