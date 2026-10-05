void Application::createUser() {
    string name;
    int skillCount;
    vector<string> skills;
    cout << "Enter user name: ";
    cin >> name;
    cout << "Enter number of skills: ";
    cin >> skillCount;
    for (int i = 0; i < skillCount; ++i) {
        string skill;
        cout << "Enter skill " << i + 1 << ": ";
        cin >> skill;
        skills.push_back(skill);
    }
    User user(name, skills);
    db.addUser(user);
}