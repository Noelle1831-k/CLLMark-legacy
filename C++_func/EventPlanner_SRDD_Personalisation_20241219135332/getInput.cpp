string UserInterface::getInput(const string& prompt) {
    cout << prompt;
    string input;
    getline(cin, input);
    return input;
}