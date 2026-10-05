void loadUserData(User *user) {
    for (int i = 0; i < 10; i++) {
        user->preferences[i] = rand() % 5;
        user->history[i] = rand() % 100;
    }
}