string InputHandler::getStringInput(string prompt) {
    string value;
    cout << prompt;
    cin.ignore();
    getline(cin, value);
    return value;
}