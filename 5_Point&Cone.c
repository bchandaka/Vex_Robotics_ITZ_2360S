void auto1()
{
		desiredLiftTicks = 400; //Lift the
		wait1Msec(50);
		moveMogo(90); //Open the Mobile Goal
		drive_straight(45); //Drive straight to the mobile goal

		wait1Msec(400);
		moveMogo(0);
		desiredChainTicks = 420; //Move chainbar to up position
		moveMogo(-80);
		wait1Msec(1000);
		isChainPID = false;
		desiredLiftTicks = 0;
		drive_straight(-35); //Drive back straight to the 5 point zone
		moveClaw(110); //Drop a preload on the mobile goal
		wait1Msec(200);
		turnDegrees(isAutoLeft * 215); //Rotate 135 degrees to the right
		desiredLiftTicks = 300;
		moveMogo(90); //Open Mobile Goal to drop it
		wait1Msec(1000);
		drive_straight(-10); //Back up from the 5point zone
		wait1Msec(1000);
		moveMogo(0);

}
