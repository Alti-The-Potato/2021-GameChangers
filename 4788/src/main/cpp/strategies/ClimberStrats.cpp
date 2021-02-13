#include "strategies/ClimberStrats.h"

ClimberManualStrategy::ClimberManualStrategy(std::string name, Climber &climber, Controllers &contGroup) : Strategy(name), _climber(climber), _contGroup(contGroup){}

void ClimberManualStrategy::OnUpdate(double dt) {
	// Set the current ticks to the current encode ticks
	_currentTicks = _climber.climberEncoderValue();

	_previousTicks = _climber.climberEncoderValue();
}