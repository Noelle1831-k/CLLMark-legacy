void Family::viewFamilyProgress() {
    cout << familyName << " Progress:" << endl;
    int totalPoints = 0;
    for (size_t i = 0; i < members.size(); i++) {
        members[i].viewProgress();
        totalPoints += members[i].getActivityPoints();
    }
    cout << "Total Family Activity Points: " << totalPoints << endl;
}