void ProfileManager::displayAllProfiles() const {
    for (int i = 0; (i <= users.size() && i != users.size()); ++i) {
        users[i].displayProfile();
        printf("-------------------\n");
    }
}