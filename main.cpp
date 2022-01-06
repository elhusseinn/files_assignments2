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
    fstream outputFile;
    file.writeInFile(outputFile, cIndexFile);

    return true;

}

File readFromFile(fstream &cIndexFile, string fileName, int m, int n) {
    vector<int> nums;
    File file(m, n);
    cIndexFile.open(fileName, ios::in);

        if (!cIndexFile){
            cout << "File not created!";
            exit(0);
        }
        else
        {
            int number;
            char ch;
            string out = "";

            while (true) {
                cIndexFile >> ch;
                if (cIndexFile.eof()){
                    break;
                }
                if(ch != ',' && ch != '?' && ch != '|'){
                    out+=ch;
                }
                else{
                    if(out != "") {
                        stringstream geek(out);
                        geek>>number;
                        nums.push_back(number);
                        out = "";
                    }
                }

            }

        }
    for (int i = 0; i < nums.size(); ++i) {
        cout<< nums[i]<<',';
    }
    cout<<endl;

        /////////////////////////////////////////////////////

        file.getFileHeader().setIKey(nums[0]);             // set file Header
        nums.erase(nums.begin());
        file.getFileHeader().setIVal(nums[0]);
        nums.erase(nums.begin());
        Block* curBlock = file.getInitialBlock();
        Record r;

        for(int i =0; i < m; i++){
            r.setIKey(nums[0]);
            nums.erase(nums.begin());

            r.setIVal(nums[0]);
            nums.erase(nums.begin());                        // set block's header

            curBlock->getHeader().setIKey(r.getIKey());
            curBlock->getHeader().setIVal(r.getIVal());
            for (int j = 0; j < n-1; ++j) {

                r.setIKey(nums[0]);
                nums.erase(nums.begin());

                r.setIVal(nums[0]);
                nums.erase(nums.begin());
                if (r.getIKey() != 0 && r.getIVal()!= 0) {
                    curBlock->insertRecord(r.getIKey(), r.getIVal());         // put records in block
                }

            }
            if(curBlock->getNext() != nullptr) {                    // itterates through blocks
                curBlock = curBlock->getNext();
            }

        }

cIndexFile.close();
    return file;

} // working hehe

int main(){
    fstream f;
    File file(3, 5);
    file = readFromFile(f, "test.txt", 3, 5);


    file.printFile();

cout<<"------------------------------------------------------------------"<<endl;

file.insertRecord(11,12,f);


file.printFile();






}

int main_(){
     CreateRecordFile("test.txt", 3, 5);
//    fstream f;
//    File file(3, 5);
//    file = readFromFile(f, "test.txt", 3, 5);
//
//
//    file.printFile();
//
//    cout<<"------------------------------------------------------------------"<<endl;
//
//    cout<<file.getInitialBlock()->getNext()->isEmpty1();
//    cout<<file.getFileHeader().getIVal();



}

