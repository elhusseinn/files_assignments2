
#ifndef FILES_ASSIGNMENT2_FILE_H
#define FILES_ASSIGNMENT2_FILE_H
#include <iostream>
#include "Record.h"
#include "Block.h"
#include <fstream>

class File {
    Record fileHeader;
public:
     Record &getFileHeader();

    void setInitialBlock( Block* initialBlock);

private:
    // just 1
    Block* initialBlock;
    int numberOfBlocks;
public:
    int getNumberOfBlocks() const;

    void setNumberOfBlocks(int numberOfBlocks);

public:
    File( int m /*number of blocks in a file*/, int n /*number of records in a block*/);

    void printFile();

    Block* getInitialBlock();
    int GetKey(char *cIndexFile, int iBlock, int iRecord); // get value iKey stored in a given block
   // iBlock and given record iRecord – returns -1 if record on block is empty

    int GetVal(char *cIndexFile, int iBlock, int iRecord); // get value iVal stored in a given block
    //iBlock and given record iRecord – returns -1 if record on block is empty

    int FirstEmptyBlock(/*char *cIndexFile*/); // return the index of the first empty block.

    void writeInFile(fstream &cIndexFile, string fileName);

    int insertRecord(int iKey, int iVal, fstream &indexFile);

    void fixUnderFlow(Block* curBlock);

    static bool compareInterval(Record r1, Record r2);

    void fixFile();


};


#endif //FILES_ASSIGNMENT2_FILE_H
