//
// Created by nathan on 07/03/16.
//
#include <SFML/Graphics.hpp>
#include "headers/grid.hpp"
#include "headers/dataManager.hpp"

#define DISPLAY


/*
 *
 *  TODO: Adjust for robot angle
 *  TODO: paint path in sequence and taking a fixed time step
 *
 */


int main() {

#ifdef DISPLAY
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(10);


    /**
     * Example of how to do lines
     */
    sf::VertexArray lines(sf::Lines);

    sf::Vertex vertex(sf::Vector2f(10, 10), sf::Color::Red);
    sf::Vertex vertex1(sf::Vector2f(100, 10), sf::Color::Red);
    lines.append(vertex);
    lines.append(vertex1);

    sf::Vertex vertex2(sf::Vector2f(20, 50), sf::Color::Red);
    sf::Vertex vertex3(sf::Vector2f(200, 150), sf::Color::Red);
    lines.append(vertex2);
    lines.append(vertex3);


    sf::VertexArray triangle(sf::Triangles, 3);

    // define the position of the triangle's points
    triangle[0].position = sf::Vector2f(200, 100);
    triangle[1].position = sf::Vector2f(250, 150);
    triangle[2].position = sf::Vector2f(600, 170);

// define the color of the triangle's points
    triangle[0].color = sf::Color::Red;
    triangle[1].color = sf::Color::Blue;
    triangle[2].color = sf::Color::Green;



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
        window.draw(lines);
        window.draw(triangle);

        // end the current frame
        window.display();
    }
#endif


    grid myGrid;
    dataManager myManager;

    myManager.readData("resources/poses.txt", "resources/ranges.txt");

    std::cout << "oops";

    return 0;
}