void pre_auton()
{
	bStopTasksBetweenModes = true;
	// resets all encoder values to zero
	SensorValue[rightDriveQuad] = 0;
	SensorValue[leftDriveQuad] = 0;
	SensorValue[leftLiftQuad] = 0;
	SensorValue[rightLiftQuad] = 0;
	SensorValue[fourQuad] = 0;

  wait1Msec(2000);
	if(LCD_CONNECTED)
	{
		clearLCD(true);
		displayLCDCenteredString(0, "PLUG IN");
		displayLCDCenteredString(1, "BATTERY #2");
		while( SensorValue[powerExpander] < 500 )
		{
		}//No battery is attached

		autonOptions[0] = "None";
		autonOptions[1] = "5 Point + Cone";
		autonOptions[2] = "10 Point + Cone";
		autonOptions[3] = "20 Point + 2 Cone";
		autonOptions[4] = "Stationary";
		autonOptions[5] = "22 Point";

		leftStart = tfQuestion("Left Side?");
		isAutoLeft = (leftStart == true) ? 1:-1;
		delay(500);
		autoChoice = autonomousSelector();
		clearLCD(true); //Clear the LCD
		displayLCDCenteredString(0, "Calibrating"); //Set top display
		displayLCDCenteredString(1, "DO NOT TOUCH"); //Set bottom display
	}
}
