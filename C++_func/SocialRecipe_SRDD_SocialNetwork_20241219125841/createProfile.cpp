void User::createProfile() {
    cout << "Enter your username: ";
    cin >> username;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout << "Write a short bio: ";
    getline(cin, bio);
    cout << "Profile created successfully!" << endl;
}