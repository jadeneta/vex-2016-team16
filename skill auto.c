void autoskill() {

int fieldlength = 1500;
	clawtarget = 1400;
  liftarm();
	waitforarmheight(ARM_HIGH-600);
	wait1Msec(700);
	closeclaw();
	wait1Msec(700);
	moveForwardWithSensor(fieldlength);
	//release first stars
	openclaw();
	wait1Msec(1000);
	moveBackwardWithSensor(450);
		armtarget = 2400;
		wait1Msec(300);
		moveForwardWithSensor(400);
		liftarm();
	moveBackwardWithSensor(fieldlength);
	clawtarget = 1400;
	wait1Msec(1500);
	moveForwardWithSensor(fieldlength);
	// release second stars
	openclaw();
	wait1Msec(1000);
	moveBackwardWithSensor(fieldlength);
	liftarm();
	wait1Msec(500);
	//waiting for first cube
	closeclaw();
	wait1Msec(1000);
	moveForwardWithSensor(fieldlength);
	// release cube
	openclaw();
	wait1Msec(1000);

	moveBackwardWithSensor(fieldlength - 50);
	//wait for second cube
	wait1Msec(1000);
	closeclaw();
	wait1Msec(1000);
	moveForwardWithSensor(fieldlength);
	// release 2nd cube
	openclaw();
  wait1Msec(1000);
  moveBackwardWithSensor(400);
  turnRightWithSensor(TURNRIGHT_90 - 30);
  moveBackwardWithSensor(150);
  clawtarget = 1400;
  wait1Msec(700);
  droparm();
  wait1Msec(800);
  // get 3 stars
  moveForwardWithSensor(1300);

  //moving away from fence
 turnright(75);
 wait1Msec(300);
 turnright(0);
   closeclaw();
  wait1Msec(600);
  moveBackwardWithSensor(100);
 armtarget = 2400;
  waitforarmheight(2000);
  turnLeftWithSensor(TURNLEFT_90 + 75);
  moveForwardWithSensor(300);
  openclaw();
  wait1Msec(700);
  moveBackwardWithSensor(200);
  turnRightWithSensor(TURNRIGHT_90 * 2);
  movebackward(75);
  wait1Msec(300);
  movebackward(0);
  droparm();
  openclaw();
 wait1Msec(1000);
 // grab cube in the middle
 moveForwardWithSensor(200);

 closeclaw();
 wait1Msec(1000);
 liftarm();
 wait1Msec(1000);
 turnRightWithSensor(TURNRIGHT_90 * 2);
 moveForwardWithSensor(300);
 openclaw();
 wait1Msec(500);
 moveBackwardWithSensor(300);
 turnRightWithSensor(TURNRIGHT_90 + 25);
 moveForwardWithSensor(1250);
  armtarget = 2400;
 turnLeftWithSensor(TURNLEFT_90);
 moveForwardWithSensor(600);




}
