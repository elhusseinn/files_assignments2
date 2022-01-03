#include <iostream>
#include "File.h"
#include <fstream>
using namespace std;





/*
// for all the prototypes the Records set is stored in a file called cIndexFile

Bool CreateRecordFile(char *cIndexFile, int m, int n); // returns true if success and false if
failure. m is the number of blocks in the file and n is the number of records in a block

int InsertVal(char *cIndexFile, int iToken, int iKey); // returns index of block in which iToken
and iKey were stored and -1 if failed, where iKey is the key of the record, and iToken = iVal in
the record.

int GetKey(char *cIndexFile, int iBlock, int iRecord); // get value iKey stored in a given block
iBlock and given record iRecord – returns -1 if record on block is empty

int GetVal(char *cIndexFile, int iBlock, int iRecord); // get value iVal stored in a given block
iBlock and given record iRecord – returns -1 if record on block is empty

int GetBlockIndex (char *cIndexFile, int iToken); // get index of block containing iKey = iToken
and -1 if record does not exist

int GetRecordIndex (char *cIndexFile, int iToken); // get index of record containing iKey = iToken
and -1 if record does not exist

void DeleteKey (char *cIndexFile, int iToken); // delete record containing value iKey
= iToken

int FirstEmptyBlock(char *cIndexFile); // return the index of the first empty block.

 */
// record at the start of the file :
// iKey -> first non-empty block   // -1 if there is not
// iVal -> first empty block  // same
bool CreateRecordFile(string cIndexFile, int m, int n){ // returns true if success and false if failure. m is the number of blocks in the file and n is the number of records in a block

    File file(m,n);

    file.getInitialBlock()->insertRecord(1,5);
    file.getInitialBlock()->insertRecord(4,3);
    file.getInitialBlock()->insertRecord(3,6);


    file.getInitialBlock()->getNext()->insertRecord(5,5);
    file.getInitialBlock()->getNext()->insertRecord(7,3);
    file.getInitialBlock()->getNext()->insertRecord(6,19);
    file.getInitialBlock()->getNext()->insertRecord(8,8);

    file.getInitialBlock()->getNext()->getNext()->insertRecord(9,58);
    file.getInitialBlock()->getNext()->getNext()->insertRecord(11,36);
    file.getInitialBlock()->getNext()->getNext()->insertRecord(10,55);
    file.printFile();

    fstream outputFile;
    file.writeInFile(outputFile, cIndexFile);

    return true;

}

/*void readFromFile(fstream &cIndexFile, string fileName, int m, int n) {
    File file(m, n);
    cIndexFile.open(fileName, ios::in);

}*/

int main() {
    fstream f;


File file(3,5);
file.printFile();

cout<<"------------------------------------------------------------------"<<endl;
    cout<<file.FirstEmptyBlock();
file.getInitialBlock()->insertRecord(1,5);
file.getInitialBlock()->insertRecord(4,3);
file.getInitialBlock()->insertRecord(3,6);


    file.getInitialBlock()->getNext()->insertRecord(5,5);
    file.getInitialBlock()->getNext()->insertRecord(7,3);
    file.getInitialBlock()->getNext()->insertRecord(6,19);
    file.getInitialBlock()->getNext()->insertRecord(8,8);

       file.getInitialBlock()->getNext()->getNext()->insertRecord(9,58);
        file.getInitialBlock()->getNext()->getNext()->insertRecord(11,36);
        file.getInitialBlock()->getNext()->getNext()->insertRecord(10,55);




file.printFile();
    cout<<"------------------------------------------------------------------"<<endl;


cout<<file.FirstEmptyBlock();
    file.getInitialBlock()->getNext()->deleteRecord(6);
    file.getInitialBlock()->getNext()->deleteRecord(5);
    file.getInitialBlock()->getNext()->deleteRecord(7);
    file.getInitialBlock()->getNext()->deleteRecord(8);
    file.printFile();
    cout<<"------------------------------------------------------------------"<<endl;
    //CreateRecordFile("test.txt", 3, 5);*/
}
