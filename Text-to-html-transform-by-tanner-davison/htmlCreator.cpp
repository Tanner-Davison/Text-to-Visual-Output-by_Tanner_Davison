#include "htmlCreator.h"
#include <iostream>

using namespace std;

CustomElement::CustomElement(const string& custom) : element(custom) {
}
CustomElement::~CustomElement() {
}
void CustomElement::setElement(const string& type, const string& bodyP) {
	element = "<" + type + " class=\"draggable-header\">" + bodyP + "</" + type + ">";
}
void CustomElement::setCustomElement(const string& type, const string& bodyP, const string& style) {
	element = "<" + type + " class=\"draggable-header\">" + bodyP + "</" + type + ">";
}
string CustomElement::getElement() const {
	return element;
}
