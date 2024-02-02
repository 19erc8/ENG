//
// Created by Evan Cohen on 2022-12-16.
//

#include "practice.h"


BadPoint::BadPoint(string m){
    this->m = m;
}
const char *BadPoint::what()const noexcept{
    return m.c_str();
}

BadOutline::BadOutline(string m){
    this->m = m;
}
const char *BadOutline::what()const noexcept{
    return m.c_str();
}


Point::Point(float x, float y){
    if(x<0||x>200){
        throw BadPoint("X value out of bounds.");
    }
    if (y< 0 || y > 200) {
        throw BadPoint("Y value out of bounds.");
    }
    this->x =x;
    this->y =y;
}

float Point::getX() const {
    return x;
}
float Point::getY() const {
    return y;
}

Outline::Outline(float *x, float *y, int size) {
    if (size < 2) {throw BadOutline("Bad number of points");}

    this->size = size;
    points = new Point*[size];
    for (int i = 0; i < size; i++)
        points[i] = new Point(x[i], y[i]);
}

int Outline::getSize() const {
    return size;
}

Point &Outline::getPoint(int index) const {
    if (index < 0 || index >= size) {
        throw BadOutline("Index out of bounds.");
    }
    return *points[index];
}

Outline::~Outline() {
    for (int i = 0; i < size; i++) {
        delete points[i];
    }
    delete[] points;
}

Outline::Outline(const Outline &other) {
    size = other.size;
    points = new Point*[size];

    for (int i = 0; i < size; i++) {
        points[i] = new Point(other.points[i]->getX(), other.points[i]->getY());
    }
}

Outline &Outline::operator=(const Outline &other) {
    if (this != &other) {
        for (int i = 0; i < size; i++) {
            delete points[i];
        }
        delete[] points;
        size = other.size;
        points = new Point*[size];
        for (int i = 0; i < size; i++) {
            points[i] = new Point(other.points[i]->getX(), other.points[i]->getY());
        }
    }
    return *this;
}
