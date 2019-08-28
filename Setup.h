#pragma once

#include"Object.h"
#include"Window.h"

namespace daxie {
	namespace system {
		class Setup :daxie::Object {
		public:
			static BOOL SetupCommonControls();
		};
	}
}