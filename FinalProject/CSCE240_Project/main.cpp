/*******************
*File: main.cpp
*Author: Jeffrey Cocklin
*Function: performs simplistic gene sequencing
*Input: a file containing gene sequences to be constructed.
*Output: One complete gene sequence.
*
*****************/

#include<iostream>
#include<fstream>
using namespace std;
#include"String.h"
#include"Gene.h"
#include"DnaQueue.h"


void readFile( ifstream &,ofstream &,DnaQueue &);
void sequence(DnaQueue &, Gene &, ofstream &);
void writeOut(ofstream &,const Gene &);

/**Driver for the program. 
 * 
 *
 */
int main(int argc, char* argv[] ){

	if (argc < 4 || argc > 4){
		cout <<"Error: 100 You need to input four arguments."<<endl;
		exit(100);
	}
	else{

		ifstream inputFile;
		ofstream outPut;
		DnaQueue seqQueue;

		inputFile.open(argv[1]);
		//cout<<"what's argv?: "<< argv[1]<<endl;

		if(inputFile.fail()){
                                
			cerr <<"Error: 101 Can't open file for read."<<endl;
			exit(101);
		}

		outPut.open(argv[2]);

		if(outPut.fail()){
			cerr <<"Error: 103 Can't open file for write."<<endl;
			exit(103);
		}

		readFile(inputFile, outPut, seqQueue);
		//
		outPut.close();
		return 0;
	}
}		

/*readFile
 *Function: read an input file
 *Input: InputFile, OutputFile, and DnaQueue object.
 *Output: passes OutputFile, DnaQueue, and a Gene object to sequence function.
 *
 */
void   readFile(ifstream & inputFile, ofstream & outPut, DnaQueue & seqQueue ){
	
	cout<<"Begin File Reading!"<<endl;
	
	int streamSize =100;
	char line[streamSize+1];

	Gene currentSeq;
	char chara;
	int count =0; 
	bool firstRead=true;

	chara= inputFile.get();

	while(!inputFile.eof()){
		while( !inputFile.eof() && count < streamSize){

			if(chara == 'A' || chara == 'T' || chara == 'C' || chara == 'G'){
				line[count]= chara; 
				count++;
			}

			chara= inputFile.get();


		}

		line[streamSize]= '\0';

		if(firstRead == true){

			Gene tempSeq(line) ;
			currentSeq= tempSeq;

			//cout<<"Seed: "<< currentSeq<<endl;
			//cout<<"\nSeed size: "<<currentSeq.length();


			firstRead= false;
		}
		else{
			if(!inputFile.eof()){
				seqQueue.enqueue(line);
			}
		}

		/*for(int i=0; i< count ; i++)// insert into node here.
		  cout<<line[i]*/

		count=0;
	}

	inputFile.close();
	cout << "Reading Complete!"<<endl;

	sequence(seqQueue,currentSeq,outPut);  

}

/**sequence
 *Function: concatenants gene sequences to form one sequence.
 *Input: DnaQueue Object, Gene Object, OutPutFile 
 *Output: passes completed sequence, and OutPutFile to write function.
 */
void sequence(DnaQueue & seqQueue, Gene & currSeq, ofstream & outPut){

	cout<<"Begin Sequencing!"<<endl; 

	int permutationLimit= seqQueue.getSize();

	while(!seqQueue.isEmpty()){

		if((seqQueue.head->permutationCount) > permutationLimit){

			seqQueue.dequeue();
		}
		//check right of seed & left of the sequence.
		else if((seqQueue.head->gene == currSeq) >= 20){
			//cout<<"\n\nConcatenating right of seed!"<<endl;
			currSeq= (seqQueue.head->gene) + currSeq;

			seqQueue.dequeue();
			/*  cout<<"queueSize: "<<seqQueue.getSize()+1<<endl;
			    cout<<"seed: ";
			    cout<< currSeq<<endl;*/

		}

		//check left of seed & right of the sequence.
		else if((currSeq == seqQueue.head->gene) >= 20){
			//cout<<"\n\nConcatenating left of seed!"<<endl; 
			currSeq= currSeq + (seqQueue.head->gene);

			seqQueue.dequeue();
			/* cout<<"queueSize: "<<seqQueue.getSize()<<endl;
			   cout<<"seed: ";
			   cout<< currSeq<<endl;*/
		}
		else{
			//  cout<<"Setting Back!"<<endl;
			seqQueue.head->permutationCount++;
			seqQueue.setBack();
		}
	}

	cout<<"Sequencing Complete!"<<endl; 

	writeOut(outPut, currSeq);

	/*  cout<<"Size of seQueue: "<<seqQueue.getSize()<<endl;
	    cout<<"test setBack: "<<endl;
	    seqQueue.setBack();

	    cout<<"Size of seQueue after setBack: "<<seqQueue.getSize()<<endl;

	    seqQueue.~DnaQueue();*/
}

/*writeOut
 *Function: writes the constructed gene to OutPut.txt
 *Input: Output file , and the completed sequence.
 *OutPut: writes the gene to a file.
 */
void writeOut(ofstream& Output,const Gene& completeSeq){
         
	// cout<<"\n\nCompleted sequeunce length: "<<completeSeq.length()<<endl;

	//    cout<<completeSeq<<endl;
        cout<<"Writing file!"<<endl;
	Output < completeSeq;
        cout<<"Writing Complete!"<<endl;
           
}


