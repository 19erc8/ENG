//
// Created by Evan Cohen on 2022-11-27.
//

#include <iostream>
#include <string>

#include "ShapesGood.h"

using namespace std;

//Shape constructors
Shape::Shape() : length(0), width(0), colour("black") {}
Shape::Shape(int l, int w, const string& col) : length(l), width(w), colour(col) {}
Shape::~Shape() {}

//shape accessors
int Shape::getLength() const {
    return length;
}

int Shape::getWidth() const {
    return width;
}

string Shape::getColour() const {
    return colour;
}

//detirmines if an object is fillable
Fillable::Fillable(const string& m) : fillColour(m) {}
Fillable::~Fillable() {}
string Fillable::getFillColour() const {
    return fillColour;
}

//detirmines if ther is a text label on the shape
label::label(const string& lab) : text(lab) {}
label::~label() {}
string label::getText() const {
    return text;
}

//draws a square
Square::Square(int l, int w, const string& col) : Shape(l, w, col) {}
Square::~Square() {}
void Square::drawOutline() const {
    cout << "\nDrawing a " + getColour() + " square.";
}
void Square::draw() {
    drawOutline();
}

//draws filled square
FilledSquare::FilledSquare(int l, int w, const string& col, const string& fillCol) : Square(l, w, col), Fillable(fillCol) {}

FilledSquare::~FilledSquare() {}

void FilledSquare::fill() {
    cout << " With " + getFillColour() + " fill.";
}
void FilledSquare::draw() {
    drawOutline();
    fill();
}

//draws filled square with text
FilledTextSquare::FilledTextSquare(int l, int w, const string& col, const string& fillCol,const string& text) : FilledSquare(l, w, col, fillCol), label(text) {}
FilledTextSquare::~FilledTextSquare() {}

void FilledTextSquare::drawText() {
    cout << " Containing the text: \"" << getText() << "\".";
}
void FilledTextSquare::draw() {
    drawOutline();
    fill();
    drawText();
}

//draws a circle
Circle::Circle(int l, int w, const string& col) : Shape(l, w, col) {}
Circle::~Circle() {}
void Circle::drawOutline() const {
    cout << "\nDrawing a " + getColour() + " circle.";
}
void Circle::draw() {
    drawOutline();
}

//draws a filled circle
FilledCircle::FilledCircle(int l, int w, const string& col, const string& fillCol) : Circle(l, w, col), Fillable(fillCol) {}
FilledCircle::~FilledCircle() {}

void FilledCircle::fill() {
    cout << " With " + getFillColour() + " fill.";
}
void FilledCircle::draw() {
    drawOutline();
    fill();
}

//draws an arc
Arc::Arc(int l, int w, const string& col) : Shape(l, w, col) {}
Arc::~Arc() {}
void Arc::draw() {
    cout << "\nDrawing a " + getColour() + " arc.";
}