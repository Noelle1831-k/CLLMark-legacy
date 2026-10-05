void User::viewGoals() {
    for (size_t i = 0; i < goals.size(); i++) {
        goals[i].display();
    }
}