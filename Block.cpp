//
// Created by Elhussein on 12/26/2021.
//

#include "Block.h"
#include <bits/stdc++.h>

Block *Block::getNext() const {
    return next;
}

void Block::setNext(Block *next) {
    Block::next = next;
}

Block::Block() {
    noOfRecordsFull = 0;
    next = nullptr;
    previous = nullptr;
    isEmpty = true;
    header.setIKey(-1);
    header.setIVal(-1);
}

void Block::blockInitializer() {
    for(int i =0; i < n-1;i++){
        Record r;
        records.push_back(r);
    }
}

  Record &Block::getHeader() {
    return header;
}

   vector<Record> &Block::getRecords(){
    return records;
}

bool Block::insertRecord(int iKey, int iVal) {
    vector<Record> newRecords;
    Record newRecord(iKey, iVal);
    for (int i = 0; i < records.size(); ++i) { // copies the legit values into a new vector
        if(records[i].getIKey() > 0){
            newRecords.push_back(records[i]);
        }
    }
    if(newRecords.size() < this->n-1){ // makes sure that the block have empty space
        newRecords.push_back(newRecord); // adds new record
        this->isEmpty = false;
        // now newRecords holds the the legit values + inserted record
    }
    else{
        return false;
    }

    records.clear(); // clears the records vector

    for (int i = 0; i < newRecords.size(); ++i) { // pushing the values into records vector
        records.push_back(newRecords[i]);
    }
    noOfRecordsFull ++;

    sort(records.begin(), records.end(), compareInterval); // sort the records on iKey

    for (int i = records.size(); i < (this->n)-1; i++) { // pushing zero's into the remaining spots
        Record r;
        records.push_back(r);
    }


    this->fixBlock();
    return true;

}

int Block::getN() const {
    return n;
}

void Block::setN(int n) {
    Block::n = n;
}

void Block::printBlock() {
    for (int i = 0; i < this->getRecords().size(); ++i) { // prints all the records in certain block
        cout<< "Record"<<i+1<<" "<<this->getRecords()[i].getIKey()<<" "<< this->getRecords()[i].getIVal()<<endl;
    }
}

bool Block::compareInterval(Record i1, Record i2) {
    return (i1.getIKey() < i2.getIKey());
}

void Block::fixBlock() {
    int maxIKey = 0;

    for (int i = 0; i < records.size(); i++) {

        if (records[i].getIKey() >= maxIKey) {
            maxIKey = records[i].getIKey();               // fix iVal in the block
        }
    }
if(maxIKey != 0){
    this->getHeader().setIVal(maxIKey);
}

    Block *curBlock = this;

    while (curBlock->getPrevious() != nullptr) { // returns to the the initial block in the file
        curBlock = curBlock->getPrevious();
    }

    Block* first = curBlock;


while (first->getNext() != nullptr){  // fix iKey of the record, gets the number of block of the closest non empty one to the whole file
    int closestNonEmptyBlock = -1;
    curBlock = first;

    while (curBlock->getNext() != nullptr) {
        if (!curBlock->getNext()->isEmpty) {
            closestNonEmptyBlock = curBlock->getNext()->getBlockNumber();
            break;
        }
            curBlock = curBlock->getNext();
    }

    first->getHeader().setIKey(closestNonEmptyBlock);

    first = first->getNext();

}


}

int Block::getBlockNumber() const {
    return blockNumber;
}

void Block::setBlockNumber(int blockNumber) {
    Block::blockNumber = blockNumber;
}

Block *Block::getPrevious() const {
    return previous;
}

void Block::setPrevious(Block *previous) {
    Block::previous = previous;
}

int Block::getRecordIVal(int recordIndex) {
    if(this->records[recordIndex-1].getIKey() == 0){
        return -1;
    }
    else{
       return this->records[recordIndex-1].getIVal();
    }
}

int Block::getRecordIKey(int recordIndex) {
    if(this->records[recordIndex-1].getIKey() == 0){
        return -1;
    }
    else{
        return this->records[recordIndex-1].getIKey();
    }
}

int Block::getRecordIndex(int iKey) {
    for(int i=0; i < this->records.size();i++){
        if(records[i].getIKey() == iKey){
            return i+1;
        }
    }
    return -1;
}

void Block::deleteRecord(int iKey) {
    int index = getRecordIndex(iKey)-1;
    records[index].setIKey(0);
    records[index].setIVal(0);
    noOfRecordsFull--;

    vector<Record> newRecords;
    for (int i = 0; i < records.size(); ++i) { // copies the legit values into a new vector
        if(records[i].getIKey() > 0){
            newRecords.push_back(records[i]);
        }
    }
    records.clear(); // clears the records vector

    for (int i = 0; i < newRecords.size(); ++i) { // pushing the values into records vector
        records.push_back(newRecords[i]);
    }
    sort(records.begin(), records.end(), compareInterval); // sort the records on iKey

    for (int i = records.size(); i < (this->n)-1; i++) { // pushing zero's into the remaining spots
        Record r;
        records.push_back(r);
    }




int counter = 0;
    for (int i = 0; i < records.size(); ++i) {
        if(records[i].getIKey() == 0 && records[i].getIVal() == 0){
            counter++;
        }
    }
    if(counter == getN() -1){
        isEmpty = true;
    }


    fixBlock();
}

bool Block::isEmpty1() const {
    return isEmpty;
}

void Block::setIsEmpty(bool isEmpty) {
    Block::isEmpty = isEmpty;
}

int Block::getNoOfRecordsFull() const {
    return noOfRecordsFull;
}

void Block::setNoOfRecordsFull(int noOfRecordsFull) {
    Block::noOfRecordsFull = noOfRecordsFull;
}

void Block::clearBlock() {
    for (int i = 0; i < this->getN(); ++i) {
        deleteRecord(records[0].getIKey());
    }

}



