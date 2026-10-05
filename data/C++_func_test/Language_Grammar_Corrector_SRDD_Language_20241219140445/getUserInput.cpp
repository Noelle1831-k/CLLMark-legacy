string UserInterface::getUserInput() {
    string input;
    cout << "Enter text to check grammar: ";
    getline(cin, input);
    return input;
}