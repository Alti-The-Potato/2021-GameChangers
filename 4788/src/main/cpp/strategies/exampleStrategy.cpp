#include "strategies/exampleStrategy.h"

// Here is our constructor for our example manual strategy class. (remember the formating is just so it
// fits on screen, you can write this out as one line)
// Just as a reminder, this assignes the reference of our public variables and passes it into the class'
// specific prvate variables
ExampleManualStrategy::ExampleManualStrategy (std::string name, Example &example, Controllers &contGroup) :
																							Strategy(name), _example(example), _contGroup(contGroup) {}


// BEHOLD, this is where your programming logic will go. This is where you will make the robot do stuff
// based off inputs and other fancy stuff. This is what you have been coding for. Pog amirite?
void ExampleManualStrategy::OnUpdate (double dt) {

	// This is an interesting statement as it uses the ternary operator. What is that, well its like a compacted if statement and its usefull in cases like this
	// This is the equivalant of typing out this:
	// if (fabs(_contGroup.Get(ControlMap::ExampleMotorInput)) > ControlMap::TriggerDeadzone) {
	// 	power = _contGroup.Get(ControlMap::ExampleMotorInput)
	// } else {
	// 	power = 0
	// }
	// Think of it like a question mark in a sentence i.e. is condition true?
	//													 v
	// The syntax is variable = <condition> ? <value if true> : <value if false>

	// As for what it does. Because the controlers arn't perfect, the chances are they can rest at 0.1 instead of 0 or you might lightly accidentally touch it.
	// if this happens, you don't want the robot triggereing instantly. So we set a range and say if the trigger/joystick is within that range then we don't read
	// the input. Otherwise, set the robot to the input
	double power = fabs(_contGroup.Get(ControlMap::ExampleMotorInput)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::ExampleMotorInput) : 0;

	// If the button to put the solanoid down was pressed This means that it actvates when the button is pushed down (ONFALL) the alternate is when the button
	// comes up (ONRISE)
	if (_contGroup.Get(ControlMap::ExampleSolanoidDown, wml::controllers::Controller::ONFALL)) {
		// We set the state and power using that function we set up in example.h and example.cpp
		_example.setExample(ExampleState::LOWERED, power);
	} else {
		// Same here
		_example.setExample(ExampleState::RAISED);
	}
}