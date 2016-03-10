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


    straightLineReadings.setPrimitiveType(sf::Lines);
    //setUpBackground();



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

    target.draw(boxGirdBackground, states);

    // draw the straightLineReadings array
    target.draw(straightLineReadings, states);

}

void grid::updateGrid() {

    //TODO: Need to check data is initilized properly

    std::vector<sf::Vertex> tmpVect = data.getNextReading();

    for(int i = 0; i < tmpVect.size(); i++){

        //TODO check for collision here for the update

        straightLineReadings.append(tmpVect[i]);

        std::cout << tmpVect[i].position.x << "," << tmpVect[i].position.y << std::endl;  ;

    }





}


void grid::setUpBackground() {

    boxGirdBackground.setPrimitiveType(sf::Quads);

    //TODO: make this read in values for size of grid
    for(int i = 0; i < 10; i++){

        for(int j = 0; j < 10; j++) {

            sf::Vertex topL(sf::Vector2f(i + 0, j+ 0 ));
            sf::Vertex topR(sf::Vector2f(i + 0, j+1));
            sf::Vertex bottomL(sf::Vector2f(i+ 1, j+0));
            sf::Vertex bottomR(sf::Vector2f(i +1, j+1));

            topL.color = sf::Color::Black;
            topR.color = sf::Color::Black;
            bottomL.color = sf::Color::Black;
            bottomR.color = sf::Color::Black;

            boxGirdBackground.append(bottomL);
            boxGirdBackground.append(topL);
            boxGirdBackground.append(topR);
            boxGirdBackground.append(bottomR);

        }
    }


}

void grid::addSquare(float tlX, float tlY, float blX, float blY, float trX, float trY, float brX, float brY) {

    sf::Vertex topL(sf::Vector2f(tlX, tlY));
    sf::Vertex topR(sf::Vector2f(trX, trY));
    sf::Vertex bottomL(sf::Vector2f(blX, blY));
    sf::Vertex bottomR(sf::Vector2f(brX, brY));

    topL.color = sf::Color::Green;
    topR.color = sf::Color::Green;
    bottomL.color = sf::Color::Green;
    bottomR.color = sf::Color::Green;

    boxGirdBackground.append(bottomL);
    boxGirdBackground.append(topL);
    boxGirdBackground.append(topR);
    boxGirdBackground.append(bottomR);


}
