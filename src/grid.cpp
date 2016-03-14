//
// Created by nathan on 07/03/16.
//

#include "headers/grid.hpp"


grid::grid(){



    //TODO: Hardcoded for now but could easily be a function or overloaded constructor
    data.readData("resources/poses.txt", "resources/ranges.txt");

    straightLineReadings.setPrimitiveType(sf::Lines);
    setUpBackground();


    //TODO: Draw the background grid of the graph

    gridMarkings.setPrimitiveType(sf::Lines);

    for(int i = 0; i < 50; i+=1){

        sf::Vector2f bottom(i/5.f, 0) ;
        sf::Vector2f top(i/5.f, 10);

        gridMarkings.append(bottom);
        gridMarkings.append(top);

        sf::Vector2f sideL(0, i/5.f) ;
        sf::Vector2f sideR(10, i/5.f);

        gridMarkings.append(sideL);
        gridMarkings.append(sideR);


    }

}

grid::~grid() {

    std::cout << "Grid destroyed" << std::endl;

}

//std::ostream &operator<<(std::ostream &os, const grid &gd) {
//
//    for(int i = 0; i <= gd.gridSize; i ++){
//        for(int j = 0; j < gd.gridSize; j++){
//            os << gd.cellGrid[i][j];
//        }
//            os << std::endl;
//    }
//
//    return os;
//}


//void grid::setupGrid(const short gridSize) {
//
//    for(short i = 0; i <= gridSize; i++){
//        cellGrid.push_back( std::vector<cell>() ); //Add anther row
//        for(short j = 0 ;j <= gridSize; j++){
//            cellGrid[i].push_back(cell(i, j));
//        }
//
//    }
//
//
//}

void grid::draw(sf::RenderTarget &target, sf::RenderStates states) const {


    // apply the entity's transform -- combine it with the one that was passed by the caller
    states.transform *= getTransform(); // getTransform() is defined by sf::Transformable





    // draw the straightLineReadings array
    //TODO: Turn on and rename
    target.draw(straightLineReadings, states);

    target.draw(boxesOnScreen, states);
    //draw the grid's markings
    target.draw(gridMarkings, states);
}

void grid::updateGrid() {

    //TODO: Need to check data is initilized properly

    std::vector<sf::Vertex> tmpVect = data.getNextReading();

    for(int i = 0; i < tmpVect.size(); i++){

        //TODO check for collision here for the update

        straightLineReadings.append(tmpVect[i]);


        //TODO: This needs to round to the closes grid based square
//        addSquare(tmpVect[i].position.x, tmpVect[i].position.y,
//                  tmpVect[i].position.x, (float) (( tmpVect[i].position.y) + 0.2),
//                  (float) (( tmpVect[i].position.x) + 0.2), tmpVect[i].position.y,
//                  (float) (tmpVect[i].position.x + 0.2), (float) (tmpVect[i].position.y + 0.2));
//

        //Attempting a rounding
//        addSquare((int)tmpVect[i].position.x + 0.2f, (int)tmpVect[i].position.y+ 0.2f,
//                  (int)tmpVect[i].position.x + 0.2f, (int) (( tmpVect[i].position.y) + 0.2f + 0.2f),
//                  (int) (( tmpVect[i].position.x) + 0.2+ 0.2f), (int)tmpVect[i].position.y+ 0.2f,
//                  (int) (tmpVect[i].position.x + 0.2+ 0.2f), (int) (tmpVect[i].position.y + 0.2 + 0.2f));


        //TODO: Read the values of these so that they are rounded properly
        float x, y;
        int xI, yI;
        //Remember: the grids are 0.2f^2
        //find X & Y
        x = tmpVect[i].position.x ;
        y = tmpVect[i].position.y ;
        xI = x * 10;
        yI = y * 10;

        x = (float) xI/10;
        y = (float) yI/10;

        if(xI % 2 == 1){
            x = x-0.1;
        }
        if(yI % 2 == 1){
            y = y-0.1;
        }

        addSquare(x, y, x, y+0.2, x+0.2, y, x+0.2, y+0.2);

    }

}


void grid::setUpBackground() {

    boxesOnScreen.setPrimitiveType(sf::Quads);

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

            boxesOnScreen.append(bottomL);
            boxesOnScreen.append(topL);
            boxesOnScreen.append(topR);
            boxesOnScreen.append(bottomR);

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

    boxesOnScreen.append(bottomL);
    boxesOnScreen.append(topL);
    boxesOnScreen.append(topR);
    boxesOnScreen.append(bottomR);




//    std::cout << "Height: " << boxesOnScreen.getBounds().height << std::endl
//    << "Width: " << boxesOnScreen.getBounds().width << std::endl
//    << "Start point: " << boxesOnScreen.getBounds().left << ", " << boxesOnScreen.getBounds().top << std::endl;



}

