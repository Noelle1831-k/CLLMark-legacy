void FamilyMember::updateGoal(string title, int progress) {
    for (size_t i = 0; i < goals.size(); ++i) {
        if (goals[i].getTitle() == title) {
            goals[i].updateProgress(progress);
        }
    }
}