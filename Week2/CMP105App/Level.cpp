#include "Level.h"
//#include <string>

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	//when w is pressed print cheese
	if (input->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "Cheese\n";
	}

	//when j k and l are pressed print borger
	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	{
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
		std::cout << "Borger\n";
	}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

	//render text
	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Error loading font\n";
	}

	//(input->getMouseX()) "Mouse Y: " (input->getMouseY()

	//Text for X
	XText.setFont(font);
	XText.setString("Mouse X: ");
	XText.setCharacterSize(15);
	XText.setPosition(10, 10);
	XText.setFillColor(sf::Color::Red);

	//Text for Y
	YText.setFont(font);
	YText.setString("Mouse Y: ");
	YText.setCharacterSize(15);
	YText.setPosition(10, 10);
	YText.setFillColor(sf::Color::Red);

	//X Position
	X.setSize(input->getMouseX());

	//std::cout << "Mouse X: " << input->getMouseX()  << "Mouse Y: " << input->getMouseY();

}

// Update game objects
void Level::update()
{

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(XText);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}