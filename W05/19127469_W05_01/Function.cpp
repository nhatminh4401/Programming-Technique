#include "Function.h"
#define IMAGE_SOURCE "D:/EnglandFlag.bmp"
void generateBitmapImage(unsigned char *image, int height, int width){

    unsigned char padding[3] = {0, 0, 0};
    int widthSize = width*bytesPerPixel;
    int paddingSize = (4 - widthSize % 4) % 4;

    unsigned char* BmpHeader = createBMPHeader(height, width, paddingSize);
    unsigned char* DibHeader = createDIBHeader(height, width);

    FILE* imageFile = fopen(IMAGE_SOURCE, "wb");

    fwrite(BmpHeader, 1, BmpHeaderSize, imageFile);
    fwrite(DibHeader, 1, DibHeaderSize, imageFile);


    for(int i = 0; i < height; i++){
        fwrite(image + ( i*widthSize), bytesPerPixel, width, imageFile);
        fwrite(padding, 1, paddingSize, imageFile);
    }

    fclose(imageFile);
}

unsigned char* createBMPHeader(int height, int width, int paddingSize){
	int widthSize = width*bytesPerPixel;
    int fileSize = BmpHeaderSize + DibHeaderSize + (widthSize + paddingSize) * height;

    static unsigned char BmpHeader[] = {
        0,0, // signature
        0,0,0,0, // image file size in bytes
        0,0,0,0, // reserved
        0,0,0,0, // start of pixel array
    };

    BmpHeader[0] = 'B';
    BmpHeader[1] = 'M';
    BmpHeader[2] = fileSize;
    BmpHeader[3] = fileSize >> 8;
    BmpHeader[4] = fileSize >> 16;
    BmpHeader[5] = fileSize >> 24;
    BmpHeader[10] = BmpHeaderSize + DibHeaderSize;

    return BmpHeader;
}

unsigned char* createDIBHeader(int height, int width){
	
    static unsigned char DibHeader[] = {
        0,0,0,0, // header size
        0,0,0,0, // image width
        0,0,0,0, // image height
        0,0, // number of color planes
        0,0, // bits per pixel
        0,0,0,0, // compression
        0,0,0,0, // image size
        0,0,0,0, // horizontal resolution
        0,0,0,0, // vertical resolution
        0,0,0,0, // colors in color table
        0,0,0,0, // important color count
    };

    DibHeader[0] = DibHeaderSize;
    DibHeader[4] = width;
    DibHeader[5] = width >> 8;
    DibHeader[6] = width >> 16;
    DibHeader[7] = width >> 24;
    DibHeader[8] = height;
    DibHeader[9] = height >> 8;
    DibHeader[10] = height >> 16;
    DibHeader[11] = height >> 24;
    DibHeader[12] = 1;
    DibHeader[14] = bytesPerPixel*8;

    return DibHeader;
}

void drawFlag(int &height, int &width){

	unsigned char image[height][width][bytesPerPixel];
	int i, j;
	for( i = 0; i < height; i++){          //Draw an entire white picture
        for(j = 0; j < width; j++){
            image[i][j][2] = 255; 
            image[i][j][1] = 255; 
            image[i][j][0] = 255; 
        }
    }
    
    for( i = 2 * height / 5; i < 3 * height / 5; i++){         //Draw a horizontal red line
	    for( j = 0; j < width; j++){
	        image[i][j][2] = 190; 
	        image[i][j][1] = 20; 
	        image[i][j][0] = 35; 
	    }
	}
	
	for( i = 0; i < height; i++){                          // Draw a vertical red line
	    for( j= 3 * width / 7; j < 4 * width / 7; j++){
	        image[i][j][2] = 190; 
	        image[i][j][1] = 20; 
	        image[i][j][0] = 35; 
	    }
	}  
	
	generateBitmapImage((unsigned char *)image, height, width);
    cout << "\nImage generated!!" << endl;
    cout << IMAGE_SOURCE;
}
