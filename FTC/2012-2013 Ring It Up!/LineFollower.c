#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Motor,  mtr_S1_C1_2,     motorBL,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_1,     motorFL,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C4_2,     motorFR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorBR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     armR,          tmotorTetrix, openLoop, encoder,reversed)
#pragma config(Motor,  mtr_S1_C2_2,     ramp,          tmotorTetrix, openLoop, encoder, reversed)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoStandard)
#pragma config(Sensor, S2,     LEGOLS,              sensorI2CCustom)
#pragma config(Sensor, S3,     light,              sensorI2CCustom)
#pragma config(Sensor, S4,     HTSMUX,              sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "/hitechnic-sensormux.h"
#include "/lego-ultrasound.h"
#include "/lego-light.h"
#include "/hitechnic-force.h"
#include "/hitechnic-irseeker-v2.h"
#include "/lego-touch.h"
// The sensor is connected to the first port
// of the SMUX which is connected to the NXT port S1.
// To access that sensor, we must use msensor_S1_1.  If the sensor
// were connected to 3rd port of the SMUX connected to the NXT port S4,
// we would use msensor_S4_3

// Give the sensor a nice easy to use namez
const tMUXSensor HTFS1 = msensor_S4_1;
const tMUXSensor HTFS2 = msensor_S4_2;
const tMUXSensor HTIRS2 = msensor_S4_3;
const tMUXSensor LEGOTS = msensor_S4_4;
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: lego-light-SMUX-test1.c 123 2012-11-02 16:35:15Z xander $
 */

/**
 * lego-light.h provides an API for the Lego Light Sensor.  This program
 * demonstrates how to use that API through a SMUX.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: More comments
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.54 AND HIGHER.
 * Xander Soldaat (xander_at_botbench.com)
 * 25 November 2009
 * version 0.2
 */

#include "/hitechnic-sensormux.h"
#include "/lego-light.h"

// The sensor is connected to the first port
// of the SMUX which is connected to the NXT port S1.
// To access that sensor, we must use msensor_S1_1.  If the sensor
// were connected to 3rd port of the SMUX connected to the NXT port S4,
// we would use msensor_S4_3

// Give the sensor a nice easy to use name
int lsVal;

/////////////////////////////////Arm Functions///////////////////////////////////
void raiseArm(int powerLevel){
	motor[armR]=powerLevel;
}

void lowerArm(int powerLevel){
	motor[armR]=-powerLevel;
}

//////////////////////////////Movement Functions/////////////////////////////////
void forward(int powerLevel){
	motor[motorBL] = powerLevel;
	motor[motorFL] = powerLevel;
	motor[motorBR] = powerLevel;
	motor[motorFR] = powerLevel;
}

void reverse(int powerLevel){
	motor[motorBL] = -powerLevel;
	motor[motorFL] = -powerLevel;
	motor[motorBR] = -powerLevel;
	motor[motorFR] = -powerLevel;
}

void left(int powerLevel){
	motor[motorBL] = 0;
	motor[motorFL] = 0;
	motor[motorBR] = powerLevel;
	motor[motorFR] = powerLevel;
}

void right(int powerLevel){
	motor[motorBL] = powerLevel;
	motor[motorFL] = powerLevel;
	motor[motorBR] = 0;
	motor[motorFR] = 0;
}

void diagonalFR(int powerLevel){
	motor[motorBL] = 0;
	motor[motorFL] = powerLevel;
	motor[motorBR] = powerLevel;
	motor[motorFR] = 0;
}


void rotateLeft(int powerLevel){
	motor[motorBL] = -powerLevel;
	motor[motorFL] = -powerLevel;
	motor[motorBR] = powerLevel;
	motor[motorFR] = powerLevel;
}

void rotateRight(int powerLevel){
	motor[motorBL] = powerLevel;
	motor[motorFL] = powerLevel;
	motor[motorBR] = -powerLevel;
	motor[motorFR] = -powerLevel;
}

void stop(){
	motor[motorBL] = 0;
	motor[motorFL] = 0;
	motor[motorBR] = 0;
	motor[motorFR] = 0;
	motor[armR] = 0;
	motor[ramp] = 0;
}


task main() {
	waitForStart();
  /*int raw = 0;
  int nrm = 0;
  bool active = true;

  // Turn the light on
  LSsetActive(LEGOLS);

  nNxtButtonTask  = -2;

  nxtDisplayCenteredTextLine(0, "Lego");
  nxtDisplayCenteredBigTextLine(1, "LIGHT");
  nxtDisplayCenteredTextLine(3, "SMUX Test");
  nxtDisplayCenteredTextLine(5, "Connect SMUX to");
  nxtDisplayCenteredTextLine(6, "S1 and sensor to");
  nxtDisplayCenteredTextLine(7, "SMUX Port 1");
  wait1Msec(2000);

  nxtDisplayClearTextLine(7);
  nxtDisplayTextLine(5, "Press [enter]");
  nxtDisplayTextLine(6, "to toggle light");
  wait1Msec(2000);*/

  //while (true) {
    // The enter button has been pressed, switch
    // to the other mode
    /*if (nNxtButtonPressed == kEnterButton) {
      active = !active;
      if (!active)
        LSsetInactive(LEGOLS);
      else
        LSsetActive(LEGOLS);

      // wait 500ms to debounce the switch
      wait1Msec(500);
    }

    nxtDisplayClearTextLine(5);
    nxtDisplayClearTextLine(6);
    raw = LSvalRaw(LEGOLS);
    nrm = LSvalNorm(LEGOLS);
    nxtDisplayTextLine(5, "Raw:  %4d", raw);
    nxtDisplayTextLine(6, "Norm: %4d", nrm);
    wait1Msec(50);
  }*/
  bool rightOfLine = true,touch=false;
  LSsetActive(LEGOLS);
  touch = TSreadState(LEGOTS);
  lsVal = LSvalRaw(LEGOLS);
	nMotorEncoder[armR] = 0; //Initiate Encoder Pos
  wait1Msec(2500);


  while(lsVal<360){
  	lsVal = LSvalRaw(LEGOLS);
  	forward(15);
  }
  stop();
  //reverse(50);
  wait1Msec(500);
  stop();
  wait1Msec(1000);
  while(nMotorEncoder[armR]<25){
		raiseArm(50);
		nxtDisplayCenteredTextLine(1,"Encoder:%i",nMotorEncoder[armR]);
	}stop();
	wait1Msec(1000);
  while(lsVal<210){
  	lsVal = LSvalRaw(LEGOLS);
  	left(50);
  }
  stop();
  wait1Msec(1000);
	ClearTimer(T1);
	while(time1[T1]<10000){
  	lsVal = LSvalRaw(LEGOLS);
  	touch = TSreadState(LEGOTS);
    nxtDisplayTextLine(5, "Raw:  %4d", lsVal);
		if(lsVal>210){
			while(lsVal>210){
				forward(15);
  			lsVal = LSvalRaw(LEGOLS);
   			nxtDisplayTextLine(5, "Raw:  %4d", lsVal);
			}
			rightOfLine=!rightOfLine;
		}
		else if(lsVal<210){
			if(rightOfLine){
				rotateLeft(50);
			}else{
				rotateRight(50);
			}
		}
	}
	stop();

	int ser=100;
	servo[servo1]=ser;
  servo[servo2]=215-ser;

  while(nMotorEncoder[armR]>5){
		lowerArm(50);
		nxtDisplayCenteredTextLine(1,"Encoder:%i",nMotorEncoder[armR]);
	}stop();
}

/*
 * $Id: lego-light-SMUX-test1.c 123 2012-11-02 16:35:15Z xander $
 */