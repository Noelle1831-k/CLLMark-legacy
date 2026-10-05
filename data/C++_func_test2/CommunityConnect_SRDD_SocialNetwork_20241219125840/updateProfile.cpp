void User::updateProfile() {
    cout << "Updating Profile..." << endl;
    cout << "Enter New Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter New Email: ";
    getline(cin, email);
    cout << "Enter New Location: ";
    getline(cin, location);
    cout << "Enter New Bio: ";
    getline(cin, bio);
    cout << "Profile updated successfully!" << endl;
}