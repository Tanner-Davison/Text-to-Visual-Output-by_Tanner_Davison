#pragma once

#include <string>

using namespace std;

class CustomElement {
public:
	CustomElement(const string& custom = "<div style=\"display:flex; align-items:center; justify-content:center;\">No custom text</div>");
	~CustomElement();

	string getElement() const;
	void setElement(const string& type = "div", const string& bodyP = "");
	void setCustomElement(const string& type = "div", const string& bodyP = "", const string& style = "");
private:
	string element;
};