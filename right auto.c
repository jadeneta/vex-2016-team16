
void autoright()
{

	armtarget =  1600;
	wait1Msec(750);
	clawtarget = 1400;
	wait1Msec(1200);
	droparm();
	wait1Msec(500);
	moveForwardWithSensor(1200);
	closeclaw();
	wait1Msec(500);
	liftarm();
	moveBackwardWithSensor(1100);
	wait1Msec(250);
	turnRightWithSensor(TURNRIGHT_90 +20);
	moveForwardWithSensor(1500);
	openclaw();
	wait1Msec(500);
	moveBackwardWithSensor(600);
	turnLeftWithSensor(TURNLEFT_90*2);
	moveBackwardWithSensor(400);
	droparm();
	wait1Msec(500);
	moveForwardWithSensor(500);
	closeclaw();
	wait1Msec(900);
	liftarm();
	wait1Msec(250);
	turnLeftWithSensor(250);
	moveForwardWithSensor(600);
	openclaw();
	wait1Msec(700);
	closeclaw();
}
