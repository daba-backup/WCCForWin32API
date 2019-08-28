#pragma once

#include"Control.h"

namespace daxie {
	namespace control {
		class Button :public daxie::control::Control {
		public:
			Button(const daxie::tstring& text, int width, int height, int x, int y, HWND hwnd_parent);
			virtual ~Button();
		};
	}
}