#pragma once
#include "../Core.h"

#include "Transformable.h"
#include <vector>

namespace Engine::Physics
{
	class ENGINE_API PhysicsSystem
	{
	public:
		PhysicsSystem();
		~PhysicsSystem();

		void Update(const float fixedDeltaTime);

		void Add(Transformable* transformable);

	private:
		std::vector<Transformable*> m_transformable = std::vector<Transformable*>();
	};
}

