#define JOY_THRESHOLD							12
//controlling the drive motors through the joysticks
task tankDrive()
{
	int    ctl_l;
	int    ctl_r;
	int    drive_l;
	int    drive_r;

	while( true )
	{
		// Get tank drive vertical joystick control
		ctl_l = vexRT[ Ch3 ]/kP_tank;
		ctl_r = vexRT[Ch2]/kP_tank;
		// Ignore joystick near center to prevent motors from running when the joystick doesn't properly center to zero
		drive_l = (abs(ctl_l) <= JOY_THRESHOLD) ? 0:ctl_l;
		drive_r = (abs(ctl_r) <= JOY_THRESHOLD) ? 0:ctl_r;
		// Now send out joystick values to motors
		leftsideDrive( drive_l );
		rightsideDrive( drive_r );
		wait1Msec( 25 );
	}
}
