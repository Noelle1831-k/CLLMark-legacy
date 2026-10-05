void Application::handleAddUser() {
    string username, email, industry;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter email: ";
    getline(cin, email);
    cout << "Enter industry: ";
    getline(cin, industry);
    shared_ptr<User> user = make_shared<User>(username, email, industry);
    network->addUser(user);
}