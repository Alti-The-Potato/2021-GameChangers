#include "Robot.h"

using namespace frc;
using namespace wml;

using hand = frc::XboxController::JoystickHand;

double currentTime;
double lastTimeStamp;
double dt; //stands for delta time

//add other variables here
double sparkSpeed;

// db means drive base
double dbLeftSpeed = 0;
double dbRightSpeed = 0;
//double talonSpeed;
//double victorSpeed;
double constexpr deadzone = 0.1;

// Robot Logic
void Robot::RobotInit() {
	//init controllers
	xbox = new frc::XboxController(0);

	_testMotor = new wml::TalonSrx(7);

	_testMotor->SetInverted(false);

// 	//Motor examples
// //	_sparkMotor = new frc::Spark(0);
// 	_talonMotorL = new wml::TalonSrx(1);
// 	_talonMotorR = new wml::TalonSrx(2);
// 	_victorSpxMotorL = new wml::VictorSpx(8);
// 	_victorSpxMotorR = new wml::VictorSpx(9);

// //	_sparkMotor->SetInverted(true);
// 	_talonMotorL->SetInverted(false);
// 	_talonMotorR->SetInverted(false);
// 	_victorSpxMotorL->SetInverted(false);
// 	_victorSpxMotorR->SetInverted(false);
}

void Robot::RobotPeriodic() {}

// Dissabled Robot Logic
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

// Auto Robot Logic
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

// Manual Robot Logic
void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
	currentTime = Timer::GetFPGATimestamp();
	dt = currentTime - lastTimeStamp;

	bool motorOnForward = false;
	bool motorOnBackward = false;

	// If the button is pressed and the motor isn't already on make motor go brrrr
	if (xbox->GetYButtonPressed() && motorOnForward == false) {
		motorOnForward = true;
	} else {
	// If the button is pressed and the motor is already on turn the motor off
		motorOnForward = false;
	}

	// Same but for backwards control
	if (xbox->GetAButtonPressed() && motorOnBackward == false) {
		motorOnBackward = true;
	} else {
		motorOnBackward = false;
	}

	if (motorOnForward) {
		if (motorOnBackward) {
			// Makes it so pressing the button for the opposite direction cancels out
			_testMotor->Set(0);
			motorOnForward = false;
			motorOnBackward = false;
		} else {
			_testMotor->Set(1);
		}
	} else if (motorOnBackward) {
		if (motorOnForward) {
			// Makes it so pressing the button for the opposite direction cancels out
			_testMotor->Set(0);
			motorOnForward = false;
			motorOnBackward = false;
		} else {
			_testMotor->Set(-1);
		}
	}
}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}