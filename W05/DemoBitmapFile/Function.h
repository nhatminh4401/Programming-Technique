#ifndef FUNCTION_H
#define FUNCTION_H

#pragma once

#include<stdio.h>
#include<fstream>
#include<cstring>
#include<stdint.h>

using namespace std;

#pragma pack(1)
struct BmpSignature
{
	unsigned char data[2];
};

struct BmpHeader
{
	BmpSignature signature;
	uint32_t fileSize;
	uint16_t reserved1;
	uint16_t reserved2;
	uint32_t dataOffset;
};

struct BmpDib
{
	uint32_t dibSize;
	int32_t imageWidth;
	int32_t imageHeight;
	uint16_t colorPlaneCount;
	uint16_t pixelSize;
	uint32_t compressMethod;
	uint32_t bitmapByteCount;
	int32_t horizontalResolution;
	int32_t verticalResolution;
	uint32_t colorCount;
	uint32_t importantColorCount;
};

struct Color
{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
};

//struct ColorTable
//{
//	Color *colors;
//	uint32_t length;
//};

struct PixelArray
{
	unsigned char *rawBytes;
	int rawByteSize;
	int lineSize;
	char paddingSize;
	
	Color **pixels;
	uint32_t rowCount;
	uint32_t columnCount;
};

struct BmpFile
{
	BmpHeader header;
	BmpDib dib;
//	ColorTable colorTable;
	PixelArray pixelArray;
};

bool isBmpFile(FILE* f);
void readBmpHeader(FILE* f, BmpFile& bmp);
void readBmpDib(FILE* f, BmpFile& bmp);
void printBmpHeader(const BmpFile& bmp);
void printBmpDib(const BmpFile& bmp);
void readBmpPixelArray(FILE* f, BmpFile &bmp);
void initPixels(PixelArray& pa, int width, int height);
void drawBmp(const BmpFile& bmp);
void releaseBmpPixelArray(BmpFile& bmp);
void readBmpFile(const char* filename, BmpFile& bmp);

#endif
