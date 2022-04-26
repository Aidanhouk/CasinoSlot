#include "Application.h"

#include "Config/Config.h"

Application::Application()
	: m_field(&m_stateMachine),
	m_stateMachine(&m_field)
{
	sf::VideoMode winMode(g_config.resX, g_config.resY);
	m_window.create(winMode, "Koi Princess", sf::Style::Close);

	// sets buttons positions and sizes
	m_startButton.setData({ 640, 657 }, { 77, 90 });
	m_stopButton.setData({ 753, 657 }, { 130, 51 });
}

void Application::runLoop()
{
	sf::Clock dtTimer;

	while (m_window.isOpen())
	{
		float dt = dtTimer.restart().asSeconds();

		processInput();

		m_stateMachine.update(dt);

		m_stateMachine.draw(m_window);

		m_window.display();
	}
}

void Application::processInput()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();
		else if (event.type == sf::Event::MouseButtonPressed)
		{
			if (m_startButton.isInsideButton(mousePos))
				m_stateMachine.clickStartButton();
			else if (m_stopButton.isInsideButton(mousePos))
				m_stateMachine.clickStopButton();
		}
	}
}
