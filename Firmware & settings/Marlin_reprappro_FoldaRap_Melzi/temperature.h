/*
  temperature.h - temperature controller
  Part of Marlin

  Copyright (c) 2011 Erik van der Zalm

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef temperature_h
#define temperature_h 

#include "Marlin.h"
#include "planner.h"
#include "slave_comms.h"

// If we are using a slave board we have multiple extruders, but we only have to worry
// about the temperature of the first one of them.

#ifdef REPRAPPRO_MULTIMATERIALS
#define EXTRUDERS_T 1
#else
#define EXTRUDERS_T EXTRUDERS
#endif

// public functions
void tp_init();  //initialise the heating
void manage_heater(); //it is critical that this is called periodically.

//low leven conversion routines
// do not use this routines and variables outsie of temperature.cpp
int temp2analog(int celsius, uint8_t e);
int temp2analogBed(int celsius);
float analog2temp(int raw, uint8_t e);
float analog2tempBed(int raw);
extern int target_raw[EXTRUDERS_T];  
extern int heatingtarget_raw[EXTRUDERS_T];  
extern int current_raw[EXTRUDERS_T];
  static int minttemp[EXTRUDERS_T] = { 50 };
  static int maxttemp[EXTRUDERS_T] = { 16383 }; // the first value used for all
extern int target_raw_bed;
extern int current_raw_bed;
extern int b_beta;
extern int b_resistor;
extern long b_thermistor;
extern float b_inf;

extern int n_beta;
extern int n_resistor;
extern long n_thermistor;
extern float n_inf;

extern float Kp,Ki,Kd,Kc;
extern int Ki_Max;

#ifdef PIDTEMP
  extern float pid_setpoint[EXTRUDERS_T];
#endif
  
//high level conversion routines, for use outside of temperature.cpp
//inline so that there is no performance decrease.
//deg=degreeCelsius

#ifdef REPRAPPRO_MULTIMATERIALS
FORCE_INLINE float degHotend(uint8_t extruder) 
{
  if(extruder == 0)  
  	return analog2temp(current_raw[extruder], extruder);
  else
	return slaveDegHotend(extruder);
};

FORCE_INLINE void setTargetHotend(const float &celsius, uint8_t extruder) 
{
  if(extruder == 0)
  {  
  	target_raw[extruder] = temp2analog(celsius, extruder);
	#ifdef PIDTEMP
  		pid_setpoint[extruder] = celsius;
	#endif //PIDTEMP
  } else
	slaveSetTargetHotend(celsius, extruder);
};

FORCE_INLINE float degTargetHotend(uint8_t extruder) 
{
  if(extruder == 0)  
  	return analog2temp(target_raw[extruder], extruder);
  else
	return slaveDegTargetHotend(extruder);
};

FORCE_INLINE bool isHeatingHotend(uint8_t extruder)
{
  if(extruder == 0)   
  	return target_raw[extruder] > current_raw[extruder];
  else
	return slaveIsHeatingHotend(extruder);
};

FORCE_INLINE bool isCoolingHotend(uint8_t extruder) 
{
  if(extruder == 0)  
  	return target_raw[extruder] < current_raw[extruder];
  else
	return slaveIsCoolingHotend(extruder);
};

#else

FORCE_INLINE float degHotend(uint8_t extruder) {  
  return analog2temp(current_raw[extruder], extruder);
};
FORCE_INLINE int rawHotend(uint8_t extruder) {  
  return current_raw[extruder];
};
FORCE_INLINE int minHotend(uint8_t extruder) {  
  return minttemp[extruder];
};
FORCE_INLINE int maxHotend(uint8_t extruder) {  
  return maxttemp[extruder];
};

FORCE_INLINE void setTargetHotend(const float &celsius, uint8_t extruder) {  
  target_raw[extruder] = temp2analog(celsius, extruder);
#ifdef PIDTEMP
  pid_setpoint[extruder] = celsius;
#endif //PIDTEMP
};

FORCE_INLINE float degTargetHotend(uint8_t extruder) {  
  return analog2temp(target_raw[extruder], extruder);
};

FORCE_INLINE bool isHeatingHotend(uint8_t extruder){  
  return target_raw[extruder] > current_raw[extruder];
};

FORCE_INLINE bool isCoolingHotend(uint8_t extruder) {  
  return target_raw[extruder] < current_raw[extruder];
};
#endif // REPRAPPRO_MULTIMATERIALS



FORCE_INLINE float degBed() {
  return analog2tempBed(current_raw_bed);
};

FORCE_INLINE float degTargetBed() {   
  return analog2tempBed(target_raw_bed);
};

FORCE_INLINE void setTargetBed(const float &celsius) {  
  
  target_raw_bed = temp2analogBed(celsius);
};

FORCE_INLINE bool isHeatingBed() {
  return target_raw_bed > current_raw_bed;
};

FORCE_INLINE bool isCoolingBed() {
  return target_raw_bed < current_raw_bed;
};

#define degHotend0() degHotend(0)
#define degTargetHotend0() degTargetHotend(0)
#define setTargetHotend0(_celsius) setTargetHotend((_celsius), 0)
#define isHeatingHotend0() isHeatingHotend(0)
#define isCoolingHotend0() isCoolingHotend(0)
#if EXTRUDERS_T > 1
#define degHotend1() degHotend(1)
#define degTargetHotend1() degTargetHotend(1)
#define setTargetHotend1(_celsius) setTargetHotend((_celsius), 1)
#define isHeatingHotend1() isHeatingHotend(1)
#define isCoolingHotend1() isCoolingHotend(1)
#else
#define setTargetHotend1(_celsius) do{}while(0)
#endif
#if EXTRUDERS_T > 2
#define degHotend2() degHotend(2)
#define degTargetHotend2() degTargetHotend(2)
#define setTargetHotend2(_celsius) setTargetHotend((_celsius), 2)
#define isHeatingHotend2() isHeatingHotend(2)
#define isCoolingHotend2() isCoolingHotend(2)
#else
#define setTargetHotend2(_celsius) do{}while(0)
#endif
#if EXTRUDERS_T > 3
#error Invalid number of extruders
#endif



int getHeaterPower(int heater);
void disable_heater();
void updatePID();

FORCE_INLINE void autotempShutdown(){
}

void PID_autotune(float temp);

#endif

