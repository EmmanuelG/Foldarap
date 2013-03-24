#ifndef _PINS_H
#define _PINS_H
 
/****************************************************************************************
* Sanguinololu pin assignment
*
****************************************************************************************/
#if MOTHERBOARD == 62
#define KNOWN_BOARD 1
#ifndef __AVR_ATmega644P__
#ifndef __AVR_ATmega1284P__
#error Oops!  Make sure you have 'Sanguino' selected from the 'Tools -> Boards' menu.
#endif
#endif

#define X_STEP_PIN         15
#define X_DIR_PIN          21
#define X_MIN_PIN          18
#define X_MAX_PIN           -1

#define Y_STEP_PIN         22
#define Y_DIR_PIN          23
#define Y_MIN_PIN          19
#define Y_MAX_PIN          -1

#define Z_STEP_PIN         3
#define Z_DIR_PIN          2
#define Z_MIN_PIN          20
#define Z_MAX_PIN          -1

#define E0_STEP_PIN         1
#define E0_DIR_PIN          0

#define PROBE_PIN          20

#define LED_PIN            -1
#define FAN_PIN            12

#define PS_ON_PIN          -1
#define KILL_PIN           -1

#define HEATER_0_PIN       13 // (extruder)
#define HEATER_1_PIN       -1
#define HEATER_2_PIN       -1

#ifdef REPRAPPRO_HUXLEY
  #define HEATER_BED_PIN     10 // bed (change to 10 for gate pin of MOSFET on heated bed)
#else
  #define HEATER_BED_PIN     12
#endif
#define X_ENABLE_PIN       14
#define Y_ENABLE_PIN       14
#define Z_ENABLE_PIN       26
#define E0_ENABLE_PIN       14

#define TEMP_0_PIN          7   // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!! (pin 33 extruder)
#define TEMP_1_PIN         -1
#define TEMP_2_PIN         -1
#define TEMP_BED_PIN        6   // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!! (pin 34 bed)
#define SDPOWER            -1
#define SDSS               31


#endif

/****************************************************************************************
* Melzi pin assignment
*
****************************************************************************************/
#if MOTHERBOARD == 63
#define KNOWN_BOARD 1
#ifndef __AVR_ATmega644P__
#ifndef __AVR_ATmega1284P__
#error Oops!  Make sure you have 'Sanguino' selected from the 'Tools -> Boards' menu.
#endif
#endif

#define X_STEP_PIN         15
#define X_DIR_PIN          21
#define X_MIN_PIN          18
#define X_MAX_PIN           -2

#define Y_STEP_PIN         22
#define Y_DIR_PIN          23
#define Y_MIN_PIN          19
#define Y_MAX_PIN          -1

#define Z_STEP_PIN         3
#define Z_DIR_PIN          2
#define Z_MIN_PIN          20
#define Z_MAX_PIN          -1

#define E0_STEP_PIN         1
#define E0_DIR_PIN          0

#define PROBE_PIN          -1    //29 on Melzi1284p A2

#define LED_PIN            27

#define FAN_PIN            4 

#define PS_ON_PIN          -1
#define KILL_PIN           -1

#define HEATER_0_PIN       13 // (extruder)
#define HEATER_1_PIN       -1
#define HEATER_2_PIN       -1
#ifdef REPRAPPRO_HUXLEY
  #define HEATER_BED_PIN     10 // bed (change to 10 for gate pin of MOSFET on heated bed)
#else
  #define HEATER_BED_PIN     12
#endif
#define X_ENABLE_PIN       14
#define Y_ENABLE_PIN       14
#define Z_ENABLE_PIN       26
#define E0_ENABLE_PIN      14

#define TEMP_0_PIN          7   // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!! (pin 33 extruder)
#define TEMP_1_PIN         -1
#define TEMP_2_PIN         -1
#define TEMP_BED_PIN        6   // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!! (pin 34 bed)
#define SDPOWER            -1
#define SDSS               31

#define SLAVE_CLOCK	   16

#endif



#ifndef KNOWN_BOARD
#error Unknown MOTHERBOARD value in configuration.h
#endif

//List of pins which to ignore when asked to change by gcode, 0 and 1 are RX and TX, do not mess with those!
#define _E0_PINS E0_STEP_PIN, E0_DIR_PIN, E0_ENABLE_PIN, HEATER_0_PIN,
#ifdef REPRAPPRO_MULTIMATERIALS
  #define _E1_PINS -1, -1, -1, -1,
  #define _E2_PINS -1, -1, -1, -1,
#else 
#if EXTRUDERS > 1
  #define _E1_PINS E1_STEP_PIN, E1_DIR_PIN, E1_ENABLE_PIN, HEATER_1_PIN,
#else
  #define _E1_PINS
#endif
#if EXTRUDERS > 2
  #define _E2_PINS E2_STEP_PIN, E2_DIR_PIN, E2_ENABLE_PIN, HEATER_2_PIN,
#else
  #define _E2_PINS
#endif
#endif

#ifdef DISABLE_MAX_ENDSTOPS
#define X_MAX_PIN          -1
#define Y_MAX_PIN          -1
#define Z_MAX_PIN          -1
#endif

#define SENSITIVE_PINS {0, 1, X_STEP_PIN, X_DIR_PIN, X_ENABLE_PIN, X_MIN_PIN, X_MAX_PIN, Y_STEP_PIN, Y_DIR_PIN, Y_ENABLE_PIN, Y_MIN_PIN, Y_MAX_PIN, Z_STEP_PIN, Z_DIR_PIN, Z_ENABLE_PIN, Z_MIN_PIN, Z_MAX_PIN, LED_PIN, PS_ON_PIN, \
                        HEATER_BED_PIN, FAN_PIN,                  \
                        _E0_PINS _E1_PINS _E2_PINS             \
                        TEMP_0_PIN, TEMP_1_PIN, TEMP_2_PIN, TEMP_BED_PIN }

#endif
