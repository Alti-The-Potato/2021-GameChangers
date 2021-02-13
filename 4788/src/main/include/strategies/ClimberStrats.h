#include "Climber.h"
#include "strategy/Strategy.h"

using Controllers = wml::controllers::SmartControllerGroup;

class ClimberManualStrategy : public wml::Strategy {
	public:
		ClimberManualStrategy(std::string name, Climber &climber, Controllers &contGroup);

		void OnUpdate(double dt) override;

		Requires(dt);
		SetTimeout(5);	
	private:
		Climber &_climber;
		Controllers &_contGroup;
};

class ClimberExtendingStrategy : public wml::Strategy {
	public:
		ClimberExtendingStrategy(std::string name, Climber &climber);

		void OnUpdate(double dt) override;
	private:
	 Climber &_climber;
	 Controllers &_contGroup;
	 int _currentTicks;
	 int _previousTicks;
}