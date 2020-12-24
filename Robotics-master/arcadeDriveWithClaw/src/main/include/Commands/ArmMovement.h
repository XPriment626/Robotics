
#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class ArmMovement : public frc::Command {
 public:
  ArmMovement();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
