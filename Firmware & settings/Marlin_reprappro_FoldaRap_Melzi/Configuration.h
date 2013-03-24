#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// ==============================================================================

// For instructions on setting these constants, see:
// Mendel: http://reprap.org/wiki/RepRapPro_Mendel_maintenance
// Huxley: http://reprap.org/wiki/RepRapPro_Huxley_maintenance

// Uncomment ONE of the next three lines - the one for your RepRap machine
//#define REPRAPPRO_HUXLEY
#define REPRAPPRO_MENDEL
//#define REPRAPPRO_WALLACE

// Uncomment ONE of the next two lines - the one for your master controller electronics
#define REPRAPPRO_MELZI
//#define REPRAPPRO_SANGUINOLOLU

// Uncomment ONE of the next two lines - the one for the series resistors on your controller
#define SERIAL_R 4700
//#define SERIAL_R 10000

// Uncomment the next line if your machine has more than one extruder
//#define REPRAPPRO_MULTIMATERIALS

// -------------------------------------------------------------------------------

#ifndef REPRAPPRO_HUXLEY
#ifndef REPRAPPRO_MENDEL
#ifndef REPRAPPRO_WALLACE
#error Uncomment one of #define REPRAPPRO_HUXLEY, REPRAPPRO_MENDEL or REPRAPPRO_WALLACE at the start of the file Configuration.h
#endif
#endif
#endif

#ifndef REPRAPPRO_MELZI
#ifndef REPRAPPRO_SANGUINOLOLU
#error Uncomment one of #define REPRAPPRO_MELZI or REPRAPPRO_SANGUINOLOLU at the start of the file Configuration.h
#endif
#endif

#ifndef SERIAL_R
#error Uncomment one of #define SERIAL_R 10000 or 4700 at the start of the file Configuration.h
#endif

// ==============================================================================

// Uncomment this if you are experimenting, know what you are doing, and want to switch off some safety
// features, e.g. allow extrude at low temperature etc.
//#define DEVELOPING

// This configurtion file contains the basic settings.
// Advanced settings can be found in Configuration_adv.h 
// BASIC SETTINGS: select your board type, temperature sensor type, axis scaling, and endstop configuration

//User specified version info of THIS file to display in [Pronterface, etc] terminal window during startup.
//Implementation of an idea by Prof Braino to inform user that any changes made
//to THIS file by the user have been successfully uploaded into firmware.
#define STRING_VERSION_CONFIG_H "2013-03-22-RJ" //Personal revision number for changes to THIS file.
#define STRING_CONFIG_H_AUTHOR "RepRapPro" //Who made the changes.

// This determines the communication speed of the printer
//#define BAUDRATE 250000
#define BAUDRATE 115200

//// The following define selects which electronics board you have. Please choose the one that matches your setup
// Sanguinololu 1.2 and above = 62
// Melzi 63

#ifdef REPRAPPRO_SANGUINOLOLU
#define MOTHERBOARD 62
#endif

#ifdef REPRAPPRO_MELZI
#define MOTHERBOARD 63
#endif



//===========================================================================
//=============================Thermal Settings  ============================
//===========================================================================

// Set this if you want to define the constants in the thermistor circuit
// and work out temperatures algebraically - added by AB.

// See http://en.wikipedia.org/wiki/Thermistor#B_or_.CE.B2_parameter_equation

// BETA is the B value
// RS is the value of the series resistor in ohms
// R_INF is R0.exp(-BETA/T0), where R0 is the thermistor resistance at T0 (T0 is in kelvin)
// Normally T0 is 298.15K (25 C).  If you write that expression in brackets in the #define the compiler 
// should compute it for you (i.e. it won't need to be calculated at run time).

// If the A->D converter has a range of 0..1023 and the measured voltage is V (between 0 and 1023)
// then the thermistor resistance, R = V.RS/(1023 - V)
// and the temperature, T = BETA/ln(R/R_INF)
// To get degrees celsius (instead of kelvin) add -273.15 to T

// This DOES assume that all extruders use the same thermistor type.


#define ABS_ZERO -273.15
#define AD_RANGE 16383

// RS 198-961
#define E_BETA 3960.0
#define E_RS SERIAL_R
#define E_NTC 100000.0
#define E_R_INF ( E_NTC*exp(-E_BETA/298.15) )


#ifdef REPRAPPRO_MENDEL
// RS 484-0149; EPCOS B57550G103J
#define BED_BETA 3480.0
#define BED_RS SERIAL_R
#define BED_NTC 10000.0
#define BED_R_INF ( BED_NTC*exp(-BED_BETA/298.15) )
#endif

#ifdef REPRAPPRO_HUXLEY
// VISHAY BC COMPONENTS - NTCS0603E3104FXT
#define BED_BETA 4100.0
#define BED_RS SERIAL_R
#define BED_NTC 100000.0
#define BED_R_INF ( BED_NTC*exp(-BED_BETA/298.15) )
#endif


