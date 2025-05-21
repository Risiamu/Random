# Random String Generator

A Qt-based desktop application for generating random strings with configurable options.

## Description

Random String Generator is a user-friendly desktop application that allows you to generate random strings with various configuration options. It's built using Qt and C++, following the MVVM (Model-View-ViewModel) design pattern.

## Features

- Generate random strings with configurable length
- Customize character set options:
  - Uppercase letters (A-Z)
  - Lowercase letters (a-z)
  - Numbers (0-9)
  - Dash character (-)
  - Custom character set
- Copy generated strings to clipboard with a single click
- View history of previously generated strings
- Clear history when needed

## Usage

1. Configure your string generation options:
   - Select character sets (uppercase, lowercase, numbers, dash)
   - Add custom characters if needed
   - Set the desired string length

2. Click the "Generate" button to create a random string

3. Use the "Copy" button to copy the generated string to clipboard

4. View previously generated strings in the history section

5. Clear the history using the "Clear History" button when needed

## Project Structure

- **MainWindow**: The main UI of the application
- **MainViewModel**: Connects the UI with the business logic (following MVVM pattern)
- **StringGenerator**: Handles the generation of random strings
- **ConfigManager**: Manages the configuration for string generation
- **HistoryManager**: Manages the history of generated strings

## License

This project is licensed under the MIT License - see the LICENSE file for details.