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

	// Determines the length of each ROW and create CustomElement objects 
	while (getline(inputFile, line)) {
		CustomElement element;
		element.setElement("div", line);
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
	outputHtml << "<!DOCTYPE html>\n"
		<< "<html lang=\"en\">\n"
		<< "<head>\n"
		<< "<meta charset=\"UTF-8\">\n"
		<< "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
		<< "<title>C++ Generated</title>\n"
		<< "  <style>\n"
		<< "    body {"
		<< "     display:flex;\n"
		<< "     gap:3px;\n"
		<< "     flex-wrap:wrap;\n"
		<< "     }\n"
		<< "    #draggable {\n"
		<< "      position: relative;\n"
		<< "      min-width: 100px;\n"
		<< "      min-height: 100px;\n"
		<< "      overflow: visible\n"
		<< "      z-index: 1;\n"
		<< "      background-color: transparent;\n"
		<< "    }\n"
		<< "    .draggable-header {\n"
		<< "      position: relative;\n"
		<< "      display: flex;\n"
		<< "      width:max-content;\n"
		<< "      height:auto;\n"
		<< "      align-self: center;\n"
		<< "      justify-self: center;\n"
		<< "      cursor: move;\n"
		<< "      z-index: 10;\n"
		<< "      padding: 10px;\n"
		<< "      background-color: transparent;\n"
		<< "      color: #00000;\n"
		<< "    }\n"
		<< "  </style>\n"
		<< "</head>\n"
		<< "<body>\n";

	for (const auto& elem : elements) {
		outputHtml << "<div id=\"draggable\">" << elem.getElement() << "</div>" << endl;
		cout << elem.getElement() << endl;
	}

	outputHtml
		<< "  <script>\n"
		<< "    function dragElement(elmnt) {\n"
		<< "      var pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0;\n"
		<< "      var header = elmnt.querySelector('.draggable');\n"
		<< "      if (header) {\n"
		<< "        header.onmousedown = dragMouseDown;\n"
		<< "      } else {\n"
		<< "        elmnt.onmousedown = dragMouseDown;\n"
		<< "      }\n"
		<< "\n"
		<< "      function dragMouseDown(e) {\n"
		<< "        e = e || window.event;\n"
		<< "        e.preventDefault();\n"
		<< "        pos3 = e.clientX;\n"
		<< "        pos4 = e.clientY;\n"
		<< "        document.onmouseup = closeDragElement;\n"
		<< "        document.onmousemove = elementDrag;\n"
		<< "      }\n"
		<< "\n"
		<< "      function elementDrag(e) {\n"
		<< "        e = e || window.event;\n"
		<< "        e.preventDefault();\n"
		<< "        pos1 = pos3 - e.clientX;\n"
		<< "        pos2 = pos4 - e.clientY;\n"
		<< "        pos3 = e.clientX;\n"
		<< "        pos4 = e.clientY;\n"
		<< "        elmnt.style.top = (elmnt.offsetTop - pos2) + 'px';\n"
		<< "        elmnt.style.left = (elmnt.offsetLeft - pos1) + 'px';\n"
		<< "      }\n"
		<< "\n"
		<< "      function closeDragElement() {\n"
		<< "        document.onmouseup = null;\n"
		<< "        document.onmousemove = null;\n"
		<< "      }\n"
		<< "    }\n"
		<< "\n"
		<< "    const draggables = document.querySelectorAll('.draggable-header');\n"
		<< "    draggables.forEach(draggable => {\n"
		<< "      dragElement(draggable);\n"
		<< "    });\n"
		<< "  </script>\n"
		<< "</body>\n"
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