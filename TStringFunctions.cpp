#include"TStringFunctions.h"
#include<iomanip>
#include<sstream>
#include<string>
#include<vector>

daxie::tstring daxie::TStringFunctions::to_string(int value) {
	daxie::tstring ret;

#ifdef UNICODE
	ret = std::to_wstring(value);
#else
	ret = std::to_string(value);
#endif

	return ret;
}
daxie::tstring daxie::TStringFunctions::to_string(float value) {
	daxie::tstring ret;

#ifdef UNICODE
	ret = std::to_wstring(value);
#else
	ret = std::to_string(value);
#endif

	return ret;
}
daxie::tstring daxie::TStringFunctions::to_string(float value, int digits) {
	daxie::tstring ret;

	std::string temp;
	std::ostringstream oss;

	oss << std::fixed << std::setprecision(digits) << value;
	temp = oss.str();

	ret = TStringFunctions::string_to_tstring(temp);

	return ret;
}

daxie::tstring daxie::TStringFunctions::string_to_tstring(const std::string& src) {
	daxie::tstring ret;

#ifdef UNICODE
	auto const dst_size = ::MultiByteToWideChar(CP_UTF8, 0U, src.data(), -1, nullptr, 0U);
	std::vector<wchar_t> dst(dst_size, TEXT('\0'));

	if (::MultiByteToWideChar(CP_UTF8, 0U, src.data(), -1, dst.data(), dst.size()) == 0) {
		throw std::system_error{ static_cast<int>(::GetLastError()),std::system_category() };
	}

	dst.resize(std::char_traits<wchar_t>::length(dst.data()));
	dst.shrink_to_fit();

	ret.assign(dst.begin(), dst.end());

#else
	ret = src;
#endif

	return ret;
}
std::string daxie::TStringFunctions::tstring_to_string(const daxie::tstring& src) {
	std::string ret;

#ifdef UNICODE
	auto const dst_size = ::WideCharToMultiByte(CP_UTF8, 0U, src.data(), -1, nullptr, 0U, nullptr, nullptr);
	std::vector<char> dst(dst_size, '\0');

	if (::WideCharToMultiByte(CP_UTF8, 0U, src.data(), -1, dst.data(), dst.size(), nullptr, nullptr) == 0) {
		throw std::system_error{ static_cast<int>(::GetLastError()),std::system_category() };
	}

	dst.resize(std::char_traits<char>::length(dst.data()));
	dst.shrink_to_fit();

	ret.assign(dst.begin(), dst.end());

#else
	ret = src;
#endif

	return ret;
}