void autoskill() {

	clawtarget = 2625;
	liftarm();
	waitforarmheight(ARM_HIGH-150);
	// goes forward while lifting arm and closing
	//turnleft(127);
	wait1Msec(1000);
	closeclaw();
	wait1Msec(500);
	//turnleft(0);
	// move forward to hit stars off wall
	moveForwardWithSensor(1350);
	clawtarget = 2000;
	wait1Msec(750);
	openclaw();
	moveBackwardWithSensor(1200);
	clawtarget = 2625;
	wait1Msec(1000);
	moveForwardWithSensor(1350);
	openclaw();


	moveBackwardWithSensor(1200);
	wait1Msec(1000);
	closeclaw();
	wait1Msec(500);
	moveForwardWithSensor(1350);
	openclaw();
	wait1Msec(500);
	openclaw();

	moveBackwardWithSensor(1200);
	wait1Msec(1000);
	closeclaw();
	wait1Msec(500);
	moveForwardWithSensor(1350);
	openclaw();


}
