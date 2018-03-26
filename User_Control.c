int FourbarCtl;
int MogoCtl;
int IntakeCtl;
int LiftCtl;
int SpeedCtl;
task usercontrol()
{
	// User control code here, inside the loop
	startTask( MotorSlewRateTask );
	startTask( tankDrive );
	isLiftPID = false;
	isFourbarAuto = false;

	// Reset LCD Display
	clearLCDLine(0);
	clearLCDLine(1);
	bLCDBacklight = true;
	displayLCDCenteredString(0, "2360S");
	displayLCDCenteredString(1, "SubZERO");


	while (true)
	{
		//manual controls(other than drive)
		// DR4B Lift Control
		LiftCtl = (vexRT[Btn6D] << 1) + vexRT[Btn6U];
		switch (LiftCtl)
			{
			case 1: // When Btn6U is pressed
				leftsideLift(100);
				rightsideLift(100);
				break;
			case 2: // When Btn6D is pressed
				leftsideLift(-80);
				rightsideLift(-80);
				break;
			default: //Do nothing when either both or neither are pressed
				leftsideLift(0);
				rightsideLift(0);
				break;
			}
		// Mobile goal controls
		MogoCtl = (vexRT[Btn8D] << 1) + vexRT[Btn8U];
		switch (MogoCtl)
			{
			case 1: // When Btn8U is pressed
				moveMogo(110);
				break;
			case 2: // When Btn8D is pressed
				moveMogo(-110);
				break;
			default: //Do nothing when either both or neither are pressed
				moveMogo(0);
				break;
			}

		// Roller Intake Controls
		IntakeCtl = (vexRT[Btn6DXmtr2] << 1) + vexRT[Btn6UXmtr2];
		switch (IntakeCtl)
			{
			case 1: // When Btn6UXmtr2 is pressed
				rollIntake(-50);
				break;
			case 2: // When Btn6DXmtr2 is pressed
				rollIntake(100);
				break;
			default: //Do nothing when either both or neither are pressed
				rollIntake(0);
				break;
			}

		FourbarCtl = (vexRT[Btn5UXmtr2] << 1) + vexRT[Btn5DXmtr2];
		switch (FourbarCtl)
			{
			case 1: // When Btn5Dmtr2 is pressed
				moveFourbar(120);
				break;
			case 2: // When Btn5Umtr2 is pressed
				moveFourbar(-120);
				break;
			default: //Do nothing when either both or neither are pressed
				moveFourbar(0);
				break;
			}
			//Speed Control
			SpeedCtl = (vexRT[Btn8UXmtr2] << 1) + vexRT[Btn8DXmtr2]  +(vexRT[Btn8UXmtr2] << 2);
			switch(SpeedCtl)
			{
				case 1: // Btn 8D
					kP_tank = 2;
					break;
				case 2: //Btn 8U
					kP_tank = 1.6;
					break;
				case 4:
					kP_tank = 1.25;
					break;
				default:
				 break;
			}
		wait1Msec(20);
	}
}
