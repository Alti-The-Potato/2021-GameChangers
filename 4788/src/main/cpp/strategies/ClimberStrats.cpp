#include "strategies/ClimberStrats.h"

ClimberManualStrategy::ClimberManualStrategy(std::string name, Climber &climber, Controllers &contGroup) :
																						Strategy(name), _climber(climber), _contGroup(contGroup) {}

ClimberExtendingStrategy::ClimberExtendingStrategy(std::string name, Climber &climber) :
																									Strategy(name), _climber(climber) {}

void ClimberManualStrategy::OnUpdate(double dt) {

}

void ClimberExtendingStrategy::OnUpdate(double dt) {
	_currentTicks = 0;

	_previousTicks = 0;
}