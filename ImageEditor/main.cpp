//
//  main.cpp
//  
//
//  Created by Shabana on 5/14/25.
//

#include <iostream>
#include "Picture.h"
using namespace std;

int main() {
    Picture pic;

    if (!pic.load("pikachu.png")) {
        cout << "Failed to load image." << endl;
        return 1;
    }

    // Call your image functions
    flipVertical(pic);
    flipHorizontal(pic);
    doubleSize(pic);
    colorFilter(pic, 255, 0, 0, 50, 0, 255, 0);  // Example filter

    // Save the modified image
    save(pic, "outputImage.jpg");

    cout << "Image processing complete. Saved as pikachu.png" << endl;

    return 0;
}
