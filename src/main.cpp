//
// Created by nathan on 07/03/16.
//
#include <SFML/Graphics.hpp>
#include "headers/grid.hpp"


/*
 *
 *  TODO: Adjust for robot angle
 *  TODO: paint path in sequence and taking a fixed time step
 *
 */


int main() {

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
    window.setFramerateLimit(10);

    grid myGrid;

    //Make bigger but rotate
    myGrid.setPosition(0, 800);
    myGrid.setScale(sf::Vector2f(80,-80));



    for(int i = 0; i < 1; i++){myGrid.updateGrid();}

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(myGrid);


        // end the current frame
        window.display();
    }




    std::cout << "oops";

    return 0;
}