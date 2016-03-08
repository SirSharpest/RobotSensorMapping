//
// Created by nathan on 3/8/16.
//

#ifndef CS22510_DATANODE_H
#define CS22510_DATANODE_H


#include <vector>

class sensorData {

private:
    std::vector<float> ranges;
    float posX;
    float posY;
    float angle;


public:

    sensorData(float s0, float s1, float s2, float s3, float s4, float s5, float s6, float s7,
    float posX, float posY, float angle);



};


#endif //CS22510_DATANODE_H
