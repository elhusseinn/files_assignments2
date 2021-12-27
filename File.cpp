#include "File.h"

File::File(int n /*number of records in a block*/, int m/*number of blocks in file*/) {

    initialBlock.blockInitializer(n); // initialize n records in vector to a block
    fileHeader.setIKey(-1);
    fileHeader.setIVal(1);

    Block* currentBlock = &initialBlock;

    int itr = 2;
    for (int i = 0; i < m-1; i++) { //
        Block* b = new Block();
        b->blockInitializer(n);
        currentBlock->setNext(b);
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
        cout<<"Block"<< j<<"Header: "<<curBlock->getHeader().getIKey()<<" "<<curBlock->getHeader().getIVal()<<endl;

        for (int i = 0; i < curBlock->getRecords().size(); ++i) { // prints all the records in certain block
            cout<< "Record"<<i+1<<" "<<curBlock->getRecords()[i].getIKey()<<" "<< curBlock->getRecords()[i].getIVal()<<endl;
        }
        curBlock=curBlock->getNext();
    }

}
