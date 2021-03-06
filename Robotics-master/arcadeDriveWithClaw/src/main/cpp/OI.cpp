// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "frc/smartdashboard/SmartDashboard.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    joystick1.reset(new frc::Joystick(0));
    
    // SmartDashboard Buttons

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

double OI::getLeftAxis()
{
    return -joystick1->GetY();
}

double OI::getRightAxis()
{
    //  return joystick1->GetRawAxis(3);
     return joystick1->GetZ();
}

bool OI::getOpenButton()
{
     return joystick1->GetRawButton(3);
}

bool OI::getCloseButton()
{
     return joystick1->GetRawButton(1);
}

bool OI::getUpButton()
{
     return joystick1->GetRawButton(8);
}

bool OI::getDownButton()
{
     return joystick1->GetRawButton(7);
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<frc::Joystick> OI::getJoystick1() {
   return joystick1;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
