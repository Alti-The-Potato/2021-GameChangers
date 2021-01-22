#include "Climber.h"
#include <iostream>

using namespace wml;
using namespace wml::controllers;

Climber::Climber(SmartControllerGroup &contGroup,
								TalonSrx &ClimberMotor) :

								_contGroup(contGroup),
								_ClimberMotor(ClimberMotor) {
								_previousTicks = _ClimberMotor.GetEncoderTicks();
}

void Climber::TeleopOnUpdate(double dt) {

	_currentTicks = _ClimberMotor.GetEncoderTicks();

	// If button is pressed pull on the string to raise climber
	if(_contGroup.Get(ControlMap::ClimberUp, Controller::ONRISE)) {
		
		// Check if the motor is jammed
		if (_currentTicks - _previousTicks < ControlMap::ClimberJamTolerance) {
			_ClimberMotor.Set(0);
		} else {
			_ClimberMotor.Set(ControlMap::ClimberSpeed);
		}

	// If button is pressed release the string to lower climber
	} else if (_contGroup.Get(ControlMap::ClimberDown, Controller::ONRISE)) {
		if (_previousTicks - _currentTicks < ControlMap::ClimberJamTolerance) {
			_ClimberMotor.Set(0);
		} else {
			_ClimberMotor.Set(-ControlMap::ClimberSpeed);
		}

	// If no button is pressed stop
	} else {
		_ClimberMotor.Set(0);
	}
}