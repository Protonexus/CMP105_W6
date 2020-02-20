#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Ball : public GameObject
{

	
public:
	Ball();
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; };
	void setInput(Input* in) { input = in; };
	void handleInput(float dt);
	void update(float dt);
protected:
	float scale;
	Animation stand;
	Animation* currentAnimation;
	sf::Vector2f stepVelocity;
	sf::Vector2f gravity;
	sf::Vector2f pos;
	sf::RenderWindow* window;
	Input* input;

};
