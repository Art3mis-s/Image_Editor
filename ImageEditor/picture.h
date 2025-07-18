// This is a header guard to prevent multiple inclusions of this file
#ifndef PICTURE_H
#define PICTURE_H

// Includes necessary libraries for PNG handling and data structures
#include "lodepng.h"  // For PNG image loading/saving functionality
#include <string>     // For using string filenames
#include <vector>     // For storing pixel data in vectors

// Use the standard namespace to avoid prefixing with std::
using namespace std;

// The Picture class provides an interface for working with PNG images
class Picture
{
public:
    // ================= CONSTRUCTORS =================

    /**
     * Default constructor - creates an empty picture with zero width and height
     */
    Picture();

    /**
     * Constructs a picture by loading from a PNG file
     * @param filename Path to the PNG file to load
     */
    Picture(string filename);

    /**
     * Constructs a solid-color picture with specified dimensions
     * @param width  Width of the new image in pixels
     * @param height Height of the new image in pixels
     * @param red    Red component (0-255, default 255/white)
     * @param green  Green component (0-255, default 255/white)
     * @param blue   Blue component (0-255, default 255/white)
     */
    Picture(int width, int height, int red = 255, int green = 255, int blue = 255);

    /**
     * Constructs a picture from grayscale values (2D vector)
     * @param grays 2D vector of grayscale values (0-255)
     */
    Picture(const vector<vector<int>>& grays);

    // ================= GETTER METHODS =================

    /**
     * Gets the width of the image
     * @return Image width in pixels
     */
    int width() const { return _width; }

    /**
     * Gets the height of the image
     * @return Image height in pixels
     */
    int height() const { return _height; }

    // ================= IMAGE OPERATIONS =================

    /**
     * Saves the image to a PNG file
     * @param filename Path where to save the PNG file
     */
    void save(string filename) const;

    // ================= PIXEL ACCESSORS =================

    /**
     * Gets the red component of a pixel
     * @param x X-coordinate (column) of the pixel
     * @param y Y-coordinate (row) of the pixel
     * @return Red value (0-255) or 0 if coordinates are invalid
     */
    int red(int x, int y) const;

    /**
     * Gets the green component of a pixel
     * @param x X-coordinate (column) of the pixel
     * @param y Y-coordinate (row) of the pixel
     * @return Green value (0-255) or 0 if coordinates are invalid
     */
    int green(int x, int y) const;

    /**
     * Gets the blue component of a pixel
     * @param x X-coordinate (column) of the pixel
     * @param y Y-coordinate (row) of the pixel
     * @return Blue value (0-255) or 0 if coordinates are invalid
     */
    int blue(int x, int y) const;

    /**
     * Sets a pixel to a specific RGB color
     * @param x     X-coordinate (column) of the pixel
     * @param y     Y-coordinate (row) of the pixel
     * @param red   Red component (0-255)
     * @param green Green component (0-255)
     * @param blue  Blue component (0-255)
     */
    void set(int x, int y, int red, int green, int blue);

    // ================= ADVANCED OPERATIONS =================

    /**
     * Converts the image to grayscale values
     * @return 2D vector of grayscale values (0-255)
     */
    vector<vector<int>> grays() const;

    /**
     * Overlays another image onto this one
     * @param other The image to overlay
     * @param x     X-position for top-left corner
     * @param y     Y-position for top-left corner
     */
    void add(const Picture& other, int x = 0, int y = 0);

private:
    /**
     * Internal helper to ensure coordinates are within bounds
     * (expands image if necessary)
     */
    void ensure(int x, int y);
    
    // Internal storage of pixel data in RGBA format (Red, Green, Blue, Alpha)
    // Stored as a 1D vector: [R,G,B,A, R,G,B,A, ...]
    vector<unsigned char> _values;

    // Image dimensions
    int _width;   // Width in pixels
    int _height;  // Height in pixels
};

// End of header guard
#endif
