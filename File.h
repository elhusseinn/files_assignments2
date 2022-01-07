
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
    int GetKey(int iBlock, int iRecord); // get value iKey stored in a given block
   // iBlock and given record iRecord – returns -1 if record on block is empty

    int GetVal(int iBlock, int iRecord); // get value iVal stored in a given block
    //iBlock and given record iRecord – returns -1 if record on block is empty

    int FirstEmptyBlock(); // return the index of the first empty block.

    void writeInFile(fstream &cIndexFile, string fileName);

    int insertRecord(int iKey, int iVal, fstream &indexFile);

    void fixUnderFlow(Block* curBlock);

    static bool compareInterval(Record r1, Record r2);

    void fixFile();

    int GetBlockIndex(int IToken);   // get index of block containing iKey = iToken and -1 if record does not exist

    int GetRecordIndex(int IToken); // get index of record inside the block containing iKey = iToken and -1 if record does not exist




};


#endif //FILES_ASSIGNMENT2_FILE_H
