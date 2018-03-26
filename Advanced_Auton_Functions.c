// Proportional-Integral-Derivative(PID) Control Algorithim to accurately hold/move the lift to any position
task PID_Lift()
{
	//Setup the constants for the P, I, and D aspects of the control loop
	//constants determined through experimentation
	const float leftkP = 0.4;
	const float leftkI = 0.002;
	const float leftkD = 0.3;
	const float rightkP = 0.297;
	const float rightkI = 0.002;
	const float rightkD = 0.24;
	int leftError;
	int rightError;
	int leftPrevError = 0 ;
	int rightPrevError = 0;
	int leftIntegral = 0;
	int rightIntegral = 0;
	int leftDeriv;
	int rightDeriv;
	int left_power;
	int right_power;
	while(true)
	{
		//Checks if the the PID control algorithim should be activated or not
		if (isLiftPID == true){
			//Proportional component, calculates the difference between the desired position and the robot's current position
			leftError = desiredLiftTicks - SensorValue[leftLiftQuad];
			rightError = desiredLiftTicks + SensorValue[rightLiftQuad];
			//Integral component, sums up the errors to account for smaller values of error that cannot be rectified
			leftIntegral = leftIntegral + leftError;
			rightIntegral = rightIntegral + rightError;
			//Derivative component, predicts future error by taking the difference of the current and previous error, prevents overshoot
			leftDeriv = leftError-leftPrevError;
			rightDeriv = rightError - rightPrevError;
			//resets the integral component if it becomes too high
			if (rightIntegral > 1000){
				rightIntegral = 0;
			}
			if (leftIntegral > 1000){
				leftIntegral = 0;
			}

			leftPrevError = leftError;
			rightPrevError = rightError;
			//multiply each component by each its repective constant and send it to the motors
			left_power = leftError*leftkP + leftIntegral*leftkI + leftDeriv* leftkD;
			right_power = rightError*rightkP + rightIntegral*rightkI + rightDeriv* rightkD;
			//send power to the motors
			leftsideLift(left_power);
			rightsideLift(right_power);
		}
		wait1Msec(MOTOR_TASK_DELAY);
	}
}


// Arctangent Control Algorithim to accurately hold/move the lift to any position
task set_fourbar()
{
	while(true)
	{
		if (isFourbarAuto == true)
		{
			moveFourbar(-90 * atan(0.005 * (desiredFourTicks - SensorValue[fourQuad])));
		}
	}
	wait1Msec(MOTOR_TASK_DELAY);
}
