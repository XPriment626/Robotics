/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2020 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package frc.robot;

import edu.wpi.first.wpilibj.TimedRobot;
import edu.wpi.first.wpilibj.smartdashboard.SendableChooser;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;

import edu.wpi.first.wpilibj.AnalogInput;
import edu.wpi.first.wpilibj.Spark;
import edu.wpi.first.wpilibj.SpeedControllerGroup;
import edu.wpi.first.wpilibj.Joystick;
import edu.wpi.first.wpilibj.drive.DifferentialDrive;
import edu.wpi.first.wpilibj.MedianFilter;

/**
 * The VM is configured to automatically run this class, and to call the
 * functions corresponding to each mode, as described in the TimedRobot
 * documentation. If you change the name of this class or the package after
 * creating this project, you must also update the build.gradle file in the
 * project.
 */

public class Robot extends TimedRobot {
  private static final String kDefaultAuto = "Default";
  private static final String kCustomAuto = "My Auto";
  private String m_autoSelected;
  private final SendableChooser<String> m_chooser = new SendableChooser<>();

  Joystick joystick = new Joystick(0);

  Spark leftFront = new Spark(0);
  Spark leftRear = new Spark(1);
  Spark rightFront = new Spark(2);
  Spark rightRear = new Spark(3);
  Spark intake = new Spark(4);
  Spark loader = new Spark(5);
  Spark leftShooter = new Spark(6);
  Spark rightShooter = new Spark(7);

  SpeedControllerGroup m_left = new SpeedControllerGroup(leftFront, leftRear);
  SpeedControllerGroup m_right = new SpeedControllerGroup(rightFront, rightRear);
  SpeedControllerGroup m_shoot = new SpeedControllerGroup(leftShooter, rightShooter);

  DifferentialDrive drive = new DifferentialDrive(m_left, m_right);

  // sensor stuff
  /*
  final int kHoldDistance = 12;
  final double kValueToInches = 0.125;
  final double kP = .05;
  final int kUltrasonicPort = 0;

  MedianFilter filter = new MedianFilter(10);
  AnalogInput sensor = new AnalogInput(kUltrasonicPort);
  */

  final int btnIntake = 5;
  final int btnLoader = 6;

  final int btnShootLight = 2;
  final int btnShootMedium = 3;
  final int btnShootHard = 4;

  final double SPEED = 0.5;
  // final double SPEED = 0.5;

  boolean intakeToggle = false;

  /**
   * This function is run when the robot is first started up and should be
   * used for any initialization code.
   */
  @Override
  public void robotInit() {
    m_chooser.setDefaultOption("Default Auto", kDefaultAuto);
    m_chooser.addOption("My Auto", kCustomAuto);
    SmartDashboard.putData("Auto choices", m_chooser);
    m_left.setInverted(true);
  }

  /**
   * This function is called every robot packet, no matter the mode. Use
   * this for items like diagnostics that you want ran during disabled,
   * autonomous, teleoperated and test.
   *
   * <p>This runs after the mode specific periodic functions, but before
   * LiveWindow and SmartDashboard integrated updating.
   */
  @Override
  public void robotPeriodic() {
    
  }

  /**
   * This autonomous (along with the chooser code above) shows how to select
   * between different autonomous modes using the dashboard. The sendable
   * chooser code works with the Java SmartDashboard. If you prefer the
   * LabVIEW Dashboard, remove all of the chooser code and uncomment the
   * getString line to get the auto name from the text box below the Gyro
   *
   * <p>You can add additional auto modes by adding additional comparisons to
   * the switch structure below with additional strings. If using the
   * SendableChooser make sure to add them to the chooser code above as well.
   */
  @Override
  public void autonomousInit() {
    m_autoSelected = m_chooser.getSelected();
    // m_autoSelected = SmartDashboard.getString("Auto Selector", kDefaultAuto);
    System.out.println("Auto selected: " + m_autoSelected);
  }

  /**
   * This function is called periodically during autonomous.
   */
  @Override
  public void autonomousPeriodic() {
    switch (m_autoSelected) {
      case kCustomAuto:
        // Put custom auto code here
        break;
      case kDefaultAuto:
      default:
        // Put default auto code here
        break;
    }
  }

  /**
   * This function is called once when teleop is enabled.
   */
  @Override
  public void teleopInit() {
  }

  /**
   * This function is called periodically during operator control.
   */
  @Override
  public void teleopPeriodic() {
    drive.arcadeDrive(joystick.getRawAxis(0) * SPEED, joystick.getRawAxis(1) * SPEED);
    
  }

  /**
   * This function is called once when the robot is disabled.
   */
  @Override
  public void disabledInit() {
  }

  /**
   * This function is called periodically when disabled.
   */
  @Override
  public void disabledPeriodic() {
  }

  /**
   * This function is called once when test mode is enabled.
   */
  @Override
  public void testInit() {
  }

  /**
   * This function is called periodically during test mode.
   */
  @Override
  public void testPeriodic() {
    /*
    double currentDistance = filter.calculate(sensor.getVoltage() ) * kValueToInches;
    // Convert distance error to a motor speed
    double currentSpeed = (kHoldDistance - currentDistance) * kP;
    // Drive robot
    // m_robotDrive.ArcadeDrive(currentSpeed, 0);

    System.out.println(currentDistance);

    if (currentDistance > 24) {
      drive.arcadeDrive(0.2, 0);
    }
    else {
      drive.arcadeDrive(0, 0);
    }


    // move();
    */

    if (joystick.getRawButtonPressed(btnIntake)){
      intakeToggle = !intakeToggle;
    }

    loader.set(joystick.getRawAxis(3) * .15);
  }

 
}
