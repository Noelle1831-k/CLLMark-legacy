void MainApplication::createUserProfile() {
    string username, email, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;
    User newUser(userIdCounter++, username, email, password);
    users[newUser.getUserId()] = newUser;
    cout << "User profile created successfully!\n";
}