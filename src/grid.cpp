//
// Created by nathan on 07/03/16.
//

#include "headers/grid.hpp"


grid::grid():
displayGrid(true),
displayBoxes(true),
displayLines(true),
displayOccupied(true){

    data.readData("resources/poses.txt", "resources/ranges.txt");
    straightLineReadings.setPrimitiveType(sf::Lines);

    setUpBackground();
    setupGrid();

}

grid::~grid() {

    std::cout << "Grid destroyed" << std::endl;

}


void grid::draw(sf::RenderTarget &target, sf::RenderStates states) const {


    // apply the entity's transform -- combine it with the one that was passed by the caller
    states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

    // draw the straightLineReadings array
    if(displayLines)
        target.draw(straightLineReadings, states);

    if(displayBoxes)
        target.draw(objectsDetected, states);

    //draw the grid's markings
    if(displayGrid)
        target.draw(gridMarkings, states);

    if(displayOccupied)
        target.draw(occupiedSpaces, states);
}

void grid::updateGrid() {


    std::vector<std::vector< sf::Vertex>> dataReadings = data.getNextReading();

    for(uint i = 0; i < 2; i++){

        std::vector<sf::Vertex> tmpVect = dataReadings[i];

        for(uint j = 0; j < tmpVect.size(); j++){

            //Take note of the straight lines on the grid
            straightLineReadings.append(tmpVect[j]);

            //Floats to store the positions of the points
            float x, y;
            x = tmpVect[j].position.x ;
            y = tmpVect[j].position.y ;

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

            //Add a square of this size to the grid
            if(x < 0 || y < 0)
                continue;

            addSquare(x, y, x, (float) (y + 0.2), (float) (x + 0.2), y, (float) (x + 0.2), (float) (y + 0.2),
                      i == 0);

        }
    }
}


void grid::setUpBackground() {

    objectsDetected.setPrimitiveType(sf::Quads);
    occupiedSpaces.setPrimitiveType(sf::Quads);


}

void grid::addSquare(float tlX, float tlY, float blX, float blY, float trX, float trY, float brX, float brY,
                     bool isOutline) {


    sf::Vertex topL(sf::Vector2f(tlX, tlY));
    sf::Vertex topR(sf::Vector2f(trX, trY));
    sf::Vertex bottomL(sf::Vector2f(blX, blY));
    sf::Vertex bottomR(sf::Vector2f(brX, brY));

    topL.color = sf::Color::Green;
    topR.color = sf::Color::Green;
    bottomL.color = sf::Color::Green;
    bottomR.color = sf::Color::Green;


    if(!isOutline){
        occupiedSpaces.append(bottomL);
        occupiedSpaces.append(topL);
        occupiedSpaces.append(topR);
        occupiedSpaces.append(bottomR);
    }else{
        objectsDetected.append(bottomL);
        objectsDetected.append(topL);
        objectsDetected.append(topR);
        objectsDetected.append(bottomR);
    }

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

void grid::switchGrid() {

    displayGrid = !displayGrid;

}

void grid::switchBoxes() {

    displayBoxes = !displayBoxes;

}

void grid::switchLines() {

    displayLines = !displayLines;

}

void grid::switchColors() {

    for(uint i = 0; i < objectsDetected.getVertexCount(); i++){

        if(objectsDetected[0].color == sf::Color::Green)
            objectsDetected[i].color = sf::Color::Red;
        else
            objectsDetected[i].color = sf::Color::Green;
    }
}

void grid::switchOccupied() {
    displayOccupied = !displayOccupied;
}
