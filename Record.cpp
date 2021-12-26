//
// Created by Elhussein on 12/26/2021.
//

#include "Record.h"

int Record::getIKey() const {
    return iKey;
}

void Record::setIKey(int iKey) {
    Record::iKey = iKey;
}

int Record::getIVal() const {
    return iVal;
}

void Record::setIVal(int iVal) {
    Record::iVal = iVal;
}

Record::Record() {
    iKey = 0;
    iVal = 0;
}

