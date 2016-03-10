//
// Created by nathan on 3/8/16.
//

#include "headers/sensorData.hpp"

sensorData::sensorData(float s0, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float posX,
                       float posY, float angle) {

    this->ranges.push_back(s0);
    this->ranges.push_back(s1);
    this->ranges.push_back(s2);
    this->ranges.push_back(s3);
    this->ranges.push_back(s4);
    this->ranges.push_back(s5);
    this->ranges.push_back(s6);
    this->ranges.push_back(s7);

    this->posX = posX;
    this->posY = posY;
    this->angle = angle;

}

std::vector<float> sensorData::getSensors() {
    return ranges;
}

sf::Vector2f sensorData::getPos() {
    return sf::Vector2<float>(posX, posY);
}

float sensorData::getAngle() {
    return this->angle;
}
