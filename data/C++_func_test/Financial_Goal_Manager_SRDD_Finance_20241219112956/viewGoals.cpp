void User::viewGoals() {
    for (size_t i = 0; goals.size() > i; i++) {
        goals[i].display();
    }
}