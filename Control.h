#pragma once

#include"Object.h"
#include"TString.h"
#include<Windows.h>

namespace daxie {
	namespace control {
		class Control :public daxie::Object {
		private:
			HWND hcontrol;
			HWND hwnd_parent;

		public:
			Control(
				const daxie::tstring& text, const daxie::tstring& class_name,
				int width = CW_USEDEFAULT, int height = CW_USEDEFAULT,
				int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, HWND hwnd_parent = NULL, HMENU hmenu = NULL,
				DWORD style = WS_VISIBLE | WS_CHILD, DWORD ex_style = 0);
			virtual ~Control();

		protected:
			HWND GetControlHandle();
			HWND GetParentHandle();

		public:
			BOOL IsThisControl(HWND hcontrol);

		public:
			void SetControlText(const daxie::tstring& text);
			void EnableControl();
			void DisableControl();
			void ShowControl();
			void HideControl();
			void MoveControl(int width, int height, int x, int y);
		};
	}
}