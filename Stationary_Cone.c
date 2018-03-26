
void auto4()
{
		desiredLiftTicks = 900; //lift the lift to max height
		drive_straight(45); //drive to stationary
		rollIntake(127); //move the claw to eject the cone
		drive_straight(-45); //drive backwards from the stationary
		rollIntake(0); //stop the claw
}
