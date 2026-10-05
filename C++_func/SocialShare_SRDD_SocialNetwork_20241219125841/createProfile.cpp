void User::createProfile() {
    cout << "Enter profile details for " << username << ": ";
    cin.ignore();
    getline(cin, profileDetails);
    cout << "Profile created successfully!" << endl;
}