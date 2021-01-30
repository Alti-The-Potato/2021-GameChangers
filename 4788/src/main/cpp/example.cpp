#include "example.h" // Include the header with our class and links to RobotMap.h and ControlMap

// This calls the constructor and gets the motors set up in RobotMap.h and passes it into
// the private variable of our object. Also note: this can be one line, but is split up for the sake
// of fitting it in the screenshot
Example::Example(wml::TalonSrx &exampleMotor, wml::actuators::DoubleSolenoid &exampleSolanoid) :
_exampleMotor(exampleMotor), _exampleSolanoid(exampleSolanoid) {}

// This is the function that we'll call from our stratergies. Using this, we can give the updateExample
// function the STATE and the power we want to set our subsystem to.
void Example::setExample (ExampleState st, double power) {
	_exampleState = st; // Set our private state to the state passed in
	_power = power;			// Set our private power to the power passed in
}

// This is the function that determines what happens depending on the state the subsystem is in
void Example::updateExample (double dt) {
	double speed = 0;

	switch (_exampleState) {
		case ExampleState::RAISED:	// If the eample subsystems state is RAIsED
			speed = 0; // Set the speed to zero (so the motor doesn't activate)

			// Keep the pistons retracted (so the subsystem on the robot is RAISED)
			_exampleSolanoid.SetTarget(wml::actuators::BinaryActuatorState::kReverse);
			break;

		case ExampleState::LOWERED:
			speed = _power; // Set the speed to the power passed in by our strategy (we'll create this later)

			// Activate the actuators and push the example subsysten down so its LOWERED (wow names are cool)
			_exampleSolanoid.SetTarget(wml::actuators::BinaryActuatorState::kForward);
			break;
	}

	_exampleMotor.Set(speed); // Actually get the motor to spin at speed
}

// This is the function that is called by the stratergies system in the wml library, we're just
// telling it to call our update up there 
void Example::update (double dt) {
	updateExample(dt);
}