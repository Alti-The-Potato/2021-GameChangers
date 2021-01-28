#include "Climber.h"
#include <iostream>

using namespace wml;
using namespace wml::controllers;

Climber::Climber(actuators::DoubleSolenoid &ClimberAuct) : _climberAuct(ClimberAuct) {
}

void Climber::setClimber(const ClimberState st, actuators::BinaryActuatorState cST) {
	_climberState = st;
	_climberAuctState = cST;
}

void Climber::updateClimber (double dt) {
	// Setup actuator state shenanigans
	actuators::BinaryActuatorState state = actuators::BinaryActuatorState::kReverse;

	switch (_climberState) {
		case ClimberState::NORMAL:
			state = _climberAuctState;
			break;
	}

	_climberAuct.SetTarget(state);
}

void Climber::update (double dt) {
	updateClimber(dt);
}




/*
void Climber::TeleopOnUpdate(double dt) {

	// If button is pressed pull on the string to raise climber
	if(_contGroup.Get(ControlMap::ClimberUp, Controller::ONRISE)) {
		_ClimberMotor.Set(ControlMap::ClimberSpeed);

	// If button is pressed release the string to lower climber
	} else if (_contGroup.Get(ControlMap::ClimberDown, Controller::ONRISE)) {
		_ClimberMotor.Set(-ControlMap::ClimberSpeed);

	// If no button is pressed stop
	} else {
		_ClimberMotor.Set(0);
	}
}
*/