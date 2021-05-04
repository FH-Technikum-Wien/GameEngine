#pragma once
#include "../Core.h"

#include "Transformable.h"
#include <vector>

namespace Engine::Physics
{
	/// <summary>
	/// Calculates physics.
	/// </summary>
	class ENGINE_API PhysicsSystem
	{
	public:
		PhysicsSystem() = default;
		~PhysicsSystem();

		/// <summary>
		/// Updates all elements.
		/// </summary>
		// <param name="fixedDeltaTime">- The fixed delta time for the physics calculation.</param>
		void Update(const float fixedDeltaTime);

		/// <summary>
		/// Adds a transformable to the calculation list.
		/// </summary>
		/// <param name="transformable">- The transformable to update.</param>
		void Add(Transformable* transformable);

	private:
		// All elements to update.
		std::vector<Transformable*> m_transformable = std::vector<Transformable*>();
	};
}

