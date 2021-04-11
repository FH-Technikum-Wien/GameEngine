#pragma once

#include "../Core.h"
#include "../Vector2.h"

#include <string>


namespace Engine::AI
{
	/// <summary>
	/// The system contains nodes and connections.
	/// <para>
	/// Each node is represented by an id, position, weigth and connections to other nodes.
	/// Like nodes, connections include a weigth as well. 
	/// The weigth determines how likely a node or connection will be picked by the algorithm (lower = better).
	/// </para>
	/// Bidirectional connections are two connections between two nodes.
	/// A connection can be directed as well as better in one direction than the other.
	/// </summary>
	/// <typeparam name="sizeType">- Defines the internal type for ids</typeparam>
	template<typename sizeType = unsigned int>
	class ENGINE_API PathFinding2D
	{

	public:
		/// <summary>
		/// A path represented by the node's ids.
		/// </summary>
		struct IdPath2D
		{
			sizeType* Ids;
			sizeType Size;
		};

		/// <summary>
		/// A path represented by the node's positions.
		/// </summary>
		struct PositionPath2D
		{
			Vector2* Positions;
			sizeType Size;
		};

	private:
		struct Connection;

		/// <summary>
		/// Consists of a position, weigthScale and arbitrary number of (bidirectional) connections to other nodes.
		/// </summary>
		struct Node
		{
			// Node's position in the array.
			sizeType Id;
			// Actual position of the node.
			Vector2 Position;
			// The algorithm will prefer nodes with a lower weigthScale.
			float weigthScale;
			// Connections to other nodes. If bidirectional the connected node will have a connection back.
			Connection* Connections;
			// Number of connections to other nodes.
			sizeType numberOfConnections;
		};

		/// <summary>
		/// Connects two nodes with a weigthScale.
		/// </summary>
		struct Connection
		{
			// Node the connection starts from.
			Node* From;
			// Node the connection ends in.
			Node* To;
			// The algorithm will prefer connections with a lower weigthScale.
			float weigthScale;
		};

	public:
		PathFinding2D();
		~PathFinding2D();

		/// <summary>
		/// Adds a node consisting of a position and a weigth to the system. 
		/// As the id is used as the position in an array, try to avoid big gaps.
		/// </summary>
		/// <param name="id">- Unique id greater or equal to 0.</param>
		/// <param name="position">- The position of the node.</param>
		/// <param name="weigthScale">- The algorithm will prefer nodes with a lower weigthScale.</param>
		/// <returns>True, if the node was added. False, if the node already exists.</returns>
		bool AddNode(sizeType id, Vector2 position, float weigthScale);

		/// <summary>
		/// Removes the node with the given id and all connections to and/or from it.
		/// As the id is used as a position in th array, finding the node will be done in O(n).
		/// </summary>
		/// <param name="id">- The id of the node to be removed.</param>
		/// <returns>True if the node was removed. False if the node does not exist.</returns>
		bool RemoveNode(sizeType id);

		/// <summary>
		/// Connects two nodes with the given ids.
		/// Will connect them bidirectional with a weigthScale of 1.
		/// Will not connect nodes multiple times.
		/// </summary>
		/// <param name="idFrom">- The id of the first node.</param>
		/// <param name="idTo">- The id of the second node.</param>
		void ConnectNodes(sizeType idFrom, sizeType idTo);

		/// <summary>
		/// Connects two nodes with the given ids.
		/// Will connect them bidirectional with the given weigthScale.
		/// Will not connect nodes multiple times.
		/// </summary>
		/// <param name="idFrom">- The id of the first node.</param>
		/// <param name="idTo">- The id of the second node.</param>
		/// <param name="weigthScale">- The algorithm will prefer connections with a lower weigthScale.</param>
		void ConnectNodes(sizeType idFrom, sizeType idTo, float weigthScale);

		/// <summary>
		/// Connects two nodes with the given ids.
		/// Will connect the nodes, depending on 'bidirectional', either (A to B) or (A to B and B to A) with a weigthScale of 1.
		/// Will not connect nodes multiple times.
		/// </summary>
		/// <param name="idFrom">- The id of the first node.</param>
		/// <param name="idTo">- The id of the second node.</param>
		/// <param name="bidirectional">- Whether the nodes should be connected bidirectional.</param>
		void ConnectNodes(sizeType idFrom, sizeType idTo, bool bidirectional);

		/// <summary>
		/// Connects two nodes with the given ids.
		/// Will connect the nodes, depending on 'bidirectional', either (A to B) or (A to B and B to A) with the given weigthScale.
		/// Will not connect nodes multiple times.
		/// </summary>
		/// <param name="idFrom">- The id of the first node.</param>
		/// <param name="idTo">- The id of the second node.</param>
		/// <param name="weigthScale">- The algorithm will prefer connections with a lower weigthScale.</param>
		/// <param name="bidirectional">- Whether the nodes should be connected bidirectional.</param>
		void ConnectNodes(sizeType idFrom, sizeType idTo, float weigthScale = 1.0f, bool bidirectional = true);	

