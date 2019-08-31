#include"ExtendedCommonControl.h"

BOOL CALLBACK daxie::dialog::OptionalEncodingFileChooser::CCHookProc(HWND hdlg, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_INITDIALOG:
		return TRUE;
	}

	return FALSE;
}

daxie::dialog::OptionalEncodingFileChooser::OptionalEncodingFileChooser() {
	OPENFILENAME& ofn = this->GetOfn();

	ofn.lpfnHook = reinterpret_cast<LPOFNHOOKPROC>(CCHookProc);
}
daxie::dialog::OptionalEncodingFileChooser::~OptionalEncodingFileChooser() {

}