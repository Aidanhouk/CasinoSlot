#pragma once

#include "StateMachine/States/WaitState.h"
#include "StateMachine/States/RunState.h"
#include "StateMachine/States/WinState.h"

class Field;

class StateMachine
{
public:
	StateMachine(Field * field);

	void update(float dt);

	void clickStartButton();
	void clickStopButton();
	
	void draw(sf::RenderWindow& window) const;

	void changeStateWait();
	void changeStateRun();
	void changeStateWin();
private:
	IState *m_currentState;

	WaitState m_waitState;
	RunState m_runState;
	WinState m_winState;
};