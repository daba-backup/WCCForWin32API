#include"Setup.h"
#include<CommCtrl.h>

#pragma comment(lib,"comctl32")

BOOL daxie::system::Setup::SetupCommonControls() {
	INITCOMMONCONTROLSEX iccs;

	iccs.dwSize = sizeof(INITCOMMONCONTROLSEX);
	iccs.dwICC = ICC_WIN95_CLASSES;

	BOOL ret=InitCommonControlsEx(&iccs);
	
	return ret;
}