//
// Created by Elhussein on 12/26/2021.
//

#include "Block.h"

Block *Block::getNext() const {
    return next;
}

void Block::setNext(Block *next) {
    Block::next = next;
}

Block::Block() {
    isEmpty = true;
    header.setIKey(-1);
    header.setIVal(-1);
}

void Block::blockInitializer(int n) {
    for(int i =0; i < n-1;i++){
        Record r;
        records.push_back(r);
    }
}

const Record &Block::getHeader() const {
    return header;
}

const vector<Record> &Block::getRecords() const {
    return records;
}
