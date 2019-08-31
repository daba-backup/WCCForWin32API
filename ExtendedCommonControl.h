#pragma once

#include"CommonDialog.h"

namespace daxie {
	namespace dialog {
		class OptionalEncodingFileChooser :public daxie::dialog::FileChooser {
		private:
			static BOOL CALLBACK CCHookProc(HWND hdlg, UINT msg, WPARAM wp, LPARAM lp);

		public:
			OptionalEncodingFileChooser();
			virtual ~OptionalEncodingFileChooser();
		};
	}
}