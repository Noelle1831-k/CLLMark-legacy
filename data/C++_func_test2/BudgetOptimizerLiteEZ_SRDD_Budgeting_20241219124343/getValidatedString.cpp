string InputHandler::getValidatedString(string prompt) {
    string value;
    cout << prompt;
    cin >> value;
    return value;
}