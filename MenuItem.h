#pragma once

#include"Object.h"
#include"TString.h"

namespace daxie {
	namespace menu {
		class MenuItem :public daxie::Object {
		private:
			daxie::tstring text;

		public:
			MenuItem(const daxie::tstring& text);
			virtual ~MenuItem();

		public:
			daxie::tstring GetText();
		};
	}
}