#pragma once
#include "picture.h"
#include <iostream>
using namespace std;

class ImageEditor
{
public:
    // The inFileName is the user's image file name, and the constructor uses it to load the image's pixels into the Picture pic object (the canvas), so you can edit it.
    // file name (like "cat.png")
	ImageEditor(string inFileName);
	void flipVertical();
	void flipHorizontal();
	void doubleSize();
    // redTarget: red component of the color you want to find in the image
    // greenTarget: green component of the target color
    // blueTarget: blue component of the target color
    // tolerance: how close a pixel's color must be to match the target color
    // newRed: red component of the new color to replace the target color with
    // newGreen: green component of the new replacement color
    // newBlue: blue component of the new replacement color
	void colorFilter(int redTarget, int greenTarget, int blueTarget, int tolerance, int newRed, int newGreen, int newBlue);
	void save(string outFileName);

private:
    // Swaps the colors of the pixel at (x1, y1) with the pixel at (x2, y2)
	void swapPixels(int x1, int y1, int x2, int y2);
    // below variable is holding the picture that the editor is modifying 
	Picture pic;
};
