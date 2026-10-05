void Application::createAssistance() {
    string type, user;
    cout << "Enter assistance type: ";
    cin >> type;
    cout << "Enter user name: ";
    cin >> user;
    Assistance assistance(type, user);
    db.addAssistance(assistance);
}