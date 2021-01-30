#pragma once // Prevents code from being compiled multiple times
#include "strategy/StrategySystem.h" // This include the strategy system
#include "RobotMap.h" // This includes the definitions of the motors for your subsystem

/*
enum class IntakeState {
	STOWED,
	DEPLOYED
};
*/

enum class ExampleState {
	RAISED,
	LOWERED
};

class Example : wml::StrategySystem {
	public: // This means that these functions are accessible by others OUTSIDE the class
	
	 Example(wml::TalonSrx &exampleMotor, wml::actuators::DoubleSolenoid &exampleSolanoid);
	 // ^^ This is a constructor and it allows an outside function to set the variables
	 // ^^ Note: it is named the EXACT SAME as the class

	 void setExample (const ExampleState, double power = 0);
	 // ^^ This is a function used to set the example's state and power

	 void updateExample (double dt);
	 // ^^ This is the looping update for the example

	 void update(double dt);
	 // ^^ This is the master loop (woah, pog)

	private: // This means that these variables are accessible only by the class

	// Note & means Reference To
	 wml::TalonSrx &_exampleMotor; // Private reference to the example's motor
	 wml::actuators::DoubleSolenoid &_exampleSolanoid; // Private reference to the example's solanoid

	 ExampleState _exampleState{ ExampleState::LOWERED };
	 // ^^ Private instance of the example state. Note it's default is LOWERED

	 double _power;
};

