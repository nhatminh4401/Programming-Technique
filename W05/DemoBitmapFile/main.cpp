#include "Function.h"
#define BMP_SOURCE "D:/pointillist.bmp"

void changeBmp(PixelArray& p)
{
	for(int i = 0; i < p.rowCount; i++)
		for(int j = 0; j < p.columnCount; j++)
		{
			Color *c = &p.pixels[i][j];
			Color *d = &p.pixels[i][j];
			
			c->red = d->red;
			c->green = d->green;
			c->blue = d->blue;
//			int avg = 0.33 * c->red + 0.33 * c->green + 0.33 * c->blue;
		}
}

void readBmp()
{
	BmpFile bmpSource;
	
	readBmpFile(BMP_SOURCE, bmpSource);
	printBmpHeader(bmpSource);
	printBmpDib(bmpSource);
	
	getchar();
	system("cls");
	
	changeBmp(bmpSource.pixelArray);
	drawBmp(bmpSource);

	releaseBmpPixelArray(bmpSource);
}
int main(){
	readBmp();
	return 0;
}
