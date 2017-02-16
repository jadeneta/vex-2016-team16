void autoleft()
{
 clawtarget = 1400;
turnRightWithSensor(TURNRIGHT_90-5);
moveForwardWithSensor(1200);
 closeclaw();
 wait1Msec(500);
 liftarm();
moveBackwardWithSensor(1100);
turnLeftWithSensor(TURNLEFT_90 +20);
moveForwardWithSensor(1500);
 openclaw();
 wait1Msec(500);
moveBackwardWithSensor(800);
 turnRightWithSensor(230);
 droparm();
 wait1Msec(500);
 moveForwardWithSensor(100);
 closeclaw();
 wait1Msec(900);
 liftarm();
 wait1Msec(250);
 turnLeftWithSensor(300);
 moveForwardWithSensor(600);
 openclaw();
 wait1Msec(500);

}
