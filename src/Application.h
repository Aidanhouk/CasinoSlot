#include "Field/Field.h"
#include "StateMachine/StateMachine.h"
#include "Renderer/Renderer.h"
#include "Button/Button.h"

#include <SFML/Graphics.hpp>

class Application
{
public:
	Application();

	void runLoop();
private:
	void processInput();

	sf::RenderWindow m_window;

	Field m_field;
	StateMachine m_stateMachine;
	Renderer m_renderer;

	Button m_startButton;
	Button m_stopButton;
};