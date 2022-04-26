#include "SpinController.h"

#include "Constants.h"
#include "Field/Field.h"

#define M_PI 3.14159265358979323846
#include <math.h>

float SpinController::updateOffset()
{
	float passedTime = m_spinTimer.getElapsedTime().asSeconds();
	float phase = passedTime / m_spinTime;
	float easeTransition = easeOutSine(phase) + shakeInTheEnd(phase);
	float offset = easeTransition * (N_SYMBOLS_PER_SPIN - N_ROWS_ON_SCREEN) * SYMBOL_HEIGHT_PIXELS;

	return offset;
}

bool SpinController::checkForSpinEnd()
{
	float passedTime = m_spinTimer.getElapsedTime().asSeconds();
	return passedTime > m_spinTime ? true : false;
}

float SpinController::easeOutSine(float x)
{
	return sin((x * M_PI) / 2.0f);
}

float SpinController::shakeInTheEnd(float x)
{
	const float jumpTime = 0.2f;
	const float amplitude = 0.02f;
	float p = x < 1.0f - jumpTime ? 0.0f : (x - (1.0f - jumpTime)) / jumpTime;
	p = sin((p * 2.0f - 0.5f) * M_PI) * 0.5f + 0.5f;
	return p * amplitude;
}
