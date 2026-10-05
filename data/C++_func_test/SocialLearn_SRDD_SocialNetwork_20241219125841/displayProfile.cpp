void User::displayProfile() const {
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Interests: ";
    for (int i = 0; i < interests.size(); i++) {
        cout << interests[i];
        if (i < interests.size() - 1) cout << ", ";
    }
    cout << endl;
    cout << "Expertise: ";
    for (int i = 0; i < expertise.size(); i++) {
        cout << expertise[i];
        if (i < expertise.size() - 1) cout << ", ";
    }
    cout << endl;
}