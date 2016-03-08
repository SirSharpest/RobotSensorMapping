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

