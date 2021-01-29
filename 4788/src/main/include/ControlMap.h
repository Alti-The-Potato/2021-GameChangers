#pragma once

#include <vector>
#include "controllers/Controllers.h"

/**
 * CAN Port System
 * 0-9 (Control System, pneumatics, PDP)
 * 10-19 (SparkMax/Brushless Motors)
 * 20- (Brushed)
 */

struct ControlMap {
	static void InitsmartControllerGroup(wml::controllers::SmartControllerGroup &contGroup);


	// ------------------ Values ------------------
	// Everything under here is our values, make sure you put your values under this

	// Controllers
	static const int Xbox1Port, Xbox2Port;

	// USB port numbers
	static const int Driver = 1;
	static const int CoDriver = 2;

	// Deadzones
	static const double XboxDeadzone;
	static const double TriggerDeadzone;

	// PCM1
	static const int PCModule;

	// Drive System
	static const int FLport, FRport, BLport, BRport;
	static const double MaxDrivetrainSpeed;
	static const double TrackWidth, TrackDepth, WheelRadius, Mass;

	// Example
	static const double ExampleMotorPort, ExampleSolanoidPort1, ExampleSolanoidPort2;
	static const int ExampleEncoderTicks;
	// This is creating the static constant variables, which we'll assign in ContorlMap.cpp


	// ------------------ Controls ------------------
	//Guess where all the controls go under

	// Drivetrain
	static const wml::controllers::tAxis DrivetrainLeft, DrivetrainRight;

	//Example
	static const wml::controllers::tAxis ExampleMotorInput;
	// This is creating a controller input that uses an axis (triggers, joystick, etc.)

	static const wml::controllers::tButton ExampleSolanoidUp, ExampleSolanoidDown;
	// This is creating a controller input that uses buttons (A, B, etc.)
};