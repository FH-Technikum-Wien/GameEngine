#pragma once

#include "../Core.h"
#include "../Types/Vector2.h"

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
	/// <typeparam name="sizeType">- Defines the internal type for ids. Should be a whole number type.</typeparam>
	template<typename sizeType = unsigned int>
	class ENGINE_API PathFinding2D
	{
	public:
		/// <summary>
		/// A path represented by the node's ids.
		/// </summary>
		struct IdPath2D
		{
			// The ids of the nodes of the path.
			sizeType* Ids;
			// The number of ids (nodes) this path represents.
			sizeType Size;
		};

		/// <summary>
		/// A path represented by the node's positions.
		/// </summary>
		struct PositionPath2D
		{
			// The position of the nodes of the path.
			Vector2* Positions;
			// The number of positions (nodes) this path represents.
			sizeType Size;
		};

	private:
		struct Connection;

		/// <summary>
		/// Consists of an id, position, weigthScale and arbitrary number of (bidirectional) connections to other nodes.
		/// </summary>
		struct Node
		{
			// Node's position in the array and unique identifier.
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

		/// <summary>
		/// A path consists of an array of nodes. The order of the nodes represents the path.
		/// </summary>
		struct Path
		{
			// Nodes that create the path.
			Node** Nodes;
			// Number of nodes the path consists of.
			sizeType Length;
		};

		/// <summary>
		/// A tilemap consists of tiles (squares) of the same size.
		/// The map will tiles that can be used for the path (e.g. weigthScale >= 0) 
		/// and tiles that cannot be used, such as walls (e.g. weigthScale = -1).
		/// </summary>
		struct Tilemap
		{
			// 2D array of nodes, creating the tilemap.
			Node** Tiles;
			// Width of the tilemap.
			float Width;
			// Height of the tilemap.
			float Height;
			// The size of each tile (square). Influences the position of the nodes.
			float TileSize;
		};

	public:
		PathFinding2D();
		PathFinding2D(sizeType capacity);
		PathFinding2D(const PathFinding2D& other);
		virtual ~PathFinding2D();

		/// <summary>
		/// Adds a node with the given position to the system. 
		/// The id will automatically be incremented and the weigthScale of the node will be set to 1.0f.
		/// As the id is used as the position in an array, gaps can be created.
		/// </summary>
		/// <param name="position">- The position of the node.</param>
		/// <returns>True, if the node was added. False, if the node already exists.</returns>
		bool AddNode(Vector2 position);

		/// <summary>
		/// Adds a node with the given position and weigthScale to the system. 
		/// The id will automatically be incremented.
		/// As the id is used as the position in an array, gaps can be created.
		/// </summary>
		/// <param name="position">- The position of the node.</param>
		/// <param name="weigthScale">- The algorithm will prefer nodes with a lower weigthScale.</param>
		/// <returns>True, if the node was added. False, if the node already exists.</returns>
		bool AddNode(Vector2 position, float weigthScale);

		/// <summary>
		/// Adds a node with the given position and id to the system. The weigthScale of the node will be set to 1.0f.
		/// As the id is used as the position in an array, gaps can be created.
		/// </summary>
		/// <param name="id">- Unique id greater or equal to 0.</param>
		/// <param name="position">- The position of the node.</param>
		/// <returns>True, if the node was added. False, if the node already exists.</returns>
		bool AddNode(sizeType id, Vector2 position);

		/// <summary>
		/// Adds a node with the given position, id and weigthScale to the system.
		/// As the id is used as the position in an array, gaps can be created.
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
		void ConnectNodes(sizeType idFrom, sizeType idTo, float weigthScale, bool bidirectional);	

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
		IdPath2D* GetIdPath(sizeType idFrom, sizeType idTo) const;

		/// <summary>
		/// Calculates a path between the given nodes and returns it as an array of the node's positions (in order of the path).
		/// </summary>
		/// <param name="idFrom">- The id of the start node.</param>
		/// <param name="idTo">- The id of the end node.</param>
		/// <returns>A 'PositionPath2D' containing all posiitons of the nodes of this path. Returns a nullptr if no path was found.</returns>
		PositionPath2D* GetPositionPath(sizeType idFrom, sizeType idTo) const;

		/// <summary>
		/// Gets the positon of the node with the given Id.
		/// </summary>
		/// <param name="id">The id of the node.</param>
		/// <returns>The position of the node.</returns>
		const Vector2& GetNodePosition(sizeType id) const;

		/// <summary>
		/// Gets the weigthScale of the node with the given Id.
		/// </summary>
		/// <param name="id">The id of the node.</param>
		/// <returns>The weigthScale of the node.</returns>
		float GetNodeWeigthScale(sizeType id) const;

		/// <summary>
		/// Gets the weigthScale of the connection between the given nodes.
		/// </summary>
		/// <param name="idFrom">- The id of the start node.</param>
		/// <param name="idTo">- The id of the end node.</param>
		float GetConnectionWeigthScale(sizeType idFrom, sizeType idTo) const;

		/// <summary>
		/// Adds a tilemap at the given position with the given width, height and tile size.
		/// This deactivates the ability to add new nodes manually.
		/// Creates nodes and connections automatically.
		/// </summary>
		/// <param name="center">- The center point of the tilemap.</param>
		/// <param name="width">- The width of the tilemap.</param>
		/// <param name="height">- The height of the tilemap.</param>
		/// <param name="tileSize">- The size of each tile (square).</param>
		void AddTilemap(Vector2 center, int width, int height, float tileSize);

		/// <summary>
		/// Removes/Deactivates the tilemap, allowing the user to manually add nodes again.
		/// This does not remove nodes. Nodes and connections created by the tilemap will stay.
		/// </summary>
		void RemoveTilemap();

		/// <summary>
		/// Clears the system, removing all nodes and connections, resetting it completely.
		/// Also removes the tilemap.
		/// </summary>
		void Clear();

		/// <summary>
		/// Allocates more memory for the array containing the nodes. Use this if you add a lot of nodes at once.
		/// </summary>
		/// <param name="numberOfNodes">- The new number of nodes in the system.</param>
		void Reserve(sizeType newCapacity);

		/// <summary>
		/// Returns the current capacity of the system (max number of nodes).
		/// </summary>
		sizeType Capacity() const;

		/// <summary>
		/// Returns the number of nodes currently in the system.
		/// </summary>
		sizeType Size() const;

		/// <summary>
		/// Finds the nearest node to the given position and returns it's id.
		/// If using a tilemap, will use the tile size to increase search speed.
		/// </summary>
		/// <param name="position">- The position to search for.</param>
		/// <returns>The id of the node.</returns>
		sizeType FindClosestNode(const Vector2 position) const;

	private:
		/// <summary>
		/// Loads nodes and connections from a file.
		/// </summary>
		/// <param name="filePath">- The path to the file.</param>
		/// <returns>True if the file was read. False if the file could not be read.</returns>
		bool LoadNodes(const std::string filePath);
		bool LoadNodes(const char* filePath);

		/// <summary>
		/// Saves nodes and connections to a file.
		/// </summary>
		/// <param name="filePath">- The path to the file.</param>
		/// <returns>True if the file was saved. False if the file could not be saved.</returns>
		void SaveNodes(const std::string filePath);
		void SaveNodes(const char* filePath);

		/// <summary>
		/// Calculates the path between the given two nodes.
		/// </summary>
		/// <param name="idFrom">- The id of the start node.</param>
		/// <param name="idTo">- The id of the end node.</param>
		Path CalculatePath(sizeType idFrom, sizeType idTo) const;

		/// <summary>
		/// Calculates the cost between the given nodes.
		/// </summary>
		/// <param name="idFrom">- The id of the start node.</param>
		/// <param name="idTo">- The id of the end node.</param>
		float CalculateCost(sizeType idFrom, sizeType idTo) const;

		/// <summary>
		/// Calculates the estimated cost between the given nodes (euclidean distance).
		/// </summary>
		/// <param name="idFrom">- The id of the start node.</param>
		/// <param name="idTo">- The id of the end node.</param>
		float CalculateEstimatedCost(sizeType idFrom, sizeType idTo) const;

		/// <summary>
		/// Creates a tilemap with the given width, height and tile size.
		/// </summary>
		/// <param name="center">- The center point of the tilemap.</param>
		/// <param name="width">- The width of the tilemap.</param>
		/// <param name="height">- The height of the tilemap.</param>
		/// <param name="tileSize">- The size of each tile (square).</param>
		/// <returns>A tilemap containing all created nodes.</returns>
		Tilemap GenerateTilemap(Vector2 center, int width, int height, float tileSize);

	private:
		// Current number of nodes in the system.
		sizeType m_size;
		// Max number of nodes with current allocated memory.
		sizeType m_capacity;
		// List of all nodes in the system.
		Node* m_nodes;
		// Current id for the auto-incrementation.
		sizeType m_currentId;
		// The current tilemap used for pathfinding.
		Tilemap* m_tilemap;
		// Prevents the user from adding nodes manually when using the tilemap.
		bool m_useTilemap;
	};
}

