#pragma once

#include <SFML/System/Clock.hpp>

class SpinController
{
public:
	float updateOffset();

	void resetSpinTimer() { m_spinTimer.restart(); }
	bool checkForSpinEnd();

	void setSpinTime(float spinTime) { m_spinTime = spinTime; }
private:
	float easeOutSine(float x);
	float shakeInTheEnd(float x);

	sf::Clock m_spinTimer;
	float m_spinTime;
};