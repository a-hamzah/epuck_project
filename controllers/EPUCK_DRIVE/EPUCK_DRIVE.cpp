// File:          EPUCK_DRIVE.cpp
// Date:
// Description:
// Author:
// Modifications:

// You may need to add webots include files such as
// <webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/DistanceSensor.hpp>


#define TIME_STEP 64
#define MAX_SPEED 6.28
// All the webots classes are defined in the "webots" namespace
using namespace webots;

// This is the main program of your controller.
// It creates an instance of your Robot instance, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node
int main(int argc, char **argv) {
  // create the Robot instance.
  Robot *robot = new Robot();
  // Motors
  Motor *leftMotor = robot->getMotor("left wheel motor");
  Motor *rightMotor = robot->getMotor("right wheel motor");
  // Distance Sensor
  DistanceSensor *ds_left = robot->getDistanceSensor("ps7");
  DistanceSensor *ds_right = robot->getDistanceSensor("ps0");
  // Enable distance sensor using time step
  ds_left->enable(TIME_STEP);
  ds_right->enable(TIME_STEP);
  
  leftMotor->setPosition(INFINITY);
  rightMotor->setPosition(INFINITY);
  
  leftMotor->setVelocity(0.0);
  rightMotor->setVelocity(0.0);

  // get the time step of the current world.
  // int timeStep = (int)robot->getBasicTimeStep();

  // You should insert a getDevice-like function in order to get the
  // instance of a device of the robot. Something like:
  //  Motor *motor = robot->getMotor("motorname");
  //  DistanceSensor *ds = robot->getDistanceSensor("dsname");
  //  ds->enable(timeStep);

  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(TIME_STEP) != -1) {
    double ds_left_val = ds_left->getValue();
    double ds_right_val = ds_right->getValue();
    
    std::cout<< "Distance Sensor Left: " << ds_left_val << std::endl;
    std::cout<< "Distance Sensor Right: " << ds_right_val << std::endl;
    
    leftMotor->setVelocity(MAX_SPEED/4);
    rightMotor->setVelocity(MAX_SPEED/4);
    // rightMotor->setVelocity(-MAX_SPEED/2);
    // Read the sensors:
    // Enter here functions to read sensor data, like:
    //  double val = ds->getValue();

    // Process sensor data here.

    // Enter here functions to send actuator commands, like:
    //  motor->setPosition(10.0);
  };

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}
