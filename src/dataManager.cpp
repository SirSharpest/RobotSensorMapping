//
// Created by nathan on 07/03/16.
//

#include <iostream>
#include "headers/dataManager.hpp"



dataManager::dataManager() {

}


void dataManager::readData(std::string posesFile, std::string rangesFile) {


    std::ifstream posFile;
    posFile.open(posesFile);

    std::ifstream rangFile;
    rangFile.open(rangesFile);

    while(!posFile.eof() && !rangFile.eof()){

        float s0, s1, s2, s3, s4, s5, s6, s7, posX, posY, angle;

        rangFile >> s0 >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7;
        posFile >> posX >> posY >> angle;

        toProcess.push(sensorData(s0, s1, s2, s3, s4, s5, s6, s7,
        posX, posY, angle));


    }


}

std::vector< sf::Vertex > dataManager::getNextReading() {

    //TODO: Calculate all the stuff

    std::vector<sf::Vertex> tmpLines;

    //This is the sensor readings adjusted for angle
    std::vector<float> tmpVect = toProcess.front().getSensors();

    //Need to compute each reading to take into account position of the robot
    for(int i = 0; i < tmpVect.size(); i++){

        //Need to add starting point first each time
        tmpLines.push_back(sf::Vertex(sf::Vector2f(toProcess.front().getPos().x, toProcess.front().getPos().y)));




        sf::Vector2f coords;
        coords.x = (toProcess.front().getPos().x + tmpVect[i] * cos(M_PI/180 * ((i*45)) + toProcess.front().getAngle()) );
        coords.y = (toProcess.front().getPos().y + tmpVect[i] * sin(M_PI/180 * ((i*45)) + toProcess.front().getAngle()) );
        
        tmpLines.push_back(sf::Vertex(coords));

    }


    toProcess.pop();


    return tmpLines;
}
