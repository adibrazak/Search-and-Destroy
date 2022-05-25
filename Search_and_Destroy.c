#include <ev3.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#define EV3SENSOR_H
#define THRESHOLD_LIGHT 15 //light sensor threshold 15 percent
#define THRESHOLD_SONAR 40 //sonar sensor threshold 40cm

//rotate factor variable
float rf = 2.75; //rotation in place factor
float mf = 21; //rotation to move forward factor

//declare counter, increment
int i;
int a;
int b;


char str[20];
int r;

//function to push object
void pushObject()
{
	while(1)
	{
		if (ReadSensor(IN_1) < THRESHOLD_LIGHT)
		{
			Off(OUT_BC);
			break;
		}

		else
		{
			OnFwdEx(OUT_BC, 90,	true);
		}
	}
}

int main()
{
	InitEV3();
	setAllSensorMode(COL_REFLECT, NO_SEN, NO_SEN, US_DIST_CM);

	while(1)
	{
		if (ButtonIsDown(BTNCENTER) == 1)
		{
			return;
			Off(OUT_BC);
			break;
		}

		else
		{
			while(1)
			{
				for(i=1;i<=30;i++)
				{
					if(ReadSensor(IN_4) > THRESHOLD_SONAR)
					{
						//rotate and find
						RotateMotorEx(OUT_BC, -50, 15, 200 , true, true);
					}

					else
					{
						pushObject();
						RotateMotorEx(OUT_BC, -70, 460, 0 , true, true);
					}
				}
				pushObject();
				break;
			}
		}
	}
	FreeEV3();
	return 0;
}
