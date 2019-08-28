#include"MenuItem.h"

daxie::menu::MenuItem::MenuItem(const daxie::tstring& text) {
	this->text = text;
}
daxie::menu::MenuItem::~MenuItem() {

}

daxie::tstring daxie::menu::MenuItem::GetText() {
	return text;
}