//
// Created by nathan on 07/03/16.
//
#include <SFML/Graphics.hpp>
#include "headers/grid.hpp"
#include <string>



int main() {

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
    window.setFramerateLimit(10);


    grid myGrid;

    //Make bigger but rotate
    myGrid.setPosition(0, 800);
    myGrid.setScale(sf::Vector2f(80,-80));

    //Image used to store output
    sf::Image screenshot;

    //Image name, that will be appended to
    std::string folderLocaiton = "output/";

    //Clock used to track when to output next reading
    sf::Clock clock;

    //counter to check how many readings have been done
    int counter = 0;


    for(int i = 0; i < 41; i++){
        myGrid.updateGrid();
    }

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed){


                //Hide/Show grid
                if(event.key.code == sf::Keyboard::G){
                    myGrid.switchGrid();
                }
                //Hide/Show boxes
                else if(event.key.code == sf::Keyboard::B){
                    myGrid.switchBoxes();
                }
                else if(event.key.code == sf::Keyboard::L){
                    myGrid.switchLines();
                }
                else if(event.key.code == sf::Keyboard::C){
                    myGrid.switchColors();
                }


            }

        }

        if(clock.getElapsedTime().asSeconds() > 2){
            myGrid.updateGrid();
            clock.restart();
          //  screenshot = window.capture();
          //  screenshot.saveToFile(folderLocaiton + std::to_string(counter) + ".png" );
          //  counter++;
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(myGrid);


        // end the current frame
        window.display();

        if(counter >= 41)
            break;


    }


    std::cout << "oops";

    return 0;
}
