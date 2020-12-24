#include "Commands/ArmMovement.h"
#include "Robot.h"

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

ArmMovement::ArmMovement() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::arm.get()); 
}

// Called just before this Command runs the first time
void ArmMovement::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ArmMovement::Execute() {
  bool up = Robot::oi->getUpButton();
  bool down = Robot::oi->getDownButton();

  Robot::arm->setPower(up, down);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmMovement::IsFinished() { return false; }

// Called once after isFinished returns true
void ArmMovement::End() {
  Robot::arm->setPower(false, false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmMovement::Interrupted() {End();}
