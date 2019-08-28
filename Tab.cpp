#include"Tab.h"
#include<CommCtrl.h>

daxie::control::Tab::Tab(int width, int height, int x, int y, HWND hwnd_parent)
	:Control(TEXT(""), WC_TABCONTROL, width, height, x, y, hwnd_parent, NULL, WS_VISIBLE | WS_CHILD | WS_CLIPSIBLINGS, 0) {

}
daxie::control::Tab::~Tab() {

}

void daxie::control::Tab::InsertItem(int index, const daxie::tstring& text) {
	TCITEM tcitem;

	tcitem.mask = TCIF_TEXT;
	tcitem.pszText = const_cast<LPTSTR>(text.c_str());

	TabCtrl_InsertItem(this->GetControlHandle(), index, &tcitem);
}