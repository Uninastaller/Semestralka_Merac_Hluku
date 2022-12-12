/*
 *** references
 http://forum.arduino.cc/index.php?topic=432991.msg2988230#msg2988230
 http://audiojudgement.com/how-to-calculate-decibels/
 https://www.luisllamas.es/medir-sonido-con-arduino-y-microfono-amplificado-max9812/
 */

#include "max9812.h"
#include "adc.h"
#include "math.h"

//const int sensitivity = -54;     // microphone sensitivity in dB
const int gain = 20;             // op-amp gain dB = 10V = 20dB

uint16_t signalMax = 0;
uint16_t signalMin = 4096;       // 12 bit ADC = 2^12

double VoltsToDecibels() {

	uint16_t peakToPeak = signalMax - signalMin;         // peak-to-peak level

	actual_voltage = ((peakToPeak * ADC_VDDA_VOLTAGE) / ADC_RESOLUTION_MAX_VALUE) * 10;

	// https://electronics.stackexchange.com/questions/96205/how-to-convert-volts-in-db-spl
	// The microphone sensitivity is -53.8db, so V RMS / PA is 0.00204
	// conversion using : http://www.sengpielaudio.com/calculator-gainloss.htm
	signalMax = 0;
	signalMin = 4096;
	return 20 * log10(actual_voltage / 0.00204);
}
