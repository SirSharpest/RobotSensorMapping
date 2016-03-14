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


    std::vector<sf::Vertex> tmpLines;

    //This is the sensor readings adjusted for angle
    std::vector<float> tmpVect = toProcess.front().getSensors();

    //Need to compute each reading to take into account position of the robot
    for(int i = 0; i < tmpVect.size(); i++){

        //Lets ignore all the infinity values
        if(tmpVect[i] >= 2.6f){
            continue;
        }


        //Need to add starting point first each time
        sf::Vertex startPoint(sf::Vector2f(toProcess.front().getPos().x, toProcess.front().getPos().y));
        startPoint.color = sf::Color::Green;


        sf::Vector2f coords;

        //If the point is greater than 0.5 (the size of a gird currently
        if(tmpVect[i] > 0.1f){

            //We want to record that and add it

            float j = tmpVect[i];

            while(j>0.1f){

                j-=0.1f;

                coords.x = (float) (toProcess.front().getPos().x + j * cos( (M_PI / 180 * ((i * 45))) +
                                                                                    (M_PI / 180 * toProcess.front().getAngle())) );

                coords.y = (float) (toProcess.front().getPos().y + j * sin( (M_PI / 180 * ((i * 45)))
                                                                            + (M_PI / 180 * toProcess.front().getAngle()) ));
                sf::Vertex endPoint(coords);
                endPoint.color = sf::Color::Red;
                tmpLines.push_back(startPoint);
                tmpLines.push_back(endPoint);

            }


        }


        coords.x = (float) (toProcess.front().getPos().x + tmpVect[i] * cos( (M_PI / 180 * ((i * 45)))
                                                                             + (M_PI / 180 *  toProcess.front().getAngle())) );

        coords.y = (float) (toProcess.front().getPos().y + tmpVect[i] * sin((M_PI / 180 * ((i * 45))) +
                                                                                    (M_PI / 180 * toProcess.front().getAngle())) );

        sf::Vertex endPoint(coords);
        endPoint.color = sf::Color::Red;



        tmpLines.push_back(startPoint);
        tmpLines.push_back(endPoint);

    }

    toProcess.pop();

    return tmpLines;
}
