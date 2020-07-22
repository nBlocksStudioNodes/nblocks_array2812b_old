
#ifndef __NB_NEOPIXEL1599
#define __NB_NEOPIXEL1599

// This is max number of pixels possible, actual number of
// used pixels will be set in constructor
#define _NUM_PIXELS 64

#include "nworkbench.h"
#include "PixelArray/neopixel.h"

class nBlock_Array2812B: public nBlockSimpleNode<1> {
public:

    nBlock_Array2812B(PinName MOSI, uint32_t numberLEDs);
    void triggerInput(uint32_t inputNumber, uint32_t value);
	void endFrame();
	
   
private:

    // Declare array/buffer of type Pixel.
    neopixel::Pixel pixels[_NUM_PIXELS];	
	//uint8_t  arrayValues[_NUM_PIXELS*3UL] =  { 0UL };
	
	
    // The pixel array control class.
    neopixel::PixelArray * _pixel_array;

	uint32_t num_leds;
	uint32_t must_update = 0;
};

#endif