void UserProfile::saveUserData() {
    ofstream file("user_data.txt");
    if (file.is_open()) {
        file << userName << endl;
        file.close();
        cout << "User data saved successfully." << endl;
    } else {
        cout << "Error saving user data." << endl;
    }
}