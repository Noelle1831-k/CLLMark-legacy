void User::listGroups() const {
    cout << "Groups for " << username << ":" << endl;
    for (size_t i = 0; i < groups.size(); ++i) {
        cout << "- " << groups[i]->getGroupName() << endl;
    }
}