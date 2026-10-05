void User::createProfile() {
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your email: ";
    getline(cin, email);
    cout << "Enter your interests (comma-separated): ";
    string interestInput;
    getline(cin, interestInput);
    size_t pos = 0;
    while ((pos = interestInput.find(',')) != string::npos) {
        interests.push_back(interestInput.substr(0, pos));
        interestInput.erase(0, pos + 1);
    }
    interests.push_back(interestInput);
    cout << "Enter your areas of expertise (comma-separated): ";
    string expertiseInput;
    getline(cin, expertiseInput);
    pos = 0;
    while ((pos = expertiseInput.find(',')) != string::npos) {
        expertise.push_back(expertiseInput.substr(0, pos));
        expertiseInput.erase(0, pos + 1);
    }
    expertise.push_back(expertiseInput);
    cout << "Profile created successfully!" << endl;
}