#define BED_USES_THERMISTOR
#define HEATER_0_USES_THERMISTOR
#define HEATER_1_USES_THERMISTOR
#define HEATER_2_USES_THERMISTOR



// Actual temperature must be close to target for this long before M109 returns success
#define TEMP_RESIDENCY_TIME 5  // (seconds)
#define TEMP_HYSTERESIS 5       // (C°) range of +/- temperatures considered "close" to the target one
#define TEMP_WINDOW     2       // (degC) Window around target to start the recidency timer x degC early.

// The minimal temperature defines the temperature below which the heater will not be enabled It is used
// to check that the wiring to the thermistor is not broken. 
// Otherwise this would lead to the heater being powered on all the time.
#define HEATER_0_MINTEMP 1
#ifdef REPRAPPRO_MULTIMATERIALS
#define HEATER_1_MINTEMP 1
#define HEATER_2_MINTEMP 1
#endif
#define BED_MINTEMP 1

// When temperature exceeds max temp, your heater will be switched off.
// This feature exists to protect your hotend from overheating accidentally, but *NOT* from thermistor short/failure!
// You should use MINTEMP for thermistor short/failure protection.
#define HEATER_0_MAXTEMP 399
#ifdef REPRAPPRO_MULTIMATERIALS
#define HEATER_1_MAXTEMP 275
#define HEATER_2_MAXTEMP 275
#endif
#define BED_MAXTEMP 150


// PID settings:
// Comment the following line to disable PID and enable bang-bang.
#define PIDTEMP
#define PID_MAX 255 // limits current to nozzle; 255=full current
#define FULL_PID_BAND 150 // Full power is applied when pid_error[e] > FULL_PID_BAND
#ifdef PIDTEMP
  //#define PID_DEBUG // Sends debug data to the serial port. 
  #define PID_INTEGRAL_DRIVE_MAX 125  //limit for the integral term
  #define K1 0.95 //smoothing factor withing the PID
  #define PID_dT 0.122 //sampling period of the PID


// RepRapPro Huxley + Mendel
    #define  DEFAULT_Kp 12.0
    #define  DEFAULT_Ki (2.2*PID_dT)
    #define  DEFAULT_Kd (80/PID_dT)

#endif // PIDTEMP

#ifndef DEVELOPING
//this prevents dangerous Extruder moves, i.e. if the temperature is under the limit
//can be software-disabled for whatever purposes by
#define PREVENT_DANGEROUS_EXTRUDE
#define EXTRUDE_MINTEMP 170
#define EXTRUDE_MAXLENGTH (200) //prevent extrusion of very large distances.
#else
#define BOGUS_TEMPERATURE_FAILSAFE_OVERRIDE
#endif

//===========================================================================
//=============================Mechanical Settings===========================
//===========================================================================

// Endstop Settings
#define ENDSTOPPULLUPS // Comment this out (using // at the start of the line) to disable the endstop pullup resistors

// The pullups are needed if you directly connect a mechanical endswitch between the signal and ground pins.
const bool X_ENDSTOPS_INVERTING = false; // set to true to invert the logic of the endstops. 
const bool Y_ENDSTOPS_INVERTING = false; // set to true to invert the logic of the endstops. 
const bool Z_ENDSTOPS_INVERTING = false; // set to true to invert the logic of the endstops. 

// For Inverting Stepper Enable Pins (Active Low) use 0, Non Inverting (Active High) use 1
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0 // For all extruders

// Disables axis when it's not being used.
#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z true
#define DISABLE_E false // For all extruders

#ifdef REPRAPPRO_MENDEL
#define INVERT_X_DIR true    // for Mendel set to false, for Orca set to true
#define INVERT_Y_DIR true    // for Mendel set to true, for Orca set to false
#define INVERT_Z_DIR false     // for Mendel set to false, for Orca set to true
#define INVERT_E0_DIR true   // for direct drive extruder v9 set to true, for geared extruder set to false
#define INVERT_E1_DIR true    // for direct drive extruder v9 set to true, for geared extruder set to false
#define INVERT_E2_DIR true   // for direct drive extruder v9 set to true, for geared extruder set to false
#endif

#ifdef REPRAPPRO_HUXLEY
#define INVERT_X_DIR true    // for Mendel set to false, for Orca set to true
#define INVERT_Y_DIR false    // for Mendel set to true, for Orca set to false
#define INVERT_Z_DIR false     // for Mendel set to false, for Orca set to true
#define INVERT_E0_DIR true   // for direct drive extruder v9 set to true, for geared extruder set to false
#define INVERT_E1_DIR true    // for direct drive extruder v9 set to true, for geared extruder set to false
#define INVERT_E2_DIR true   // for direct drive extruder v9 set to true, for geared extruder set to false
#endif


// ENDSTOP SETTINGS:
// Sets direction of endstops when homing; 1=MAX, -1=MIN
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1

