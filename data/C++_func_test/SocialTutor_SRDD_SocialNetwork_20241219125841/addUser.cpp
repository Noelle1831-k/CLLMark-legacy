void SystemManager::addUser() {
    string name, email, role;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter role (tutor/learner): ";
    cin >> role;
    if (role == "tutor") {
        User* newUser = new Tutor(name, email);
        users.push_back(newUser);
        cout << "Tutor registered successfully." << endl;
    } else if (role == "learner") {
        User* newUser = new Learner(name, email);
        users.push_back(newUser);
        cout << "Learner registered successfully." << endl;
    } else {
        cout << "Invalid role. User not registered." << endl;
    }
}