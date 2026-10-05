void User::setDetails() {
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your instrument: ";
    getline(cin, instrument);
    cout << "Enter your skill level (Beginner/Intermediate/Advanced): ";
    getline(cin, skillLevel);
}