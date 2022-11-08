#pragma once
#include "Application.h"
#include "Module.h"
#include "Prop.h"
#include "ModulePhysics.h"
#include "ModuleTextures.h"

class ModulePhysics;
class SDL_Texture;

enum FLIPPERSIDE {
	LEFT,
	RIGHT
};

class Flipper : Prop {
public:
	Flipper(PropType type, FLIPPERSIDE side) : Prop(type) {
		texture = App->textures->Load("pinball/Textures/temp_flipper.png");

		switch (side)
		{
		case LEFT:
			x = 10;
			y = 100;
			xPin = 15;
			yPin = 105;
			break;
		case RIGHT:
			x = 100;
			y = 100;
			xPin = 105;
			yPin = 105;
			break;
		default:
			break;
		}


		pBody = App->physics->CreateRectangle(x, y, 20, 10);
		pin = App->physics->CreateRectangle(xPin, yPin, 1, 1);
	}



private:
	int x;
	int y;

	int xPin;
	int yPin;

	PhysBody* pBody;
	PhysBody* pin;
	b2RevoluteJoint* joint;

	SDL_Texture* texture;
};