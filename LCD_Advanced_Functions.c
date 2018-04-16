#pragma systemFile
//LCD Advanced Functions
const char RIGHT_ARROW = 199;
const char LEFT_ARROW = 200;


#ifndef NUM_AUTON_OPTIONS
	#define NUM_AUTON_OPTIONS 6
#endif
#define LEFT_BUTTON (nLCDButtons == 1 || vexRT[Btn7L] || vexRT[Btn8L] || vexRT[Btn7LXmtr2] || vexRT[Btn8LXmtr2])
#define MIDDLE_BUTTON (nLCDButtons == 2 || vexRT[Btn7U] || vexRT[Btn7D] || vexRT[Btn8U] || vexRT[Btn8D] || vexRT[Btn7UXmtr2] || vexRT[Btn7DXmtr2] || vexRT[Btn8UXmtr2] || vexRT[Btn8DXmtr2])
#define RIGHT_BUTTON (nLCDButtons == 4 || vexRT[Btn7R] || vexRT[Btn8R] || vexRT[Btn7RXmtr2] || vexRT[Btn8RXmtr2])

string autonOptions[NUM_AUTON_OPTIONS];


void clearLCD(bool backlight = false) {
	bLCDBacklight = backlight;
	clearLCDLine(0);
	clearLCDLine(1);
}


bool tfQuestion(char* question) {
	clearLCD(true);
	displayLCDCenteredString(0, question);
	displayLCDCenteredString(1, "true       false");
	while(true) { //Run until something causes this loop to exit
		if(LEFT_BUTTON) //Left button
			return true;
		if(RIGHT_BUTTON) //Right button
			return false;
	}
}


bool ynQuestion(char* question) {
	clearLCD(true);
	displayLCDCenteredString(0, question);
	displayLCDCenteredString(1, "yes           no");
	while(true) { //Run until something causes this loop to exit
		if(LEFT_BUTTON) //Left button
			return true; //yes
		if(RIGHT_BUTTON) //Right button
			return false; //no
	}
}


int autonomousSelector() {
	int choice = 0;
	clearLCD(true);
	displayLCDCenteredString(0, autonOptions[choice]);
	displayLCDCenteredString(1, "Select");
	displayLCDChar(1, 0, LEFT_ARROW);
	displayLCDChar(1, 15, RIGHT_ARROW);

	while(!MIDDLE_BUTTON) {
		if(LEFT_BUTTON) { //Left button
			choice--; //Decrement the choice
			if(choice < 0)
				choice = NUM_AUTON_OPTIONS - 1;
		displayLCDCenteredString(0, autonOptions[choice]);
			delay(500); //Delay 500 ms

		}

		if(RIGHT_BUTTON) { //Right button
			choice++; //Increment the choice
			if(choice > NUM_AUTON_OPTIONS - 1)
				choice = 0; //Set it to zero
			displayLCDCenteredString(0, autonOptions[choice]);
			delay(500); //Delay 500 ms
		}

	}

	return choice;
}
