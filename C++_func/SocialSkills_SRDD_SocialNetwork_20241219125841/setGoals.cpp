void User::setGoals() {
    cout << "Setting goals..." << endl;
    cout << "Enter your social skill improvement goal: ";
    cin.ignore();
    getline(cin, goals);
    cout << "Goal set: " << goals << endl;
}