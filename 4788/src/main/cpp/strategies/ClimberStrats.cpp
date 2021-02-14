#include "strategies/ClimberStrats.h"

ClimberManualStrategy::ClimberManualStrategy(std::string name, Climber &climber, Controllers &contGroup) :
																						Strategy(name), _climber(climber), _contGroup(contGroup) {}

void ClimberManualStrategy::OnUpdate(double dt) {
	_power = fabs((_contGroup.Get(ControlMap::ClimberAdjust))) > ControlMap::XboxDeadzone ? ControlMap::ClimberMaxSpeed * _contGroup.Get(ControlMap::ClimberAdjust) : 0;

	if (_contGroup.Get(ControlMap::ClimberToggle, wml::controllers::Controller::ONFALL)) {
		_climber.setClimber(RequestState::kToggle, 0);
	}

	_climber.setClimber(RequestState::kMove, _power);
}