//
// Created by Elhussein on 12/26/2021.
//

#ifndef FILES_ASSIGNMENT2_FILE_H
#define FILES_ASSIGNMENT2_FILE_H
#include <iostream>
#include "Record.h"
#include "Block.h"

class File {
    Record fileHeader; // just 1
    Block initialBlock;
public:
    File(int n /*number of records in a block*/, int m /*number of blocks in a file*/);
    void printFile();
};


#endif //FILES_ASSIGNMENT2_FILE_H
