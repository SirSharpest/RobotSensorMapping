//
// Created by nathan on 07/03/16.
// TODO: Set up scaling properly
//

#ifndef CS22510_GRID_HPP
#define CS22510_GRID_HPP

#include <iosfwd>
#include <iostream>
#include "dataManager.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include <math.h>

class grid : public sf::Drawable, public sf::Transformable{

private:

    sf::VertexArray straightLineReadings;
    sf::VertexArray objectsDetected;
    sf::VertexArray occupiedSpaces;
    sf::VertexArray gridMarkings;

    dataManager data; // Object used to retrieve data


    /*
     * Creates the memory required for a grid of a particular size
     */
    void setupGrid();


    /*
     * Sets up all required information for the background of the grid
     */
    void setUpBackground();

    /*
     * Is the interface function from SFML drawable type objects that is overloaded
     */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /*
     * Paints a square on the grid
     */
    void addSquare(float tlX, float tlY, float blX, float blY, float trX, float trY, float brX, float brY,
                       bool isOutline);

    /*
     * Boolean switches to change what is displayed on the window
     */
    bool displayGrid, displayBoxes, displayLines, displayOccupied;


public:

    /*
     * Default constructor
     */
    grid();


    /*
     * Called to perform 1 update of information on the grid
     */
    void updateGrid();


    /*
     * Collection of functions to flip the switches
     * which dictate what is displayed on the grid at any one time
     */
    void switchGrid();
    void switchBoxes();
    void switchLines();
    void switchColors();
    void switchOccupied();

    /*
     * Destructor
     */
    ~grid();

};


#endif //CS22510_GRID_HPP
