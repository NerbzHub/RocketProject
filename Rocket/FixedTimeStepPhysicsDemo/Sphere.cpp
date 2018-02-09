#include "Sphere.h"



Sphere::Sphere(glm::vec2 position, glm::vec2 velocity,
	float mass, float radius, glm::vec4 colour) : RigidBody(SPHERE, position, velocity, 0, mass)
{
	m_radius = radius;
	m_colour = colour;
}

Sphere::Sphere(glm::vec2 position, float inclination, float speed, float mass, float radius, glm::vec4 colour) 
	: Sphere(position, glm::vec2(sin(inclination), cos(inclination)) * speed, mass, radius, colour)
{
	m_radius = radius;
	m_colour = colour;
}


Sphere::~Sphere()
{
}

void Sphere::makeGizmo()
{
	aie::Gizmos::add2DCircle(m_position, m_radius, 12, m_colour);

}

bool Sphere::checkCollision(PhysicsObject* pOther)
{
	Sphere* other = dynamic_cast<Sphere*>(pOther);
		if(other)
		{
			return((other->m_radius + this->m_radius) >
				glm::distance(other->m_position, this->m_position));
		}
		return false;
}
