#pragma once

#include"Object.h"
#include"TString.h"

namespace daxie {
	class TStringFunctions :public Object {
	public:
		static daxie::tstring to_string(int value);
		static daxie::tstring to_string(float value);
		static daxie::tstring to_string(float value, int digits);

		static daxie::tstring string_to_tstring(const std::string& src);
		static std::string tstring_to_string(const daxie::tstring& src);
	};
}