string UserInterface::getUserInput() {
    string input;
    cout << "Enter the path to the audio file or link to the track: ";
    cin >> input;
    return input;
}