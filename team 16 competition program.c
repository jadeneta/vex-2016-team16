#pragma config(Sensor, in1, liftSensor, sensorPotentiometer)
#pragma config(Sensor, in2, clawSensor, sensorPotentiometer)
#pragma config(Sensor, dgtl1, bumper, sensorTouch)
#pragma config(Sensor, dgtl3, leftshaft, sensorQuadEncoder)
#pragma config(Sensor, dgtl12, touch, sensorTouch)
#pragma config(Motor, port1, , tmotorVex393_HBridge, openLoop)
#pragma config(Motor, port2, rightbackwheel, tmotorVex393_MC29, openLoop,      \
               driveRight)
#pragma config(Motor, port3, rightfrontwheel, tmotorVex393_MC29, openLoop,     \
               driveRight)
#pragma config(Motor, port4, leftlift, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port5, backwheel, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port6, leftbackwheel, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port7, leftfrontwheel, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port8, claw, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port9, rightlift, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor, port10, , tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard !!*//

#pragma platform(VEX)
#define DEADBAND 20

// Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(300)
#pragma userControlDuration(900)
#include "Vex_Competition_Includes.c" //Main competition background code...do not modify!
#include "slew motor program.c"
int clawtarget = 1000;
int armtarget = 300;
bool clawhold = false;
bool lifthold = false;
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

int min(int a, int b) {
  if (a > b)
    return b;
  return a;
}

