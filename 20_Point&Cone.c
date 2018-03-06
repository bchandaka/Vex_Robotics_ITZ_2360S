void auto3()
{
		desiredLiftTicks = 200; //Lift the lift
		moveMogo(90); //Open the Mobile Goal
		drive_straight(50); //Drive straight to the mobile goal
		wait1Msec(800);
		moveMogo(0);
		desiredChainTicks = 480; //Move chainbar to up position
		moveMogo(-100);
		wait1Msec(1000);
		moveClaw(127); //Drop a preload on the mobile goal
		wait1Msec(500);
		moveClaw(-80); //Pick up a ground cone
		desiredChainTicks = 1139; //Move chainbar to ground position
		moveClaw(0);
		moveMogo(0);
		desiredChainTicks = 480; //move chainbar to up position after picking up the ground cone
		turnDegrees(isAutoLeft * 180); //Rotate 180 degrees to the left
		drive_straight(55); //Drive straight to the 10 point zone
		moveClaw(127); //Drop the last cone
		wait1Msec(500);
		moveClaw(0);
		turnDegrees(isAutoLeft * -90); //Turn to center position
		drive_straight(15); //drive to center
		turnDegrees(isAutoLeft* -90); //turn to face goals
		drive_straight(15); //drive to 20 point zone
		moveMogo(-90); //Open Mobile Goal to drop it
		wait1Msec(1000);
		drive_straight(-10); //Back up from the 20 point zone
		moveMogo(90); //Pull up the mobile goal
		wait1Msec(1000);
		moveMogo(0);

}
