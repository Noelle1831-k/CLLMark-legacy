void User::displayProfile() const {
    cout << "Name: " << name << endl;
    cout << "Skills: ";
    for (int i = 0; i < skills.size(); i++) {
        cout << skills[i];
        if (i < skills.size() - 1) cout << ", ";
    }
    cout << endl;
    cout << "Interests: ";
    for (int i = 0; i < interests.size(); i++) {
        cout << interests[i];
        if (i < interests.size() - 1) cout << ", ";
    }
    cout << endl;
}