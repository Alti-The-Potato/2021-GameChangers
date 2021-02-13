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

class Climber : public wml::StrategySystem, public wml::devices::StateDevice<ClimberState> {
  public :
	// Constructor
    Climber(wml::TalonSrx &ClimberMotor);

		void DeActivate();

		void Extend();

		void setClimber(ClimberState state, double power = 0);

		void OnStatePeriodic(ClimberState state, double dt) override;

		

  private :
		wml::TalonSrx &_climberMotor;
		ClimberState _climberState{ ClimberState::DISABLED };

		double _power;
};