/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/AnalogInput.h>
#include <frc/MedianFilter.h>
#include <frc/PWMVictorSPX.h>
#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Spark.h>

/**
 * This is a sample program demonstrating how to use an ultrasonic sensor and
 * proportional control to maintain a set distance from an object.
 */
class Robot : public frc::TimedRobot {
 public:
  /**
   * Tells the robot to drive to a set distance (in inches) from an object using
   * proportional control.
   */

  void setPower(double leftP,double rightP){
    left->Set(leftP);
    right->Set(rightP);
    left1->Set(leftP);
    right1->Set(rightP);
}

  void TeleopInit() override {
    left.reset(new frc::Spark(0));
    left1.reset(new frc::Spark(1));
    // right.reset(new frc::Spark(2));
    // right1.reset(new frc::Spark(3));    
  }

  void TeleopPeriodic() override {
    // Sensor returns a value from 0-4095 that is scaled to inches
    // returned value is filtered with a rolling median filter, since
    // ultrasonics tend to be quite noisy and susceptible to sudden outliers
    double currentDistance = m_filter.Calculate(m_ultrasonic.GetVoltage()) * kValueToInches;
    // Convert distance error to a motor speed
    double currentSpeed = (kHoldDistance - currentDistance) * kP;
    // Drive robot
    // m_robotDrive.ArcadeDrive(currentSpeed, 0);

    setPower(currentSpeed, currentSpeed);
  }

 private:
  std::shared_ptr<frc::SpeedController> left;
  std::shared_ptr<frc::SpeedController> left1;
  std::shared_ptr<frc::SpeedController> right;
  std::shared_ptr<frc::SpeedController> right1;
  // Distance in inches the robot wants to stay from an object
  static constexpr int kHoldDistance = 12;

  // Factor to convert sensor values to a distance in inches
  static constexpr double kValueToInches = 0.125;

  // Proportional speed constant
  static constexpr double kP = 0.05;

  static constexpr int kLeftMotorPort = 0;
  static constexpr int kRightMotorPort = 1;
  static constexpr int kUltrasonicPort = 0;

  // median filter to discard outliers; filters over 10 samples
  frc::MedianFilter<double> m_filter{10};

  frc::AnalogInput m_ultrasonic{kUltrasonicPort};

  frc::PWMVictorSPX m_left{kLeftMotorPort};
  frc::PWMVictorSPX m_right{kRightMotorPort};
  frc::DifferentialDrive m_robotDrive{m_left, m_right};
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
