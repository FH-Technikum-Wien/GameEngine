#pragma once
#include "../Core.h"

#include <string>
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "../Types/Vector2.h"

namespace Engine::Rendering
{
	class ENGINE_API RenderWindow
	{
	public:
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
		struct Event
		{
		private:
			struct Mouse
			{
				Vector2 Position;
			};


		public:
			EventType Type;
			Mouse Mouse;
		};

	public:
		RenderWindow(unsigned int width, unsigned int height, const std::string& title);

		void Draw(Drawable* drawable, const float stateBlending);
		void Show();
		void Clear();
		bool PollEvent(Event& event);
		void Close();

	private:
		sf::RenderWindow* m_sfWindow;
	};
}

