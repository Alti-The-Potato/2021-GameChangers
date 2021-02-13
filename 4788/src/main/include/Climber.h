#pragma once
#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class ClimberState {
	kEnabled = 0,
	kDisabled,
	kExtending
};

class Climber : public wml::StrategySystem, public wml::devices::StateDevice<ClimberState> {
  public :
	// Constructor
    Climber(wml::TalonSrx &ClimberMotor);

		void Down();

		void Extend(double power);

		void Activated(double power);

		void OnStatePeriodic(ClimberState state, double dt) override;

		

  private :
		wml::TalonSrx &_climberMotor;
		ClimberState _climberState{ ClimberState::DISABLED };

		double _power;
};