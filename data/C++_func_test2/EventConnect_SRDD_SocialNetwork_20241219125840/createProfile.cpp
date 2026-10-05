void User::createProfile() {
    cout << "Creating user profile..." << endl;
    username = "JohnDoe";
    location = "New York";
    interests.push_back("Music");
    interests.push_back("Technology");
    cout << "Profile created successfully!" << endl;
}