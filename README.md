# RobotSensorMapping
This is a little program that does a few things 

- It takes in some input (sensor readings from a robot) 
- Computes the data, taking into account position of the input's sensors 
- Outputs a 2D graphical map of objects in an environment

##Data provided:
Output Folder:
    - This folder contains 41 images of this program in action from start to finish!
    - The program generates this folder by itself

src Folder:
    - This folder contains all of the .hpp and .cpp files that are the source of this program

Resources Folder:
    - This folder contains the raw data that was given as .txt files in order to be ran by this program

Video folder:
    - This folder contains a video of the project running.
    - The video clearly shows how to build and run this program from a linux terminal
        - Note that there are no build errors or compiler warnings
    - The video at the end shows the additional functionality which I added to give more detailed information


##Building & Running this code
In order to build this code on any system (Windows, Mac X or Linux) you will need:
    - CMake 2.6 or higher
    - C++11
    - SFML 2.x or higher

To build the project on Linux (I don't use windows so cannot provide accurate instructions):
    - "cmake CMakeLists.txt"
    - "make"

To execute the program on Linux:
    - "./CS22510"
