void UserProfile::viewProgress() const {
    std::cout << "Progress for " << username << " (" << age << " years old):" << std::endl;
    for (size_t i = 0; i < activeChallenges.size(); ++i) {
        activeChallenges[i].viewChallenge();
    }
}