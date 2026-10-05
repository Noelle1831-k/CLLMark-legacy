void Family::viewFamilyRewards() {
    int totalPoints = 0;
    for (size_t i = 0; i < members.size(); i++) {
        totalPoints += members[i].getActivityPoints();
    }
    if (totalPoints >= 150) {
        cout << familyName << " earned a Family Gold Reward!" << endl;
    } else if (totalPoints >= 100) {
        cout << familyName << " earned a Family Silver Reward!" << endl;
    } else {
        cout << familyName << " earned a Family Bronze Reward!" << endl;
    }
}