		/// <summary>
		/// Clears the system, removing all nodes and connections.
		/// </summary>
		void Clear();

		/// <summary>
		/// Updates the position of the node with the given id.
		/// </summary>
		/// <param name="id">- The id of the node to be updated.</param>
		/// <param name="newPosition">- The new position of the node.</param>
		void UpdateNode(sizeType id, Vector2 newPosition);

		/// <summary>
		/// Updates the weigth of the node with the given id.
		/// </summary>
		/// <param name="id">- The id of the node to be updated.</param>
		/// <param name="newWeigth">- The new weigth of the node.</param>
		void UpdateNode(sizeType id, float newWeigthScale);

		/// <summary>
		/// Updates the position and weigth of the node with the given id.
		/// </summary>
		/// <param name="id">- The id of the node to be updated.</param>
		/// <param name="newPosition">- The new position of the node.</param>
		/// <param name="newWeigth">- The new weigth of the node.</param>
		void UpdateNode(sizeType id, Vector2 newPosition, float newWeigthScale);

		/// <summary>
		/// Updates the weigthScale of an already defined connection.
		/// This does not update both connection for a bidirectional connection.
		/// </summary>
		/// <param name="idFrom">- The id of the first node.</param>
		/// <param name="idTo">- The id of the second node.</param>
		/// <param name="newWeigthScale">- The new weigthScale of the connection.</param>
		void UpdateConnection(sizeType idFrom, sizeType idTo, float newWeigthScale);

		/// <summary>
		/// Calculates a path between the given nodes and returns it as an array of the node's ids (in order of the path).
		/// </summary>
		/// <param name="idFrom">- The id of the start node.</param>
		/// <param name="idTo">- The id of the end node.</param>
		/// <returns>An 'IdPath2D' containing all ids of the nodes of this path. Returns a nullptr if no path was found.</returns>
		IdPath2D* GetIdPath(sizeType idFrom, sizeType idTo);

		/// <summary>
		/// Calculates a path between the given nodes and returns it as an array of the node's positions (in order of the path).
		/// </summary>
		/// <param name="idFrom">- The id of the start node.</param>
		/// <param name="idTo">- The id of the end node.</param>
		/// <returns>A 'PositionPath2D' containing all posiitons of the nodes of this path. Returns a nullptr if no path was found.</returns>
		PositionPath2D* GetPositionPath(sizeType idFrom, sizeType idTo);

		/// <summary>
		/// Gets the positon of the node with the given Id.
		/// </summary>
		/// <param name="id">The id of the node.</param>
		/// <returns>The position of the node.</returns>
		Vector2 GetNodePosition(sizeType id);

		/// <summary>
		/// Gets the weigthScale of the node with the given Id.
		/// </summary>
		/// <param name="id">The id of the node.</param>
		/// <returns>The weigthScale of the node.</returns>
		float GetNodeWeigthScale(sizeType id);

		/// <summary>
		/// Gets the weigthScale of the connection between the given nodes.
		/// </summary>
		/// <param name="idFrom">- The id of the start node.</param>
		/// <param name="idTo">- The id of the end node.</param>
		float GetConnectionWeigthScale(sizeType idFrom, sizeType idTo);

		/// <summary>
		/// Allocates more memory for the array containing the nodes. Use this if you add a lot of nodes at once.
		/// </summary>
		/// <param name="numberOfNodes">- The new number of nodes in the system.</param>
		void Reserve(sizeType numberOfNodes);

		/// <summary>
		/// Returns the current capacity of the system (max number of nodes).
		/// </summary>
		sizeType Capacity();

		/// <summary>
		/// Returns the number of nodes currently in the system.
		/// </summary>
		sizeType Size();

	private:
		/// <summary>
		/// Loads nodes and connections from a file.
		/// </summary>
		/// <param name="filePath">- The path to the file.</param>
		/// <returns>True if the file was read. False if the file could not be read.</returns>
		bool LoadNodes(std::string filePath);
		/// <summary>
		/// Saves nodes and connections to a file.
		/// </summary>
		/// <param name="filePath">- The path to the file.</param>
		/// <returns>True if the file was saved. False if the file could not be saved.</returns>
		void SaveNodes(std::string filePath);

		/// <summary>
		/// Calculates the cost between the given nodes.
		/// </summary>
		/// <param name="idFrom">- The id of the start node.</param>
		/// <param name="idTo">- The id of the end node.</param>
		void CalculateCost(sizeType idFrom, sizeType idTo);

		/// <summary>
		/// Calculates the estimated cost between the given nodes (euclidean).
		/// </summary>
		/// <param name="idFrom">- The id of the start node.</param>
		/// <param name="idTo">- The id of the end node.</param>
		void CalculateEstimatedCost(sizeType idFrom, sizeType idTo);

	private:

		// Current number of nodes in the system.
		sizeType m_size;
		// Max number of nodes with current allocated memory.
		sizeType m_capacity;
		// List of all nodes in the system.
		Node* m_nodes;
	};
}

