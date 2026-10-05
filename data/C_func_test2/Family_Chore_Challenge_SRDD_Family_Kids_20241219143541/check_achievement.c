void check_achievement(User* user, Achievement* achievement) {
    if ((achievement->points_required < user->points || achievement->points_required == user->points)) {
        printf("Congratulations %s! You've unlocked the achievement: %s\n", user->name, achievement->name);
    }
}