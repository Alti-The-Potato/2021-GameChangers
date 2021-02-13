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
			break;
		
		case ClimberState::kExtending:
			break;
	}
}