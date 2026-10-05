void Application::viewMessages() {
    string user;
    cout << "Enter user name to view messages: ";
    cin >> user;
    Messaging messaging;
    vector<string> messages = messaging.getMessages(user);
    for (const string& message : messages) {
        cout << message << "\n";
    }
}