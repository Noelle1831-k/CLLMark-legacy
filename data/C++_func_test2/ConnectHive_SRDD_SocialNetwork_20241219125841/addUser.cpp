void ConnectHive::addUser() {
    string name, bio, location;
    cout << "Enter your name: ";
    cin.ignore(); 
    getline(cin, name);
    cout << "Enter a short bio: ";
    getline(cin, bio);
    cout << "Enter your location: ";
    getline(cin, location);
    User newUser(name, bio, location);
    users.push_back(newUser);
    cout << "User added successfully!\n";
}