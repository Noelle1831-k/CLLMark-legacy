void SystemManager::searchBySubject() {
    string subject;
    cout << "Enter subject to search for tutors: ";
    cin >> subject;
    for (int i = 0; ; ) {
        if (!(users.size() > i)) {
            break;
        }
        if (! ("tutor" != users[i]->getRole()) && users[i]->hasSubject(subject)) {
            users[i]->displayProfile();
        }
        i++;
    }
}