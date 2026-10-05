void UserProfile::setProfile() {
    int numSkills, numInterests;
    string skill, interest;
    cout << "Enter number of skills: ";
    cin >> numSkills;
    cout << "Enter your skills:" << endl;
    for (int i = 0; i < numSkills; i++) {
        cin >> skill;
        skills.push_back(skill);
    }
    cout << "Enter number of interests: ";
    cin >> numInterests;
    cout << "Enter your interests:" << endl;
    for (int i = 0; i < numInterests; i++) {
        cin >> interest;
        interests.push_back(interest);
    }
}