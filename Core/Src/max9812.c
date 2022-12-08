/*
 *** references
http://forum.arduino.cc/index.php?topic=432991.msg2988230#msg2988230
http://audiojudgement.com/how-to-calculate-decibels/
https://www.luisllamas.es/medir-sonido-con-arduino-y-microfono-amplificado-max9812/
 */

#include "max9812.h"
#include "adc.h"
const int sensitivity = -58;     // microphone sensitivity in dB
const int gain = 20;             // op-amp gain dB

double VoltsToDecibels()
{
      // https://electronics.stackexchange.com/questions/96205/how-to-convert-volts-in-db-spl
      // The microphone sensitivity is -58db, so V RMS / PA is 0.001259
      // conversion using : http://www.sengpielaudio.com/calculator-gainloss.htm
   double volts_db = 20*log10(actual_voltage/0.001259);


     //  94 is a 1 Pa expressed as dB SPL
     // https://support.biamp.com/General/Audio/Microphone_sensitivity
     // https://forums.adafruit.com/download/file.php?id=38278&sid=3f8400ec828f5b22ed3be3ef64eb4e86
   double spl_db = volts_db + 94 + sensitivity - gain;

   return spl_db;
}
