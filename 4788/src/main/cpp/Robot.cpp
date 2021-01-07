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

	//Motor examples
//	_sparkMotor = new frc::Spark(0);
	_talonMotorL = new wml::TalonSrx(1);
	_talonMotorR = new wml::TalonSrx(2);
	_victorSpxMotorL = new wml::VictorSpx(8);
	_victorSpxMotorR = new wml::VictorSpx(9);

//	_sparkMotor->SetInverted(true);
	_talonMotorL->SetInverted(false);
	_talonMotorR->SetInverted(false);
	_victorSpxMotorL->SetInverted(false);
	_victorSpxMotorR->SetInverted(false);
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

	//motor examples
//	sparkSpeed = xbox->GetY(hand::kLeftHand);
//	_sparkMotor->Set(sparkSpeed);

	// Make left side motors move based off left hand joystick
	dbLeftSpeed = xbox->GetY(hand::kLeftHand);
	if (abs(dbLeftSpeed) >= deadzone) {
		_talonMotorL->Set(dbLeftSpeed);
		_victorSpxMotorL->Set(dbLeftSpeed);
	} else {
		_talonMotorL->Set(0);
		_victorSpxMotorL->Set(0);
	}

	// Make right side motors move based off left hand joystick 
	dbRightSpeed = xbox->GetY(hand::kRightHand);
	if (abs(dbRightSpeed) >= deadzone) {
		_talonMotorR->Set(dbRightSpeed);
		_victorSpxMotorR->Set(dbRightSpeed);
	} else {
		_talonMotorR->Set(0);
		_victorSpxMotorR->Set(0);
	}

	// ^ the equivilant using a conditional statement
	//talonSpeed = xbox->GetTriggerAxis(hand::kRightHand) > deadzone ? xbox->GetTriggerAxis(hand::kRightHand) : 0; _talonMotor->Set(talonSpeed);

//	if(xbox->GetXButton()) {
//		_solenoid.SetTarget(wml::actuators::BinaryActuatorState::kForward);
//	} else {
//		_solenoid.SetTarget(wml::actuators::BinaryActuatorState::kReverse);
//	}

	_compressor.Update(dt);
	_solenoid.Update(dt);

	if (_solenoid.IsDone()) _solenoid.Stop();
	lastTimeStamp = currentTime;
}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}