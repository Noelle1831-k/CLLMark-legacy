void UserProfile::getProfile() const {
    cout << "Name: " << name << endl;
    cout << "Skills: ";
    for (size_t i = 0; i < skills.size(); i++) {
        cout << skills[i] << " ";
    }
    cout << endl;
    cout << "Interests: ";
    for (size_t i = 0; i < interests.size(); i++) {
        cout << interests[i] << " ";
    }
    cout << endl;
}