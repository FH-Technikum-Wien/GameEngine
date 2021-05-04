#pragma once
#include "../Core.h"

#include <string>
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "../Types/Vector2.h"

namespace Engine::Rendering
{
	/// <summary>
	/// Wrapper for the SFML RenderWindow.
	/// </summary>
	class ENGINE_API RenderWindow
	{
	public:
		/// <summary>
		/// Event types that the RenderWindow can poll. Need to align with the SFML event types.
		/// </summary>
		enum EventType
		{
			CLOSE,                 
			RESIZED,               
			LOST_FOCUS,             
			GAINED_FOCUS,           
			TEXT_ENTERED,           
			KEY_PRESSED,            
			KEY_RELEASED,           
			MOUSE_WHEEL_MOVED,       
			MOUSE_WHEEL_SCROLLED,    
			MOUSE_BUTTON_PRESSED,    
			MOUSE_BUTTON_RELEASED,   
			MOUSE_MOVED,            
			MOUSE_ENTERED,          
			MOUSE_LEFT,
		};

		/// <summary>
		/// Includes the event type and (for now only) the mouse position. 
		/// </summary>
		struct Event
		{
		private:
			/// <summary>
			/// A small struct containing mouse data (currently only its position).
			/// </summary>
			struct Mouse
			{
				Vector2 Position;
			};


		public:
			// The type of the event.
			EventType Type;
			// The mouse data of the event.
			Mouse Mouse;
		};

	public:
		/// <summary>
		/// Creates a new RenderWindow by creating an internal SFML RenderWindow element.
		/// </summary>
		/// <param name="width">- The width of the window.</param>
		/// <param name="height">- The height of the window.</param>
		/// <param name="title">- The title of the window.</param>
		RenderWindow(unsigned int width, unsigned int height, const std::string& title);

		/// <summary>
		/// Draws the given drawable with an optional interpolation.
		/// </summary>
		/// <param name="drawable">- The drawable to draw.</param>
		/// <param name="stateBlending">- Allows the interpolation of variables to compensate stutter due to difference in System Framerates.</param>
		void Draw(Drawable* drawable, const float stateBlending);

		/// <summary>
		/// Shows the drawn elements. Needs to be called after everything got drawn.
		/// </summary>
		void Show();

		/// <summary>
		/// Clears the RenderWindow. Needs to be called before drawing the next frame.
		/// </summary>
		void Clear();

		/// <summary>
		/// Polls the next window event.
		/// </summary>
		/// <param name="event">- The event data.</param>
		/// <returns>True, if there was an event to poll.</returns>
		bool PollEvent(Event& event);

		/// <summary>
		/// Closes the RenderWindow (the internal SFML RenderWindow).
		/// </summary>
		void Close();

	private:
		// The internal SFML RenderWindow.
		sf::RenderWindow* m_sfWindow;
	};
}

