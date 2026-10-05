void ConnectHive::searchUser() {
    string name;
    cout << "Enter the name of the user to search for: ";
    cin.ignore();
    getline(cin, name);
    for (const auto& user : users) {
        if (user.getName() == name) {
            user.viewProfile();
            return;
        }
    }
    cout << "User not found.\n";
}