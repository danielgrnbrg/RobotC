#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Motor,  mtr_S1_C1_1,     arm1,   tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C2_1,    arm2,                     tServoNormal)
#pragma config(Servo,  srvo_S1_C2_2,    baseS,                     tServoNormal)
#pragma config(Servo,  srvo_S1_C2_3,    wristS,                     tServoNormal)
#pragma config(Servo,  srvo_S1_C2_4,    clawS,                     tServoNormal)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

const int threshold = 20;

task main()
{
	nMotorEncoder[arm1]=0;
	servoChangeRate[clawS]=1;
	servoChangeRate[baseS]=1;
	servoChangeRate[wristS] = 1;
	int base=0;
	int claw=0;
	int arm=0;
	int wrist=0;
	while(true){
		//Update servo positions
		servo[wristS]=wrist;
		servo[arm2]=arm;
		servo[baseS]=base;
		servo[clawS]=claw;
		
		if(joystick.joy1_x1>threshold){
			base++;
		}else if(joystick.joy1_x1<-threshold){
			base--;
		}else
			base=ServoValue[baseS];
		if(joy1Btn(3)&&ServoValue[clawS]<150)
			claw++;
		else if(joy1Btn(2))
			claw--;
		else
			claw=ServoValue[clawS];
		if(joy1Btn(4))
			wrist++;
		else if(joy1Btn(5))
			wrist--;
		else
			wrist=ServoValue[wristS];
		if(joy1Btn(6))
			arm++;
		else if(joy1Btn(7))
			arm--;
		else
			arm=ServoValue[arm2];
		if(joystick.joy1_y1>threshold){
			motor[arm1]=30;
		}
		else if(joystick.joy1_y1<-threshold)
			motor[arm1]=-30;
		else{
			motor[arm1]=0;
		}
		nxtDisplayCenteredTextLine(1,"Base:%i",ServoValue[baseS]);
		nxtDisplayCenteredTextLine(2,"arm2:%i",ServoValue[arm2]);
		nxtDisplayCenteredTextLine(3,"wrist:%i",ServoValue[wristS]);
		nxtDisplayCenteredTextLine(4,"claw:%i",ServoValue[clawS]);
	}
}