void leftsideDrive( int speed)
{
	motorReq[leftDrive] = speed;
	motorReq[leftWheel] = speed;
}

void rightsideDrive( int speed)
{
	motorReq[rightDrive] = speed;
	motorReq[rightWheel] = speed;
}

void leftsideLift( int speed)
{
	motorReq[leftLift] = speed;
}

void rightsideLift( int speed)
{
	motorReq[rightLift] = speed;
}

void moveMogo( int speed)
{
	motorReq[leftMogo] = speed;
	motorReq[rightMogo] = speed;
}

void moveFourbar( int speed)
{
	motorReq[fourbar] = speed;
}

void rollIntake( int speed)
{
	motorReq[intake] = speed;
}
