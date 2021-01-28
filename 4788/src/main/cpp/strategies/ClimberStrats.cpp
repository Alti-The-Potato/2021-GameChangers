#include "strategies/ClimberStrats.h"

ClimberManualStrategy::ClimberManualStrategy(std::string name, Climber &climber, Controllers &contGroup) : Strategy(name), _climber(climber), _contGroup(contGroup){}

void ClimberManualStrategy::OnUpdate(double dt) {

	// If button is pressed make the climber go up
	if(_contGroup.Get(ControlMap::ClimberUp, wml::controllers::Controller::ONRISE)) {
		_climber.setClimber(ClimberState::NORMAL, wml::actuators::BinaryActuatorState::kForward);

	// If button is pressed make the climber go down
	} else if (_contGroup.Get(ControlMap::ClimberDown, wml::controllers::Controller::ONRISE)) {
		_climber.setClimber(ClimberState::NORMAL, wml::actuators::BinaryActuatorState::kReverse);

	}
}