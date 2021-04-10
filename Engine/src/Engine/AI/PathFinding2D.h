#pragma once

#include "../Core.h"
#include "../Vector2.h"


namespace Engine::AI
{
	template<typename sizeType = int>
	class ENGINE_API PathFinding2D
	{

	public:
		struct IdPath2D
		{
			sizeType* Ids;
			sizeType Size;
		};

		struct PositionPath2D
		{
			Vector2* Positions;
			sizeType Size;
		};
	private:
		struct Node
		{
			Vector2 Position;
			bool Bidirectional;
		};

	public:
		bool AddNode(sizeType id, Vector2 position, float weigthScale);
		bool RemoveNode(sizeType id);
		void ConnectNodes(sizeType idFirst, sizeType idSecond, bool bidirectional);
		void Clear();

		void UpdateNode(sizeType id, Vector2 position, bool bidirectional);
		void UpdateNode(sizeType id, Vector2 position);
		void UpdateNode(sizeType id, bool bidirectional);

		IdPath2D* GetIdPath(sizeType idFrom, sizeType idTo);
		PositionPath2D* GetPositionPath(sizeType idFrom, sizeType idTo);
		Vector2 GetNodePosition(sizeType id);

		void Reserve(sizeType numberOfNodes);
		sizeType GetCapacity();

		sizeType Size();


	private:
		sizeType m_size;
		sizeType m_capacity;

		Node* m_nodes;
	};
}

