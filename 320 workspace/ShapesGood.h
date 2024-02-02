//
// Created by Evan Cohen on 2022-11-27.
//

#ifndef INC_320_WORKSPACE_SHAPESGOOD_H
#define INC_320_WORKSPACE_SHAPESGOOD_H

#endif //INC_320_WORKSPACE_SHAPESGOOD_H

#include <string>
using namespace std;

#pragma once

//main shape class
class Shape {
public:
    //constructors
    Shape();
    Shape(int length, int width, const string& colour);

    //accessors
    int getLength() const;
    int getWidth() const;
    string getColour() const;

    virtual ~Shape();
    virtual void draw() = 0;
private:
    int length;
    int width;
    string colour;
};

class Fillable {
public:
    //constructors
    Fillable(const string& fillColour);
    virtual ~Fillable();
    virtual void fill() = 0;

    //accessors
    string getFillColour() const;
private:
    string fillColour;
};

class label {
public:
    //constructors
    label(const string& text);

    //accessors
    string getText() const;

    virtual ~label();
    virtual void drawText() = 0;
private:
    string text;
};

class Square : public Shape {
public:
    //constructors
    Square(int length, int width, const string& colour);
    ~Square();

    void drawOutline() const;
    void draw();
};

class FilledSquare : public Square, public Fillable {
public:
    //constructors
    FilledSquare(int length, int width, const string& colour, const string& fillColour);
    ~FilledSquare();

    void fill();
    void draw();
};

class FilledTextSquare : public FilledSquare, public label {
public:
    //constructors
    FilledTextSquare(int length, int width, const string& colour, const string& fillColour,
                     const string& text);
    ~FilledTextSquare();
    void drawText();
    void draw();
};

class Circle : public Shape {
public:
    //constructors
    Circle(int length, int width, const string& colour);
    ~Circle();
    void drawOutline() const;
    void draw();
};

class FilledCircle : public Circle, public Fillable {
public:
    //constructors
    FilledCircle(int length, int width, const string& colour, const string& fillColour);
    ~FilledCircle();

    void fill();
    void draw();
};

class Arc : public Shape {
public:
    //constructors
    Arc(int length, int width, const string& colour);
    ~Arc();

    void draw();
};