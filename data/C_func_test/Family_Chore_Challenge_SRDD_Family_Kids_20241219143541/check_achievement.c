void check_achievement(User* user, Achievement* achievement) {
    if (user->points >= achievement->points_required) {
        printf("Congratulations %s! You've unlocked the achievement: %s\n", user->name, achievement->name);
    }
}