//
// Created by nathan on 07/03/16.
// TODO: Set up scaling properly
//

#ifndef CS22510_GRID_HPP
#define CS22510_GRID_HPP

#include <iosfwd>
#include <iostream>
#include "dataManager.hpp"
#include "cell.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

class grid : public sf::Drawable, public sf::Transformable{

private:



    //TODO: Is this needed???
    const short gridSize; // Size of the grid (x == y)
    short cellSize; // Size of each cell

    std::vector<std::vector<cell> > cellGrid;

    sf::VertexArray vertex;

    dataManager data; // Object used to retrieve data


    /*
     * Functions to be called in the constructor
     * which will define environment details
     */
    void setGridSize(short newGridSize);
    void setCellSize(short newCellSize);

    /*
     * Creates the memory required for a grid of a particular size
     */
    void setupGrid(const short gridSize);


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:

    /*
     * Default constructor
     */
    grid();


    /*
     * Overloading the << operator so that the object can easily be printed
     */
    friend std::ostream& operator<<(std::ostream& os, const grid& gd);


    void updateGrid();


    /*
     * Destructor
     */
    ~grid();

};


#endif //CS22510_GRID_HPP
