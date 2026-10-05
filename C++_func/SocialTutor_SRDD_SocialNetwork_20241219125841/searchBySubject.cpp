void SystemManager::searchBySubject() {
    string subject;
    cout << "Enter subject to search for tutors: ";
    cin >> subject;
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getRole() == "tutor" && users[i]->hasSubject(subject)) {
            users[i]->displayProfile();
        }
    }
}