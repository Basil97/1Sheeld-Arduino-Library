/*

  Project:       1Sheeld Library 
  File:          GLCDButton.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/

#ifndef GLCDButton_h
#define GLCDButton_h

#define GLCD_BUTTON_TYPE					0x08
#define GLCD_BUTTON_TEXT					0x03
#define GLCD_BUTTON_DIMENSIONS				0x04
#define GLCD_BUTTON_STYLE					0x05

#define GLCD_BUTTON_VALUE					0x01

#define DIMENSION_2D						0x00
#define DIMENSION_3D						0x01

#include "InteractiveShapeClass.h"

class GLCDButton : public InteractiveShapeClass
{
public:
	GLCDButton(int , int , int ,int );
	GLCDButton(int , int , int ,int ,char *);
	void setText(char *);
	void setStyle(byte );
	void setDimensions(int,int);
	// bool isPressed();
	void setOnChange(void (*userFunction)(byte));
	byte value; 
private:
	void draw();
	int width; 
	int height;
	char * dataString;
	void (*onChangeCallback)(byte);
};

#endif