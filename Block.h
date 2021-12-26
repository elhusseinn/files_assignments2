//
// Created by Elhussein on 12/26/2021.
//

#ifndef FILES_ASSIGNMENT2_BLOCK_H
#define FILES_ASSIGNMENT2_BLOCK_H
#include "Record.h"
#include <vector>
#include <iostream>
using namespace std;

class Block {
    vector <Record> records;
public:
    const vector<Record> &getRecords() const;

private:
    // have n-1 records
    Block* next;
    Block* previous;
    Record header;
public:
    const Record &getHeader() const;

private:
    // iKey-> maximum key in this block. ... iVal-> next block number(if not empty) -1 if it's the last block or the next block is empty.
    bool isEmpty;
public:
    Block *getNext() const;

    void setNext(Block *next);

    Block();

    void blockInitializer(int n /* number of records*/);


};


#endif //FILES_ASSIGNMENT2_BLOCK_H
