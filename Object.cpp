#include"Object.h"

daxie::Object::Object() {
	str = "";
}
daxie::Object::Object(const std::string& str) {
	this->str = str;
}
daxie::Object::~Object() {

}

std::string daxie::Object::toString() {
	return str;
}