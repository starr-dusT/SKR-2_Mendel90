#ifndef __CONFIGURATION_H
#define __CONFIGURATION_H

// Mendel90 hobbed bolt and 39:11 Wade's gears
#define E_STEPS_PER_MM ((3200 * 39.0)/(11.0 * 6.75 * 3.142))

// This configurtion file contains the basic settings.
// Advanced settings can be found in Configuration_adv.h 
// BASIC SETTINGS: select your board type, temperature sensor type, axis scaling, and endstop configuration

//User specified version info of this build to display in [Pronterface, etc] terminal window during startup.
//Implementation of an idea by Prof Braino to inform user that any changes made
#define STRING_VERSION_CONFIG_H __DATE__ " " __TIME__ // build date and time
#define STRING_CONFIG_H_AUTHOR "nophead" //Who made the changes.

// This determines the communication speed of the printer
#define BAUDRATE 250000
//#define BAUDRATE 115200

//// The following define selects which electronics board you have. Please choose the one that matches your setup
// Gen7 custom (Alfons3 Version) = 10 "https://github.com/Alfons3/Generation_7_Electronics"
// Gen7 v1.1, v1.2 = 11
// Gen7 v1.3 = 12
// Gen7 v1.4 = 13
// MEGA/RAMPS up to 1.2 = 3
// RAMPS 1.3 = 33 (Power outputs: Extruder, Bed, Fan)
// RAMPS 1.3 = 34 (Power outputs: Extruder0, Extruder1, Bed)
// Gen6 = 5
// Gen6 deluxe = 51
// Sanguinololu 1.2 and above = 63
// Melzi = 63
// Ultimaker = 7
// Teensylu = 8
// Gen3+ =9

#ifndef MOTHERBOARD
#define MOTHERBOARD 63
#endif

//===========================================================================
//=============================Thermal Settings  ============================
//===========================================================================

//// Temperature sensor settings:
// -2 is thermocouple with MAX6675 (only for sensor 0)
// -1 is thermocouple with AD595
// 0 is not used
// 1 is 100k thermistor
// 2 is 200k thermistor
// 3 is mendel-parts thermistor
// 4 is 10k thermistor !! do not use it for a hotend. It gives bad resolution at high temp. !!
// 5 is ParCan supplied 104GT-2 100K
// 6 is EPCOS 100k
// 7 is 100k Honeywell thermistor 135-104LAG-J01
// 8 is Epcos B57560G104F 100K
// 9 is Epcos B57861S104F40 100K 155C for bed only

#define TEMP_SENSOR_0 8
#define TEMP_SENSOR_1 0
#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_BED 9 // 1 for Mendel90 kits 1-6, 9 for kits 7 onwards

// Actual temperature must be close to target for this long before M109 returns success
#define TEMP_RESIDENCY_TIME 60	// (seconds)
#define TEMP_HYSTERESIS 5.0     // (degC) range of +/- temperatures considered "close" to the target one
#define TEMP_WINDOW     1.0     // (degC) Window around target to start the recidency timer x degC early.

// The minimal temperature defines the temperature below which the heater will not be enabled It is used
// to check that the wiring to the thermistor is not broken. 
// Otherwise this would lead to the heater being powered on all the time.
#define HEATER_0_MINTEMP 5
#define HEATER_1_MINTEMP 5
#define HEATER_2_MINTEMP 5
#define BED_MINTEMP 5

// When temperature exceeds max temp, your heater will be switched off.
// This feature exists to protect your hotend from overheating accidentally, but *NOT* from thermistor short/failure!
// You should use MINTEMP for thermistor short/failure protection.
#define HEATER_0_MAXTEMP 275
#define HEATER_1_MAXTEMP 275
#define HEATER_2_MAXTEMP 275
#define BED_MAXTEMP 150


// PID settings:
// Comment the following line to disable PID and enable bang-bang.
#define PIDTEMP
#define PID_MAX 255 // limits current to nozzle; 255=full current
#ifdef PIDTEMP
  //#define PID_DEBUG // Sends debug data to the serial port. 
  //#define PID_OPENLOOP 1 // Puts PID in open loop. M104 sets the output power in %
  #define PID_INTEGRAL_DRIVE_MAX 255  //limit for the integral term
  #define K1 0.95 //smoothing factor withing the PID
  #define PID_dT ((16.0 * 8.0)/(F_CPU / 64.0 / 256.0)) //sampling period of the

// If you are using a preconfigured hotend then you can use one of the value sets by uncommenting it
// J-Head Mk V-B
    #define  DEFAULT_Kp 25.05
    #define  DEFAULT_Ki 2.30  
    #define  DEFAULT_Kd 68.15  
    

// Ultimaker
//    #define  DEFAULT_Kp 22.2
//    #define  DEFAULT_Ki 1.08  
//    #define  DEFAULT_Kd 114  

// Makergear
//    #define  DEFAULT_Kp 7.0
//    #define  DEFAULT_Ki 0.1  
//    #define  DEFAULT_Kd 12  

// Mendel Parts V9 on 12V    
//    #define  DEFAULT_Kp 63.0
//    #define  DEFAULT_Ki 2.25
//    #define  DEFAULT_Kd 440
#endif // PIDTEMP

//this prevents dangerous Extruder moves, i.e. if the temperature is under the limit
//can be software-disabled for whatever purposes by
#define PREVENT_DANGEROUS_EXTRUDE
#define EXTRUDE_MINTEMP 170
#define EXTRUDE_MAXLENGTH (X_MAX_LENGTH+Y_MAX_LENGTH) //prevent extrusion of very large distances.