int max(int a, int b) {
  if (a > b)
    return a;
  return b;
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
task claw_Control() {
  while (true) {

    int currentvalue = SensorValue[clawSensor];
    int clawerror = clawtarget - abs(currentvalue);
    motorReq[claw] = clawerror / 5;
    if (clawerror > 127) {
      clawerror = 127;
    }
    if (clawerror < -127)
      clawerror = -127;

    wait1Msec(MOTOR_TASK_DELAY);
  }
}
task arm_Control() {
  int arm = 0;

  int armerror = 0;

  while (true) {

    if (lifthold) {
      int currentvalue = SensorValue[liftSensor];
      armerror = armtarget - abs(currentvalue);
      arm = armerror / 5;
      if (arm > 127) {
        arm = 127;
      }
      if (abs(arm) < 20)
        arm = 0;
      if (arm < -127)
        arm = -127;
      motorReq[rightlift] = arm;
      motorReq[leftlift] = arm;
    }
    wait1Msec(MOTOR_TASK_DELAY);
  }
}
void auto();
void moveforward(int forward) {
  motorReq[leftfrontwheel] = forward;
  motorReq[leftbackwheel] = forward;
  motorReq[rightfrontwheel] = -forward;
  motorReq[rightbackwheel] = -forward;
}
void movebackward(int backward) {
  motorReq[leftfrontwheel] = -backward;
  motorReq[leftbackwheel] = -backward;
  motorReq[rightfrontwheel] = backward;
  motorReq[rightbackwheel] = backward;
}
void turnleft(int left) {
  motorReq[leftfrontwheel] = left;
  motorReq[leftbackwheel] = left;
  motorReq[rightfrontwheel] = left;
  motorReq[rightbackwheel] = left;
}
void turnright(int right) {
  motorReq[leftfrontwheel] = -right;
  motorReq[leftbackwheel] = -right;
  motorReq[rightfrontwheel] = -right;
  motorReq[rightbackwheel] = -right;
}
void setArmPower(int speed) {
  // motorReq[leftclaw] = speed;
  motorReq[claw] = speed;
}
task autonomous() {
  startTask(MotorSlewRateTask);
  startTask(arm_Control);
  startTask(claw_Control);

  int leftBspeed = 0;
  int leftFspeed = 0;
  int rightFspeed = 0;
  int rightBspeed = 0;

  auto();
}
void auto() {
  clawhold = true;
  lifthold = true;
  int leftBspeed = 0;
  int leftFspeed = 0;
  int rightFspeed = 0;
  int rightBspeed = 0;

  setArmPower(0);
  armtarget = 110;

  // motorReq[front] = -50;
  // motorReq[back] = 50;
  armtarget = 2600;
  clawtarget = 1190;
  wait1Msec(1600);
  // goes forward while lifting arm and closing

  moveforward(127);
  wait1Msec(2500); // 4100
  // the claw hits the star and opens to hit multiply off
  movebackward(127);

  wait1Msec(1150); // 5250
  turnleft(127);

  wait1Msec(700); // 5950
  turnleft(0);
  armtarget = 700;
  wait1Msec(500); // 6450
  moveforward(127);
  wait1Msec(700); // 7150
  moveforward(0);
  clawtarget = 2870;
  wait1Msec(500); // 7650
  armtarget = 2700;
  wait1Msec(750); // 8400
  turnright(127);
  wait1Msec(450); // 8850
  moveforward(127);
  wait1Msec(1700); // 10350
  moveforward(0);
  clawtarget = 1190;
  wait1Msec(1000); // 11350
  movebackward(127);
  wait1Msec(750); // 12100
  turnleft(127);
  armtarget = 2600;
  wait1Msec(450); // 12550
  moveforward(127);
  wait1Msec(500); // 13050
  movebackward(127);
  wait1Msec(500); // 13550
  stopTask(MotorSlewRateTask);
  stopTask(arm_Control);
  stopTask(claw_Control);
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
  startTask(arm_Control);
  startTask(claw_Control);
  startTask(MotorSlewRateTask);
  int clawOpenSpeed = 127;
  int clawCloseSpeed = 127;
  int clawGrabSpeed = 100;
  bool clawGrab = false;
  lifthold = false;

  int clawspeed = 0;
  int arm = 0;
  int armerror = 0;
  armtarget = 40;
  while (true) {
    int clawSensorValue = SensorValue[clawSensor];
    int liftSensorValue = SensorValue[liftSensor];
    int backwheelspeed = 0;
    int leftBspeed = 0;
    int leftFspeed = 0;
    int rightFspeed = 0;
    int rightBspeed = 0;
    // if (vexRT[Btn5U] == 1) {
    // auto();
    // }

    // Turn left-right
    if (abs(vexRT[Ch4]) > DEADBAND) {
      leftBspeed = vexRT[Ch4] / 2;
      leftFspeed = vexRT[Ch4] / 2;
      rightBspeed = vexRT[Ch4] / 2;
      rightFspeed = vexRT[Ch4] / 2;
    } else {
      // Move Forward/Backward
      if (abs(vexRT[Ch2]) > DEADBAND) {
        leftFspeed = vexRT[Ch2];
        leftBspeed = vexRT[Ch2];
        rightFspeed = -vexRT[Ch2];
        rightBspeed = -vexRT[Ch2];
      }

      // Move Right/Left
      if (abs(vexRT[Ch1]) > DEADBAND) {
        backwheelspeed = -vexRT[Ch1];
      }
    }

    // Close Claw
    if (vexRT[Btn8UXmtr2] == 1) {
      clawtarget = min(2950, clawtarget + 25);
      clawhold = false;
    }
    // Open Claw
    else if (vexRT[Btn8DXmtr2] == 1) {
      clawtarget = max(1200, clawtarget - 25);
      clawhold = false;

    } else {
      // Grab and Hold
      if (vexRT[Btn6UXmtr2] == 1) {
        clawtarget = 2940;
        clawhold = true;
      }
      if (!clawhold) {
        clawspeed = 0;
      }
    }

    // Lift
    if (vexRT[Btn5UXmtr2] == 1) {
      lifthold = true;
      armtarget = 1500;
    }

    if (vexRT[Btn7UXmtr2] == 1) {
      // Srop Arm when switch activated
      armtarget = min(2700, armtarget + 30);
      lifthold = true;
    }

    // Drop Lift
    else if (vexRT[Btn7DXmtr2] == 1) {
      armtarget = max(900, armtarget - 25);
      lifthold = true;
    }

    else {
      arm = 0;
    }

    if (vexRT[Btn5DXmtr2] == 1) {
      arm = 0;
      lifthold = false;
    }

    // keeps lift up a little to move around
    /*
    if (SensorValue[touch] == 1) {
      if (arm > 0) {
        arm = 0;
      }
      claw = clawOpenSpeed;
      clawhold = false;
      lifthold = false;
    }
    if (SensorValue[bumper] == 1) {
      if (arm < 0) {
        arm = 0;
      }
      SensorValue[leftshaft] = 0;
    }
    */
    motorReq[backwheel] =
        backwheelspeed; // arm Sensor max value 2700(top) min value 900(bottom)
    motorReq[leftbackwheel] = leftBspeed; // claw closed 2870 claw middle 1250
    motorReq[leftfrontwheel] = leftFspeed;
    motorReq[rightfrontwheel] = rightFspeed;
    motorReq[rightbackwheel] = rightBspeed;

    if (!clawhold)
      motorReq[claw] = clawspeed;
    if (!lifthold) {
      motorReq[rightlift] = arm;
      motorReq[leftlift] = arm;
    }
    wait1Msec(MOTOR_TASK_DELAY);
  }
}
// motor max power ;-;
