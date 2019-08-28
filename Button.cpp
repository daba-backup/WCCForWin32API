#include"Button.h"

daxie::control::Button::Button(const daxie::tstring& text, int width, int height, int x, int y, HWND hwnd_parent) :
	Control(text, TEXT("BUTTON"), width, height, x, y, hwnd_parent, NULL, WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 0) {

}
daxie::control::Button::~Button() {

}