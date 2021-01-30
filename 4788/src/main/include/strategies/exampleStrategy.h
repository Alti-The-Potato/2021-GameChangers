#include "example.h"	// Include the example class from example.h and in turn RobotMap and ControlMap
#include "strategy/Strategy.h" // Include the necissary functions from the library

// This statement means that instead of typing out wml::controllers::SmartControllerGroup every time
// we only have to type Controllers
using Controllers = wml::controllers::SmartControllerGroup;

// Create a new class to be used by the strategy.cpp file. It takes in our example subsystem and a
// controller group. It also inherrits from wml::Strategy
class ExampleManualStratergy : public wml::Strategy {

	public: // Remember what this means?

	// Here is this classes constructor (just like the one from example.h)
	 ExampleManualStratergy(std::string name, Example &example, Controllers  &contGroup);

	// Here is the function that is called by the library. The override makes sure this function doesn't
	// interfere with the one from the inherrited class.
	 void OnUpdate(double dt) override

	private:
	// Private (or class specific) variables for the class
	 Example &_example;
	 Controllers &_contGroup;
};