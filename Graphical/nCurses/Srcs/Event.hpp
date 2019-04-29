/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Event
*/

#ifndef EVENT_HPP_
    #define EVENT_HPP_
#include "arcade/interface/graphic/IEvent.hpp"
#include <curses.h>
#include <vector>
#include "arcade/interface/graphic/IWindow.hpp"

namespace arcade::nCurses {
	class Event : public arcade::interface::graphic::IEvent {
		public:
			Event(int keyCode);
			~Event();
			arcade::interface::graphic::IEvent::EventType getType();
			arcade::interface::graphic::Key getKey();
		protected:
		private:
			int _keyCode;
			std::vector<int> _key = {
				'a',            // The A key
				'b',            // The B key
				'c',            // The C key
				'd',            // The D key
				'e',            // The E key
				'f',            // The F key
				'g',            // The G key
				'h',            // The H key
				'i',            // The I key
				'j',            // The J key
				'k',            // The K key
				'l',            // The L key
				'm',            // The M key
				'n',            // The N key
				'o',            // The O key
				'p',            // The P key
				'q',            // The Q key
				'r',            // The R key
				's',            // The S key
				't',            // The T key
				'u',            // The U key
				'v',            // The V key
				'w',            // The W key
				'x',            // The X key
				'y',            // The Y key
				'z',            // The Z key
				'0',         // The 0 key
				'1',         // The 1 key
				'2',         // The 2 key
				'3',         // The 3 key
				'4',         // The 4 key
				'5',         // The 5 key
				'6',         // The 6 key
				'7',         // The 7 key
				'8',         // The 8 key
				'9',         // The 9 key
				27,       // The Escape key
				-1,     // The left Control key
				-1,       // The left Shift key
				-1,         // The left Alt key
				-1,      // The left OS specific key: window (Windows and Linux), apple (MacOS X), ...
				-1,     // The right Control key
				-1,       // The right Shift key
				-1,         // The right Alt key
				-1,      // The right OS specific key: window (Windows and Linux), apple (MacOS X), ...
				-1,         // The Menu key
				'[',     // The [ key
				']',     // The ] key
				';',    // The ; key
				',',        // The , key
				'.',       // The . key
				'\'',        // The ' key
				'/',        // The / key
				'\'',    // The \ key
				'~',        // The ~ key
				'=',        // The = key
				'-',       // The - key (hyphen)
				' ',        // The Space key
				'\n',        // The Enter/Return keys
				KEY_BACKSPACE,    // The Backspace key
				'\t',          // The Tabulation key
				-1,       // The Page up key
				-1,     // The Page down key
				KEY_END,          // The End key
				KEY_HOME,         // The Home key
				-1,       // The Insert key
				KEY_UNDO,       // The Delete key
				'+',          // The + key
				'-',     // The - key (minus, usually from ')'
				'*',     // The * key
				'/',       // The / key
				KEY_LEFT,         // Left arrow
				KEY_RIGHT,        // Right arrow
				KEY_UP,           // Up arrow
				KEY_DOWN,         // Down arrow
				'0',      // The ' '0 key
				'1',      // The ' '1 key
				'2',      // The ' '2 key
				'3',      // The ' '3 key
				'4',      // The ' '4 key
				'5',      // The ' '5 key
				'6',      // The ' '6 key
				'7',      // The ' '7 key
				'8',      // The ' '8 key
				'9',      // The ' '9 key
				-1,           // The F1 key
				-1,           // The F2 key
				-1,           // The F3 key
				-1,           // The F4 key
				-1,           // The F5 key
				-1,           // The F6 key
				-1,           // The F7 key
				-1,           // The F8 key
				-1,           // The F9 key
				-1,          // The F10 key
				-1,          // The F11 key
				-1,          // The F12 key
				-1,          // The F13 key
				-1,          // The F14 key
				-1,          // The F15 key
				-1,        // The Pause key
			};
	};
}

#endif /* !EVENT_HPP_ */
