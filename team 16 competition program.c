#pragma config(Sensor, dgtl1,  bumper,         sensorTouch)
#pragma config(Sensor, dgtl3,  leftshaft,      sensorQuadEncoder)
#pragma config(Sensor, dgtl12, touch,          sensorTouch)
#pragma config(Motor,  port1,            ,             tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           front,         tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port3,           leftclaw,      tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port4,           rightclaw,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           left,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           right,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           back,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightlift,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           leftlift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,           ,             tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)
#define DEADBAND 20

// Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(300)
#pragma userControlDuration(900)
#include "Vex_Competition_Includes.c" //Main competition background code...do not modify!
#include "slew motor program.c"
/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them
// in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton() {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX
// Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous() {
  startTask(MotorSlewRateTask);
  //  int rightspeed=0;
  //  int leftspeed=0;
  int turnspeedratio = 0.5;
  int frontspeed = 0;
  int backspeed = 0;
  int claw = 0;
  int arm = 0;
  motorReq[left] = 127;
  motorReq[right] = -127;
  wait(2);
  motorReq[left] = 0;
  motorReq[right] = 0;
  backspeed = 127;
  frontspeed = 127;
  motorReq[front] = frontspeed;
  motorReq[back] = backspeed;
  wait(.5);
  frontspeed = 0;
  backspeed = 0;
  motorReq[front] = frontspeed;
  motorReq[back] = backspeed;
  arm = 127;
  motorReq[rightlift] = arm;
  motorReq[leftlift] = arm;
  wait(2);
  arm = 0;
  motorReq[rightlift] = arm;
  motorReq[leftlift] = arm;
  claw = -127;
  motorReq[rightclaw] = claw;
  motorReq[leftclaw] = claw;
  wait(1);
  claw = 127;
  motorReq[rightclaw] = claw;
  motorReq[leftclaw] = claw;
  wait(1);
  claw = 0;
  motorReq[rightclaw] = claw;
  motorReq[leftclaw] = claw;
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a
// VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol() {
  // User control code here, inside the loop
  startTask(MotorSlewRateTask);
  float turnspeedratio = 0.3;
  int clawOpenSpeed = 50;
  int clawCloseSpeed = 127;
  int clawGrabSpeed = 75;
  bool clawGrab = false;
  bool liftinglift = false;
  bool lifthold=false;
  int claw = 0;
   int arm = 0;
   int armtarget = 40;
   int armerror = 0;
  while (true) {

    int rightspeed = 0;
    int leftspeed = 0;
    int frontspeed = 0;
    int backspeed = 0;


    // Turn left-right
    if (abs(vexRT[Ch4]) > DEADBAND) {
      frontspeed = vexRT[Ch4] * turnspeedratio;
      rightspeed = vexRT[Ch4] * turnspeedratio;
      leftspeed = vexRT[Ch4] * turnspeedratio;
      backspeed = vexRT[Ch4] * turnspeedratio;
    } else {
      // Move Forward/Backward
      if (abs(vexRT[Ch2]) > DEADBAND) {
        leftspeed = vexRT[Ch2];
        rightspeed = -vexRT[Ch2];
      }

      // Move Right/Left
      if (abs(vexRT[Ch1]) > DEADBAND) {
        frontspeed = vexRT[Ch1];
        backspeed = -vexRT[Ch1];
      }
    }

    // Close Claw
    if (vexRT[Btn8UXmtr2] == 1) {
      claw = -clawCloseSpeed;
      clawGrab = false;
    }
    // Open Claw
    else if (vexRT[Btn8DXmtr2] == 1) {
      claw = clawOpenSpeed;
      clawGrab = false;

    } else {
      // Grab and Hold
      if (vexRT[Btn6UXmtr2] == 1) {
        claw = -clawGrabSpeed;
        clawGrab = true;
      }
      if (!clawGrab) {
        claw = 0;
      }
    }

    // Lift
    if (vexRT[Btn5UXmtr2] == 1) {
      lifthold=true;
    }

    if (vexRT[Btn7UXmtr2] == 1) {
      // Srop Arm when switch activated
        arm = 127;
        lifthold=false;
    }

    // Drop Lift
    else if (vexRT[Btn7DXmtr2] == 1)
    {
      arm = -50;
      lifthold=false;
    }

    else if (lifthold) {
      int currentvalue = SensorValue[leftshaft];
      armerror = armtarget - abs(currentvalue);
      arm = armerror*2;
    }

    if (vexRT[Btn5DXmtr2] == 1) {
     arm = 0;
     lifthold=false;
    }

    // keeps lift up a little to move around
    if (SensorValue[touch] == 1) {
       if (arm > 0)
       {
         arm = 0;
       }
        claw = clawOpenSpeed;
        clawGrab = false;
        lifthold=false;
    }
    if(SensorValue[bumper] == 1)
    {
      if (arm < 0)
      {
        arm = 0;
      }
      SensorValue[leftshaft] = 0;
    }


    motorReq[right] = rightspeed;
    motorReq[left] = leftspeed;
    motorReq[front] = frontspeed;
    motorReq[back] = backspeed;
    motorReq[rightclaw] = claw;
    motorReq[leftclaw] = claw;
    motorReq[rightlift] = arm;
    motorReq[leftlift] = arm;

    wait1Msec(MOTOR_TASK_DELAY);
  }
}
// motor max power ;-;