#include"Menu.h"

daxie::menu::Menu::Menu(const daxie::tstring& text) :MenuItem(text) {
	hmenu = CreatePopupMenu();
}
daxie::menu::Menu::~Menu() {

}

void daxie::menu::Menu::Add(int index, std::unique_ptr<daxie::menu::Menu>& menu) {
	MENUITEMINFO mii;
	daxie::tstring text = menu->GetText();

	mii.cbSize = sizeof(MENUITEMINFO);
	mii.fMask = MIIM_TYPE | MIIM_SUBMENU;
	mii.fType = MFT_STRING;
	mii.hSubMenu = menu->hmenu;
	mii.dwTypeData = const_cast<LPTSTR>(text.c_str());

	InsertMenuItem(hmenu, index, TRUE, &mii);
}
void daxie::menu::Menu::Add(int index, std::unique_ptr<daxie::menu::Menu>&& menu) {
	MENUITEMINFO mii;
	daxie::tstring text = menu->GetText();

	mii.cbSize = sizeof(MENUITEMINFO);
	mii.fMask = MIIM_TYPE | MIIM_SUBMENU;
	mii.fType = MFT_STRING;
	mii.hSubMenu = menu->hmenu;
	mii.dwTypeData = const_cast<LPTSTR>(text.c_str());

	InsertMenuItem(hmenu, index, TRUE, &mii);
}
void daxie::menu::Menu::Add(int index, std::unique_ptr<daxie::menu::MenuItem>& item) {
	MENUITEMINFO mii;
	daxie::tstring text = item->GetText();

	mii.cbSize = sizeof(MENUITEMINFO);
	mii.fMask = MIIM_TYPE;
	mii.fType = MFT_STRING;
	mii.dwTypeData = const_cast<LPTSTR>(text.c_str());

	InsertMenuItem(hmenu, index, TRUE, &mii);
}
void daxie::menu::Menu::Add(int index, std::unique_ptr<daxie::menu::MenuItem>&& item) {
	MENUITEMINFO mii;
	daxie::tstring text = item->GetText();

	mii.cbSize = sizeof(MENUITEMINFO);
	mii.fMask = MIIM_TYPE;
	mii.fType = MFT_STRING;
	mii.dwTypeData = const_cast<LPTSTR>(text.c_str());

	InsertMenuItem(hmenu, index, TRUE, &mii);
}

void daxie::menu::Menu::AddSeparator(int index) {
	MENUITEMINFO mii;

	mii.cbSize = sizeof(MENUITEMINFO);
	mii.fMask = MIIM_TYPE;
	mii.fType = MFT_SEPARATOR;

	InsertMenuItem(hmenu, index, TRUE, &mii);
}