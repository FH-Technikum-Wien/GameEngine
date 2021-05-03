#include "PhysicsSystem.h"

namespace Engine::Physics
{
	PhysicsSystem::PhysicsSystem()
	{
	}

	PhysicsSystem::~PhysicsSystem()
	{
	}

	void PhysicsSystem::Update(const float fixedDeltaTime)
	{
		for (Transformable* transformable : m_transformable)
		{
			transformable->Transform(fixedDeltaTime);
		}
	}

	void PhysicsSystem::InterpolateLastPosition(const float alpha)
	{
		for (Transformable* transformable : m_transformable)
		{
			transformable->InterpolateLastPosition(alpha);
		}
	}

	void PhysicsSystem::Add(Transformable* transformable)
	{
		m_transformable.push_back(transformable);
	}
}
