void SocialNetwork::loginUser() {
    string username;
    cout << "Enter username to login: ";
    cin >> username;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == username) { 
            cout << "Login successful!" << endl;
            users[i].viewProfile();
            return;
        }
    }
    cout << "User not found. Please register first." << endl;
}