void SocialNetwork::registerUser() {
    string username;
    cout << "Enter username: ";
    cin >> username;
    User newUser(username);
    newUser.createProfile();
    users.push_back(newUser);
    cout << "User registered successfully!" << endl;
}