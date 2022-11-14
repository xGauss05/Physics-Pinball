#pragma once
#include "Application.h"
#include "Module.h"
#include "Prop.h"
#include "ModulePhysics.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"

class ModulePhysics;
class SDL_Texture;

enum SensorSide {
	EVO,
	GET,
	HOLE,
	UPGRADE
};

class Sensor : public Prop {
public:
	Sensor(PropType type, SensorSide sSide) : Prop(type) {

		this->side = sSide;
		switch (sSide)
		{
		case EVO:
			pBody1 = App->physics->CreateRectangleSensor(29, 247, 5, 5);
			pBody2 = App->physics->CreateRectangleSensor(43, 115, 5, 5);
			pBody1->prop = pBody2->prop = this;
			pBody1->listener = pBody2->listener = (Module*)App->pManager;
			pBody1->body->SetType(b2BodyType::b2_staticBody);
			pBody2->body->SetType(b2BodyType::b2_staticBody);
			break;
		case GET:
			pBody1 = App->physics->CreateRectangleSensor(210, 247, 5, 5);
			pBody2 = App->physics->CreateRectangleSensor(202, 131, 5, 5);
			pBody1->prop = pBody2->prop = this;
			pBody1->listener = pBody2->listener = (Module*)App->pManager;
			pBody1->body->SetType(b2BodyType::b2_staticBody);
			pBody2->body->SetType(b2BodyType::b2_staticBody);
			break;
		case HOLE:
			pBody1 = App->physics->CreateRectangleSensor(32, 359, 5, 5);
			pBody2 = App->physics->CreateRectangleSensor(56, 359, 5, 5);
			pBody3 = App->physics->CreateRectangleSensor(182, 359, 5, 5);
			pBody4 = App->physics->CreateRectangleSensor(206, 359, 5, 5);
			pBody1->prop = pBody2->prop = pBody3->prop = pBody4->prop = this;
			pBody1->listener = pBody2->listener = pBody3->listener = pBody4->listener = (Module*)App->pManager;
			pBody1->body->SetType(b2BodyType::b2_staticBody);
			pBody2->body->SetType(b2BodyType::b2_staticBody);
			pBody3->body->SetType(b2BodyType::b2_staticBody);
			pBody4->body->SetType(b2BodyType::b2_staticBody);
			break;
		case UPGRADE:
			pBody1 = App->physics->CreateRectangleSensor(87, 118, 5, 5);
			pBody2 = App->physics->CreateRectangleSensor(108, 118, 5, 5);
			pBody3 = App->physics->CreateRectangleSensor(129, 118, 5, 5);
			pBody1->prop = pBody2->prop = pBody3->prop = this;
			pBody1->listener = pBody2->listener = pBody3->listener = (Module*)App->pManager;
			pBody1->body->SetType(b2BodyType::b2_staticBody);
			pBody2->body->SetType(b2BodyType::b2_staticBody);
			pBody3->body->SetType(b2BodyType::b2_staticBody);
			break;
		default:
			break;
		}
	}

	bool Update() {

		return true;
	}



	void PlaySFX() {

	}

	void OnCollision(PhysBody* bodyB) {

	}

private:

	SensorSide side;

	PhysBody* pBody1;
	PhysBody* pBody2;
	PhysBody* pBody3;
	PhysBody* pBody4;


};