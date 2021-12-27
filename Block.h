
#ifndef FILES_ASSIGNMENT2_BLOCK_H
#define FILES_ASSIGNMENT2_BLOCK_H
#include "Record.h"
#include <vector>
#include <iostream>
using namespace std;

class Block {
    vector <Record> records;
    // have n-1 records
    Block* next;
    Block* previous;
    Record header;
public:

private:
// iKey-> maximum key in this block. ... iVal-> next block number(if not empty) -1 if it's the last block or the next block is empty.
    bool isEmpty;
public:
    const vector<Record> &getRecords() const;

     Record &getHeader() ;

    Block *getNext() const;

    void setNext(Block *next);

    Block();

    void blockInitializer(int n /* number of records*/);


};


#endif //FILES_ASSIGNMENT2_BLOCK_H
