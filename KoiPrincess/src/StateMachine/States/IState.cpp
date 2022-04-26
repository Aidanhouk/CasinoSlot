#include "StateMachine/States/IState.h"

IState::IState(StateMachine * stateMachine, Field * field)
	: m_stateMachine{ stateMachine }, m_field{ field }
{
	m_background.loadFromFile("slot_background");
	m_foreground.loadFromFile("slot_foreground");
}
