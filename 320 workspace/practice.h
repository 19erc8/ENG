//
// Created by Evan Cohen on 2022-12-16.

#include <stdlib.h>
#pragma once
#include <iostream>
#include <exception>

using namespace std;

class BadPoint:public std::exception{
public:
    explicit BadPoint(string m);
    const char * what() const noexcept override;
private:
    string m;
};

class BadOutline:public std::exception{
public:
    explicit BadOutline(string m);
    const char * what() const noexcept override;
private:
    string m;
};

class Point{
public:
    Point() = default;
    Point(float x, float y);

    float getX() const;
    float getY() const;
private:
    float x, y;
};

class Outline{
public:
    Outline(float *x, float *y, int size);

    int getSize() const;
    Point& getPoint(int index) const;

    Outline(const Outline& other);
    Outline& operator=(const Outline& other);
    ~Outline();
private:
    Point** points;
    int size;
};