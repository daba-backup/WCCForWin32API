#pragma once

#include"Object.h"
#include"TString.h"
#include<Windows.h>

namespace daxie {
	namespace menu {
		class MenuItem :public daxie::Object {
			friend class MenuBar;
			friend class Menu;

		private:
			daxie::tstring text;
			int id;

			HMENU hmenu;

		public:
			MenuItem(const daxie::tstring& text);
			virtual ~MenuItem();

		private:
			MENUITEMINFO MakeMenuItemInfo();
			UINT GetState();

		public:
			BOOL IsThisMenuItem(int id);
			void Check();
			void Uncheck();
			void Enable();
			void Disable();
			void Gray();
			void Hilite();
			void Unhilite();

		public:
			daxie::tstring GetText();
			bool IsChecked();
			bool IsEnabled();
			bool IsGrayed();
			bool IsHilited();
		};
	}
}