//
// Created by nathan on 07/03/16.
//

#include "headers/grid.hpp"


grid::grid():
gridSize(100){

    //TODO: Is this needed either??
    setupGrid(gridSize);

    //TODO: Hardcoded for now but could easily be a function or overloaded constructor
    data.readData("resources/poses.txt", "resources/ranges.txt");


    vertex.setPrimitiveType(sf::Lines);




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

void grid::draw(sf::RenderTarget &target, sf::RenderStates states) const {


    // apply the entity's transform -- combine it with the one that was passed by the caller
    states.transform *= getTransform(); // getTransform() is defined by sf::Transformable


    // draw the vertex array
    target.draw(vertex, states);

}

void grid::updateGrid() {

    //TODO: Need to check data is initilized properly

    std::vector<sf::Vertex> tmpVect = data.getNextReading();

    for(int i = 0; i < tmpVect.size(); i++){
        vertex.append(tmpVect[i]);
    }


}
