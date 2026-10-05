void UserProfile::loadUserData() {
    ifstream file("user_data.txt");
    if (file.is_open()) {
        getline(file, userName);
        file.close();
        cout << "Welcome back, " << userName << "!" << endl;
    } else {
        cout << "No user data found. Please enter your name: ";
        cin >> userName;
        cout << "Hello, " << userName << "! Your data will be saved for future use." << endl;
    }
}