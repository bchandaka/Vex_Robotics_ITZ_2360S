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
		ctl_l = vexRT[ Ch3 ]/1.25;
		ctl_r = vexRT[Ch2]/1.25;
		// Ignore joystick near center to prevent motors from running when the joystick doesn't properly center to zero
		if (abs(ctl_l) <= JOY_THRESHOLD)
		{
			drive_l = 0;
		}
		else
		{
			drive_l = (ctl_l)/ (1.25);
		}
		if (abs(ctl_r) <= JOY_THRESHOLD)
		{
			drive_r = 0;
		}
		else
		{
			drive_r = (ctl_r)/ (1.25);
		}
		// Now send out joystick values to motors
		leftsideDrive( drive_l );
		rightsideDrive( drive_r );
		// don't hog CPU
		wait1Msec( 25 );
	}
}
