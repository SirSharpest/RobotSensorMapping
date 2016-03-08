//
// Created by nathan on 07/03/16.
//

#include "headers/cell.hpp"


cell::cell(short x, short y) {

    isOccupied = true; //assume it is occupied until we know it is not
    this->posX = x;
    this->posY = y;
}

void cell::setOccupied(bool isOccupied) {
    this->isOccupied = isOccupied;
}

bool cell::isCellOccupied() {
    return this->isOccupied;
}

std::ostream &operator<<(std::ostream &os, const cell &cl) {

    if(cl.isOccupied){
        os << "-";
    }else{
        os << "x";
    }
    return os;
}
