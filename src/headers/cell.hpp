//
// Created by nathan on 07/03/16.
//

#ifndef CS22510_CELL_HPP
#define CS22510_CELL_HPP


#include <iosfwd>
#include <iostream>

class cell {


public:

    /*
     * Default constructor
     * that sets the position on the map
     */
    cell(short x, short y);

    /*
     * sets the occupancy of the cell
     */
    void setOccupied(bool isOccupied);

    bool isCellOccupied();

    friend std::ostream& operator<<(std::ostream& os, const cell& cl);



private:

    //Shorts indicating the position on the grid
    short posX;
    short posY;

    bool isOccupied;



};


#endif //CS22510_CELL_HPP
