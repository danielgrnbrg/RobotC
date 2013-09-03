#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Motor,  mtr_S1_C1_2,     motorBL,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_1,     motorFL,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C4_2,     motorFR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorBR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     armR,          tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     armL,          tmotorTetrix, openLoop, encoder, reversed)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoStandard)
#pragma config(Sensor, S2,     lightSensor,            sensorLightActive)
#pragma config(Sensor, S3,     HTIRS2,              sensorI2CCustom)
#pragma config(Sensor, S4,     HTSMUX,              sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "/hitechnic-irseeker-v2.h"

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

void right(int powerLevel){
	motor[motorBL] = -powerLevel;
	motor[motorFL] = powerLevel;
	motor[motorBR] = powerLevel;
	motor[motorFR] = -powerLevel;
}

void left(int powerLevel){
	motor[motorBL] = powerLevel;
	motor[motorFL] = -powerLevel;
	motor[motorBR] = -powerLevel;
	motor[motorFR] = powerLevel;
}

void diagonalFR(int powerLevel){
	motor[motorBL] = 0;
	motor[motorFL] = powerLevel;
	motor[motorBR] = powerLevel;
	motor[motorFR] = 0;
}

void diagonalBL(int powerLevel){
	motor[motorBL] = 0;
	motor[motorFL] = -powerLevel;
	motor[motorBR] = -powerLevel;
	motor[motorFR] = 0;
}

void diagonalFL(int powerLevel){
	motor[motorBL] = powerLevel;
	motor[motorFL] = 0;
	motor[motorBR] = 0;
	motor[motorFR] = powerLevel;
}

void diagonalBR(int powerLevel){
	motor[motorBL] = -powerLevel;
	motor[motorFL] = 0;
	motor[motorBR] = 0;
	motor[motorFR] = -powerLevel;
}

void rotateRight(int powerLevel){
	motor[motorBL] = powerLevel;
	motor[motorFL] = powerLevel;
	motor[motorBR] = -powerLevel;
	motor[motorFR] = -powerLevel;
}

void rotateLeft(int powerLevel){
	motor[motorBL] = -powerLevel;
	motor[motorFL] = -powerLevel;
	motor[motorBR] = powerLevel;
	motor[motorFR] = powerLevel;
}

void stop(){
	motor[motorBL] = 0;
	motor[motorFL] = 0;
	motor[motorBR] = 0;
	motor[motorFR] = 0;
	motor[armL] = 0;
}

int dcS1, dcS2, dcS3, dcS4, dcS5, servoPos;

void init(){
	servoPos=30;
	servo[servo1]=servoPos;
}

task main()
{
	init();
	while(true){
		HTIRS2readAllDCStrength(HTIRS2,dcS1,dcS2,dcS3,dcS4,dcS5);
		nxtDisplayCenteredTextLine(1,"IRSensor\n%i\n%i\n%i\n%i\n%i)",dcS1,dcS2,dcS3,dcS4,dcS5);
		if(dcS1>5||dcS2>5||dcS3>5||dcS4>5||dcS5>5){
			if(dcS4>dcS2&&dcS4>dcS3&&dcS4>dcS5){//&&dcS3>dcS5){
				forward(35);
			}
			else if(dcS4+dcS5<dcS3+dcS2){
				rotateLeft(35);
			}
			else if(dcS3+dcS2<dcS5+dcS4){
				rotateRight(35);
			}
			else{
				stop()
			}
		}
		else{
			forward(30);
		}
	}
}