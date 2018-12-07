#include "DynamixelSerial.cpp"
//#include <map>

#define HOR_R_1 12
#define VER_R_1 16
#define LIN_R_1 9

#define HOR_L_1 17
#define VER_L_1 10
#define LIN_L_1 11

#define HOR_R_2 4
#define VER_R_2 2
#define LIN_R_2 1

#define HOR_L_2 14
#define VER_L_2 9
#define LIN_L_2 13

#define ALL 0xFF

//DynamixelClass Dynamixel;
float map(float x, float in_min, float in_max, float out_min, float out_max);
int ConvVal(int Val);


int main(void){

	
	Dynamixel.begin(1000000, 1);
	
	//Dynamixel.setEndless(ALL, false);
	//delay(50);
	//Dynamixel.setAngleLimit(ALL, 0, 1023);
	//delay(50);

	printf("Set Endless and Angle limit");
	
	Dynamixel.moveSpeed(HOR_R_1, 511+ConvVal(30), 100);
	Dynamixel.moveSpeed(VER_R_1, 670-ConvVal(0), 100);
	Dynamixel.moveSpeed(LIN_R_1, 511+ConvVal(-150), 200);
	Dynamixel.moveSpeed(HOR_L_1, 511+ConvVal(-30), 100);
	Dynamixel.moveSpeed(VER_L_1, 675+ConvVal(0), 100);
	Dynamixel.moveSpeed(LIN_L_1, 511+ConvVal(150), 200);
	Dynamixel.moveSpeed(HOR_R_2, 511+ConvVal(-30), 100);
	Dynamixel.moveSpeed(VER_R_2, 670-ConvVal(0), 100);
	Dynamixel.moveSpeed(LIN_R_2, 511+ConvVal(+150), 200);
	Dynamixel.moveSpeed(HOR_L_2, 511+ConvVal(+30), 100);
	Dynamixel.moveSpeed(VER_L_2, 675+ConvVal(0), 100);
	Dynamixel.moveSpeed(LIN_L_2, 511+ConvVal(-150), 200);
        delay(2000);
	printf("Setting up to the start position");

while(true)
{
	Dynamixel.moveSpeed(LIN_R_2, 511+ConvVal(30), 500);
	delay(500);
	Dynamixel.moveSpeed(LIN_L_1, 511+ConvVal(0), 500);
	delay(500);
	Dynamixel.moveSpeed(HOR_L_1, 511+ConvVal(-60), 500);
	delay(500);
	Dynamixel.moveSpeed(LIN_L_1, 511+ConvVal(150), 500);
        Dynamixel.moveSpeed(LIN_R_2, 511+ConvVal(150), 500);
	delay(500);
	Dynamixel.moveSpeed(HOR_L_1, 511+ConvVal(-50), 1000);
	Dynamixel.moveSpeed(HOR_R_1, 511+ConvVal(+20), 1000);
	Dynamixel.moveSpeed(HOR_L_2, 511+ConvVal(+40), 1000);
	Dynamixel.moveSpeed(HOR_R_2, 511+ConvVal(-40), 1000);

	delay(500);

        Dynamixel.moveSpeed(LIN_L_1, 511+ConvVal(30), 500);
	delay(500);
        Dynamixel.moveSpeed(LIN_R_2, 511+ConvVal(0), 500);
	delay(500);
	Dynamixel.moveSpeed(HOR_R_2, 511+ConvVal(-10), 500);
	delay(500);
	Dynamixel.moveSpeed(LIN_R_2, 511+ConvVal(+150), 500);
        Dynamixel.moveSpeed(LIN_L_1, 511+ConvVal(150), 500);

        delay(500);

	Dynamixel.moveSpeed(HOR_L_1, 511+ConvVal(-40), 1000);
	Dynamixel.moveSpeed(HOR_R_1, 511+ConvVal(+10), 1000);
	Dynamixel.moveSpeed(HOR_L_2, 511+ConvVal(+50), 1000);
	Dynamixel.moveSpeed(HOR_R_2, 511+ConvVal(-20), 1000);

	delay(500);

        //Dynamixel.moveSpeed(LIN_L_2, 511+ConvVal(10), 2000);
	//delay(500);
        Dynamixel.moveSpeed(LIN_R_1, 511+ConvVal(0), 500);
	delay(500);
	Dynamixel.moveSpeed(HOR_R_1, 511+ConvVal(+50), 500);
	delay(500);
	Dynamixel.moveSpeed(LIN_R_1, 511+ConvVal(-150), 500);
        //Dynamixel.moveSpeed(LIN_L_2, 511+ConvVal(-150), 2000);
	delay(500);
     
	Dynamixel.moveSpeed(HOR_L_1, 511+ConvVal(-30), 1000);
	Dynamixel.moveSpeed(HOR_R_1, 511+ConvVal(+40), 1000);
	Dynamixel.moveSpeed(HOR_L_2, 511+ConvVal(+60), 1000);
	Dynamixel.moveSpeed(HOR_R_2, 511+ConvVal(-30), 1000);
        
        delay(500);

        Dynamixel.moveSpeed(LIN_R_1, 511+ConvVal(-30), 500);
	delay(500);
        Dynamixel.moveSpeed(LIN_L_2, 511+ConvVal(0), 500);
	delay(500);
	Dynamixel.moveSpeed(HOR_L_2, 511+ConvVal(+20), 500);
	delay(500);
	Dynamixel.moveSpeed(LIN_L_2, 511+ConvVal(-150), 500);
        Dynamixel.moveSpeed(LIN_R_1, 511+ConvVal(-150), 500);

        delay(500);
        Dynamixel.moveSpeed(HOR_L_1, 511+ConvVal(-30), 1000);
	Dynamixel.moveSpeed(HOR_R_1, 511+ConvVal(+30), 1000);
	Dynamixel.moveSpeed(HOR_L_2, 511+ConvVal(+30), 1000);
	Dynamixel.moveSpeed(HOR_R_2, 511+ConvVal(-30), 1000);
        
        delay(500);

	printf("loop complited");

  /* add main program code here */

}
return 1;
}

int ConvVal(int Val)
{
	
	return (int)map(Val, 0, 300, 0, 1023);
}

float map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
