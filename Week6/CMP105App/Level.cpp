#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballTexture.loadFromFile("gfx/MarioSheetT.png");
	ball.setSize(sf::Vector2f(15, 21));
	ball.setPosition(100, 100);
	ball.setTexture(&ballTexture);
	ball.setWindow(window);
	ball.setInput(input);

	goombaTexture.loadFromFile("gfx/Goomba");
	goomba.setSize(sf::Vector2f(16, 16));
	goomba.setPosition(0, 0);
	goomba.setTexture(&ballTexture);
	goomba.setWindow(window);
	
	
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	ball.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ball.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball);
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