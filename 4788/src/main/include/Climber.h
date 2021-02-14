#pragma once
#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class ClimberState {
	kEnabled = 0,
	kDisabled,
	kExtending,
	kRetracting
};

enum class RequestState {
	kToggle = 0,
	kMove
};

class Climber : public wml::StrategySystem {
  public :
	// Constructor
    Climber(wml::TalonSrx &ClimberMotor);

		void Retract();

		void Extend();

		void setClimber(RequestState state, double power);

		void ClimberLoop(double dt);

		void update(double dt);

		

  private :
		wml::TalonSrx &_climberMotor;
		ClimberState _climberState{ ClimberState::kDisabled };

		double _power;
};