#include "Rocket.h"


Rocket::Rocket(glm::vec2 position, glm::vec2 velocity,
	float mass, float radius, glm::vec4 colour) : RigidBody(SPHERE, position, velocity, 0, mass)
{
	m_radius = radius;
	m_colour = colour;
}

Rocket::Rocket(glm::vec2 position, float inclination, float speed, float mass, float radius, glm::vec4 colour)
	: Rocket(position, glm::vec2(sin(inclination), cos(inclination)) * speed, mass, radius, colour)
{
	m_radius = radius;
	m_colour = colour;
}
Rocket::~Rocket()
{
}

void Rocket::makeGizmo()
{
	aie::Gizmos::add2DCircle(m_position, m_radius, 20, m_colour);
}

bool Rocket::checkCollision(PhysicsObject * pOther)
{
	Rocket* other = dynamic_cast<Rocket*>(pOther);
	if (other)
	{
		return((other->m_radius + this->m_radius) >
			glm::distance(other->m_position, this->m_position));
	}
	return false;
}

void Rocket::Blast()
{

}

void Rocket::Exhaust(glm::vec2 startPos, float inclination, float speed, float gravity)
{
	//creates a sphere and shoots it down
	Rocket* fuel;

	fuel = new Rocket(m_position, glm::vec2(0, 0), 10.0f, 1, glm::vec4(0, 0.5, 0.5, 1));



	//must have collision to blast rocket up.


}