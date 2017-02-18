void autoleft()
{
	armtarget =  1600;
	wait1Msec(750);
 clawtarget = 1400;
 wait1Msec(1200);
 droparm();
 wait1Msec(500);
moveForwardWithSensor(1300);
 closeclaw();
 wait1Msec(500);
 liftarm();
moveBackwardWithSensor(1300);
turnLeftWithSensor(TURNLEFT_90 - 10);
moveForwardWithSensor(1500);
 openclaw();
 wait1Msec(500);
moveBackwardWithSensor(800);
 turnRightWithSensor(230);
  moveBackwardWithSensor(200);
 droparm();
 wait1Msec(500);
 moveForwardWithSensor(200);
 closeclaw();
 wait1Msec(900);
 liftarm();
 wait1Msec(250);
 turnLeftWithSensor(300);
 moveForwardWithSensor(600);
 openclaw();
 wait1Msec(1500);


}
