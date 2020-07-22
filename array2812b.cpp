#include "array2812b.h"



nBlock_Array2812B::nBlock_Array2812B(PinName MOSI, uint32_t numberLEDs) {
	
	// Number of LEDs to be used
	num_leds = numberLEDs;
	
	// Reset flag
	must_update = 0;
	
    // The pixel array control class.
    _pixel_array = new neopixel::PixelArray(MOSI, neopixel::BYTE_ORDER_GRB, neopixel::PROTOCOL_800KHZ);
	
	
}


void nBlock_Array2812B::triggerInput(uint32_t inputNumber, uint32_t value){
	// input 0 receives an array of bytes
	if (inputNumber == 0) {
		// Copy values to internal array
		uint8_t * source_values;
		source_values = ((uint8_t *)value);
		for (uint32_t i = 0; i < num_leds; i++) {
			pixels[i].red   = source_values[i*3];
			pixels[i].green = source_values[(i*3) + 1];
			pixels[i].blue  = source_values[(i*3) + 2];
		}
		must_update =  1;
		//for (uint32_t i = 0; i < (num_leds*3); i++) {
		//	arrayValues[i] = ((uint8_t *)value)[i];
		//}
	}
}

void nBlock_Array2812B :: endFrame(void){

	if (must_update) {
		must_update = 0;
		array.update(pixels, NUM_PIXELS);
	}
	
	
}


