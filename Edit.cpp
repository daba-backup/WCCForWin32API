#include"Edit.h"

daxie::control::Edit::Edit(int x, int y, int width, int height, HWND hwnd_parent)
	:Control(TEXT(""), TEXT("EDIT"), x, y, width, height, hwnd_parent, NULL,
		WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE, 0) {

}
daxie::control::Edit::~Edit() {

}