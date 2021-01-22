#pragma once
#include "RobotMap.h"
#include "strategy/StrategySystem.h"


class Climber {
  public :
	// Constructor
    Climber(wml::controllers::SmartControllerGroup &contGroup,
						wml::TalonSrx &ClimberMotor);
		
		// Setup Functions
		void TeleopOnUpdate (double dt);
		void AutoOnUpdate(double dt);
 		void TestOnUpdate(double dt);

  private :
		wml::controllers::SmartControllerGroup &_contGroup;
		wml::TalonSrx &_ClimberMotor;
		int _previousTicks;
		int _currentTicks;
};