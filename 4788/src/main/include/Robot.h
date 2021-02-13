#pragma once
#include "RobotMap.h"

// Subsystems
#include "strategies/exampleStrategy.h"

class Robot : public frc::TimedRobot, protected wml::StrategyController, protected wml::NTProvider {
 public:
	void RobotInit() override;
	void RobotPeriodic() override;

	void DisabledInit() override;
	void DisabledPeriodic() override;

	void AutonomousInit() override;
	void AutonomousPeriodic() override;

	void TeleopInit() override;
	void TeleopPeriodic() override;

	void TestInit() override;
	void TestPeriodic() override;

 private:
	// Istances
	RobotMap robotMap;
	wml::Drivetrain *drivetrain; // WML drivetrain (Not local)
	Example *example; // Create an instance of our example class
};
