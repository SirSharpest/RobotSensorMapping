//
// Created by nathan on 07/03/16.
//

#include "headers/grid.hpp"


grid::grid(){

    data.readData("resources/poses.txt", "resources/ranges.txt");
    straightLineReadings.setPrimitiveType(sf::Lines);

    setUpBackground();
    setupGrid();

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




void grid::draw(sf::RenderTarget &target, sf::RenderStates states) const {


    // apply the entity's transform -- combine it with the one that was passed by the caller
    states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

    // draw the straightLineReadings array
    target.draw(straightLineReadings, states);

    target.draw(boxesOnScreen, states);
    //draw the grid's markings
    target.draw(gridMarkings, states);
}

void grid::updateGrid() {

    std::vector<sf::Vertex> tmpVect = data.getNextReading();

    for(int i = 0; i < tmpVect.size(); i++){

        //Take note of the straight lines on the grid
        straightLineReadings.append(tmpVect[i]);

        //Floats to store the positions of the points
        float x, y;
        x = tmpVect[i].position.x ;
        y = tmpVect[i].position.y ;

        // Store the Integer values to shave off useless accuracy
        int xI, yI;
        xI = (int) (x * 10);
        yI = (int) (y * 10);

        //Crop off the value and return to the float destination
        x = (float) xI/10;
        y = (float) yI/10;

        //Remove the squares between and round to entire square
        if(xI % 2 == 1){
            x = (float) (x - 0.1);
        }
        if(yI % 2 == 1){
            y = (float) (y - 0.1);
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

void grid::setupGrid() {

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
