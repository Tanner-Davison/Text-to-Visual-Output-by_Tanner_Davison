#include "htmlCreator.h"
#include <iostream>

using namespace std;

CustomElement::CustomElement(const string& custom) : element(custom) {
}
CustomElement::~CustomElement() {
}
void CustomElement::setElement(const string& type, const string& bodyP, const string& style) {
	element = "<" + type + " style=\"" + style + "\">" + bodyP + "</" + type + ">";
}
string CustomElement::getElement() const {
	return element;
}
