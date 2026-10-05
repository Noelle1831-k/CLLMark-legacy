void SocialMatchup::registerUser() {
    string name;
    cout << "Enter your name: ";
    cin >> name;
    UserProfile user(name);
    user.setProfile();
    users.push_back(user);
    cout << "User registered successfully!" << endl;
}