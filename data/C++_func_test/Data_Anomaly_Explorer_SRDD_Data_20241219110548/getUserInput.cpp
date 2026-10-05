string UserInterface::getUserInput(const string& prompt) {
    cout << prompt;
    string input;
    getline(cin, input);
    return input;
}