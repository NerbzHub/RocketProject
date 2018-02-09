#pragma once
#include "Sphere.h"
#include "RigidBody.h"

class Rocket : public RigidBody
{
public:
	Rocket(glm::vec2 position, glm::vec2 velocity,
		float mass, float radius, glm::vec4 colour);

	Rocket(glm::vec2 position, float inclination, float speed, float mass, float radius, glm::vec4 colour);
	~Rocket();

	virtual void makeGizmo();
	virtual bool checkCollision(PhysicsObject* pOther);
	virtual void Rocket::Blast();

	void Exhaust(glm::vec2 startPos, float inclination, float speed, float gravity);


	float getRadius() { return m_radius; }
	glm::vec4 getColour() { return m_colour; }

protected:
	float m_radius;
	glm::vec4 m_colour;
};

