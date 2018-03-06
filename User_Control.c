task usercontrol()
{
	// User control code here, inside the loop
	startTask( MotorSlewRateTask );
	startTask(PID_Chainbar);
	startTask( tankDrive );
	startTask(PID_Lift);
	isLiftPID = false;
	isChainPID = false;


	clearLCDLine(0);                                            // Clear line 1 (0) of the LCD
	clearLCDLine(1);                                            // Clear line 2 (1) of the LCD
	bLCDBacklight = true;
	displayLCDCenteredString(0, "2360S");
	displayLCDCenteredString(1, "SubZERO");


	while (true)
	{
		//preset controls(other than drive)
		if (vexRT[Btn5UXmtr2] == 1)
		{
			isChainPID = false;
			moveChain(120);
		}
		else if (vexRT[Btn5DXmtr2] == 1)
		{
			isChainPID = false;
			moveChain(-120);
		}
		else if	(isChainPID == false)
		{
			moveChain(0);
		}
		//chain presets
		//int counter  = 0;
		if (vexRT[Btn7UXmtr2] == 1)
		{
			//counter = counter + 10;
			isChainPID = true;
			desiredChainTicks = 435 ;

		}
		else if (vexRT[Btn7LXmtr2] == 1)
		{
			isChainPID = true;
			desiredChainTicks = 1239;
		}
		else if( vexRT[Btn7DXmtr2] == 1)
		{
			isChainPID = true;
			desiredChainTicks = 1455;
		}
		else if(vexRT[Btn7U] == 1)
		{
			isChainPID = true;
			desiredChainTicks = 435 ;
			//counter = counter + 10;

		}
		else if(vexRT[Btn7L])
		{
			isChainPID = true;
			desiredChainTicks = 1239;
		}
		else if(vexRT[Btn7D])
		{
			isChainPID = true;
			desiredChainTicks = 1239;
		}
		// Mobile goal controls
		if (vexRT[Btn8U] == 1)
		{
			moveMogo(110);
		}
		else if (vexRT[Btn8D] == 1)
		{
			moveMogo(-110);
		}
		else
		{
			moveMogo(0);
		}
		if (vexRT[Btn6UXmtr2]== 1)
		{
			motorReq[claw] = -45;
		}
		else if (vexRT[Btn6DXmtr2]== 1)
		{
			motorReq[claw] = 127;
		}
		else
		{
			motorReq[claw] = 0;
		}
		if (vexRT[Btn6U] == 1)
		{
			isLiftPID = false;
			leftsideLift(127);
			rightsideLift(127);
		}
		else if (vexRT[Btn6D] == 1)
		{
			isLiftPID = false;
			leftsideLift(-80);
			rightsideLift(-80);
		}
		else if(isLiftPID == false)
		{
			leftsideLift(0);
			rightsideLift(0);
		}
		wait1Msec(20);
	}
}
