void award_badge(User* user, RewardSystem* reward_system, const char* badge) {
    strcpy(reward_system->badges[reward_system->badge_count++], badge);
    printf("%s has been awarded the badge: %s\n", user->name, badge);
}