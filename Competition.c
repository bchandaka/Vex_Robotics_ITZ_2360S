#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    powerExpander,  sensorAnalog)
#pragma config(Sensor, in2,    gyro,           sensorGyro)
#pragma config(Sensor, I2C_1,  leftDriveQuad,  sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  rightDriveQuad, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  rightLiftQuad,  sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  leftLiftQuad,   sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_5,  fourQuad,       sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           leftWheel,     tmotorVex393HighSpeed_HBridge, openLoop, driveLeft, encoderPort, I2C_1)
#pragma config(Motor,  port2,           leftDrive,     tmotorVex393HighSpeed_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           rightDrive,    tmotorVex393HighSpeed_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port4,           leftMogo,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           rightMogo,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           leftLift,      tmotorVex393_MC29, openLoop, encoderPort, I2C_4)
#pragma config(Motor,  port7,           rightLift,     tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_3)
#pragma config(Motor,  port8,           fourbar,       tmotorVex393_MC29, openLoop, encoderPort, I2C_5)
#pragma config(Motor,  port9,           intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightWheel,    tmotorVex393HighSpeed_HBridge, openLoop, reversed, driveRight, encoderPort, I2C_2)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex competition platform
#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Pre-Autonomous                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
#include "Slew_Control.c"
#include "LCD_Advanced_Functions.c"
int autoChoice = 4; //run 10 point with cone by default
bool leftStart = true;
int isAutoLeft = 1;
bool LCD_CONNECTED = true;
#include "Pre_Auton.c"
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                Autonomous                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
int desiredLiftTicks = 0;
bool isLiftPID = true;
int desiredFourTicks;
bool isFourbarAuto = true;
#include "Auton_Drive_Functions.c"
#include "Advanced_Auton_Functions.c"
#include "Autonomous.c"
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
//Speed control variable
int kP_tank = 1.25; // fast by default
#include "Tank_Drive.c"
#include "User_Control.c"
