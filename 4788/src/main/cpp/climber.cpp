#include "Climber.h"
#include <iostream>

using namespace wml;
using namespace wml::controllers;

Climber::Climber(TalonSrx &ClimberMotor) : _climberMotor(ClimberMotor) {}

void Climber::Down() {

}

void Climber::Extend(double power) {

}

void Climber::Activated(double power) {

}

void Climber::OnStatePeriodic(ClimberState state, double dt) {

	switch (state) {
		case ClimberState::kDisabled:
			break;
		
		case ClimberState::kEnabled:
			_climberMotor.Set(_power)
			break;
		
		case ClimberState::kExtending:
			Climber::Extend();
			break;

		case ClimberState::kRetracting:
			Climber::DeActivate();
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
		_climberMotor.Set(0.7);
		_climberState = ClimberState::kExtending;
	}
}

void Climber::DeActivate () {
	// If the motor isn't moving fast enough (i.e its hit a mechanical limit) as we don't have limit switches
	if(abs(climberMotor.GetSensorVelocity()) < 100) {
		// Stop the motor
		_climberMotor.Set(0);
		// Set the climber state to disabled
		_climberState = ClimberState::kDisabled;
	} else {
		// Other wise keep going
		_climberMotor.Set(-0.7);
		_climberState = ClimberState::kRetracting;
	}
}

void Climber::setClimber (RequestState state, double power = 0) {

	// Sorry, this isn't very readable but lets go: Depending on what the controller sets the state to we do
	// stuff
	switch (RequestState) {
		// If they request the state to be set to enabled
		case RequestState::kMove:
			if (_climberState == ClimberState::kEnabled){
				_power = power;
			}
			break;
		
		// If they request the state to be toggled
		case RequestState::kToggle:
			switch (_climberState) {
				case ClimberState::kEnabled:
					_climberState = ClimberState::kRetracting;
					break;
				
				case ClimberState::kDisabled:
					_climberState = ClimberState::kExtending;

			}
			break;
	}
}