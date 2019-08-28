#pragma once

#include"Object.h"
#include"TString.h"
#include<Windows.h>

namespace daxie {
	namespace window {
		class Window :public daxie::Object {
		private:
			static HINSTANCE hinstance;
			HWND hwnd;
			static daxie::window::Window* p_this;

			static const daxie::tstring WINDOW_CLASS_NAME;

		public:
			Window();
			virtual ~Window();

			static BOOL DHRegisterWindowClass();
			virtual BOOL DHCreateWindow(
				const daxie::tstring& title, int x = CW_USEDEFAULT, int y = CW_USEDEFAULT,
				int width = CW_USEDEFAULT, int height = CW_USEDEFAULT, HWND hwnd_parent = NULL, HMENU hmenu = NULL,
				const daxie::tstring& class_name = WINDOW_CLASS_NAME,
				DWORD style = WS_OVERLAPPEDWINDOW | WS_VISIBLE, DWORD ex_style = 0);

		private:
			static LRESULT CALLBACK WndProcMgr(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
			LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

		public:
			static void MsgLoop();

			virtual void Idle();
			virtual BOOL onCreate(HWND hwnd, LPCREATESTRUCT cs);
			virtual void onDestroy(HWND hwnd);
			virtual void onPaint(HWND hwnd);
			virtual void onSize(HWND hwnd, UINT state, int cx, int cy);
			virtual void onTimer(HWND hwnd, UINT id);
			virtual void onCommand(HWND hwnd, int id, HWND hwndctrl, UINT code_notify);
			virtual void onChar(HWND hwnd, TCHAR ch, int c_repeat);
			virtual void onLButtonDown(HWND hwnd, BOOL is_double_click, int x, int y, UINT key_flags);
			virtual void onRButtonDown(HWND hwnd, BOOL is_double_click, int x, int y, UINT key_flags);
			virtual void onMButtonDown(HWND hwnd, BOOL is_double_click, int x, int y, UINT key_flags);
			virtual void onLButtonUp(HWND hwnd, int x, int y, UINT key_flags);
			virtual void onRButtonUp(HWND hwnd, int x, int y, UINT key_flags);
			virtual void onMButtonUp(HWND hwnd, int x, int y, UINT key_flags);
			virtual void onMouseMove(HWND hwnd, int x, int y, UINT key_flags);
			virtual void onMouseWheel(HWND hwnd, int x, int y, int z_delta, UINT fw_keys);

		public:
			void DHSetWindowText(const daxie::tstring& text);

			daxie::tstring DHGetWindowText();
		};
	}
}