#pragma config(Sensor, dgtl1,  rightshaft,     sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftshaft,      sensorQuadEncoder)
#pragma config(Sensor, dgtl12, touch,          sensorTouch)
#pragma config(Motor,  port1,           righttop,      tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           left,          tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port3,           front,         tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port4,           rightbottom,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           lefttop,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           leftclaw,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rightclaw,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           right,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           back,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          leftbottom,    tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)
#define DEADBAND 20

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(300)
#pragma userControlDuration(900)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  int rightspeed=0;
  int leftspeed=0;
  int frontspeed=0;
  int backspeed=0;
  int claw=0;
  int arm=0;
  motor(left) = 127;
  motor(right) = -127;
  wait(2);
  motor(left) = 0;
  motor(right) = 0;
  backspeed = 127;
  frontspeed = 127;
  motor[front] = frontspeed;
  motor[back] = backspeed;
  wait(.5);
  frontspeed = 0;
  backspeed = 0;
  motor[front] = frontspeed;
  motor[back] = backspeed;
  arm = 127;
  motor[righttop] = arm;
  motor[rightbottom] = arm;
  motor[lefttop] = arm;
  motor[leftbottom] = arm;
  wait(2);
  arm = 0;
  motor[righttop] = arm;
  motor[rightbottom] = arm;
  motor[lefttop] = arm;
  motor[leftbottom] = arm;
  claw = -127;
  motor[rightclaw] = claw;
  motor[leftclaw] = claw;
  wait(1);
  claw = 127;
  motor[rightclaw] = claw;
  motor[leftclaw] = claw;
  wait(1);
  claw = 0;
  motor[rightclaw] = claw;
  motor[leftclaw] = claw;

}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
  // User control code here, inside the loop

  while (true)
  {

    int rightspeed=0;
    int leftspeed=0;
    int frontspeed=0;
    int backspeed=0;
    int claw=0;
    int arm=0;

    if (abs(vexRT[Ch4])>DEADBAND)
    {
      frontspeed =vexRT[Ch4];
      rightspeed =vexRT[Ch4];
      leftspeed =vexRT[Ch4];
      backspeed =vexRT[Ch4];
    }
    else {
      if(abs(vexRT[Ch2])>DEADBAND)
      {
        leftspeed =vexRT[Ch2];
        rightspeed =-vexRT[Ch2];
      }

      if(abs(vexRT[Ch1])>DEADBAND)
      {
        frontspeed =vexRT[Ch1];
        backspeed =-vexRT[Ch1];
      }
    }
    if(SensorValue[touch] == 1)
    {
      arm = 0;
    }





    if(SensorValue[leftshaft] > 30)
    {
      arm = 30;
    }
    else if(SensorValue[leftshaft] < 30)
    {
      arm = -30;
    }


    if(vexRT[Btn8UXmtr2] ==1)
    {
      claw = -127;
    }
    else if(vexRT[Btn8DXmtr2] ==1)
    {
      claw = 127;
    }
    else
    {
      claw = 0;
    }
    if(vexRT[Btn7UXmtr2] ==1)
    {
      arm = 127;
    }
    else if(vexRT[Btn7DXmtr2] ==1)
    {
      arm = -127;
    }
    else
    {
      arm = 0;
    }


    motor[right] = rightspeed;
    motor[left] = leftspeed;
    motor[front] = frontspeed;
    motor[back] = backspeed;
    motor[rightclaw] = claw;
    motor[leftclaw] = claw;
    motor[righttop] = arm;
    motor[rightbottom] = arm;
    motor[lefttop] = arm;
    motor[leftbottom] = arm;
  }
}
  // motor max power ;-;
