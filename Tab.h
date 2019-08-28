#pragma once

#include"Control.h"

namespace daxie {
	namespace control {
		class Tab :public daxie::control::Control {
		public:
			Tab(int width, int height, int x, int y, HWND hwnd_parent);
			virtual ~Tab();

		public:
			void InsertItem(int index, const daxie::tstring& text);
		};
	}
}