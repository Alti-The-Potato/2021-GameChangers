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

	if (xbox->GetYButtonPressed()) {
		_testMotor->Set(1);
	} else {
		_testMotor->Set(0);
	}

	if (xbox->GetAButtonPressed()) {
		_testMotor->Set(-1);
	} else {
		_testMotor->Set(0);
	}

}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}