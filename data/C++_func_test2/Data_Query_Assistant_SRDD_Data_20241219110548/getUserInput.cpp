string UserInterface::getUserInput() {
    cout << "Enter your query (or 'exit' to quit): ";
    string input;
    getline(cin, input);
    return input;
}