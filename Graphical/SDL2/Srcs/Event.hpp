/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Event
*/

#ifndef EVENT_HPP_
    #define EVENT_HPP_
#include "arcade/interface/graphic/IEvent.hpp"
#include "arcade/interface/graphic/IWindow.hpp"
#include <SDL2/SDL.h>
#include <vector>

namespace arcade::SDL2 {
	class Event : public arcade::interface::graphic::IEvent {
		public:
			Event(SDL_Event &event);
			~Event();
			arcade::interface::graphic::IEvent::EventType getType();
			arcade::interface::graphic::Key getKey();
		protected:
		private:
		        SDL_Event _event;
			std::vector<SDL_Keycode> _key = {
				SDLK_a,
				SDLK_b,            // The B key
				SDLK_c,            // The C key
				SDLK_d,            // The D key
				SDLK_e,            // The E key
				SDLK_f,            // The F key
				SDLK_g,            // The G key
				SDLK_h,            // The H key
				SDLK_i,            // The I key
				SDLK_j,            // The J key
				SDLK_k,            // The K key
				SDLK_l,            // The L key
				SDLK_m,            // The M key
				SDLK_n,            // The N key
				SDLK_o,            // The O key
				SDLK_p,            // The P key
				SDLK_q,            // The Q key
				SDLK_r,            // The R key
				SDLK_s,            // The S key
				SDLK_t,            // The T key
				SDLK_u,            // The U key
				SDLK_v,            // The V key
				SDLK_w,            // The W key
				SDLK_x,            // The X key
				SDLK_y,            // The Y key
				SDLK_z,            // The Z key
				SDLK_0,         // The 0 key
				SDLK_1,         // The 1 key
				SDLK_2,         // The 2 key
				SDLK_3,         // The 3 key
				SDLK_4,         // The 4 key
				SDLK_5,         // The 5 key
				SDLK_6,         // The 6 key
				SDLK_7,         // The 7 key
				SDLK_8,         // The 8 key
				SDLK_9,         // The 9 key
				SDLK_ESCAPE,       // The Escape key
				SDLK_LCTRL,     // The left Control key
				SDLK_LSHIFT,       // The left Shift key
				SDLK_LALT,         // The left Alt key
				SDLK_APPLICATION,      // The left OS specific key: window (Windows and Linux), apple (MacOS X), ...
				SDLK_RCTRL,     // The right Control key
				SDLK_RSHIFT,       // The right Shift key
				SDLK_RALT,         // The right Alt key
				SDLK_APPLICATION, // THe right system
				SDLK_MENU,         // The Menu key
				SDLK_LEFTBRACKET,     // The [ key
				SDLK_RIGHTBRACKET,     // The ] key
				SDLK_SEMICOLON,    // The ; key
				SDLK_COMMA,        // The , key
				SDLK_PERIOD,       // The . key
				SDLK_QUOTE,        // The ' key
				SDLK_SLASH,        // The / key
				SDLK_BACKSLASH,    // The \ key
				SDLK_BACKQUOTE,        // The ~ key
				SDLK_EQUALS,        // The = key
				SDLK_UNKNOWN,       // The - key (hyphen)
				SDLK_SPACE,        // The Space key
				SDLK_RETURN,        // The Enter/Return keys
				SDLK_BACKSPACE,    // The Backspace key
				SDLK_TAB,          // The Tabulation key
				SDLK_PAGEUP,       // The Page up key
				SDLK_PAGEDOWN,     // The Page down key
				SDLK_END,          // The End key
				SDLK_HOME,         // The Home key
				SDLK_INSERT,       // The Insert key
				SDLK_DELETE,       // The Delete key
				SDLK_KP_PLUS,          // The + key
				SDLK_KP_MINUS,     // The - key (minus, usually from SDLK_pad)
				SDLK_KP_MULTIPLY,     // The * key
				SDLK_KP_DIVIDE,       // The / key
				SDLK_LEFT,         // Left arrow
				SDLK_RIGHT,        // Right arrow
				SDLK_UP,           // Up arrow
				SDLK_DOWN,         // Down arrow
				SDLK_0,         // The 0 key
				SDLK_1,         // The 1 key
				SDLK_2,         // The 2 key
				SDLK_3,         // The 3 key
				SDLK_4,         // The 4 key
				SDLK_5,         // The 5 key
				SDLK_6,         // The 6 key
				SDLK_7,         // The 7 key
				SDLK_8,         // The 8 key
				SDLK_9,         // The 9 key
				SDLK_F1,           // The F1 key
				SDLK_F2,           // The F2 key
				SDLK_F3,           // The F3 key
				SDLK_F4,           // The F4 key
				SDLK_F5,           // The F5 key
				SDLK_F6,           // The F6 key
				SDLK_F7,           // The F7 key
				SDLK_F8,           // The F8 key
				SDLK_F9,           // The F9 key
				SDLK_F10,          // The F10 key
				SDLK_F11,          // The F11 key
				SDLK_F12,          // The F12 key
				SDLK_F13,          // The F13 key
				SDLK_F14,          // The F14 key
				SDLK_F15,          // The F15 key
				SDLK_PAUSE,        // The Pause key
			};
	};
}

#endif /* !EVENT_HPP_ */
