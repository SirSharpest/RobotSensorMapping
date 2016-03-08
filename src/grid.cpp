//
// Created by nathan on 07/03/16.
//

#include "headers/grid.hpp"


grid::grid():
gridSize(100){

    setupGrid(gridSize);


}

grid::~grid() {

    std::cout << "Grid destroyed" << std::endl;

}

std::ostream &operator<<(std::ostream &os, const grid &gd) {

    for(int i = 0; i <= gd.gridSize; i ++){
        for(int j = 0; j < gd.gridSize; j++){
            os << gd.cellGrid[i][j];
        }
            os << std::endl;
    }

    return os;
}


void grid::setupGrid(const short gridSize) {

    for(short i = 0; i <= gridSize; i++){
        cellGrid.push_back( std::vector<cell>() ); //Add anther row
        for(short j = 0 ;j <= gridSize; j++){
            cellGrid[i].push_back(cell(i, j));
        }

    }


}
