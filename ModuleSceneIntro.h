#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"

class PhysBody;

struct GroundAsset {
	int x;
	int y;
	SDL_Rect rect;
	bool isActive;
};

class ModuleSceneIntro : public Module
{
public:

	// Constructors & Destructors
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	// Main module steps
	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);

public:

	// Lists of physics objects
	p2List<PhysBody*> circles;
	p2List<PhysBody*> boxes;
	p2List<PhysBody*> ricks;

	// Lower ground sensor (will kill all objects passig through it)
	PhysBody* lower_ground_sensor;
	bool sensed;

	// Map Textures
	SDL_Texture* mapLayer0;
	SDL_Texture* mapLayer1;
	SDL_Texture* mapLayer2;
	SDL_Texture* mapLayer3;
/*
	SDL_Texture* assetsTexture;

	// Assets for the Map
	// Arrows
	GroundAsset greenArrow1;
	GroundAsset greenArrow2;
	GroundAsset greenArrow3;
	GroundAsset blueArrow1;
	GroundAsset blueArrow2;
	GroundAsset blueArrow3;
	GroundAsset redArrow1;
	GroundAsset redArrow2;
	GroundAsset redArrow3;
	GroundAsset yellowArrow1;
	GroundAsset yellowArrow2;
	GroundAsset yellowArrow3;
	GroundAsset yellowArrow4;

	// Bumpers
	GroundAsset bumperLeft;
	GroundAsset bumperRight;

	// TODO Water Animation

	// TODO Screen Animation

	// TODO Hole Animation

	// TODO P Animation

	// H-O-L-E Letters
	GroundAsset holeLight1;
	GroundAsset holeLight2;
	GroundAsset holeLight3;
	GroundAsset holeLight4;

	// Saver
	GroundAsset saverLatios;

	// Dots
	GroundAsset dotsLight1;
	GroundAsset dotsLight2;
	GroundAsset dotsLight3;

	// Lives 
	GroundAsset livesLight1;
	GroundAsset livesLight2;
	GroundAsset livesLight3;

	p2List<GroundAsset*> groundAssets;

	*/


	// Textures
	SDL_Texture* circle;
	SDL_Texture* box;
	SDL_Texture* rick;

	// FX
	uint bonus_fx;
	int font;

	// Raycast
	p2Point<int> ray;
	bool ray_on;
};
