#include "PropsManager.h"
#include "Prop.h"
#include "Flipper.h"
#include "Ball.h"
#include "Spring.h"
#include "Bumper.h"
#include "Button.h"
#include "Trough.h"
#include "Sensor.h"
#include "Slingshot.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModulePhysics.h"


PropsManager::PropsManager(Application* app, bool start_enabled) : Module(app, start_enabled) {

}

// Destructor
PropsManager::~PropsManager()
{}

bool PropsManager::Start() {

	bool ret = true;

	//Iterates over the entities and calls Start
	p2List_item<Prop*>* item;
	Prop* prop = NULL;

	for (item = props.getFirst(); item != NULL && ret == true; item = item->next)
	{
		prop = item->data;

		if (prop->active == false) continue;
		ret = item->data->Start();
	}

	return ret;
}

// Called before quitting
bool PropsManager::CleanUp()
{
	bool ret = true;
	p2List_item<Prop*>* item;
	item = props.getLast();

	while (item != NULL && ret == true)
	{
		ret = item->data->CleanUp();
		item = item->prev;
	}

	props.clear();

	return ret;
}

Prop* PropsManager::CreateProp(PropType type)
{
	Prop* prop = nullptr;

	switch (type)
	{
	case PropType::BALL:
		prop = (Prop*)new Ball(type);
		break;
	case PropType::BUMPERTOP:
		prop = (Prop*)new Bumper(type, BumperPlace::BBOTTOM);
		break;
	case PropType::BUMPERRIGHT:
		prop = (Prop*)new Bumper(type, BumperPlace::BRIGHT);
		break;
	case PropType::BUMPERLEFT:
		prop = (Prop*)new Bumper(type, BumperPlace::BLEFT);
		break;
	case PropType::FLIPPER_LEFT:
		prop = (Prop*)new Flipper(type, FlipperSide::LEFT);
		break;
	case PropType::FLIPPER_RIGHT:
		prop = (Prop*)new Flipper(type, FlipperSide::RIGHT);
		break;
	case PropType::SPRING:
		prop = (Prop*)new Spring(type);
		break;
	case PropType::MINUN_BUTTON:
		prop = (Prop*)new Button(type, ButtonType::MINUN);
		break;
	case PropType::PLUSLE_BUTTON:
		prop = (Prop*)new Button(type, ButtonType::PLUSLE);
		break;
	case PropType::SEEDOT_BUTTON:
		prop = (Prop*)new Button(type, ButtonType::SEEDOT);
		break;
	case PropType::ZIGZAGOON_BUTTON:
		prop = (Prop*)new Button(type, ButtonType::ZIGZAGOON);
		break;
	case PropType::PELIPPER_BUTTON:
		prop = (Prop*)new Button(type, ButtonType::PELIPPER);
		break;
	case PropType::TROUGH:
		prop = (Prop*)new Trough(type);
		break;
	case PropType::SENSOR_EVO:
		prop = (Prop*)new Sensor(type, SensorSide::EVO);
		break;
	case PropType::SENSOR_GET:
		prop = (Prop*)new Sensor(type, SensorSide::GET);
		break;
	case PropType::SENSOR_HOLE:
		prop = (Prop*)new Sensor(type, SensorSide::HOLE);
		break;
	case PropType::SENSOR_UPGRADE:
		prop = (Prop*)new Sensor(type, SensorSide::UPGRADE);
		break;
	case PropType::SENSOR_COINS:
		prop = (Prop*)new Sensor(type, SensorSide::COINS);
		break;
	case PropType::SENSOR_MOUNTAIN:
		prop = (Prop*)new Sensor(type, SensorSide::MOUNTAIN);
		break;
	case PropType::SENSOR_SPRING:
		prop = (Prop*)new Sensor(type, SensorSide::SPRING);
		break;
	case PropType::SLINGSHOT_RIGHT:
		prop = (Prop*)new Slingshot(type, SlingPlace::SRIGHT);
		break;
	case PropType::SLINGSHOT_LEFT:
		prop = (Prop*)new Slingshot(type, SlingPlace::SLEFT);
		break;
	case PropType::UNKNOWN:
		break;
	default:
		break;
	}

	// Created entities are added to the list
	AddProp(prop);

	return prop;
}

void PropsManager::DestroyProp(Prop* prop)
{
	p2List_item<Prop*>* item;

	for (item = props.getFirst(); item != NULL; item = item->next)
	{
		if (item->data == prop) props.del(item);
	}
}

void PropsManager::AddProp(Prop* prop)
{
	if (prop != nullptr) props.add(prop);
}

void PropsManager::OnCollision(PhysBody* pBody1, PhysBody* pBody2)
{
	if (pBody1->prop != nullptr) {
		pBody1->prop->OnCollision(pBody2);
	}
}

void PropsManager::EndCollision(PhysBody* pBody1, PhysBody* pBody2)
{
	if (pBody1->prop != nullptr) {
		pBody1->prop->EndCollision(pBody2);
	}
}

update_status PropsManager::Update()
{
	bool ret = true;
	p2List_item<Prop*>* item;
	Prop* prop = NULL;

	for (item = props.getFirst(); item != NULL && ret == true; item = item->next)
	{
		prop = item->data;

		if (prop->active == false) continue;
		ret = item->data->Update();
	}

	return UPDATE_CONTINUE;
}

update_status PropsManager::PostUpdate()
{
	bool ret = true;
	p2List_item<Prop*>* item;
	Prop* prop = NULL;

	for (item = props.getFirst(); item != NULL && ret == true; item = item->next)
	{
		prop = item->data;

		if (prop->active == false) continue;
		ret = item->data->PostUpdate();
	}

	return UPDATE_CONTINUE;
}

void PropsManager::BlitPropsByLayer(int layer)
{
	p2List_item<Prop*>* item;
	Prop* prop = NULL;

	for (item = props.getFirst(); item != NULL; item = item->next)
	{
		prop = item->data;

		if (prop->active == false) continue;
		item->data->BlitByLayer(layer);
	}
}
