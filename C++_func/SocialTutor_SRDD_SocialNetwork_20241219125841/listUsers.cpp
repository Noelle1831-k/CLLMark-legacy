void SystemManager::listUsers() {
    cout << "Listing all users:" << endl;
    for (int i = 0; i < users.size(); i++) {
        users[i]->displayProfile();
    }
}