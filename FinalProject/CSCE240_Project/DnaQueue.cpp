#include<iostream>
#include<new>
using namespace std;

#include"DnaQueue.h"
#include "Gene.h"


/* Default constructor forDnaQueue
 *
 */
 
DnaQueue::DnaQueue(){
	
	this->size=0;


}
/* Default Constructor for Node
 *
 */

DnaQueue::Node::Node(){
    
  
}
/*Alt Constructor for Node
 *
 */

DnaQueue::Node::Node(const char str[]){

   for (int i =0; i< 100; i++){
        gene[i]= str[i];
   }
  // cout<<"made it to node"<<endl;
}

/*Destructor for Node
 *
 */
DnaQueue::Node::~Node(){
  
}   


/*Destructor forDnaQueue
 *
 */

DnaQueue::~DnaQueue(){
   int count=0;
   Node* iter= this->head;
   //cout<<"made it to dna destructor"<<endl; 
   while(!this->isEmpty()){
    
    cout<<"seq#"<<count<<":"<<endl;
    for(int i =0; i< 100; i++)
           cout<<(this->head->gene[i]);
       cout<<endl;
       count++;
       this->dequeue();
   }
  
}

/*enqueue
 * Creates a new node in the queue with the given char []
 * as payload
 */
void DnaQueue::enqueue(const char str[] ){

  if(this->isEmpty()){
     
    // cout<<"about to invoke new for first elem."<<endl; 
      
     this->head = this->tail =  new Node(str);
   }
   else{
      Node* tailprev= tail;
      
      tail->next= new Node(str);
      tail= tail->next;
      tail->previous= tailprev;
     // cout<<"about to invoke new more than one elem."<<endl; 

        
  }
    this->size++;
}

/*dequeue
 * Removes the head node from the queue, and sets the next
 * node as the head.
 */
void DnaQueue::dequeue(){
   
   if(this->head->next != nullptr){
      Node* toDestroy= this->head;
      this->head= this->head->next;
      
      delete toDestroy;
   
   }
   else{
       delete this->head;
   }
   this->size--;
}

/*setBack 
 * Moves the head node to the back of the queue, and sets the next
 * node as the head.
 *
 */

void DnaQueue::setBack(){
  tail->next= this->head;
  this->head->previous= tail;
  this->head= this->head->next;
  tail= tail->next;
  tail->next=nullptr;

}


/*getSize
 * Returns the size of the queue. 
 */

int DnaQueue::getSize(){
    return this->size;
}

/*isEmpty
 * Returns boolean value true if the queue is empty, and
 * false when the queue still contains nodes.
 */
bool DnaQueue::isEmpty(){
     if(this->size == 0)
           return true;
     else
          return false;
}


