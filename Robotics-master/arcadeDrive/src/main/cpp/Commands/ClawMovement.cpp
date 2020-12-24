/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/ClawMovement.h"
#include "Robot.h"

ClawMovement::ClawMovement() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::claw.get());
}

// Called just before this Command runs the first time
void ClawMovement::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ClawMovement::Execute() {
  if (Robot::oi->getUpButton() == true)
  {
    Robot::claw->setPower(1.0);
  }

  else if (Robot::oi->getDownButton() == true)
  {
    Robot::claw->setPower(-1.0);
  }
}

// Make this return true when this Command no longer needs to run execute()
bool ClawMovement::IsFinished() { return false; }

// Called once after isFinished returns true
void ClawMovement::End() {
  Robot::claw->setPower(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawMovement::Interrupted() {End();}
