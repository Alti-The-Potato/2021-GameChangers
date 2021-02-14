#include "Climber.h"
#include <iostream>

using namespace wml;
using namespace wml::controllers;

Climber::Climber(TalonSrx &ClimberMotor) : _climberMotor(ClimberMotor) {}

void Climber::ClimberLoop (double dt) {

	switch (_climberState) {
		case ClimberState::kDisabled:
			break;
		
		case ClimberState::kEnabled:
			_climberMotor.Set(_power);
			break;
		
		case ClimberState::kExtending:
			Climber::Extend();
			break;

		case ClimberState::kRetracting:
			Climber::Retract();
			break;
	}
}

void Climber::Extend () {
	// If the motor isn't moving fast enough (i.e its hit a mechanical limit) as we don't have limit switches
	if (abs(_climberMotor.GetSensorVelocity()) < 100) {
		// Stop the motor
		_climberMotor.Set(0);
		// Set the state to enabled
		_climberState = ClimberState::kEnabled;
	} else {
		// Otherwise keep going
		_climberMotor.Set(ControlMap::ClimberMaxSpeed);
		_climberState = ClimberState::kExtending;
	}
}

void Climber::Retract () {
	// If the motor isn't moving fast enough (i.e its hit a mechanical limit) as we don't have limit switches
	if(abs(_climberMotor.GetSensorVelocity()) < 100) {
		// Stop the motor
		_climberMotor.Set(0);
		// Set the climber state to disabled
		_climberState = ClimberState::kDisabled;
	} else {
		// Other wise keep going
		_climberMotor.Set(-ControlMap::ClimberMaxSpeed);
		_climberState = ClimberState::kRetracting;
	}
}

void Climber::setClimber (RequestState state, double power = 0) {

	// Sorry, this isn't very readable but lets go: Depending on what the controller sets the state to we do
	// stuff
	switch (state) {
		// If they request to move
		case RequestState::kMove:
			// If the climber is enabled
			if (_climberState == ClimberState::kEnabled) {
				// Make motor go brrrrrrrrrrrrrrrrrrrrr
				_power = power;
			}
			break;
		
		// If they request the state to be toggled
		case RequestState::kToggle:
			switch (_climberState) {
				// If the climber is enabled (up)
				case ClimberState::kEnabled:
					// Make the climber go down
					_climberState = ClimberState::kRetracting;
					break;
				// If the climber is disabled (down)
				case ClimberState::kDisabled:
					// Make the climber go up
					_climberState = ClimberState::kExtending;
					break;

				default:
					break;

			}
			break;

		default :
			break;
	}
}

void Climber::update (double dt) {
	Climber::ClimberLoop(dt);
}