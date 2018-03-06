#include "Auton_Drive_Functions.c"
#include "Advanced_Auton_Functions.c"
#include "5_point&Cone.c"
#include "10_point&Cone.c"
#include "20_point&Cone.c"
#include "Stationary_Cone.c"
task autonomous()
{
	startTask(MotorSlewRateTask);
	startTask(PID_Chainbar);
	startTask(PID_Lift);
	isChainPID = true;
	isLiftPID = true;


	clearLCD(); //Clear the LCD


	displayLCDCenteredString(0, "Running:"); //Display "Running" on top
	displayLCDCenteredString(1, autonOptions[autoChoice]);
	switch(autoChoice) { //Select a normal autonomous program
		case 1: auto1(); break;
		case 2: auto2(); break;
		case 3: auto3(); break;
		case 4: auto4(); break;
		default: break; //Don't run anything
}
	clearLCD(true); //Clear the LCD
	displayLCDCenteredString(0, "Done");

}
