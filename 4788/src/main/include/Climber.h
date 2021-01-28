#pragma once
#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class ClimberState {
	NORMAL
};

class Climber : public wml::StrategySystem{
  public :
	// Constructor
    Climber(wml::actuators::DoubleSolenoid &ClimberAuct);

		//Set climber state and power
		void setClimber(const ClimberState, wml::actuators::BinaryActuatorState = wml::actuators::BinaryActuatorState::kReverse);

		// Looping and update for climber
		void updateClimber(double dt);

		// Update (master loop for Climber)
		void update (double dt);

		int climberEncoderValue();
		/*
		// Setup Functions
		void TeleopOnUpdate (double dt);
		void AutoOnUpdate(double dt);
 		void TestOnUpdate(double dt);
		 */

  private :
		wml::actuators::DoubleSolenoid &_climberAuct;
		ClimberState _climberState{ ClimberState::NORMAL };

		wml::actuators::BinaryActuatorState state;
};