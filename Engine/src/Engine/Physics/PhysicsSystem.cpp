#include "PhysicsSystem.h"

namespace Engine::Physics
{
	PhysicsSystem::~PhysicsSystem()
	{
		// TODO: DELETE DATA
	}

	void PhysicsSystem::Update(const float fixedDeltaTime)
	{
		for (Transformable* transformable : m_transformable)
		{
			transformable->Transform(fixedDeltaTime);
		}
	}

	void PhysicsSystem::Add(Transformable* transformable)
	{
		m_transformable.push_back(transformable);
	}
}
