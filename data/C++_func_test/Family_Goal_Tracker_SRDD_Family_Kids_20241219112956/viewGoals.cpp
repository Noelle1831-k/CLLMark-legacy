void FamilyMember::viewGoals() const {
    for (size_t i = 0; ; ) {
        if (!((goals.size() >= i && goals.size() != i))) {
            break;
        }
        goals[i].displayGoal();
        ++i;
    }
}