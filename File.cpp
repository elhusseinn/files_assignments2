#include "File.h"

File::File( int m/*number of blocks in file*/,int n /*number of records in a block*/) {
    fileHeader.setIKey(-1);
    fileHeader.setIVal(1);

    initialBlock.setN(n);
    initialBlock.blockInitializer(); // initialize n records in vector to a block
    initialBlock.setBlockNumber(1);
    this->setNumberOfBlocks(m);


    Block* currentBlock = &initialBlock;

    int itr = 2;
    for (int i = 0; i < m-1; i++) {
        Block* b = new Block();
        b->setN(n);
        b->blockInitializer();
        b->setBlockNumber(itr);
        currentBlock->setNext(b);
        b->setPrevious(currentBlock);
        currentBlock->getHeader().setIVal(itr);
        itr++;
        currentBlock = currentBlock->getNext();

    }
}

void File::printFile() {
    cout<< "File Header: "<<fileHeader.getIKey()<<" "<<fileHeader.getIVal()<<endl; cout<<endl;
    Block* curBlock = &initialBlock;
    int j=0;
    while(curBlock!= nullptr){
        j++;
        cout<<"Block"<< j<<"Header: "<<curBlock->getHeader().getIKey()<<" "<<curBlock->getHeader().getIVal()<<" "<<"Block number: "<<curBlock->getBlockNumber()<<endl;
        curBlock->printBlock();
        curBlock=curBlock->getNext();
    }


}

Block* File::getInitialBlock(){
    Block* curBlock = &initialBlock;
    return curBlock;
}

int File::GetKey(char *cIndexFile, int iBlock, int iRecord) {
    // get value iKey stored in a given block
    // iBlock and given record iRecord – returns -1 if record on block is empty
Block* curBlock = &initialBlock;
    for (int i = 0; i < iBlock-1; ++i) {
        curBlock = curBlock->getNext();
    }
    return curBlock->getRecordIKey(iRecord);


}

int File::GetVal(char *cIndexFile,int iBlock, int iRecord) {
    // get value iKey stored in a given block
    // iBlock and given record iRecord – returns -1 if record on block is empty
    Block *curBlock = &initialBlock;
    for (int i = 0; i < iBlock - 1; ++i) {
        curBlock = curBlock->getNext();
    }
    return curBlock->getRecordIVal(iRecord);

}

int File::FirstEmptyBlock(/*char *cIndexFile*/) {
    Block *curBlock = &initialBlock;
    for (int i = 0; i < this->getNumberOfBlocks(); i++){
        if (curBlock->isEmpty1()) {
            return curBlock->getBlockNumber();
        }
        curBlock = curBlock->getNext();


}

    return -1;
}

int File::getNumberOfBlocks() const {
    return numberOfBlocks;
}

void File::setNumberOfBlocks(int numberOfBlocks) {
    File::numberOfBlocks = numberOfBlocks;
}

void File::writeInFile(fstream &cIndexFile, string fileName) {

cIndexFile.open(fileName, ios::out);

cIndexFile<<fileHeader.getIKey()<<','<<fileHeader.getIVal()<<'?'; // prints the file header
Block* curBlock = &initialBlock;
for(int i =0; i < this->getNumberOfBlocks(); i++){ // prints all the blocks in the file
    cIndexFile<<curBlock->getHeader().getIKey()<<','<<curBlock->getHeader().getIVal()<<'?'; // prints the block header

    for (int j = 0; j < this->getInitialBlock()->getN()-1; j++) { // prints all the records in the current block
        cIndexFile<<curBlock->getRecords()[j].getIKey()<<','<<curBlock->getRecords()[j].getIVal()<<'?'; // prints all the records
    }

    cIndexFile<<'|';
curBlock = curBlock->getNext();
}
cIndexFile.close();

}

int File::insertRecord(int iKey, int iVal) {

    Block* curBlock = &initialBlock;
    int numFirstEmptyBlock = fileHeader.getIVal();
    if (numFirstEmptyBlock == -1){
        cout<< "failed"<<endl;
        return -1;
    }

    for (int i = 1; i < numFirstEmptyBlock; ++i) { // gets the first empty block
        curBlock = curBlock->getNext();
    }
    if (curBlock->getPrevious() != nullptr) { curBlock = curBlock->getPrevious(); } // gets the block before the empty block because it still might have space to take other records

    if(curBlock->insertRecord(iKey, iVal)) {

        fixUnderFlow(curBlock);

    } else{
        curBlock = curBlock->getNext();
        curBlock->insertRecord(iKey, iVal);
        fixUnderFlow(curBlock);
    }


}

void File::fixUnderFlow(Block* curBlock) {

    if (curBlock->getNoOfRecordsFull() < (curBlock->getN() / 2)   && curBlock->getPrevious() != nullptr) { // checks for underflow on the Entry block and if there previous blocks to fix from


            Record temp;
            int numberOfBlocksTakenFromPrevRecord = (curBlock->getNoOfRecordsFull()) - (curBlock->getN() /2); // need to take numberOfBlocksTakenFromPrevRecord from previous record to fix underFlow

            for (int i =1; i <= numberOfBlocksTakenFromPrevRecord;i++) { // move records from previous block to current block
                temp = curBlock->getPrevious()->getRecords()[curBlock->getPrevious()->getRecords().size()-i];
                curBlock->insertRecord(temp.getIKey(), temp.getIVal());
                curBlock->getPrevious()->deleteRecord(temp.getIKey());
            }

        curBlock =&initialBlock;
        vector <Record> records;

        for (int i = 0; i < this->getNumberOfBlocks(); ++i) { // loops through all the blocks in the file
            for (int j = 0; j < curBlock->getNoOfRecordsFull(); ++j) { // (saves all the records of every block in a ArrayList)
                records.push_back(curBlock->getRecords()[j]);
            }
            if(curBlock->getNext() != nullptr) {
                curBlock = curBlock->getNext();
            }

        }
        sort(records.begin(), records.end(), compareInterval); // sort the records on iKey

        /*
         * override kol l records bl records al mawgoda fl vector u created
         * fix header file GG
         *
         * */



    }



}

bool File::compareInterval(Record r1, Record r2) {
    return (r1.getIKey() < r2.getIKey());
}