#define min_software_endstops true //If true, axis won't move to coordinates less than zero.
#define max_software_endstops true  //If true, axis won't move to coordinates greater than the defined lengths below.

// The position of the homing switches. Use MAX_LENGTH * -0.5 if the center should be 0, 0, 0
#define X_HOME_POS 0
#define Y_HOME_POS 0
#define Z_HOME_POS 0

//// MOVEMENT SETTINGS
#define NUM_AXIS 4 // The axis order in all axis related arrays is X, Y, Z, E

#ifdef REPRAPPRO_MENDEL

#define AXES_MAX_LENGTHS {210, 210, 140}
#define HOMING_FEEDRATE {10*60, 10*60, 1*60, 0}  // set the homing speeds (mm/min)
#define FAST_HOME_FEEDRATE {50*60, 50*60, 3*60, 0}  // set the homing speeds (mm/min)
#define DEFAULT_MAX_FEEDRATE  {500, 500, 3, 45}
#define DEFAULT_MAX_FEEDRATE          {300, 300, 3, 45}    // (mm/sec)    
#define DEFAULT_MAX_ACCELERATION      {800,800,30,800}    // X, Y, Z, E maximum start speed for accelerated moves. E default values

#else

#define AXES_MAX_LENGTHS {155, 150, 90}
#define HOMING_FEEDRATE {10*60, 10*60, 1*60, 0}  // set the homing speeds (mm/min)
#define FAST_HOME_FEEDRATE {80*60, 80*60, 3*60, 0}  // set the homing speeds (mm/min)
#define DEFAULT_MAX_FEEDRATE  {500, 500, 5, 45}    // (mm/sec)
#define DEFAULT_MAX_FEEDRATE          {500, 500, 5, 45}    // (mm/sec)    
#define DEFAULT_MAX_ACCELERATION      {1000,1000,50,1000}    // X, Y, Z, E maximum start speed for accelerated moves. E default values

#endif


// default settings 
// X, Y, Z, E steps per mm
#define DEFAULT_AXIS_STEPS_PER_UNIT   {3200/17/2.032, 3200/17/2.032, 4000, 660} 

// Defaults changed by the G10 command

#define X_EXTRUDER_OFFSET 0
#define Y_EXTRUDER_OFFSET 0
#define Z_EXTRUDER_OFFSET 0
#define STANDBY_TEMP 140
#define PLA_TEMP 205
#define ABS_TEMP 250
#define DEFAULT_TEMP PLA_TEMP


#define DEFAULT_ACCELERATION          1000    // X, Y, Z and E max acceleration in mm/s^2 for printing moves 
#define DEFAULT_RETRACT_ACCELERATION  1000   // X, Y, Z and E max acceleration in mm/s^2 for r retracts

// 
#define DEFAULT_XYJERK                15.0    // (mm/sec)
#define DEFAULT_ZJERK                 0.4     // (mm/sec)
#define DEFAULT_EJERK                 15.0    // (mm/sec)

//===========================================================================
//=============================Additional Features===========================
//===========================================================================

// EEPROM
// the microcontroller can store settings in the EEPROM, e.g. max velocity...
// M500 - stores paramters in EEPROM
// M501 - reads parameters from EEPROM (if you need reset them after you changed them temporarily).  
// M502 - reverts to the default "factory settings".  You still need to store them in EEPROM afterwards if you want to.
//define this to enable eeprom support
#define EEPROM_SETTINGS
//to disable EEPROM Serial responses and decrease program space by ~1700 byte: comment this out:
// please keep turned on if you can.
#define EEPROM_CHITCHAT

//LCD and SD support
//#define ULTRA_LCD  //general lcd support, also 16x2
#define SDSUPPORT // Enable SD Card Support in Hardware Console

//#define ULTIPANEL
#ifdef ULTIPANEL
  //#define NEWPANEL  //enable this if you have a click-encoder panel
  #define SDSUPPORT
  #define ULTRA_LCD
  #define LCD_WIDTH 20
  #define LCD_HEIGHT 4

// Preheat Constants
  #define PLA_PREHEAT_HOTEND_TEMP 180 
  #define PLA_PREHEAT_HPB_TEMP 70
  #define PLA_PREHEAT_FAN_SPEED 255		// Insert Value between 0 and 255

  #define ABS_PREHEAT_HOTEND_TEMP 240
  #define ABS_PREHEAT_HPB_TEMP 100
  #define ABS_PREHEAT_FAN_SPEED 255		// Insert Value between 0 and 255

#else //no panel but just lcd 
  #ifdef ULTRA_LCD
    #define LCD_WIDTH 16
    #define LCD_HEIGHT 2
  #endif
#endif

// Enable uM-FPU support:
#define UMFPUSUPPORT 1

// M240  Triggers a camera by emulating a Canon RC-1 Remote
// Data from: http://www.doc-diy.net/photo/rc-1_hacked/
// #define PHOTOGRAPH_PIN     23

#include "Configuration_adv.h"


#endif //__CONFIGURATION_H
