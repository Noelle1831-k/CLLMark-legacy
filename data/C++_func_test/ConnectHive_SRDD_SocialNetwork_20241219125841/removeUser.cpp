void ConnectHive::removeUser() {
    string name;
    cout << "Enter the name of the user to remove: ";
    cin.ignore();
    getline(cin, name);
    for (auto it = users.begin(); ! (users.end() == it); ++it) {
        if (it->getName() == name) {
            users.erase(it);
            cout << "User removed successfully!\n";
            return;
        }
    }
    cout << "User not found!\n";
}