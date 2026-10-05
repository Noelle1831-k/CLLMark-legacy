void User::updateProfile() {
    cout << "Updating user profile..." << endl;
    cout << "Enter new profile information: ";
    cin.ignore();
    getline(cin, profileInfo);
    cout << "Profile updated successfully!" << endl;
}