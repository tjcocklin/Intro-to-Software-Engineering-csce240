
#ifndef DNAQUEUE_H
#define DNAQUEUE_H

#include"Gene.h"

/**  File: DnaQueue.h 
 *  Author: Jeffrey Cocklin
 *  Function: Decleares DnaQueue interface.
 *  Input:
 *  Output:
 */

class DnaQueue
{


	private:
		class Node{

			public:			
                                //attributes
				//
				char gene [100];
				Node* previous= nullptr;
				Node* next= nullptr;
				int permutationCount=0; 

                                //Constructors/Destructors
				//
				
				/**
				 * Default Constructor
				 */
				Node();
				
				/**
				* Alternate Constructor
				*/
				Node(const char str[]);
				
				/**
				* Deconstructor
				*/
				
				virtual ~Node(); 
		};

	public: 
		//attributes
		//
		Node* tail= nullptr;
		Node* head= nullptr;
		int size;
		// Constructors/Destructors
		//  


		/**
		 * Default Constructor
		 */
		DnaQueue();


		/**
		 * Destructor
		 */
		virtual ~DnaQueue();

		// Methods
		//

		void enqueue(const char str[] );
		void  dequeue();
		int  getSize();
		bool isEmpty();
		void setBack(); 


};

#endif // DNAQUEUE_H
