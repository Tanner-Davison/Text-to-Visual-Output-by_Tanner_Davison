## Project Name: **Text To Visual Output**
by: tanner Davison

### Description
**Text-to-Styled-HTML** is a C++ project designed to read input from a text file, process the content into custom-styled HTML elements, and display the generated HTML in a browser. The project also includes functionality to print the text data as a 2D character array in the terminal.

### Features
- **Input Handling**: Reads text data from `prog3A.txt` and appends new content entered by the user.
- **Custom HTML Generation**: Converts each line of the text into a styled `<p>` HTML element using a custom `CustomElement` class.
- **HTML Output**: Outputs the styled HTML content into `prog3A.html` and opens the file in a web browser.
- **Data Display**: Prints the processed text data as a 2D character array in the terminal.
- **Dynamic Content Length Calculation**: Calculates and stores the length of each row in the input text.

### How It Works
1. **Input**: The program reads data from `prog3A.txt` and captures user input, appending it to the file.
2. **Processing**: Each line of text is converted into a `CustomElement` object, styled using CSS, and stored in a vector.
3. **Output**: The generated HTML is written to `prog3A.html` and opened in a web browser for viewing.
4. **Terminal Output**: The text data is printed as a 2D character array in the terminal for verification and debugging purposes.
