#pragma once

#include"Control.h"

namespace daxie {
	namespace control {
		class Edit :public daxie::control::Control {
		public:
			Edit(int x, int y, int width, int height, HWND hwnd_parent);
			virtual ~Edit();
		};
	}
}