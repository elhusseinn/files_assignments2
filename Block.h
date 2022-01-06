
#ifndef FILES_ASSIGNMENT2_BLOCK_H
#define FILES_ASSIGNMENT2_BLOCK_H
#include "Record.h"
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Block {
     vector <Record> records;
     int n; // number of records in the block
     int blockNumber;
    // have n-1 records
    Block* next;
    Block* previous;
    Record header; // iKey-> maximum key in this block. ... iVal-> next block number(if not empty) -1 if it's the last block or the next block is empty.
    bool isEmpty;
    int noOfRecordsFull;
public:
    int getNoOfRecordsFull() const;

    void setNoOfRecordsFull(int noOfRecordsFull);


public:
    Block();

    void blockInitializer();

    int getBlockNumber() const;

    void setBlockNumber(int blockNumber);

    Block *getPrevious() const;

    void setPrevious(Block *previous);

    int getN() const;

    static bool compareInterval(Record r1, Record r2);

    void setN(int n);

     vector<Record> &getRecords();

    Record &getHeader();

    Block *getNext() const;

    void setNext(Block *next);

    bool insertRecord(int iKey, int iVal);

    void printBlock();

    void fixBlock();

    int getRecordIKey(int iKey);

    int getRecordIVal(int iVal);

    int getRecordIndex(int iKey);

    void deleteRecord(int iKey);

    bool isEmpty1() const;

    void setIsEmpty(bool isEmpty);



};


#endif //FILES_ASSIGNMENT2_BLOCK_H
