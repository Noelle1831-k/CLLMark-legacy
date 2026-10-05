void Family::trackProgress() const {
    for (size_t i = 0; i < members.size(); ++i) {
        members[i].viewGoals();
    }
}