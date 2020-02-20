#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
#include "Framework/Animation.h"


class Goomba : public GameObject
{
public:
	Goomba();
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; };
	void update(float dt);

protected:
	sf::RenderWindow* window;
	float dt;
	
};