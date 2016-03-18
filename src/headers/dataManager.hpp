//
// Created by nathan on 07/03/16.
//

#ifndef CS22510_DATAMANAGER_HPP
#define CS22510_DATAMANAGER_HPP

#include <queue>
#include "sensorData.hpp"
#include <string>
#include <fstream>
#include <cmath>
#include <SFML/Graphics/VertexArray.hpp>

/*
 * Class that will read and manage the data read in
 * and used for the grid object
 */
class dataManager {


private:
    //Using a queue of nodes that need to be processed
    std::queue<sensorData> toProcess;

    /*
     * Gets the next reading to be processed
     * from the priority queue, that is displaying
     * detected objects
     */
    std::vector< sf::Vertex > getNextObjects();

    /*
     * Gets the next occupied squares reading
     */
    std::vector< sf::Vertex > getNextOccupiedSquares();


public:

    /*
     * Default constructor of dataManager to produce the inits needed
     */
    dataManager();

    /*
     * Reads in the data from two text files
     */
    void readData(std::string posesFile, std::string rangesFile);



    /*
     * Used to get all the data in one function rather than have
     * multiple queue systems
     */
    std::vector<std::vector<sf::Vertex >> getNextReading();

};




#endif //CS22510_DATAMANAGER_HPP
