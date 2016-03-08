//
// Created by nathan on 07/03/16.
//

#ifndef CS22510_DATAMANAGER_HPP
#define CS22510_DATAMANAGER_HPP

#include <queue>
#include "sensorData.hpp"
#include <string>
#include <fstream>

/*
 * Class that will read and manage the data read in
 * and used for the grid object
 */
class dataManager {


private:
    //Using a queue of nodes that need to be processed
    std::queue<sensorData> toProcess;


public:

    dataManager();

    /*
     * Reads in the data from two text files
     */
    void readData(std::string posesFile, std::string rangesFile);



};


#endif //CS22510_DATAMANAGER_HPP
