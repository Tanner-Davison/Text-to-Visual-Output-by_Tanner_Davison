#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "HtmlCreator.h" 

using namespace std;

int main() {
	ifstream inputFile("prog3A.txt");
	ofstream outputFile("prog3A.txt", ios::app);
	ofstream outputHtml("prog3A.html", ios::out);
	string line;
	vector<int> rowLengths;
	vector<CustomElement> elements;

	if (!inputFile.is_open() || !outputFile.is_open()) {
		cerr << "Error opening file!" << endl;
		return 1;
	}

	getline(cin, line, '\n');

	outputFile << line << endl;

	// Determine the length of each ROW and create CustomElement objects 
	while (getline(inputFile, line)) {
		CustomElement element;
		element.setElement("p", line,
			"display:flex; align-items:center; font-weight:bold; font-size:20px;");
		elements.push_back(element);

		//Total length of words from each line/ROW;
		istringstream iss(line);
		int count = 0;
		string word;

		while (iss >> word) {
			count += word.size();
		}
		rowLengths.push_back(count);
	}

	inputFile.clear();
	inputFile.seekg(0);

	vector<vector<char>> colPlayerRewards;

	for (size_t i = 0; i < rowLengths.size(); i++) {
		getline(inputFile, line);
		vector<char> row(line.begin(), line.end());
		colPlayerRewards.push_back(row);
	}

	inputFile.close();
	outputFile.close();
	//Adding html body before elements
	outputHtml << "<!DOCTYPE html>\n"
		<< "<html lang=\"en\">\n"
		<< "<head>\n"
		<< "<meta charset=\"UTF-8\">\n"
		<< "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
		<< "<title>Document</title>\n"
		<< "</head>\n"
		<< "<body>\n";
	for (const auto& elem : elements) {
		outputHtml << elem.getElement() << endl;
		cout << elem.getElement() << endl;
	}
	outputHtml << "</body>\n"
		<< "</html>\n";

	outputHtml.close();

	ShellExecuteA(NULL, "open", "prog3A.html", NULL, NULL, SW_SHOWNORMAL);

	// prints the 2D character array in the os terminal
	for (const auto& row : colPlayerRewards) {
		for (char c : row) {
			cout << c;
		}

		cout << endl;
	}

	return 0;
}