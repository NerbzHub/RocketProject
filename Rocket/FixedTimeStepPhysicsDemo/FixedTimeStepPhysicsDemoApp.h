#pragma once
#include "glm\glm.hpp"
#include "glm\vec2.hpp"
#include "Application.h"
#include "Renderer2D.h"


class PhysicsScene;

#define M_PI 3.1415926

class FixedTimeStepPhysicsDemoApp : public aie::Application {
public:

	FixedTimeStepPhysicsDemoApp();
	virtual ~FixedTimeStepPhysicsDemoApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	PhysicsScene* m_physicsScene;
	virtual void setupContinuousDemo(glm::vec2 startPos, float inclination, float speed, float gravity);

	void Exhaust(glm::vec2 startPos, float inclination, float speed, float gravity);

	float radius = 10.0f;
	float speed = 30;
	glm::vec2 startPos = glm::vec2(0, 0);
	glm::vec2 startPosfuel = glm::vec2(0, 0);
	float inclination = (float)M_PI / 1.0f;


protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};