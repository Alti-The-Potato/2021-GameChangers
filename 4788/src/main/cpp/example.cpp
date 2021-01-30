#include "example.h" // Include the header with our class and links to RobotMap.h and ControlMap

// This calls the constructor and gets the motors set up in RobotMap.h and passes it into
// the private variable of our object. Also note: this can be one line, but is split up for the sake
// of fitting it in the screenshot
Example::Example(wml::TalonSrx &exampleMotor, wml::actuators::DoubleSolenoid &exampleSolanoid) :
_exampleMotor(exampleMotor), _exampleSolanoid(exampleSolanoid) {}

// This is the function that we'll call from our stratergies. Using this, we can give the updateExample
// function the STATE and the 
void Example::updateExample (ExampleState st, double power) {
	_exampleState = st;
	_power = power;
}

void Example::updateExample (double dt) {

}