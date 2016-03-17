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
    sf::VertexArray boxesOnScreen;
    sf::VertexArray gridMarkings;

    dataManager data; // Object used to retrieve data


    /*
     * Creates the memory required for a grid of a particular size
     */
    void setupGrid();


    void setUpBackground();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void addSquare(float tlX, float tlY, float blX, float blY, float trX, float trY, float brX, float brY);

    bool displayGrid, displayBoxes, displayLines;


public:

    /*
     * Default constructor
     */
    grid();


    void updateGrid();


    void switchGrid();
    void switchBoxes();
    void switchLines();
    void switchColors();

    /*
     * Destructor
     */
    ~grid();

};


#endif //CS22510_GRID_HPP
