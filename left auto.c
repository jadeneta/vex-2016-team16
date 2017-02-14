void autoleft() {
  clawtarget = 2300;
	moveForwardWithSensor(640);
	turnRightWithSensor(260);
	moveForwardWithSensor(450);
	closeclaw();
	wait1Msec(500);
	liftarm();
	waitforarmheight(2500);
	turnLeftWithSensor(200);
	moveForwardWithSensor(750);
	openclaw();
	moveBackwardWithSensor(300);
	turnLeftWithSensor(480);

}
