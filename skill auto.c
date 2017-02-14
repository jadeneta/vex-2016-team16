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
	/*
	moveForwardWithSensor(100);
	moveBackwardWithSensor(70);
	clawtarget = 2300;

	turnRightWithSensor(300);

	droparm();
	wait1Msec(1000);
	moveForwardWithSensor(900);
	turnRightWithSensor(50);
	closeclaw();
	liftarm();
	wait1Msec(1000);
	turnLeftWithSensor(200);
	moveForwardWithSensor(150);
	openclaw();
 wait1Msec(750);
 moveBackwardWithSensor(500);
turnRightWithSensor(450);
droparm();








	/*////2600

	moveBackwardWithSensor(200);
	// turns to get stars infront of middle fence
	turnRightWithSensor(280);
	/*clawtarget = 2300;
	wait1Msec(500);

	droparm();
	wait1Msec(1000);
	// moves forward and grabs the 3 stars infront of the middle fence
	moveForwardWithSensor(1160);
	closeclaw();
	liftarm();
	waitforarmheight(2500);
	movebackwardWithSensor(150);
	// drop the 3 stars on the other side
	turnLeftWithSensor(200);
	moveForwardWithSensor(150);
	openclaw();
	wait1Msec(500);
	// turn  to grab cube
	turnRightWithSensor(449);
	droparm();
	wait1Msec(700);
	// move forward and grab cube
	moveForwardWithSensor(150);
	closeclaw();

	wait1Msec(500);
	liftarm();
	wait1Msec(1000);
	// drops cube on the other side
	turnLeftWithSensor(500);
	moveForwardWithSensor(400);
	openclaw();
	wait1Msec(500);
/*	// turns around
	turnLeftWithSensor(425);
	moveForwardWithSensor(1000);
	// grabs first cube
	wait1Msec(1000);
	closeclaw();
	wait1Msec(500);
	//drops first cube
	turnRightWithSensor(475);
	moveForwardWithSensor(1250);
	openclaw();
	wait1Msec(1000);
	//turns around and moves forward
	turnLeftWithSensor(440);
	moveForwardWithSensor(1000);
	wait1Msec(1000);
	// grabs secound cube
	closeclaw();
	wait1Msec(500);
	// goes forward with second cube
	turnRightWithSensor(500);
	moveForwardWithSensor(1250);
	openclaw();
	wait1Msec(1000);
	turnLeftWithSensor(460);
	moveForwardWithSensor(1000);
	wait1Msec(1000);
	closeclaw();
	wait1Msec(500);
	turnRightWithSensor(475)
	moveForwardWithSensor(1250);
	openclaw();
*/	/*  moveforward(127);
	wait1Msec(1700);
	moveforward(0);
	closeclaw();
	wait1Msec(250);
	liftarm();
	wait1Msec(1000);
	turnleft(127);
	wait1Msec(600);
	moveforward(127);
	wait1Msec(550);
	openclaw();
	wait1Msec(500);
	movebackward(127);
	wait1Msec(450);
	turnright(127);
	wait1Msec(1150);
	turnright(0);
	droparm();
	wait1Msec(1000);
	moveforward(127);
	wait1Msec(400);
	moveforward(0);
	closeclaw();
	wait1Msec(500);
	liftarm();
	wait1Msec(1000);
	turnleft(127);
	wait1Msec(1000);
	moveforward(127);
	wait1Msec(900);
	moveforward(0);
	openclaw();
	wait1Msec(500);
	movebackward(127);
	wait1Msec(900);
	turnright(127);
	wait1Msec(600);
	droparm();
	moveforward(127);
	clawtarget = 2400;
	wait1Msec(1600);
	moveforward(0);
	closeclaw();
	wait1Msec(500);
	liftarm();
	wait1Msec(1000);
	turnleft(127);
	wait1Msec(1400);
	moveforward(127);
	wait1Msec(1500);
	*/ // moveforward(0);

	// 2400
}
