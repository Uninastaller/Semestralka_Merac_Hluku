/*
 *** references
 http://forum.arduino.cc/index.php?topic=432991.msg2988230#msg2988230
 http://audiojudgement.com/how-to-calculate-decibels/
 https://www.luisllamas.es/medir-sonido-con-arduino-y-microfono-amplificado-max9812/
 */

#include "max9812.h"
#include "adc.h"
//const int sensitivity = -54;     // microphone sensitivity in dB
const int gain = 20;             // op-amp gain dB = 10V = dB

int signalMax = 0;
int signalMin = 4096;       // 12 bit ADC = 2^12

double VoltsToDecibels() {
	// https://electronics.stackexchange.com/questions/96205/how-to-convert-volts-in-db-spl
	// The microphone sensitivity is -58db, so V RMS / PA is 0.001259
	// conversion using : http://www.sengpielaudio.com/calculator-gainloss.htm
	unsigned int peakToPeak = signalMax - signalMin;         // peak-to-peak level

//	for (int i = 0; i < ADC_DMA_BUFFER_SIZE; i++) {
//		if (adcConvertedDataBuffer[i] > signalMax) {
//			signalMax = adcConvertedDataBuffer[i];
//		} else if (adcConvertedDataBuffer[i] < signalMin) {
//			signalMin = adcConvertedDataBuffer[i];
//		}
//	}
	actual_voltage = ((peakToPeak * 5.0) / 4096) * 10;

	// https://electronics.stackexchange.com/questions/96205/how-to-convert-volts-in-db-spl
	// The microphone sensitivity is -58db, so V RMS / PA is 0.001259
	// conversion using : http://www.sengpielaudio.com/calculator-gainloss.htm
//	double volts_db = 20 * log10(actual_voltage / 0.00204);

	//  94 is a 1 Pa expressed as dB SPL
	// https://support.biamp.com/General/Audio/Microphone_sensitivity
	// https://forums.adafruit.com/download/file.php?id=38278&sid=3f8400ec828f5b22ed3be3ef64eb4e86
//	double spl_db = volts_db + 94 + sensitivity - gain;

//	return volts_db;
	signalMax = 0;
	signalMin = 4096;
	return 20 * log10(actual_voltage / 0.00204);
}
