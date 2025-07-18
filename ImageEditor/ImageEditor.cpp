//  ImageEditor.cpp
//  Created by Shabana on 5/14/25.
// This is the constructor function named ImageEditor which belongs to the ImageEditor class.
// The :: is called the scope resolution operator, linking the constructor definition to the class.
ImageEditor::ImageEditor(string inFileName)
// load that user's file (.png file) into the pic object 
: pic(inFileName) {}

void ImageEditor::swapPixels(int x1, int y1, int x2, int y2)
{
    // Get RGB of first pixel
    // These three integers (r1, g1, b1) represent the RGB color of the first pixel.
    // (r1, g1, b1) are temporary holding spots for color values during the swap they are temporary variables;
    // 2 pixels cause we are swaping to pixels at a time but with a loop all the pic
    int r1 = pic.red(x1, y1);
    int g1 = pic.green(x1, y1);
    int b1 = pic.blue(x1, y1);
    
    // Get RGB of second pixel
    int r2 = pic.red(x2, y2);
    int g2 = pic.green(x2, y2);
    int b2 = pic.blue(x2, y2);
    
    // Swap the pixel's color
    // When you call pic.set(x, y, red, green, blue), you change the pixel’s color in the actual
    // image data stored inside the pic object.
    pic.set(x1, y1, r2, g2, b2);
    pic.set(x2, y2, r1, g1, b1);
    
}

void flipVertical()
{
    /*
     | Step | x (column) | y (row, top half) | oppositeY (row, bottom half) | Pixels swapped           |
     | ---- | ---------- | ----------------- | ---------------------------- | ------------------------ |
     | 1    | 0          | 0                 | 3 (4-0-1)                    | (0,0) swapped with (0,3) |
     | 2    | 0          | 1                 | 2 (4-1-1)                    | (0,1) swapped with (0,2) |
     | 3    | 1          | 0                 | 3                            | (1,0) swapped with (1,3) |
     | 4    | 1          | 1                 | 2                            | (1,1) swapped with (1,2) |
     | 5    | 2          | 0                 | 3                            | (2,0) swapped with (2,3) |
     | 6    | 2          | 1                 | 2                            | (2,1) swapped with (2,2) |
     | 7    | 3          | 0                 | 3                            | (3,0) swapped with (3,3) |
     | 8    | 3          | 1                 | 2                            | (3,1) swapped with (3,2) |

     */
    
    // // Get the image width (number of columns)
    int width = pic.width();
    // Get the image height (number of rows)
    int height = pic.height();
    
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height / 2; y++)
        {
            // // Swap the pixel at (x, y) with the pixel at (x, h - y - 1) to flip vertically in column x
            swapPixels(x, y, x, height - y - 1);
        }
    }
}
void flipHorizontal()
{
    int width = pic.width();
    int height = pic.height();
    
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width / 2; x++)
        {
            swapPixels(x, y, width - x - 1, y);
        }
    }
}
void doubleSize()
{
    /*
     | Original (x, y) | xOut = x * 2 | yOut = y * 2 | Expanded Pixels in picOut                                 |
     |-----------------|--------------|--------------|------------------------------------------------------------|
     | (0, 0)          | 0            | 0            | (0,0), (1,0), (0,1), (1,1) ← copies of pixel (0,0)         |
     | (1, 0)          | 2            | 0            | (2,0), (3,0), (2,1), (3,1) ← copies of pixel (1,0)         |
     | (0, 1)          | 0            | 2            | (0,2), (1,2), (0,3), (1,3) ← copies of pixel (0,1)         |
     | (1, 1)          | 2            | 2            | (2,2), (3,2), (2,3), (3,3) ← copies of pixel (1,1)         |
     */
    int width = pic.width();
    int height = pic.height();
    
    // // Get original image width and height
    Picture picOut(width * 2, height * 2);
    
    // Loop through each pixel in the original image
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // Calculate the top-left coordinates of the 2×2 block in picOut
            // These two are the counters(coordinates)
            int xOut = x * 2;
            int yOut = y * 2;
            
            // Copy the red, green, and blue values to 4 adjacent pixels in picOut
            
            /*
               Explanation of doubleSize() logic:

               - We are doubling the size of the image, so each pixel in the original image
                 becomes a 2x2 block in the new image (picOut).

               - We loop through each pixel (x, y) in the original image (pic), and get its
                 red, green, and blue color values using getRed, getGreen, and getBlue.

               - We then copy this color into 4 adjacent pixels in the new image (picOut):
                   (xOut, yOut)
                   (xOut + 1, yOut)
                   (xOut, yOut + 1)
                   (xOut + 1, yOut + 1)

               - xOut and yOut are used to track the position in the larger image.
                 They start at 0 and increase by 2 each time because we are placing
                 a 2x2 block for each original pixel.

               - setRGB is used to set the color at those new locations.

               Summary: get color from (x, y) in the small image, then set the same color
               in 4 spots (2x2 block) in the bigger image to "stretch" it.
             */

             */
            // (0, 0)
            picOut.setRed(xOut, yOut, pic.getRed(x,y));
            picOut.setGreen(xOut, yOut, pic.getGreen(x,y));
            picOut.setBlue(xOut, yOut, pic.Blue(x,y));
            
            // (1,0)
            picOut.setRed(xOut + 1, yOut, pic.getRed(x,y));
            picOut.setGreen(xOut + 1, yOut, pic.getGreen(x,y));
            picOut.setBlue(xOut + 1, yOut, pic.Blue(x,y));
            
            // (0, 1)
            picOut.setRed(xOut, yOut + 1, pic.getRed(x,y));
            picOut.setGreen(xOut, yOut + 1, pic.getGreen(x,y));
            picOut.setBlue(xOut, yOut + 1, pic.Blue(x,y));
            
            // (1, 1)
            picOut.setRed(xOut + 1, yOut + 1, pic.getRed(x,y));
            picOut.setGreen(xOut + 1, yOut + 1, pic.getGreen(x,y));
            picOut.setBlue(xOut + 1, yOut + 1, pic.Blue(x,y));
            
            xOut += 2; // Move 2 columns ahead in new images
        }
        
        yOut += 2; // Move 2 rows ahead in new image
    }
    // Replace original image with the bigger one
    pic = picOut;
}

void colorFilter(int redTarget, int greenTarget, int blueTarget, int tolerance, int newRed, int newGreen, int newBlue)
{
    int width = pic.width();
    int height = pic.height();
    
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            // Get the original RGB values of pixel (x, y)
            int red = gerRed(x, y);
            int green = getGreen(x ,y);
            int blue = getBlue(x, y);
            
            // Calculate the absolute difference from teh target color
            int redDiff = abs(red - redTarget);
            int greenDiff = abs(green - greenTarget);
            int blueDiff = abs(blue - blueTarget);
            
            // If all color difference are within the tolarance, we recolor it
            if (redDiff <= tolarance && greenDiff <= tolarance && blueDiff <= tolarance)
            {
                setRGB (x, y, newRed, newGreen, newBlue);
            }
        }
    }
}

void save(string outFileName)
{
    // Assuming pic has a save() method that takes a filename
    pic.save(outFileName);
}

