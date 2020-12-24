/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package org.usfirst.frc.team6954.robot;

import org.usfirst.frc.team6954.robot.commands.forward;

import edu.wpi.first.wpilibj.CameraServer;
import edu.wpi.first.wpilibj.DriverStation;
import edu.wpi.first.wpilibj.IterativeRobot;
import edu.wpi.first.wpilibj.Joystick;
import edu.wpi.first.wpilibj.Spark;
import edu.wpi.first.wpilibj.SpeedController;
import edu.wpi.first.wpilibj.SpeedControllerGroup;
import edu.wpi.first.wpilibj.Talon;
import edu.wpi.first.wpilibj.Timer;
import edu.wpi.first.wpilibj.drive.DifferentialDrive;
import edu.wpi.first.wpilibj.hal.MatchInfoData;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
//import edu.wpi.first.wpilibj.AnalogGyro;

/**
 * This is a demo program showing the use of the RobotDrive class, specifically
 * it contains the code necessary to operate a robot with tank drive.
 */
public class Robot extends IterativeRobot {
        private DifferentialDrive m_myRobot;
        private Joystick m_joyStick;
        private Timer drive_timer;
        private boolean isTimerStart = false;
        private Talon m_Talon = new Talon(4);
       // private AnalogGyro m_gyro = new AnalogGyro(0);
        private SpeedController gLeftMotor = new SpeedControllerGroup(new
Spark(2), new Spark(3));
        private SpeedController gRightMotor = new SpeedControllerGroup(new
Spark(0), new Spark(1));

        forward autonCommand;
        
        @Override
        public void robotInit() {
        		drive_timer = new Timer();
                m_myRobot = new DifferentialDrive(gLeftMotor, gRightMotor);
                m_joyStick = new Joystick(0);
                CameraServer.getInstance().startAutomaticCapture();
               // m_gyro.initGyro();
                //m_gyro.reset();
                autonCommand = new forward();
        }

        @Override
        public void teleopPeriodic() {
        	
                m_myRobot.arcadeDrive(-m_joyStick.getY()*.90, m_joyStick.getX()*.90);

                if(m_joyStick.getRawButton(5)){
                        m_Talon.set(-0.5);

                } else if(m_joyStick.getRawButton(6)) {
                        m_Talon.set(0.7);
                }
                else {
                        m_Talon.set(0);
                }
                //SmartDashboard.putNumber("gyro", m_gyro.getAngle());

        }
        
        public void autonomousInit() {
        	autonCommand = new forward();
        	drive_timer.reset();
        	drive_timer.start();
        	//m_gyro.reset();
        }
        
        public void autonomousPeriodic() 
        {
        	//String gameData;
        	
//         	if(!isTimerStart) {
//        		isTimerStart = true;
//        		drive_timer.start();
//        	}
//        	if (drive_timer.get() > 6.25)
//        	{
//        		if (m_gyro.getAngle() > 0.2)
//        		{
//        			m_myRobot.tankDrive(0.5, 0.75);
//        		}
//        		else if (m_gyro.getAngle() < -0.2) {
//        			m_myRobot.tankDrive(0.75, 0.5);
//        		}
//        		else {
//        			m_myRobot.tankDrive(0.5, 0.5);
//        		}
//        	}
        	if(drive_timer.get() > 7) 
        	{
        		//m_myRobot.tankDrive(leftSpeed, rightSpeed);
        		m_myRobot.arcadeDrive(0.0, 0.0);
        	}
        	
        	else {
        		m_myRobot.arcadeDrive(0.6, 0.0);
        	}
        	/*
        	if (drive_timer.get() <= 10.0 && drive_timer.get() >7) {
        		gameData = DriverStation.getInstance().getGameSpecificMessage();
            if(gameData.length() > 0)
            {
    	      if(gameData.charAt(0) == 'L')
    	      	{
    	    	  		  //Put left auto code here
    	    	  		  m_myRobot.arcadeDrive(-m_joyStick.getY()*.70, m_joyStick.getX()*.00);
    	    	  		  
    	    	} else {
    	    			  //Put right auto code here
    	    			  m_myRobot.arcadeDrive(-m_joyStick.getY()*.00, m_joyStick.getX()*.70);
    	    			}
    	      
            }
            } 
        	/*
        	else {
    			m_myRobot.arcadeDrive(0.0, 0.0);
            }
            
        	if (drive_timer.get() <= 13.0 && drive_timer.get() >10) {
        		m_myRobot.arcadeDrive(-0.7, 0.0);
        	}
        	
        	else {
        		m_myRobot.arcadeDrive(0.0, 0.0);
        	}
        	
        	if (drive_timer.get() <= 15.0 && drive_timer.get() >13) {
        		m_Talon.set(.7);
        	} 
        	
        	else {
        		m_Talon.set(0.0);
        	}
        	
        	*/
        	

        }
        	
    	}
