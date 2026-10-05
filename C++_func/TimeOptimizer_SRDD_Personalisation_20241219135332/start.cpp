void AppInterface::start() {
    cout << "Welcome to the Personalization Software!\n";
    cout << "Type 'help' for a list of commands.\n";
    string input;
    while (true) {
        cout << "Enter a command (track, schedule, analyze, summary, quit): ";
        getline(cin, input);
        if (input == "quit") break;
        handleUserInput(input);
    }
}