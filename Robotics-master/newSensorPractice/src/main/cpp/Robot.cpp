/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2020 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>




void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {

}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  // m_autoSelected = m_chooser.GetSelected();
  // // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  // //     kAutoNameDefault);
  // std::cout << "Auto selected: " << m_autoSelected << std::endl;

  // if (m_autoSelected == kAutoNameCustom) {
  //   // Custom Auto goes here
  // } else {
  //   // Default Auto goes here
  // }
}

void Robot::AutonomousPeriodic() {
  // if (m_autoSelected == kAutoNameCustom) {
  //   // Custom Auto goes here
  // } else {
  //   // Default Auto goes here
  // }
}

void Robot::TeleopInit() {
  // left.reset(new frc::Spark(0));
  // right.reset(new frc::Spark(1));
  
}

void Robot::TeleopPeriodic() {
  // Sensor returns a value from 0-4095 that is scaled to inches
    // returned value is filtered with a rolling median filter, since
    // ultrasonics tend to be quite noisy and susceptible to sudden outliers
    double currentDistance = m_filter.Calculate(m_ultrasonic.GetVoltage()) * kValueToInches;
    // Convert distance error to a motor speed
    double currentSpeed = (kHoldDistance - currentDistance) * kP;
    // Drive robot
    // m_robotDrive.ArcadeDrive(currentSpeed, 0);

    std::cout << currentDistance << '\n';
    left.Set(currentSpeed);
    right.Set(currentSpeed);
}

void Robot::DisabledInit(){}
void Robot::TestInit(){}
void Robot::DisabledPeriodic(){}
void Robot::TestPeriodic(){}



#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