//===========================================================================
//=============================Mechanical Settings===========================
//===========================================================================

// Endstop Settings
#define ENDSTOPPULLUPS // Comment this out (using // at the start of the line) to disable the endstop pullup resistors

// The pullups are needed if you directly connect a mechanical endswitch between the signal and ground pins.
const bool X_ENDSTOPS_INVERTING = false; // set to true to invert the logic of the endstops. 
const bool Y_ENDSTOPS_INVERTING = false; // set to true to invert the logic of the endstops. 
const bool Z_ENDSTOPS_INVERTING = false; // set to true to invert the logic of the endstops. 
//#define DISABLE_MAX_ENDSTOPS

// For Inverting Stepper Enable Pins (Active Low) use 0, Non Inverting (Active High) use 1
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0 // For all extruders

// Disables axis when it's not being used.
#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false
#define DISABLE_E false // For all extruders

#define INVERT_X_DIR false    // for Mendel set to false, for Orca set to true
#define INVERT_Y_DIR false    // for Mendel set to true, for Orca set to false
#define INVERT_Z_DIR true     // for Mendel set to false, for Orca set to true
#define INVERT_E0_DIR true   // for direct drive extruder v9 set to true, for geared extruder set to false
#define INVERT_E1_DIR false    // for direct drive extruder v9 set to true, for geared extruder set to false
#define INVERT_E2_DIR false   // for direct drive extruder v9 set to true, for geared extruder set to false

// ENDSTOP SETTINGS:
// Sets direction of endstops when homing; 1=MAX, -1=MIN
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR  1

#define min_software_endstops true //If true, axis won't move to coordinates less than HOME_POS.
#define max_software_endstops true  //If true, axis won't move to coordinates greater than the defined lengths below.
// Travel limits after homing
#define X_MIN_POS -100
#define X_MAX_POS 100
#define Y_MIN_POS -100
#define Y_MAX_POS 100
#define Z_MIN_POS 0
#define Z_MAX_POS (Z_HOME_POS - 6.0)

// The position of the homing switches. Use MAX_LENGTH * -0.5 if the center should be 0, 0, 0
#define X_HOME_POS (X_MIN_POS - 1)  
#define Y_HOME_POS (Y_MIN_POS - 1)
#define Z_HOME_POS (203.3)

#define X_MAX_LENGTH (X_MAX_POS - X_MIN_POS)
#define Y_MAX_LENGTH (Y_MAX_POS - Y_MIN_POS)
#define Z_MAX_LENGTH (Z_MAX_POS - Z_MIN_POS)

//// MOVEMENT SETTINGS
#define NUM_AXIS 4 // The axis order in all axis related arrays is X, Y, Z, E
#define HOMING_FEEDRATE {35*60, 35*60, 4*60, 0}  // set the homing speeds (mm/min)

// default settings 
#define DEFAULT_AXIS_STEPS_PER_UNIT   {80,80,200*16/1,E_STEPS_PER_MM}  // Mendel90 with Wades and Stoffel15 bolt 
#define DEFAULT_MAX_FEEDRATE          {400, 400, 4, 30}    // (mm/sec)
#define DEFAULT_MAX_ACCELERATION      {2000,2000,150,5000}    // X, Y, Z, E maximum start speed for accelerated moves. E default values are good for skeinforge 40+, for older versions raise them a lot.

#define DEFAULT_ACCELERATION          2000    // X, Y, Z and E max acceleration in mm/s^2 for printing moves 
#define DEFAULT_RETRACT_ACCELERATION  5000   // X, Y, Z and E max acceleration in mm/s^2 for r retracts

// 
#define DEFAULT_XYJERK                10.0    // (mm/sec)
#define DEFAULT_ZJERK                 0.0     // (mm/sec)
#define DEFAULT_EJERK                 10.0    // (mm/sec)

//===========================================================================
//=============================Additional Features===========================
//===========================================================================

// EEPROM
// the microcontroller can store settings in the EEPROM, e.g. max velocity...
// M500 - stores paramters in EEPROM
// M501 - reads parameters from EEPROM (if you need reset them after you changed them temporarily).  
// M502 - reverts to the default "factory settings".  You still need to store them in EEPROM afterwards if you want to.
//define this to enable eeprom support
//#define EEPROM_SETTINGS
//to disable EEPROM Serial responses and decrease program space by ~1700 byte: comment this out:
// please keep turned on if you can.
//#define EEPROM_CHITCHAT

//LCD and SD support
//#define ULTRA_LCD  //general lcd support, also 16x2
#define SDSUPPORT // Enable SD Card Support in Hardware Console

//#define ULTIMAKERCONTROLLER //as available from the ultimaker online store.
//#define ULTIPANEL  //the ultipanel as on thingiverse


#ifdef ULTIMAKERCONTROLLER    //automatic expansion
 #define ULTIPANEL
 #define NEWPANEL
#endif 
 

#ifdef ULTIPANEL
//  #define NEWPANEL  //enable this if you have a click-encoder panel
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

// Increase the FAN pwm frequency. Removes the PWM noise but increases heating in the FET/Arduino
//#define FAST_PWM_FAN

// M240  Triggers a camera by emulating a Canon RC-1 Remote
// Data from: http://www.doc-diy.net/photo/rc-1_hacked/
// #define PHOTOGRAPH_PIN     23

#include "Configuration_adv.h"
#include "thermistortables.h"

#endif //__CONFIGURATION_H
