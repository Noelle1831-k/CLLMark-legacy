void FamilyMember::viewGoals() const {
    for (size_t i = 0; i < goals.size(); ++i) {
        goals[i].displayGoal();
    }
}