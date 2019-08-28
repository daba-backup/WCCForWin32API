#include"Control.h"

daxie::control::Control(
	const daxie::tstring& text, const daxie::tstring& class_name,
	int width, int height, int x, int y,
	HWND hwnd_parent, HMENU hmenu, DWORD style, DWORD ex_style) {
	HINSTANCE hinstance = GetModuleHandle(NULL);

	hcontrol = CreateWindowEx(ex_style, class_name.c_str(), text.c_str(), style,
		x, y, width, height, hwnd_parent, hmenu, hinstance, NULL);
	this->hwnd_parent = hwnd_parent;
}
daxie::control::~Control() {

}

HWND daxie::control::Control::GetControlHandle() {
	return hcontrol;
}
HWND daxie::control::Control::GetParentHandle() {
	return hwnd_parent;
}

BOOL daxie::control::Control::IsThisControl(HWND hcontrol) {
	if (this->hcontrol == hcontrol)return TRUE;
	else return FALSE;
}

void daxie::control::Control::SetControlText(const tstring& text) {
	SetWindowText(hcontrol, text.c_str());
}
void daxie::control::Control::EnableControl() {
	EnableWindow(hcontrol, TRUE);
}
void daxie::control::Control::DisableControl() {
	EnableWindow(hcontrol, FALSE);
}
void daxie::control::Control::ShowControl() {
	ShowWindow(hcontrol, SW_SHOW);
}
void daxie::control::Control::HideControl() {
	ShowWindow(hcontrol, SW_HIDE);
}
void daxie::control::Control::MoveControl(int width, int height, int x, int y) {
	MoveWindow(hcontrol, x, y, width, height, TRUE);
}