void addSkill(User *user, const char *skill) {
    if (user->skillCount < 5) {
        strcpy(user->skills[user->skillCount++], skill);
    }
}