#include "Ball.h"

Ball::Ball()
{
	scale = 200.0f;
	gravity = sf::Vector2f(0.f, 9.8f) * scale;

	stand.addFrame(sf::IntRect(0, 0, 15, 21));

	currentAnimation = &stand;
	setTextureRect(currentAnimation->getCurrentFrame());

	stepVelocity = sf::Vector2f(0.f,0.f);
}

void Ball::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		stepVelocity.y = -4.f * scale;
	}

	if (input->isMouseLDown())
	{
		setPosition(input ->getMouseX(),input->getMouseY());
	}
}

void Ball::update(float dt)
{
	//s = ut + 0.5*a*t^2
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;
	stepVelocity += gravity * dt;
	setPosition(getPosition() + pos);

	if (getPosition().y + getSize().y >= window->getSize().y)
	{
		setPosition(getPosition().x, window->getSize().y - getSize().y);
		stepVelocity = sf::Vector2f(0.f, 0.f);
	}
	
}
