void autoleft()
{
 clawtarget = 2250;
 turnrightwithsensor(TURNRIGHT_90-5);
 moveforwardwithsensor(1200);
 closeclaw();
 wait1Msec(500);
 liftarm();
 movebackwardwithsensor(1100);
 turnleftwithsensor(TURNLEFT_90 +20);
 moveforwardwithsensor(1500);
 openclaw();
 wait1Msec(500);
 movebackwardwithsensor(800);
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
