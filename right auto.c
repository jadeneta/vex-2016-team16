
void autoright()
{
	clawtarget = 2300;


	moveForwardWithSensor(600);

	wait1Msec(500);
	turnLeftWithSensor(200);
	moveForwardWithSensor(400);
	closeclaw();
	wait1Msec(500);
	liftarm();
	waitforarmheight(2500);
	turnRightWithSensor(130);
	moveForwardWithSensor(850);
	clawtarget = 2300;
	wait1Msec(1000);
	moveBackwardWithSensor(600);
	armtarget = 2400;
	openclaw();
	//turnWithSensor(60);
	wait1Msec(500);
	moveForwardWithSensor(650);
	wait1Msec(300);
	moveBackwardWithSensor(650);

	droparm();
}
