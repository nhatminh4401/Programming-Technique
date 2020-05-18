#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>

using namespace std;

void generateBitmapImage(unsigned char *image, int height, int width);
unsigned char* createBMPHeader(int height, int width, int paddingSize);
unsigned char* createDIBHeader(int height, int width);
void drawFlag(int &height, int &width);

const int bytesPerPixel = 3;   //  This is a 24-bit bitmap file setting
const int BmpHeaderSize = 14;  // This is a 24-bit bitmap file setting								
const int DibHeaderSize = 40;  //This is a 24-bit bitmap file setting    


#endif
