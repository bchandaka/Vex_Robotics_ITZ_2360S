#define MOTOR_NUM									10
#define MOTOR_MAX_VALUE   				127
#define MOTOR_MIN_VALUE						(-127)
#define MOTOR_DEFAULT_SLEW_RATE 	10
#define MOTOR_FAST_SLEW_RATE			256
#define MOTOR_TASK_DELAY					20
#define MOTOR_DEADBAND						10
// Array to hold requested speed for the motors
int motorReq[ MOTOR_NUM ];
// Array to hold "slew rate" for the motors, the maximum change every time the task
// runs checking current motor speed.
int motorSlew[ MOTOR_NUM ];
#include "Motor_Functions.c"
//Task - gradually increment/decrements motor speeds to meet new required motor speeds
task MotorSlewRateTask()
{
	unsigned int motorIndex;
	int motorTmp;
	// Initialize stuff
	for(motorIndex=0;motorIndex<MOTOR_NUM;motorIndex++)
	{
		motorReq[motorIndex] = 0;
		motorSlew[motorIndex] = MOTOR_DEFAULT_SLEW_RATE;
	}
	// run task until stopped
	while( true )
	{
		// run loop for every motor
		for( motorIndex=0; motorIndex<MOTOR_NUM; motorIndex++)
		{
			// So we don't keep accessing the internal storage
			motorTmp = motor[ motorIndex ];
			// Do we need to change the motor value ?
			if( motorTmp != motorReq[motorIndex] )
			{
				// increasing motor value
				if( motorReq[motorIndex] > motorTmp )
				{
					motorTmp += motorSlew[motorIndex];
					// limit
					if( motorTmp > motorReq[motorIndex] )
						motorTmp = motorReq[motorIndex];
				}
				// decreasing motor value
				if( motorReq[motorIndex] < motorTmp )
				{
					motorTmp -= motorSlew[motorIndex];
					// limit
					if( motorTmp < motorReq[motorIndex] )
						motorTmp = motorReq[motorIndex];
				}
				// finally set motor
				motor[motorIndex] = motorTmp;
			}
		}
		// Wait approx the speed of motor update over the spi bus
		wait1Msec( MOTOR_TASK_DELAY );
	}
}
