#include"MenuItem.h"
#include"UniqueIDGenerator.h"

daxie::menu::MenuItem::MenuItem(const daxie::tstring& text) {
	this->text = text;
	id = daxie::tool::UniqueIDGenerator::GetNextID();

	hmenu = NULL;
}
daxie::menu::MenuItem::~MenuItem() {

}

MENUITEMINFO daxie::menu::MenuItem::MakeMenuItemInfo() {
	MENUITEMINFO mii = { 0 };

	mii.cbSize = sizeof(MENUITEMINFO);
	mii.fMask = MIIM_STATE;

	return mii;
}
UINT daxie::menu::MenuItem::GetState() {
	MENUITEMINFO mii = this->MakeMenuItemInfo();
	GetMenuItemInfo(hmenu, id, FALSE, &mii);

	return mii.fState;
}

BOOL daxie::menu::MenuItem::IsThisMenuItem(int id) {
	if (this->id == id)return TRUE;
	else return FALSE;
}
void daxie::menu::MenuItem::Check() {
	MENUITEMINFO mii = this->MakeMenuItemInfo();
	mii.fState = MFS_CHECKED;

	SetMenuItemInfo(hmenu, id, FALSE, &mii);
}
void daxie::menu::MenuItem::Uncheck() {
	MENUITEMINFO mii = this->MakeMenuItemInfo();
	mii.fState = MFS_UNCHECKED;

	SetMenuItemInfo(hmenu, id, FALSE, &mii);
}
void daxie::menu::MenuItem::Enable() {
	MENUITEMINFO mii = this->MakeMenuItemInfo();
	mii.fState = MFS_ENABLED;

	SetMenuItemInfo(hmenu, id, FALSE, &mii);
}
void daxie::menu::MenuItem::Disable() {
	MENUITEMINFO mii = this->MakeMenuItemInfo();
	mii.fState = MFS_DISABLED;

	SetMenuItemInfo(hmenu, id, FALSE, &mii);
}
void daxie::menu::MenuItem::Gray() {
	MENUITEMINFO mii = this->MakeMenuItemInfo();
	mii.fState = MFS_GRAYED;

	SetMenuItemInfo(hmenu, id, FALSE, &mii);
}
void daxie::menu::MenuItem::Hilite() {
	MENUITEMINFO mii = this->MakeMenuItemInfo();
	mii.fState = MFS_HILITE;

	SetMenuItemInfo(hmenu, id, FALSE, &mii);
}
void daxie::menu::MenuItem::Unhilite() {
	MENUITEMINFO mii = this->MakeMenuItemInfo();
	mii.fState = MFS_UNHILITE;

	SetMenuItemInfo(hmenu, id, FALSE, &mii);
}

daxie::tstring daxie::menu::MenuItem::GetText() {
	return text;
}
bool daxie::menu::MenuItem::IsChecked() {
	bool ret;
	UINT state = this->GetState();

	if (state&MFS_CHECKED)ret = true;
	else ret = false;

	return ret;
}
bool daxie::menu::MenuItem::IsEnabled() {
	bool ret;
	UINT state = this->GetState();

	if (state&MFS_ENABLED)ret = true;
	else ret = false;

	return ret;
}
bool daxie::menu::MenuItem::IsGrayed() {
	bool ret;
	UINT state = this->GetState();

	if (state&MFS_GRAYED)ret = true;
	else ret = false;

	return ret;
}
bool daxie::menu::MenuItem::IsHilited() {
	bool ret;
	UINT state = this->GetState();

	if (state&MFS_HILITE)ret = true;
	else ret = false;

	return ret;
}
