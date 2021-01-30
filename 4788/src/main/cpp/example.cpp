#include "example.h" // Include the header with our class and links to RobotMap.h and ControlMap

// This calls the constructor and gets the motors set up in RobotMap.h and passes it into
// the private variable of our object. Also note: this can be one line, but is split up for the sake
// of fitting it in the screenshot
Example::Example(wml::TalonSrx &exampleMotor, wml::actuators::DoubleSolenoid &exampleSolanoid) :
_exampleMotor(exampleMotor), _exampleSolanoid(exampleSolanoid) {}

