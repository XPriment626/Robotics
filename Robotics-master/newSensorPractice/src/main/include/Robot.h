/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2020 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/Spark.h>
#include <frc/MedianFilter.h>
#include <frc/AnalogInput.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

 private:
 frc::Spark left{0};
 frc::Spark right{1};

//  std::shared_ptr<frc::SpeedController> left;
//  std::shared_ptr<frc::SpeedController> right;
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
  // Distance in inches the robot wants to stay from an object
  static constexpr int kHoldDistance = 12;

  // Factor to convert sensor values to a distance in inches
  static constexpr double kValueToInches = 0.125;

  // Proportional speed constant
  static constexpr double kP = 0.05;

  // static constexpr int kLeftMotorPort = 0;
  // static constexpr int kRightMotorPort = 1;
  static constexpr int kUltrasonicPort = 0;

  // median filter to discard outliers; filters over 10 samples
  frc::MedianFilter<double> m_filter{10};

  frc::AnalogInput m_ultrasonic{kUltrasonicPort};

};
