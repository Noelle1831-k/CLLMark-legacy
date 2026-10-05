void User::editProfile() {
    cout << "Editing user profile..." << endl;
    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new location: ";
    cin >> location;
    cout << "Add interests (type 'done' to finish): ";
    interests.clear();
    string interest;
    while (true) {
        cin >> interest;
        if (interest == "done") break;
        interests.push_back(interest);
    }
    cout << "Profile edited successfully!" << endl;
}