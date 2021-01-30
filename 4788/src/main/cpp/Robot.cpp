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

double maxSpeed = 0.8;
double waitTime = 1; // In seconds

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
void Robot::AutonomousInit() {
	_timer.Reset();
	_timer.Start();
	goFwrd = true;
}
void Robot::AutonomousPeriodic() {

	if (_timer.Get() >= 1) {
		if (goFwrd == true) {
			goFwrd = false;
			_timer.Reset();
			_timer.Start();
		} else {
			goFwrd = true;
			_timer.Reset();
			_timer.Start();
		}
	}

	if (goFwrd == true) {
		_testMotor->Set(maxSpeed);
	} else {
		_testMotor->Set(-maxSpeed);
	}
}

// Manual Robot Logic
void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
	currentTime = Timer::GetFPGATimestamp();
	dt = currentTime - lastTimeStamp;


	// If the button is pressed and the motor isn't already on make motor go brrrr
	if (xbox->GetYButtonPressed() && _motorOnForward == false) {
		_motorOnForward = true;
	} else {
	// If the button is pressed and the motor is already on turn the motor off
		_motorOnForward = false;
	}

	// Same but for backwards control
	if (xbox->GetAButtonPressed() && _motorOnBackward == false) {
		_motorOnBackward = true;
	} else {
		_motorOnBackward = false;
	}

	if (_motorOnForward) {
		if (_motorOnBackward) {
			// Makes it so pressing the button for the opposite direction cancels out
			_testMotor->Set(0);
			_motorOnForward = false;
			_motorOnBackward = false;
		} else {
			_testMotor->Set(maxSpeed);
		}
	} else if (_motorOnBackward) {
		if (_motorOnForward) {
			// Makes it so pressing the button for the opposite direction cancels out
			_testMotor->Set(0);
			_motorOnForward = false;
			_motorOnBackward = false;
		} else {
			_testMotor->Set(-maxSpeed);
		}
	}
}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}